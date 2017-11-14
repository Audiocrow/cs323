#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <utility>
#include <regex>

#include "table2Trace.h"

using namespace std;

int main() {

	map<char, int> NON_STATES{
		{ 'a', 16 },{ '+', 17 },{ '-', 18 },{ '*', 19 },{ '/', 20 },
		{ '(', 21 },{ ')', 22 },{ '$', 23 },{ 'E', 24 },{ 'T', 25 },
		{ 'F', 26 }
	};

	map<int, pair<char,int>> RULES{
		{1,{'E',3}},{2,{'E',3}},{3,{'E',1}},{4,{'T',3}},
		{5,{'T',3}},{6,{'T',1}},{7,{'F',3}},{8,{'F',1}}
	};


	//this map will not be needed for the final project
	map<int, char> NON_STATE_REVERSE{
		{ 16, 'a' },{ 17, '+' },{ 18, '-' },{ 19, '*' },{ 20, '/' },
		{ 21, '(' },{ 22, ')' },{ 23, '$' },{ 24, 'E' },{ 25, 'T' },
		{ 26, 'F' }
	};

	string word1 = "(a+a)/a$";
	string word2 = "a(a+a)$";
	string word3 = "a/a+(a*a)$";
	

	string table[16][11] = {
		{ "S5" ,  ""  ,  ""  ,  ""  ,  ""  , "S4" ,  ""  ,  ""  , "1" , "2" , "3" },
		{  ""  , "S6" , "S7" ,  ""  ,  ""  ,  ""  ,  ""  , "ACC",  "" ,  "" ,  "" },
		{  ""  , "R3" , "R3" , "S8" , "S9" ,  ""  , "R3" , "R3" ,  "" ,  "" ,  "" },
		{  ""  , "R6" , "R6" , "R6" , "R6" ,  ""  , "R6" , "R6" ,  ""  , "" ,  "" },
		{ "S5" ,  ""  ,  ""  ,  ""  ,  ""  , "S4" ,  ""  ,  ""  , "10" , "2", "3" },
		{  ""  , "R8" , "R8" , "R8" , "R8" ,  ""  , "R8" , "R8" ,  ""  ,"12", "3" },
		{ "S5" ,  ""  ,  ""  ,  ""  ,  ""  , "S4" ,  ""  ,  ""  ,  ""  ,"11", "3" },
		{ "S5" ,  ""  ,  ""  ,  ""  ,  ""  , "S4" ,  ""  ,  ""  ,  ""  , "" ,  "" },
		{ "S5" ,  ""  ,  ""  ,  ""  ,  ""  , "S4" ,  ""  ,  ""  ,  ""  , "" , "13"},
		{ "S5" ,  ""  ,  ""  ,  ""  ,  ""  , "S4" ,  ""  ,  ""  ,  ""  , "" , "14"},
		{  ""  , "S6" , "S7" ,  ""  ,  ""  ,  ""  , "S15",  ""  ,  ""  , "" ,  "" },
		{  ""  , "R1" , "R1" , "S8" , "S9" ,  ""  , "R1" , "R1" ,  ""  , "" ,  "" },
		{  ""  , "R2" , "R2" , "S8" , "S9" ,  ""  , "R2" , "R2" ,  ""  , "" ,  "" },
		{  ""  , "R4" , "R4" , "R4" , "R4" ,  ""  , "R4" , "R4" ,  ""  , "" ,  "" },
		{  ""  , "R5" , "R5" , "R5" , "R5" ,  ""  , "R5" , "R5" ,  ""  , "" ,  "" },
		{  ""  , "R7" , "R7" , "R7" , "R7" ,  ""  , "R7" , "R7" ,  ""  , "" ,  "" }
	};

	cout << word1 << endl;
	traceWord(word1, table, NON_STATES, RULES, NON_STATE_REVERSE);
	cout << endl;

	cout << word2 << endl;
	traceWord(word2, table, NON_STATES, RULES, NON_STATE_REVERSE);
	cout << endl;

	cout << word3 << endl;
	traceWord(word3, table, NON_STATES, RULES, NON_STATE_REVERSE);
	cout << endl;

	
	system("Pause");

	return 0;
}