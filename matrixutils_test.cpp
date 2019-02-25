#include "Matrix.h" 						//our matrix library 
#include "UnitTest.h" 						//unit test structure
#include <iostream> 						//allows << operator 
#include <vector> 							//allows vector implementation 
#include <math.h> 							//For use of M_PI value 
#include <string> 							//allows string methods, compare()

using namespace std; 						//We want easy string, vector, << access
using namespace MATRIX; 					//We want to simulate a user with matrix functions 

/* Takes in command lines for specifying outputting results of each individual test. Initializes
 * unit tests and data vectors for arguments, expected, strings, and operations for each test. 
 * Specifically aims to test initialization and constructors, '==' operator, '*' operator, and 
 * the transpose methods.*/
int main(int argc, char* argv[]){
	cout<<"Entering Matrix Client";
	string commandArg = ""; 
	//Check command line prompt. Defaults to quiet if user enters nothing 
	if(argc>2)
	{
		cout<<"Error: usage matrixclient [speak]/[quiet]"<<endl;
		return 1; 										//Indicate failure from improper arguments 
	}
	else if(argc>1){commandArg=argv[1];}
	size_t idIndex=1; 									//ID of each unit test we initialize
	bool speak;											//Flag for sending strings to stdout
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
	//Set proper data fields for the unit test 
	string testOperations = "transpose"; 				
	vector<vector<double>> test1Arguments; 
	vector<vector<double>> test1Expected; 
	//We aim to create our arguments with various types, values and lengths to test for edge cases 
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
	v = {
	-2,	3,	 
	1,	5,
	7,	2,
	};
	test1Arguments.push_back(v); v.clear(); 
	v = {
	5,	3,	-1,	 
	1,	-3,	6,
	0,	2,	4
	};
	test1Arguments.push_back(v); v.clear(); 
	v = {
	5,	3,	 
	0,	-2,
	-3,	1,
	6,	-1,
	};
	test1Arguments.push_back(v); v.clear(); 
	v = {
	2,	-4,	3,	 
	0,	5,	4
	};
	test1Arguments.push_back(v); v.clear(); 
	v = {
	3,	2,	4,	 
	6,	5,	7,	
	};
	test1Arguments.push_back(v); v.clear(); 
	v = {
		-1,	-4,	2,	0,	 
		3,	4,	5,	6,
		7,	-3,	8,	9,
	};
	test1Arguments.push_back(v); v.clear(); 
	//Pass all of our data fields created above into our unit test structure 
	UnitTest test1(idIndex++, speak);
	if(speak)test1.setResults(testPrompt); 
	test1.setOperations(testOperations); 
	test1.setArguments(test1Arguments); 
	test1.setExpected(test1Expected); 
	//Run all tests for this transposition case 
	test1.runAllTests(); 

	//Set all our data fields for our second test of constructors. This one is simple to check 
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

	//Set data for test3 on more initialization to make sure our matrices are exactly as expected 
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
	test3Arguments.push_back(v); v.clear(); 
	v = {
	-2,	3,	 
	1,	5,
	7,	2,
	};
	test3Arguments.push_back(v); v.clear(); 
	v = {
	5,	3,	-1,	 
	1,	-3,	6,
	0,	2,	4
	};
	test3Arguments.push_back(v); v.clear(); 
	v = {
	5,	3,	 
	0,	-2,
	-3,	1,
	6,	-1,
	};
	test3Arguments.push_back(v); v.clear(); 
	v = {
	2,	-4,	3,	 
	0,	5,	4
	};
	test3Arguments.push_back(v); v.clear(); 
	v = {
	3,	2,	4,	 
	6,	5,	7,	
	};
	test3Arguments.push_back(v); v.clear(); 
	v = {
		-1,	-4,	2,	0,	 
		3,	4,	5,	6,
		7,	-3,	8,	9,
	};
	test3Arguments.push_back(v); v.clear(); 

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

	
	vector<double> test4Scalars{4.31,0,1.5, -5.6, 10000,5.5, -3.14, 100, 17.5}; 
	UnitTest test4(idIndex++, speak); 
	if(speak)test4.setResults(testPrompt); 
	test4.setOperations(testOperations); 
	test4.setArguments(test1Arguments); 
	test4.setScalars(test4Scalars); 
	test4.setExpected(test4Expected); 
	test4.runAllTests();   

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
	"Test of multiplying 3x3 with matrix transposed into a vector returned:        ",
	"Test of multiplying 3x3 double with 3x2 double returned:                      ",
	"Test of multiplying 2x3 double with 3x3 double returned:                      ",
	"Test of multiplying 4x2 float with 2x3 float returned:                        ",
	"Test of multiplying 2x3 long with 2x4 long returned:                          ",
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
	10,15,
	10,15,
	10,15,
	10,15,
	10,15,
	};
	test5Expected.push_back(v); v.clear(); 
	v={
	40000,15000,
	40000,15000,
	25000,15000,
	20000,7500,
	20000,7500
	};
	test5Expected.push_back(v); v.clear();
	v = {4,4,4,4}; 
	test5Expected.push_back(v); v.clear(); 
	v = {
	10,10,10,10,10,
	-30,-30,-30,-30,-30
	}; 
	test5Expected.push_back(v); v.clear(); 
	v = { 4.56,4.56,4.56,4.56};
	test5Expected.push_back(v); v.clear(); 
	v = {
	-5000,-5000,2500,-2500,-2500,
	-30000,-30000,-30000,-15000,-15000
	};
	test5Expected.push_back(v); v.clear(); 
	v = {
	74,189,304,
	102,263,424,
	74,189,304
	};
	test5Expected.push_back(v); v.clear(); 
	v = {
	-14,28,	 
	37,	0,
	30,	18,
	};
	test5Expected.push_back(v); v.clear(); 
	v = {
	-9,5,36,
	20,-2,35
	};
	test5Expected.push_back(v); v.clear(); 
	v = {
	10,	-5,	27,	 
	0,	-10,-8,
	-6,	17,	-5,
	12,	-29, 14	
	}; 
	test5Expected.push_back(v); v.clear(); 
	v ={
	31,	-16, 48, 48,	 
	58,	-25, 93, 93
	};
	test5Expected.push_back(v); v.clear(); 


	testOperations = "matrixMult"; 
	UnitTest test5(idIndex++, speak); 
	if(speak)test5.setResults(testPrompt); 
	test5.setOperations(testOperations); 
	test5.setArguments(test1Arguments); 
	test5.setExpected(test5Expected); 
	test5.runAllTests(); 

	testPrompt.clear(); 
	testPrompt = {
	"Test of multiplying 3x3 int single element matrix with transpose returned:    ",
	"Test of multiplying 3x3 int various element matrix with transpose returned:   ",
	"Test of multiplying square int matrix with its tranpose returned:             ",
	"Test of multiplying 5x2 matrix float matrix with its transpose returned:      ", 
	"Test of multiplying square int matrix with its transpose returned:            ", 
	"Test of multiplying 15x15 giant double matrix with transpose returned:        ",
	"Test of multiplying single value double matrix with transpose returned:       ",
	"Test of multiplying 5x5 int matrix with transpose returned:                   ",
	"Test of multiplying 3x3 double matrix with 3x3 double matrix returned:        ",
	"Test of multiplying 3x3 double matrix with 3x3 double matrix returned:        ",
	"Test of multiplying 4x2 float matrix with 2x4 float matrix returned:          ",
	"Test of multiplying 2x3 float matrix with 3x2 float matrix returned:          ",
	"Test of multiplying 2x3 long matrix with 3x2 long matrix returned:            ",
	"Test of multiplying 3x4 long matrix with 4x3 long matrix returned:            "
	};

	vector<vector<double>> test6Expected; 
	v.clear(); 
	v ={
	11,9,11,
	9,19,9,
	11,9,11
	};
	test6Expected.push_back(v); v.clear(); 
	v = {
		325,-300,
		-300,900
	}; 
	test6Expected.push_back(v); v.clear(); 
	v={
		28.5,21,
		21,32.5
	};
	test6Expected.push_back(v); v.clear(); 
	v={
		758,1770,2782,
		1770,4369,6968,
		2782,6968,11154
	};
	test6Expected.push_back(v); v.clear(); 
	for(size_t i=0;i<16;++i)v.push_back(1); 
	test6Expected.push_back(v); v.clear(); 
	v={
	2000000,2000000,1500000,1000000,1000000,
	2000000,2000000,1500000,1000000,1000000,
	1500000,1500000,1250000,750000,750000,
	1000000,1000000,750000,500000,500000,
	1000000,1000000,750000,500000,500000
	};
	test6Expected.push_back(v); v.clear(); 
	v={	//I 100% used pre-existing matrix calculators to compute these 
	15,38,61,84,107,130,155,180,203,226,249,272,295,320,345,
	38,131,222,313,404,495,590,683,776,867,958,1049,1140,1235,1328,
	61,222,383,542,701,860,1025,1186,1347,1508,1667,1826,1985,2150,2311,
	84,313,542,771,998,1225,1460,1689,1918,2147,2376,2603,2830,3065,3294,
	107,404,701,998,1295,1590,1895,2192,2489,2786,3083,3380,3675,3980,4277,
	130,495,860,1225,1590,1955,2330,2695,3060,3425,3790,4155,4520,4895,5260,
	155,590,1025,1460,1895,2330,2780,3215,3650,4085,4520,4955,5390,5840,6275,
	180,683,1186,1689,2192,2695,3215,3720,4223,4726,5229,5732,6235,6755,7260,
	203,776,1347,1918,2489,3060,3650,4223,4796,5367,5938,6509,7080,7670,8243,
	226,867,1508,2147,2786,3425,4085,4726,5367,6008,6647,7286,7925,8585,9226,
	249,958,1667,2376,3083,3790,4520,5229,5938,6647,7356,8063,8770,9500,10209,
	272,1049,1826,2603,3380,4155,4955,5732,6509,7286,8063,8840,9615,10415,11192,
	295,1140,1985,2830,3675,4520,5390,6235,7080,7925,8770,9615,10460,11330,12175,
	320,1235,2150,3065,3980,4895,5840,6755,7670,8585,9500,10415,11330,12275,13190,
	345,1328,2311,3294,4277,5260,6275,7260,8243,9226,10209,11192,12175,13190,14175
	};
	test6Expected.push_back(v); v.clear(); 
	v.push_back(20.7936); test6Expected.push_back(v); v.clear(); 
	for(size_t i=0;i<25;++i)v.push_back(1); 
	test6Expected.push_back(v); v.clear(); 
	v = {
	13,13,-8,
	13,26,17,
	-8,17,53
	};
	test6Expected.push_back(v); v.clear(); 
	v = {
	35,-10,2,
	-10,46,18,
	2,18,20
	};
	test6Expected.push_back(v); v.clear(); 
	v = {
	34,-6,-12,27,
	-6,4,-2,2,
	-12,-2,10,-19,
	27,2,-19,37
	};
	test6Expected.push_back(v); v.clear(); 
	v = {
	29,-8,
	-8,41
	};
	test6Expected.push_back(v); v.clear(); 
	v = {
	29,56,
	56,110
	};
	test6Expected.push_back(v); v.clear(); 
	v = {
	21,-9,21,
	-9,86,103,
	21,103,203
	};
	test6Expected.push_back(v); v.clear(); 

	testOperations = "transMult"; 
	UnitTest test6(idIndex++, speak); 
	if(speak)test6.setResults(testPrompt); 
	test6.setOperations(testOperations); 
	test6.setArguments(test1Arguments); 
	test6.setExpected(test6Expected); 
	test6.runAllTests(); 


	cout<<"Exiting Matrix Client"<<endl; 
	return 0; 
}