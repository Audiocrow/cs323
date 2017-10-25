// Domingo, Daniel
// Edgar, Alexander
// Wulwick, Sean


#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

string printStack(stack<char>& myStack) {
	stack<char> copy(myStack);
	string result;
	while (!copy.empty()) {
		result += copy.top();
		copy.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}

//Returns true if the word could be traced and is valid, otherwise false
template <size_t rows, size_t cols>
bool traceWord(string word, string(&parsingTable)[rows][cols], char firstState, map<char, int>& states, map<char, int>& terminals) {
	int state;
	stack<char> traceStack;
	char top;
	map<char, int>::iterator mapIt;
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
	for (int i = 0; i<word.length(); i++) {
		//If a letter is not in the language, immedietly reject
		if (terminals.find(word[i]) == terminals.end()) {
			cout << "Invalid because " << word[i] << " is not in the language." << endl;
			return false;
		}
		top = pop();
		mapIt = states.find(top);
		//Keep looking until a terminal is popped
		while (mapIt != states.end()) {
			state = states.at(top);
			string str = parsingTable[state][terminals.at(word[i])];
			if (str.empty()) {
				cout << "Invalid at entry " << state*cols + terminals.at(word[i]) << endl;
				return false;
			}
			//Using '\n' to be lambda:
			else if (str.size() == 1 && str[0] == '\n') {
				top = pop();
				mapIt = states.find(top);
				continue;
			}
			for (string::reverse_iterator rit = str.rbegin(); rit != str.rend(); ++rit)
				push(*rit);
			top = pop();
			mapIt = states.find(top);
		}
		if (word[i] == top) {
			cout << "Matched " << word[i] << ". Stack:" << printStack(traceStack) << endl;
			if (word[i] == '$') {
				cout << "Valid." << endl;
				return true;
			}
		}
		else {
			cout << "Invalid match:" << word[i] << "!=" << top << " at entry " << state*cols + terminals.at(word[i]) << endl;
			return false;
		}
	}
	return false;
}

int main() {
	cout << "Problem 2" << endl << "----------" << endl;
	string parsingTable[6][10] = {
		{"a=E",  ""  ,  ""  ,  ""  ,  ""  ,  "" ,  "" , ""  , ""  , ""  },
		{ "TQ", "TQ" ,   "" ,  ""  ,  ""  ,  "" , "TQ", ""  , ""  , ""  },
		{ ""  , "+TQ", "-TQ",  ""  ,  ""  ,  "" , ""  , "\n", ""  ,"\n" }, //Using '\n' = lambda
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
	return 0;
}
