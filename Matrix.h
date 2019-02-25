//Author: Ian Feekes, ianfeekes@gmail.com 

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream> 
#include <exception> 
#include <fstream> 
#include <math.h> 
#include <vector> 			//Matrices can be initialized with vector objects 
#include <map>				//This include may be taken out later 

#define EPSILON .001 		//Used for floating point comparison == 

namespace MATRIX { 			//We want to define our own namespace for this library 

	template<size_t M, size_t N, typename T = int> 
	class Matrix{
	//We make our matrices a friend with the ostream operator for nice testing representation

	private: 
		const static size_t ROWS=M;
		const static size_t COLS=N; 

	public: 

		//Array representation of data for cache hit maximization
		T arr[M*N];  
		
		//Empty constructor 
		Matrix(); 

		//Single value constructor
		Matrix(T val);

		//Single value constructor of different data type 
		template<typename U>
		Matrix(U val); 
		
		//Cpy constructor 
		template<size_t P, size_t Q, typename U>
		Matrix(const Matrix<P, Q, U>& copyMatrix); 

		//Vector constructor 
		Matrix(const std::vector<T> values); 

		//Different-typed vector constructor 
		template<typename U> 
		Matrix(const std::vector<U> values); 

		//Same-typed matrices contain all elements of same value 
		bool operator==(const Matrix <M,N,T>& compareMatrix) const; 

		//Different-typed matrices with fitting row-col arrangement
		template<typename U> 
		bool operator==(const Matrix<M,N,U>& compareMatrix) const;
		
		//Matrix of same type but different column and row numbers 
		template<size_t O, size_t P>
		inline bool operator==(const Matrix<O,P,T>&) const{return false;}

		//Matrix with different number of columns 
		template<size_t O>
		inline bool operator==(const Matrix<O,N,T>&) const {return false;}

		//Matrix with different number of row
		template<size_t O> 
		inline bool operator==(const Matrix<M,O,T>&) const {return false;} 

		//Vector with data values 
		bool operator ==(const std::vector<T>& dataVec) const; 

		//Vector with data values of a different type 
		template<typename U> 
		bool operator ==(const std::vector<U>& dataVec) const; 

		//Entirely different matrix 
		template<size_t O, size_t P, typename U>
		inline bool operator==(const Matrix<O,P,U>&) const{return false;}

		//Used to copy from a matrix of identical data fields
		const Matrix<M,N,T>& operator=(const Matrix<M,N,T >& toCopy);

		//Sets matrice's fields to the vector
		const Matrix<M,N,T>& operator=(const std::vector<T>& newData);

		//Sets the matrice's fields to a single entry
		const Matrix<M,N,T>& operator=(const T singleValue);  

		//This function is used for matrix multiplication eg. m=multiply(m1,m2) 
		template<size_t P> 
		void multiply(const Matrix <M,P,T>& m1, const Matrix<P,N,T>& m2); 

		/*Allows for multiplication of differently-typed matrices with nearly identical
		  algorithm, just kept separate so that same-typed matrix multiplication is 
		  optimized*/ 
		template<size_t P, typename U> 
		void multiply(const Matrix <M,P,T>& m1, const Matrix<P,N,U>& m2); 

		//Returns a new matrix from resulting multiplication eg b=m1*m2; 
		template<size_t P> 
		Matrix<M,P,T> operator*(const Matrix<N,P,T>& multiplyMatrix) const; 

		/*This functions to allow for compatible differently-typed multiplication while
		  still allowing for optimality*/ 
		template<size_t P, typename U> 
		Matrix<M,P,T> operator*(const Matrix<N,P,U>& multiplyMatrix) const; 

		//Scalar multiplication implementation is trivial but necessary for user possibilities 
		Matrix<M,N,T> scalarMult(const T val);

		//Different-typed scalar multiplication 
		template<typename U> 
		Matrix<M,N,T> scalarMult(const U val);

		//*= scalar functionality 
		inline void operator*=(const T val){for(size_t i=0;i<M;++i)for(size_t j=0;j<N;j++)this->arr[(i*N)+j]*=val;}

