#include "Matrix.h" 						//our matrix library 
#include "UnitTest.h" 						//unit test structure
#include <iostream> 						//allows << operator 
#include <vector> 							//allows vector implementation 
#include <math.h> 							//For use of M_PI value 
#include <string> 							//allows string methods, compare()

using namespace std; 						//We want easy string, vector, << access
using namespace MATRIX; 					//We want to simulate a user with matrix functions 

//TODO: use "testPrompt" as a single string to avoid intializing too many variables 

int main(int argc, char* argv[]){
	cout<<"Entering Matrix Client";
	string commandArg = ""; 
	//Check command line prompt. Defaults to quiet if user enters nothing 
	if(argc>2)
	{
		cout<<"Error: usage matrixclient [speak]/[quiet]"<<endl;
		return 1; 							//Indicate failure due to improper arguments 
	}
	else if(argc>1){commandArg=argv[1];}
	size_t idIndex=1; 
	//Initialize our unit test with the capacity to talk based on user input 
	bool speak;
	if(commandArg.compare("talk")==0)speak=true; 
	else speak=false; 
	
	//string output representation for what each unit test is looking for 
	vector<string> testPrompt{
	"Test of 3x3 int matrix transposition with vector constructor returned:        ", 
 	"Test of 2x2 int matrix transposition with double vector constructor returned: ",
	"Test of 2x10 float matrix transpose with double vector constructor returned:  ",
	"Test of 3x3 int matrix transpose with double vector constructor returned:     ", 
	"Test of 4x1 int matrix transpose with vector constructor returned:            ",
	"Test of 5x2 int matrix tranpose with vector constructor returned:             ",
	"Test of 15x15 large double matrix transpose with vector constructor returned: ", 
	"Test of single value double matrix transpose with vector constructor returned:", 
	"Test of 5x2 int matrix transposition with vector constructor returned:        ", 
	"Test of 3x3 int matrix with single value constructor transposeTo returned:    ", 
	"Test of 2x2 matrix with dif. type value constructor transposeTo returned:     ",
	"Test of float matrix with dif. type value constructor transposeTo returned:   ",
	"Test of int matrix with dif. type constructor transposeTo returned:           ",
	"TranposeTo on non-square int matrix with single value constructor returned:   ",
	"Attempt of casting diff value constructor to large double matrix transposeTo  ",
	"TransposeTo on single-value double matrix returned                            ",
	"Casting double constructor on int matrix and transposeTo returned:            "
	};
	
	//This will be modified to have a key for each piece of functionality we are testing 
	string testOperations = "transpose"; 

	vector<vector<double>> test1Arguments; 
	vector<vector<double>> test1Expected; 
	vector<double> v= {1,3,1,3,1,3,1,3,1}; 
	test1Arguments.push_back(v); 
	test1Expected.push_back(v); 
	v.clear(); 
	v= {10,15,-30,0};
	test1Arguments.push_back(v); 
	v.clear(); 
	v={10,-30,15,0}; 
	test1Expected.push_back(v); 
	v.clear(); 
	v={1.5,2.5,2.5,0.5,0.5,1.5,1.5,2.5,2.5,0.5,0.5,1.5,1.5,2.5,2.5,0.5,0.5,1.5,1.5,2.5};
	test1Expected.push_back(v); 
	v.clear(); 
	v={
		7.6656,30.6624,53.6592,
		15.3312,38.328,61.3248,
		22.9968,45.9936,68.9904
}	;
	test1Expected.push_back(v); 
	v.clear(); 
	v={-1,-1,-1,-1}; 
	test1Expected.push_back(v); 
	v.clear(); 
	v={1000,1000,1000,500,500,-1000,-1000,-500,-500,-500};
	test1Expected.push_back(v);
	v.clear(); 
	v={ 0,2,4,6,8,10,13,15,17,19,21,23,25,28,30,
		0,2,4,6,8,11,13,15,17,19,21,23,26,28,30,
		0,2,4,6,9,11,13,15,17,19,21,24,26,28,30,
		0,2,4,7,9,11,13,15,17,19,22,24,26,28,30,
		0,2,5,7,9,11,13,15,17,20,22,24,26,28,30,
		0,3,5,7,9,11,13,15,18,20,22,24,26,28,30,
		1,3,5,7,9,11,13,16,18,20,22,24,26,28,31,
		1,3,5,7,9,11,14,16,18,20,22,24,26,29,31,
		1,3,5,7,9,12,14,16,18,20,22,24,27,29,31,
		1,3,5,7,10,12,14,16,18,20,22,25,27,29,31,
		1,3,5,8,10,12,14,16,18,20,23,25,27,29,31,
		1,3,6,8,10,12,14,16,18,21,23,25,27,29,31,
		1,4,6,8,10,12,14,16,19,21,23,25,27,29,31,
		2,4,6,8,10,12,14,17,19,21,23,25,27,29,32,
		2,4,6,8,10,12,15,17,19,21,23,25,27,30,32};
	test1Expected.push_back(v); 
	v.clear(); 
	test1Expected.push_back(vector<double>{-4.56});
	v={1,1,1,1,1,
       0,0,0,0,0}; 
	test1Expected.push_back(v); 
	v.clear(); 
	for(size_t i=1;i<21;++i)v.push_back(i%3 + .5); 
	test1Arguments.push_back(v); 
	v.clear(); 
	for(size_t i=1;i<10;++i)v.push_back(7.6656*i);
	test1Arguments.push_back(v);
	v.clear(); 
	v = {-1,-1,-1,-1}; 
	test1Arguments.push_back(v); 
	v.clear(); 
	v = {1000,-1000,1000,-1000,1000,-500,500,-500,500,-500}; 
	test1Arguments.push_back(v); 
	v.clear(); 
	for(size_t i=1;i<=225;++i)v.push_back(i/7); 
	test1Arguments.push_back(v); 
	v.clear(); 
	v = {-4.56}; 
	test1Arguments.push_back(v); 
	v.clear(); 
	for(size_t i=1;i<11;++i)v.push_back(i%2); 
	test1Arguments.push_back(v); 
	v.clear(); 

	//Initialize test1 with all necessary values and run it 
	UnitTest test1(idIndex++, speak);
	if(speak)test1.setResults(testPrompt); 
	test1.setOperations(testOperations); 
	test1.setArguments(test1Arguments); 
	test1.setExpected(test1Expected); 
	test1.runAllTests(); 



	testOperations = "initialize"; 
	vector<vector<double>>test2Arguments = test1Arguments;
	testPrompt.clear(); 
	testPrompt = {
	"Test of initializing 3x3 int matrix returned:                                 ",
	"Test of initializing 2x2 int matrix with double vector returned:              ",
	"Test of initializing 2x10 float matrix with double vector returned:           ",
	"Test of initializing 3x3 int matrix returned:                                 ",
	"Test of initializing 4x1 int matrix returned:                                 ",
	"Test of initializing 5x2 int matrix returned:                                 ",
	"Test of initializing 15x15 large double matrix returned:                      ",
	"Test of initializing a single value double matrix returned:                   ",
	"Test of initializing 5x2 int matrix returned:                                 "
	};

	//Initialize test2 with all necessary values and run it 
	UnitTest test2(idIndex++, speak); 
	if(speak)test2.setResults(testPrompt); 
	test2.setOperations(testOperations);
	test2.setArguments(test2Arguments); 
	test2.setExpected(test2Arguments); 		//Initialization should be same in as out
	test2.runAllTests(); 



	testOperations = "equalizeSingle"; 
	vector<vector<double>>test3Arguments;
	v.clear(); 
	for(size_t i=0;i<9;++i)v.push_back(-1.5); 
	test3Arguments.push_back(v); 
	v.clear(); 
	for(size_t i=0;i<4;++i)v.push_back(3); 
	test3Arguments.push_back(v); 
	v.clear(); 
	for(size_t i=0;i<20;++i)v.push_back(0); 
	test3Arguments.push_back(v); 
	v.clear(); 
	for(size_t i=0;i<9;i++)v.push_back(6.7); 
	test3Arguments.push_back(v); 
	v.clear(); 
	for(size_t i=0;i<4;++i)v.push_back(1000000005);
	test3Arguments.push_back(v); 
	v.clear(); 
	for(size_t i=0;i<10;++i)v.push_back(6.56); 
	test3Arguments.push_back(v); 
	v.clear(); 
	for(size_t i=0;i<225;++i)v.push_back(3.14);
	test3Arguments.push_back(v); 
	v.clear(); 
	v.push_back(54321); 
	test3Arguments.push_back(v); 
	v.clear(); 
	for(size_t i=0;i<10;++i)v.push_back(-1111); 
	test3Arguments.push_back(v); 
	v.clear(); 
	testPrompt.clear(); 
	testPrompt = {
	"Test of initializing int matrix with negative value returned:                 ",
	"Test of initializing int matrix with positive value returned:                 ", 
	"Test of initializing zeroed out float matrix returned:                        ",
	"Test of initializing 3x3 int matrix returned:                                 ",
	"Test of initializing int matrix with double value returned:                   ",
	"Test of initializing int matrix with positive value returned:                 ",
	"Test of initializing large double matrix with double value returned:          ",
	"Test of initializing a single value double matrix with int value returned:    ",
	"Test of initializing int matrix with negative value returned:                 "
	};

	vector<double>test3Expected{-1,3,0,6.01,1000000005,6,3.14,54321,-1111};

	UnitTest test3(idIndex++, speak); 
	if(speak)test3.setResults(testPrompt); 
	test3.setOperations(testOperations); 
	test3.setArguments(test3Arguments); 
	test3.setExpected(test3Expected);  
	test3.runAllTests(); 

	testOperations = "scalarMult";
	testPrompt.clear(); 
	testPrompt = {
	"Test of multiplying int matrix with negative scalar integer returned:         ",
	"Test of multiplying int matrix with positive scalar integer returned:         ",
	"Test of multiplying float matrix with zero scalar returned:                   ",
	"Test of multiplying int matrix with positive double returned:                 ", 
	"Test of multiplying int matrix with very large integer returned:              ", 
	"Test of multiplying large double matrix with reduced pi returned:             ",
	"Test of multiplying int matrix with large integer returned:                   ",
	"Test of multiplying int matrix with negative integer returned                 "
	};

	//This will be fixed later once calculations have been performed 
	vector<vector<double>>test4Expected;
	v = {4, 12, 4,
		12, 4, 12,
		 4, 12, 4
	};
	test4Expected.push_back(v); 
	v.clear(); 
	v = {
		0,0,
		0,0
	};
	test4Expected.push_back(v); 
	v.clear(); 
	v = {
		2.25,3.75,0.75,2.25,3.75,0.75,2.25,3.75,0.75,2.25,
		3.75,0.75,2.25,3.75,0.75,2.25,3.75,0.75,2.25,3.75
	};
	test4Expected.push_back(v); 
	v.clear(); 
	v = {
		-35,-75,-110,
		-150,-190,-225,
		-265,-305,-340
	};
	test4Expected.push_back(v); 
	v.clear(); 
	v = {
		-10000,
		-10000,
		-10000,
		-10000
	};
	test4Expected.push_back(v); 
	v.clear(); 
	v = {
		5000,-5000,
		5000,-5000,
		5000,-2500,
		2500,-2500,
		2500,-2500
	};
	test4Expected.push_back(v); 
	v.clear(); 
	for(size_t i=0;i<test1Arguments[6].size();++i)v.push_back(test1Arguments[6][i]*-3.14); 
	test4Expected.push_back(v); 
	v.clear(); 
	v = {-456}; 
	test4Expected.push_back(v); 
	v.clear(); 
	v = {
		17,0,
		17,0,
		17,0,
		17,0,
		17,0,
	};
	test4Expected.push_back(v); 
	v.clear(); 

	/*
	vector<double> test4Scalars{4.31,0,1.5, -5.6, 10000,5.5, -3.14, 100, 17.5}; 
	UnitTest test4(idIndex++, speak); 
	if(speak)test4.setResults(testPrompt); 
	test4.setOperations(testOperations); 
	test4.setArguments(test1Arguments); 
	test4.setScalars(test4Scalars); 
	test4.setExpected(test4Expected); 
	test4.runAllTests();  */ 

	testPrompt.clear(); 
	testPrompt = {
	"Test of multiplying 3x3 int matrices with single value elements returned:     ",
	"Test of multiplying 3x3 int matrices with various value elements returned:    ",
	"Test of multiplying square int matrix with itself returned:                   ",
	"Test of multiplying 5x2 matrix with a 2x2 matrix returned:                    ", 
	"Test of multiplying int matrix with a single-entry double matrix returned:    ", 
	"Test of multiplying non-square matrices after transposition returned:         ",
	"Test of multiplying double and int matrices after transposition returned:     ",
	"Test of multiplying 2x5 with 2x5 post transposition returned:                 ",
	"Test above post transposition with matrices reversed returned:                ",
	"Test of multiplying 3x3 with matrix transposed into a vector returned:        "
	};
	vector<vector<double>> test5Expected;// = test4Expected; 
	v.clear(); 
	v={
	-6,-6,-6,
	-6,-6,-6,
	-6,-6,-6
	}; 
	test5Expected.push_back(v); v.clear(); 
	v={
	150,190,225,
	210,266,315,
	150,190,225
	};
	test5Expected.push_back(v); v.clear(); 
	v={
	1665,2017,2325,
	3735,4639,5430,
	5805,7261,8535,
	};
	test5Expected.push_back(v); v.clear(); 
	v={
	-1325391862,32709,
	-1325391862,32709,
	-1325391862,32709,
	-1325391862,32709,
	1884160010,-451458129
	};
	test5Expected.push_back(v); v.clear(); 
	v={
		40000,0,
		40000,0,
		25000,0,
		20000,0,
		20000,0,
	};
	test5Expected.push_back(v); v.clear();
	v = {4,4,4,4}; 
	test5Expected.push_back(v); v.clear(); 
	v = {
	0,0,0,0,0,
	10,0,0,0,0
	}; 
	test5Expected.push_back(v); v.clear(); 
	v = { 4.56,4.56,4.56,4.56};
	test5Expected.push_back(v); v.clear(); 
	v = {
	-5000,-5000,2500,-2500,-2500,
	-175207728,-175207728,-2059924784,2059879784,2059879784
	};
	test5Expected.push_back(v); v.clear(); 
	v = {
	74,189,304,
	102,263,424,
	74,189,304
	};
	test5Expected.push_back(v); v.clear(); 


	testOperations = "matrixMult"; 
	UnitTest test5(idIndex++, speak); 
	if(speak)test5.setResults(testPrompt); 
	test5.setOperations(testOperations); 
	test5.setArguments(test1Arguments); 
	test5.setExpected(test5Expected); 
	test5.runAllTests(); 

	/*Matrix<3,3,int> i1(1); 
	Matrix<3,3,int> i2(-2); 
	Matrix<3,3,int> p1(0);
	p1.multiply(i1,i2); 
	p1.toString(cout); */ 

	cout<<"Exiting Matrix Client"<<endl; 
	return 0; 
}