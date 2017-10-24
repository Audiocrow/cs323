#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

string printStack(stack<char>& myStack) {
	stack<char> copy(myStack);
	string result;
	while(!copy.empty()) {
		result += copy.top();
		copy.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}

//Returns true if the word could be traced and is valid, otherwise false
template <size_t rows, size_t cols>
bool traceWord(string word, string (&parsingTable)[rows][cols], char firstState, map<char,int>& states, map<char,int>& terminals) {
	int state;
	stack<char> traceStack;
	char top;
	map<char,int>::iterator mapIt;
	//Pop traceStack and return what was popped
	auto pop = [&]() {
		char temp = traceStack.top();
		traceStack.pop();
		return temp;
	};
	//Push onto traceStack
	auto push = [&](char c) { traceStack.push(c); };
	traceStack.push('$');
	traceStack.push(firstState);
	for(int i=0; i<word.length(); i++) {
		//If a letter is not in the language, immedietly reject
		if(terminals.find(word[i]) == terminals.end()) {
			cout << "Invalid because " << word[i] << " is not in the language." << endl;
			return false;
		}
		top=pop();
		mapIt = states.find(top);
		//Keep looking until a terminal is popped
		while(mapIt != states.end()) {
			state = states.at(top);
			string str = parsingTable[state][terminals.at(word[i])];
			if(str.empty()) {
				cout << "Invalid at entry " << state*cols+terminals.at(word[i]) << endl; 
				return false;
			}
			//Using '\n' to be lambda:
			else if(str.size() == 1 && str[0] == '\n') {
				top=pop();
				mapIt = states.find(top);
				continue;
			}
			for(string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit)
					push(*rit);	
			top=pop();
			mapIt = states.find(top);
		}
		if(word[i] == top) {
			cout << "Matched " << word[i] << ". Stack:" << printStack(traceStack) << endl;
			if(word[i] == '$') {
				cout << "Valid." << endl;
				return true;
			}
		}
		else {
			cout << "Invalid match:" << word[i] << "!=" << top << " at entry " << state*cols+terminals.at(word[i]) << endl;
			return false;
		}
	}
	return false;
}

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
	return 0;
}
