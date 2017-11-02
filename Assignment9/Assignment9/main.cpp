#include "table2Trace.h"

int main() {

	map<char, int> NON_STATES{
		{ 'a', 16 },{ '+', 17 },{ '-', 18 },{ '*', 19 },{ '/', 20 },
		{ '(', 21 },{ ')', 22 },{ '$', 23 },{ 'E', 24 },{ 'T', 25 },
		{ 'F', 26 }
	};

	map<int, char> LEFT_HAND_RULE{
		{1,'E'},{2,'E'},{3,'E'},{4,'T'},
		{5,'T'},{6,'T'},{7,'F'},{8,'F'}
	};

	map<int, int> RIGHT_HAND_RULE{
		{1,3},{2,3},{3,1},{4,3},
		{5,3},{6,1},{7,3},{8,1}
	};

	map<int, char> NON_STATE_REVERSE{
		{ 16, 'a' },{ 17, '+' },{ 18, '-' },{ 19, '*' },{ 20, '/' },
		{ 21, '(' },{ 22, ')' },{ 23, '$' },{ 24, 'E' },{ 25, 'T' },
		{ 26, 'F' }
	};

	string word1 = "(a+a)/a$";
	string word2 = "a(a+a)$";
	string word3 = "a/a+(a*a)$";
	string word4 = "a*a*(+a)$";
	string word5 = "z/a*(a+a)$";
	string word6 = "a\\a*(a+a)$";
	string word7 = "a/a*(z+a)$";

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
	traceWord(word1, table, NON_STATES, LEFT_HAND_RULE, RIGHT_HAND_RULE, NON_STATE_REVERSE);
	cout << endl;

	cout << word2 << endl;
	traceWord(word2, table, NON_STATES, LEFT_HAND_RULE, RIGHT_HAND_RULE, NON_STATE_REVERSE);
	cout << endl;

	cout << word3 << endl;
	traceWord(word3, table, NON_STATES, LEFT_HAND_RULE, RIGHT_HAND_RULE, NON_STATE_REVERSE);
	cout << endl;

	cout << word4 << endl;
	traceWord(word4, table, NON_STATES, LEFT_HAND_RULE, RIGHT_HAND_RULE, NON_STATE_REVERSE);
	cout << endl;

	cout << word5 << endl;
	traceWord(word5, table, NON_STATES, LEFT_HAND_RULE, RIGHT_HAND_RULE, NON_STATE_REVERSE);
	cout << endl;

	cout << word6 << endl;
	traceWord(word6, table, NON_STATES, LEFT_HAND_RULE, RIGHT_HAND_RULE, NON_STATE_REVERSE);
	cout << endl;

	cout << word7 << endl;
	traceWord(word7, table, NON_STATES, LEFT_HAND_RULE, RIGHT_HAND_RULE, NON_STATE_REVERSE);
	cout << endl;
	system("Pause");

	return 0;
}