#ifndef _UNITTEST_H_
#define _UNITTEST_H_

#include <iostream> 
#include <exception> 
#include <fstream> 
#include <vector> 
#include <math.h> 		    
#include "Matrix.h" 
#include <unordered_map>    //Hash table 

using namespace std;                        //vectors, strings << 
using namespace MATRIX;                     //matrix library 

class UnitTest
{
    private: 

        size_t ID;                          //Each test gets an ID 

        bool talk;                          //If the user wants to see string-formatted results

        vector<string> resultsString;       //For outputting to determine which calls failed 

        string operation;                   //Determines test type 

        vector<vector<double>> expected;    //Expected vectors for matrices 

        vector<double> expectedConst;       //Expected single value entries for matrix arguments 

        vector<vector<double>> arguments;   //Values to to initialize matrices to 

        vector<double> scalars;             //Values used in scalar multiplication tests 

        vector<double> argumentsConst; 

         vector<bool> results;              //Outcome of each test is pushed back 

    public: 

        friend std::ostream& operator << (std::ostream& out, const UnitTest& test)
        {
            out<<test.toString(); 
            return out; 
        } 

        //Constructor set to remain silent 
        UnitTest(const size_t ID, bool talk = false){this->ID=ID;this->talk=talk;}

        //Strings for outputting results 
        inline void setResults(vector<string> resultsList){this->resultsString.clear();this->resultsString=resultsList;} 


        //Operations for the matrices to perform during this test 
        inline void setOperations(string operation){this->operation=operation;}

        //The vectors of data entries that will be initialized for each matrix 
        void setArguments(vector<vector<double>> arguments);

        //Overload setting expected for single value constructors 
        inline void setArguments(vector<double> arguments){this->argumentsConst=arguments;}

        //The expected result for the outcome of a given operation for a unit test 
        void setExpected(vector<vector<double>> expected);

        //Overload set expected for single-value constuctor unit testing 
        inline void setExpected(vector<double> expected){this->expectedConst = expected;}; 

        inline void setScalars(vector<double> scalars){this->scalars = scalars;} 

        //Runs all tests
        void runAllTests(); 

        //Used for appending to string output representation 
        void evaluateResults(); 

        string toString() const; 

        
};

 void UnitTest::setArguments(vector<vector<double>> arguments)
 {
    this->expected.clear(); 
    //for(size_t i=0;i<this->arguments.size();++i)this->arguments[i].clear(); 
    this->arguments=arguments;
 }

 void UnitTest::setExpected(vector<vector<double>> expected)
 {
     this->expected.clear(); 
     //for(size_t i=0;i<this->expected.size();++i)this->expected[i].clear(); 
     this->expected=expected; 
 }

