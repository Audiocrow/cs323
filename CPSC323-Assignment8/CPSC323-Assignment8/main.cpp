#include <exception>
#include <iostream>
#include <map>
#inclde <stack>
#include <string>

using namespace std;

//Returns "success" if the word could be traced
//Otherwise returns the number of the failed spot on the table
string traceWord(string word, string& parsingTable, map<char,int>& states, map<char,int>& terminals) {
	int state;
	stack<char> traceStack;
	char top;
	//Pop traceStack and return what was popped
	char pop = [&]() {
		char temp = traceStack.top();
		traceStack.pop();
		return temp;
	};
	//Push onto traceStack
	void push = [&](char c) { traceStack.push(c); };
	traceStack.push('$');
	traceStack.push('E');
	for(int i=0; i<word.length(); i++) {
		top=pop();
		//Did we match a letter?
		if(top == word[i]) {
		}
		else {
			try {
				string str = parsingTable[state][top];
				for(string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit)
					push(*it);
			}
			//If this letter is not even in the language
			catch(out_of_range e) {
				return "invalid";
			}
		}
	}
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
