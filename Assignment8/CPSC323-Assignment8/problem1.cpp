#include "trace.h"

using namespace std;

int main() {
	cout << "Problem 1" << endl << "----------" << endl;
	string parsingTable[5][8] = {
		{ "TQ", "", "", "", "", "TQ", "", "" },
		{ "", "+TQ", "-TQ", "", "", "", "\n", "\n" }, //Using '\n' = lambda
		{ "FR", "", "", "", "", "FR", "", "" },
		{ "", "\n", "\n", "*FR", "/FR", "", "\n", "\n" },
		{ "a", "", "", "", "", "(E)", "", "" },
	};
	map<char,int> parseRow = { {'E',0}, {'Q',1}, {'T',2}, {'R',3}, {'F',4} };
	map<char,int> parseCol = { {'a',0}, {'+',1}, {'-',2}, {'*',3}, {'/',4}, {'(',5}, {')',6}, {'$',7} };
	cout << "(a+a)*a$" << endl;
	traceWord("(a+a)*a$", parsingTable, 'E', parseRow, parseCol);
	cout << endl << "a*(a/a)$" << endl;
	traceWord("a*(a/a)$", parsingTable, 'E', parseRow, parseCol);
	cout << endl << "a(a+a)$" << endl;
	traceWord("a(a+a)$", parsingTable, 'E', parseRow, parseCol);
	system("Pause");
	return 0;
}