void UnitTest::runAllTests()
{
    size_t argI=0;                             //Index for the argument vector for initialization
    //Create various matrices for testing  
    string operation = this->operation;
    //Templatized matrices must be initialized explicitly with literals in template 
    Matrix<3,3,int> m1(this->arguments[argI++]); 
    Matrix<2,2,int> m2(this->arguments[argI++]); 
    Matrix<2,10,float> m3(this->arguments[argI++]);  
    Matrix<3,3,int> m4(this->arguments[argI++]); 
    Matrix<4,1,int> m5(this->arguments[argI++]);
    Matrix<5,2,int> m6(this->arguments[argI++]);
    Matrix<15,15,double> m7(this->arguments[argI++]); 
    Matrix<1,1,double> m8(this->arguments[argI++]); 
    Matrix<5,2,int> m9(this->arguments[argI++]); 
    size_t index=0; 

    if(operation.compare("multiply")==0)
    {
            
    }
    else if(operation.compare("transpose")==0)
    {
        Matrix<3,3,int> t1= m1.createTranspose();  
        results.push_back(t1==this->expected[index++]);
        Matrix<2,2,int> t2= m2.createTranspose(); 
        results.push_back(t2==this->expected[index++]);
        Matrix<10,2,float> t3= m3.createTranspose();
        results.push_back(t3==this->expected[index++]);
        Matrix<3,3,int> t4= m4.createTranspose(); 
        results.push_back(t4==this->expected[index++]);
        Matrix<1,4,int> t5= m5.createTranspose(); 
        results.push_back(t5==this->expected[index++]); 
        Matrix<2,5,int> t6 = m6.createTranspose();
        results.push_back(t6==this->expected[index++]);
        Matrix<15,15,double> t7 = m7.createTranspose();
        results.push_back(t7==this->expected[index++]);
        Matrix<1,1,double> t8= m8.createTranspose(); 
        results.push_back(t8==this->expected[index++]);
        Matrix<2,5,int>t9 = m9.createTranspose(); 
        cout<<endl; 
        results.push_back(t9==this->expected[index++]);
        Matrix<3,3,int>t10(0); 
        m1.transpose(t10); 
        results.push_back(t1==t10); 
        Matrix<2,2,int>t11(3.5); 
        m2.transpose(t11); 
        results.push_back(t2==t11); 
        Matrix<10,2, float>t12(-3); 
        m3.transpose(t12); 
        results.push_back(t3==t12);
        Matrix<3,3, int> t13(4);
        m4.transpose(t13); 
        results.push_back(t4==t13); 
        Matrix<1,4,int> t14(0); 
        m5.transpose(t14);
        results.push_back(t5==t14); 
        Matrix<2,5,int> t15(0); 
        m6.transpose(t15);
        results.push_back(t6==t15); 
        Matrix<15,15,double>t16((int).5); 
        m7.transpose(t16); 
        results.push_back(t7==t16); 
        Matrix<1,1,double>t17(0); 
        m8.transpose(t17); 
        results.push_back(t8==t17); 
        Matrix<2,5,int>t18(2.5);
        m9.transpose(t18); 
        results.push_back(t9==t18);  
    }
    else if(operation.compare("initialize")==0)
    {
        results.push_back(m1==this->expected[index++]);
        results.push_back(m2==this->expected[index++]);
        results.push_back(m3==this->expected[index++]);
        results.push_back(m4==this->expected[index++]);
        results.push_back(m5==this->expected[index++]);
        results.push_back(m6==this->expected[index++]);
        results.push_back(m7==this->expected[index++]);
        results.push_back(m8==this->expected[index++]);
        results.push_back(m9==this->expected[index++]);  
    }
    else if(operation.compare("equalizeSingle")==0)
    {
        results.push_back(m1==this->expectedConst[index++]);
        results.push_back(m2==this->expectedConst[index++]);
        results.push_back(m3==this->expectedConst[index++]);
        results.push_back(m4==this->expectedConst[index++]);
        results.push_back(m5==this->expectedConst[index++]);
        results.push_back(m6==this->expectedConst[index++]);
        results.push_back(m7==this->expectedConst[index++]);
        results.push_back(m8==this->expectedConst[index++]);
        results.push_back(m9==this->expectedConst[index++]);   
    }
    else if(operation.compare("scalarMult")==0)
    {
        results.push_back(m1.scalarMult(this->scalars[index])==this->expected[index]);index++;
        results.push_back(m2.scalarMult(this->scalars[index])==this->expected[index]);index++; 
        results.push_back(m3.scalarMult(this->scalars[index])==this->expected[index]);index++; 
        results.push_back(m4.scalarMult(this->scalars[index])==this->expected[index]);index++;
        results.push_back(m5.scalarMult(this->scalars[index])==this->expected[index]);index++; 
         //(m6*this->scalars[index]).toString(cout); 
        results.push_back(m6.scalarMult(this->scalars[index])==this->expected[index]);index++; 
        results.push_back(m7.scalarMult(this->scalars[index])==this->expected[index]);index++; 
        index++; 
        results.push_back(m9.scalarMult(this->scalars[index])==this->expected[index]);
    }
    else if(operation.compare("matrixMult")==0)
    {
        Matrix<3,3,int> i1(1); 
	    Matrix<3,3,int> i2(-2); 
	    Matrix<3,3,int> p1(0);
        p1.multiply(i1,i2);
	    results.push_back(p1==this->expected[index++]); 
        
        Matrix<3,3,int> p2(0); 
        p2.multiply(m1,m4); 
        //p2.toString(cout); 
        results.push_back(p2==this->expected[index++]); 

        Matrix<3,3,int> p3(0); 
        p3.multiply(m4,m4); 
        //p3.toString(cout); 
        results.push_back(p3==this->expected[index++]); 

        Matrix<5,2,int> p4(0); 
        p4.multiply(m9,m2); 
       /* m9.toString(cout); 
        m2.toString(cout);cout<<endl; 
        p4.toString(cout); 
        for(size_t j=0;j<this->expected[index].size();++j)cout<<this->expected[index][j]<<", ";*/ 
        //cout<<endl; 

        results.push_back(p4==this->expected[index++]); 

        Matrix<5,2,int> p5(0); 
        p5.multiply(m6,m2); 

       /* m6.toString(cout); 
        m2.toString(cout); 
        cout<<endl; 
        p5.toString(cout); 
        for(size_t j=0;j<this->expected[index].size();++j)cout<<this->expected[index][j]<<", ";
        cout<<endl; */ 
        results.push_back(p5==this->expected[index++]); 

        Matrix<4,1,int> p6(0); 
        p6.multiply(m5,m8); 
        //p6.toString(cout); 
        results.push_back(p6==this->expected[index++]); 

     /*   Matrix<3,3,int> p7(0); 
        p7.multiply(m5, m9.createTranspose()); 
        p7.toString(cout); */ 

        Matrix<2,5,int> p8(0);
        p8.multiply(m2,m9.createTranspose()); 
        //p8.toString(cout);cout<<endl;
        //m2.toString(cout);cout<<endl;
       // m9.toString(cout);cout<<endl; 
        //(m9.createTranspose()).toString(cout); cout<<endl; 
        //for(size_t j=0;j<this->expected[index].size();++j)cout<<this->expected[index][j]<<", ";

        results.push_back(p8==this->expected[index++]); 

        Matrix<1,4,double> p9(0); 
        p9.multiply(m8,m5.createTranspose()); 
        //p9.toString(cout); 
        results.push_back(p9==this->expected[index++]); 

        Matrix<2,5,int> p10(0);
        p10.multiply(m2,m6.createTranspose()); 
        /*m2.toString(cout);cout<<endl; 
        m6.toString(cout);cout<<endl; 
        p10.toString(cout);cout<<endl; 
        for(size_t j=0;j<this->expected[index].size();++j)cout<<this->expected[index][j]<<", ";
        cout<<endl;  */ 
        results.push_back(p10==this->expected[index++]); 

        Matrix<3,3,int> p11(0);
        p11.multiply(m1,m4.createTranspose());
        //p11.toString(cout); 
        results.push_back(p11==this->expected[index++]); 
     /* Matrix<3,3,int> p1 = m4*m1; 
      Matrix<3,3,int> p2 = m4*m4; 
      Matrix<2,5,int> p3 = m9*m2;
      Matrix<2,5,int> p4 = m6*m2; 
      Matrix<1,1,int> p5 = m5*m8; 
      Matrix<3,3,int> p6 = m5*(m1.createTranspose()); 
      Matrix<2,5,int> p7 = m2*(m9.createTranspose()); 
      Matrix<1,1,double> p8 = m8*(m5.createTranspose()); 
      Matrix<2,5,int> p9 = m2*(m6.createTranspose()); 
      Matrix<3,3,int> p10 = m1*(m4.createTranspose()); */ 
    }

    if(this->talk)
    {
        this->evaluateResults(); 
        cout<<this->toString(); 
    }
}

void UnitTest:: evaluateResults() 
{
    string str = ""; 
    for(size_t i=0;i<this->results.size();++i)
    {
        str = this->results[i] ? "True" : "False"; 
        this->resultsString[i] = this->resultsString[i]+str+"\n"; 
    }
}

string UnitTest::toString() const 
{
    string toReturn = ""; 
    for(size_t i=0;i<this->resultsString.size();++i)toReturn = toReturn+this->resultsString[i];  
    return toReturn; 
}

#endif 