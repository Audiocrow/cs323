#include <iostream>
#include <map>
#inclde <stack>
#include <string>

using namespace std;

//Pops the stack and returns what was popped
template <typename T>
T smartPop(stack<T>& myStack) {
	T item = myStack.top();
	myStack.pop();
	return item;
}

//Returns "success" if the word could be traced
//Otherwise returns the number of the failed spot on the table
string traceWord(string word, string& parsingTable) {
	stack<char> traceStack;
	char top;
	#define pop top=smartPop<char>(traceStack)
	#define push(A) traceStack.push('A')
	traceStack.push('$');
	traceStack.push('E');
	for(int i=0; i<word.length(); i++) {
		pop;
		switch(word[i]) {
			case 'a':
				for(int y=
				break;
	}
	#undef pop
}

int main() {
	string parsingTable[5][8] = {
		{ "TQ", "", "", "", "", "TQ", "", "" },
		{ "", "+TQ", "-TQ", "", "", "", "\n", "\n" }, //Using '\n' = lambda
		{ "FR", "", "", "", "", "FR", "", "" },
		{ "", "\n", "\n", "*FR", "/FR", "", "\n", "\n" },
		{ "a", "", "", "", "", "(E)", "", "" },
	};
	map<char, int> parseRow = { {'E',0}, {'Q',1}, {'T',2}, {'R',3}, {'F',4} };
	map<char, int> parseCol = { {'a',0}, {'+',1}, {'-',3}, {'*',4}, {'/',5}, {'(',6}, {')',7}, {'$',8} };
	return 0;
}