		//*= different-typed scalar functionality 
		template<typename U>
		inline void operator*=(const U val){for(size_t i=0;i<M;++i)for(size_t j=0;j<N;j++)this->arr[(i*N)+j]*=static_cast<T>(val);}

		//Sets transposition data into a matrix with proper fields 
		void transpose(Matrix<N,M,T>& newTranspose) const; 

		//More user-friendly transposition functionality 
		Matrix<N,M,T> createTranspose() const; 

		//Output representation 
		void toString(std::ostream& out )const;

	};//End of matrix class


	//CONSIDER DELETING THIS 
	template<size_t M, size_t N, typename T> 
	Matrix<M, N, T>:: Matrix() 
	{
		T copyArr [M*N]= {0}; 
		memcpy( this->arr, copyArr, M * N * sizeof(T));
    	return *this;
	}

	//Matrices can be initialized through values 
	template<size_t M, size_t N, typename T> 
	Matrix<M,N,T>:: Matrix(T val)
	{
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)this->arr[(i*N)+j]=val; 
	}

	//Different-typed single-value constructor 
	template<size_t M, size_t N, typename T> 
	template<typename U> 
	Matrix<M,N,T>:: Matrix(U val) 
	{
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)this->arr[(i*N)+j]=static_cast<T>(val); 
	}

	//Cpy constructor for matrices of different fields. Just changes pointer 
	template<size_t M, size_t N, typename T> 
	template<size_t P, size_t Q, typename U> 
	Matrix<M, N, T>:: Matrix(const Matrix<P, Q, U>& copyMatrix)
	{
		*this=copyMatrix; 
	}

	//Same-typed vector constructor 
	template<size_t M, size_t N, typename T> 
	Matrix<M, N, T>:: Matrix(const std::vector<T> vec)
	{
		//Test and throw errors for monkey-at-the-keyboard behavior 
		if(typeid(T)==typeid(char) || typeid(T)==typeid(std::string))
			std::cerr<<"Error: cannot initialize matrix with string or char data types"<<std::endl; 
		if(vec.size()!=M*N)
			std::cerr<<"Error: attempt to initialize matrix with vector that does not contain correct amount of entries"<<std::endl;   
		int ptr = 0; 
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)this->arr[(i*N)+j]=vec[ptr++]; 
	}

	//Different-typed vector constructor 
	template<size_t M, size_t N, typename T> 
	template<typename U>
	Matrix<M,N,T>:: Matrix(const std::vector<U> vec)
	{
		if(typeid(T)==typeid(char) || typeid(T)==typeid(std::string))
			std::cerr<<"Error: cannot initialize matrix with string or char data types"<<std::endl; 
		if(vec.size()!=M*N)
			std::cerr<<"Error: attempt to initialize matrix with vector that does not contain correct amount of entries"<<std::endl;   
		int ptr = 0; 
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)
				this->arr[(i*N)+j]=static_cast<T>(vec[ptr++]); 
	}
	
	//Compares each entry between the two matrices assuming they contain the same value type 
	template<size_t M, size_t N, typename T> 
	bool Matrix<M, N, T>:: operator==(const Matrix<M,N,T>& compareMatrix) const
	{
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)if(this->arr[(i*N)+j]!=compareMatrix.arr[(i*N)+j])return false; 
		return true; 
	}	

	//Different-typed matrix comparison operator simply uses static cast 
	template<size_t M, size_t N, typename T> 
	template<typename U> 
	bool Matrix<M, N, T>:: operator==(const Matrix<M,N,U>& compareMatrix) const
	{
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)if(this->arr[(i*N)+j]!=static_cast<T>(compareMatrix.arr[(i*N)+j]))return false; 
		return true; 
	}

	//Comparison with a vector that holds the same data fields 
	template<size_t M, size_t N, typename T> 
	bool Matrix<M,N,T>:: operator==(const std::vector<T>& dataVec) const
	{
		if(dataVec.size()!=M*N)return false; 
		bool flag = false; 
		if(typeid(T)==typeid(float) || typeid(T)==typeid(double))flag=true; 
		int vecIndex=0; 
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)
			{
				if(flag)if(fabs(this->arr[i*N+j]-dataVec[vecIndex])>=EPSILON)return false; 
				if(!flag)if(this->arr[i*N+j]!=dataVec[vecIndex])return false; 
				vecIndex++; 
			}
		return true; 
	}

	//Comparison with a vector that has different data fields
	template<size_t M, size_t N, typename T> 
	template<typename U> 
	bool Matrix<M,N,T>:: operator==(const std::vector<U>& dataVec) const
	{
		if(dataVec.size()!=M*N)return false; 
		bool flag = false; 
		if(typeid(T)==typeid(float) && typeid(U)==typeid(double))flag=true;
		int vecIndex=0; 
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)
			{
				if(flag && fabs(this->arr[i*N+j]-dataVec[vecIndex])>=EPSILON)return false;
				else if(!flag && this->arr[i*N+j]!=static_cast<T>(dataVec[vecIndex]))return false; 
				vecIndex++;
			}
		return true; 
	}

	//This is used for copying matrices with the same fields 
	template< size_t M, size_t N, typename T>
	const Matrix<M,N,T>& Matrix<M,N,T>::operator=( const Matrix< M, N, T >& toCopy)
	{
    	memcpy( this->arr, toCopy.arr, M * N * sizeof(T));	//Simply rearranges addressse
    	return *this;
	}


	//Takes in new data from the vector 
	template<size_t M, size_t N, typename T> 
	const Matrix<M,N,T>& Matrix<M,N,T>::operator=(const std::vector<T>& newData)
	{
		if(newData==NULL || newData.size()!=M*N)
		{
			std::cerr<<"Error: = Vector entries cannot fill data container of argument matrix"<<std::endl; 
			return *this; 
		}
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)
				this->arr[i*N+j]=newData[i*N+j];
		return *this; 
	}

	//Sets every entry in the matrix to a single value 
	template<size_t M, size_t N, typename T> 
	const Matrix<M,N,T>& Matrix<M,N,T>:: operator=(const T singleValue)
	{
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)this->arr[i*N+j]=singleValue; 
		return *this; 
	}
	
	/*This is the heart of matrix multiplication. The for loops allow reduction of cache misses.
	 This is the most straightforward algorithm for non-square matrices for O(M*N*P) time, which
	 could still be faster.*/ 
	template<size_t M, size_t N, typename T> 
	template<size_t P> 
	void Matrix<M, N, T>:: multiply( const Matrix<M,P,T>& m1, const Matrix<P,N,T>& m2)
	{
		T currEntry=0; 					//Initialize our value here to avoid reallocating same variable
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)
			{
				currEntry = 0;
				for(size_t k=0;k<P;++k)
				{
					if(m1.arr[i*P+k]!=0 && m2.arr[k*N+j]!=0)currEntry+=m1.arr[i*P+k]*m2.arr[k*N+j]; 
				}
				this->arr[i*N+j]=currEntry; 
			}
	}  

	/*This code may seem superfluous to the above method, however it avoids taking a static 
	  cast for each step (saving us on M*N*P rather large steps for our entire iteration), 
	  in an attempt to remain efficient unless absolutely necessary to perform this step*/ 
	template<size_t M, size_t N, typename T> 
	template<size_t P, typename U> 
	void Matrix<M, N, T>:: multiply( const Matrix<M,P,T>& m1, const Matrix<P,N,U>& m2)
	{
		T currEntry=0; 
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)
			{	
				currEntry = 0;
				for(size_t k=0;k<P;++k)
				{
					if(m1.arr[i*P+k]!=0 && m2.arr[k*N+j]!=0)currEntry+=static_cast<T>(m1.arr[i*P+k]*m2.arr[k*N+j]); 
				}
				this->arr[i*N+j]=currEntry; 
			}
	}  

	//Simply creates a new matrix that has been zeroed out, calls multiply, and returns it
	template<size_t M, size_t N,  typename T> 
	template<size_t P> 
	Matrix<M, P, T> Matrix<M, N, T>:: operator*(const Matrix<N,P,T>& multiplyMatrix) const
	{
		Matrix<M,P,T> productMatrix(0); 
		productMatrix.multiply(*this,multiplyMatrix);  
		return productMatrix; 
	}

	//Same as above, it simply calls the appropriate multiply and allows preventation of errors being thrown 
	template<size_t M, size_t N, typename T>
	template<size_t P, typename U> 
	Matrix<M, P, T> Matrix<M, N, T>:: operator*(const Matrix<N,P,U>& multiplyMatrix) const
	{
		Matrix<M,P,T> productMatrix(0); 
		productMatrix.multiply(*this,multiplyMatrix);  
		return productMatrix; 
	}

	//Trivial algorithm, but still may prove useful 
	template<size_t M, size_t N, typename T> 
	Matrix<M,N,T> Matrix<M,N,T>:: scalarMult(const T val)
	{
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)this->arr[i*N+j]*=val;
		return *this;
	}

	/*Different-typed scalarMult. Overloading may seem superfluous, but avoiding taking a static_cast
	  call for each entry in a potentially huge matrix saves on time. */ 
	template<size_t M, size_t N, typename T> 
	template<typename U> 
	Matrix<M,N,T> Matrix<M,N,T>:: scalarMult(const U val)
	{
		for(size_t i=0;i<M;++i)
			for(size_t j=0;j<N;++j)this->arr[i*N+j]*=static_cast<T>(val);
		return *this;
	}

	/*Sets the data fields in the new Transpose matrix to the transpose of the matrix calling 
	 *the function. 
	 *
	 * @ param: a Matrix with a number of rows equal to the number of columns of the matrix calling
	 *          this function, and a number of columns equal to the row number of the matrix calling
	 *          this function likewise. 
	 * 
	 * Returns nothing, however we have modified the argument matrix. 
	 * 
	 * NOTE: This algorithm is a very typical linear algebra implementation used for rotating images */ 
	template<size_t M, size_t N, typename T> 
	void Matrix<M, N, T>:: transpose(Matrix<N, M, T>& newTranspose) const 
	{
		/* Due to taking advantage of spatial locality in caching, it is ideally avoidable to be 
		 * calling up blocks [j][i] rather than [i][j] as this may force a cache with small block 
		 * sizes to perform more reads. However, with our underlying 2D array interface with matrices,
		 * this must be permitted to allow transposition to run in O(n) or O(N*M) time for the total 
		 * number of entries within a given matrix.*/
		for(size_t i=0;i<M;i++) 
			for(size_t j=0;j<N;j++)newTranspose.arr[j*M+i] = this->arr[i*N+j]; 
	}

	/*Returns the transpose of a given matrix. Does this by creating a new matrix of the appropriate fields
	 *and calling the above tranpose method on it. 
	 *
	 *Slower performance of the method because it requires the initializing of a new matrix and it eats up
	 *more stack space, however its convenience is a lot more user-friendly in simply returning a matrix
	 *and the user not having to create their own matrix takes out some of the heavy lifting. 
	 * 
	 * @ param: None
	 * 
	 * Returns a <N,M,T> matrix that is the transpose of the matrix that calls this function. 
	 */ 
	template<size_t M, size_t N, typename T> 
	Matrix<N,M,T> Matrix<M,N,T>::createTranspose() const
	{
		Matrix<N,M,T> t (0); 
		this->transpose(t); 
		return t; 
	}

	//Prints the matrix in a nicely formated row-column order 
	template<size_t M, size_t N, typename T> 
	void Matrix<M,N,T>::toString(std::ostream& out )const
	{
		for(size_t i=0;i<M;++i)
		{
			out<<"["; 
			for(size_t j=0;j<N;++j)
			{
				out<<this->arr[i*N+j];
				if(j<N-1)out<<",";
			}
			out<<"]"<<std::endl; 
		}
	}

}// ending MATRIX namespace library 

#endif 
