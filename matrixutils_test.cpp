#include "Matrix.h" 						//our matrix library 
#include "UnitTest.h" 						//unit test structure
#include <iostream> 						//allows << operator 
#include <vector> 							//allows vector implementation 
#include <math.h> 							//For use of M_PI value 
#include <string> 							//allows string methods, compare()

using namespace std; 
using namespace MATRIX; 

int main(int argc, char* argv[]){
	cout<<"Entering Matrix Client";
	string commandArg = ""; 
	//Check command line prompt. Defaults to quiet if user enters nothing 
	if(argc>2)
	{
		cout<<"Error: usage matrixclient [speak]/[quiet]"<<endl;
		return 1; 
	}
	else if(argc>1){commandArg=argv[1];}
	size_t idIndex=1; 
	//Initialize our unit test with the capacity to talk based on user input 
	bool speak;
	if(commandArg.compare("quiet")==0 || commandArg.compare("")==0) speak=false; 
	else speak=true;
	
	vector<string> test1Prompt{
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
	if(speak)test1.setResults(test1Prompt); 
	test1.setOperations(testOperations); 
	test1.setArguments(test1Arguments); 
	test1.setExpected(test1Expected); 
	test1.runAllTests(); 



	testOperations = "initialize"; 
	vector<vector<double>>test2Arguments = test1Arguments;
	vector<string> test2Prompt = {
	"Test of initializing 3x3 int matrix returned:                                 ",
	"Test of initializing 2x2 int matrix with double vector returned:              ",
	"Test of initializing 2x10 float matrix with double vector returned:           ",
	"Test of initializing 3x3 int matrix returned:                                 ",
	"Test of initializing 4x1 int matrix returned:                                 ",
	"Test of initializing 5x2 int matrix returned:                                 ",
	"Test of initializing 15x15 large double matrix returned:                      ",
	"Test of initializing a single value double matrix returned:                   ",
	"Test of initializing 5x2 int matrix returned:                                 "};

	//Initialize test2 with all necessary values and run it 
	UnitTest test2(idIndex++, speak); 
	if(speak)test2.setResults(test2Prompt); 
	test2.setOperations(testOperations);
	test2.setArguments(test2Arguments); 
	test2.setExpected(test2Arguments); 		//Initialization should be same in as out
	test2.runAllTests(); 



	testOperations = "equalizeSingle"; 
	vector<double>test3Arguments{-1.5,3,0,6.7,1000000005,6.56,3.14,54321,-1111}; 
	vector<string >test3Prompt = {
		"",
		"", 
		"",
		"",
		"",
		"",
		"",
		"",
		""
	};
	vector<double>test3Expected{-1,3,0,6,1000000005,6,3.14,54321,-1111};
	



	/*UnitTest test3(idIndex++, speak); 
	if(speak)test3.setResults(test3Prompt); 
	test3.setOperations(testOperations); 
	test3.setArguments(test3Arguments); 
	test3.setExpected(test3Expected); 
	test3.runAllTests(); 
	*/
  



	cout<<"Exiting Matrix Client"<<endl; 
	return 0; 
}