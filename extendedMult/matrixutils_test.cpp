#include "Matrix.h" 						//our matrix library 
#include <iostream> 						//allows << operator 
#include <vector> 							//allows vector implementation 
#include <math.h> 							//For use of M_PI value 
#include <string> 							//allows string methods, compare()

using namespace std; 						//We want easy string, vector, << access
using namespace MATRIX; 					//We want to simulate a user with matrix functions 


int main(int argc, char* argv[]){
	vector<double>v;
	double val =0; 
	//cout<<"boutta make first"<<endl; 
	for(size_t i=0;i<400;++i)
	{
		val = i%2==0? M_PI : -M_PI; 
		v.push_back(val); 
	}

	Matrix<20,20,double> bigBoy(v); 
	//cout<<"boutta make second"<<endl; 
	v.clear(); 
	for(size_t i=0;i<2500;++i)
	{
		//v.push_back(rand()*10000%i); 
		v.push_back((7+3*i)/4000); 
	}
	Matrix<50,50,double> biggerBoy(v); 
	v.clear(); 

	//cout<<"boutta make third"<<endl; 
	for(size_t i=0;i<2500;++i)
	{
		v.push_back((3*i)%1000); 
		//v.push_back((rand()*10-i)/3);
	}
	Matrix<50,50,double> biggestBoy(v); 
	v.clear(); 

	for(size_t j=0;j<8000;++j)
	{
		bigBoy = bigBoy * (bigBoy.createTranspose());
		biggerBoy = biggerBoy * (biggerBoy.createTranspose()); 
		biggestBoy = biggestBoy * (biggestBoy.createTranspose()); 
	}

	cout<<"done"; 

	return 0; 
}