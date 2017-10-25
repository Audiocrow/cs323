#include "trace.h"

using namespace std;

int main() {
	cout << "Problem 2" << endl << "----------" << endl;
	string parsingTable[6][10] = {
		{"a=E",  ""  ,  ""  ,  ""  ,  ""  ,  "" ,  "" , ""  , ""  , ""  },
		{ "TQ", "TQ" ,   "" ,  ""  ,  ""  ,  "" , "TQ", ""  , ""  , ""  },
		{ ""  ,  ""  , "+TQ", "-TQ",  ""  ,  "" , ""  , "\n", ""  ,"\n" }, //Using '\n' = lambda
		{ "FR", "FR" ,  ""  ,  ""  ,  ""  , ""  , "FR", ""  , ""  , ""  },
		{ ""  ,  ""  , "\n" , "\n" , "*FR","/FR",  "" , "\n", ""  ,"\n" },
		{ "a" ,  "b" ,  ""  ,  ""  ,  ""  , ""  ,"(E)",  "" , ""  , ""  },
	};
	map<char, int> parseRow = { {'S',0},{ 'E',1 },{ 'Q',2 },{ 'T',3 },{ 'R',4 },{ 'F',5 } };
	map<char, int> parseCol = { { 'a',0 },{ 'b',1 },{ '+',2 },{ '-',3 },{ '*',4 },{ '/',5 },{ '(',6 },{ ')',7 },{ '=',8 },{ '$',9 } };
	cout << "a=(a+a)*b$" << endl;
	traceWord("a=(a+a)*b$", parsingTable, 'S', parseRow, parseCol);
	cout << endl << "a=a*(b-a)$" << endl;
	traceWord("a=a*(b-a)$", parsingTable, 'S', parseRow, parseCol);
	cout << endl << "a=(a+a)b$" << endl;
	traceWord("a=(a+a)b$", parsingTable, 'S', parseRow, parseCol);
	system("pause");
}
