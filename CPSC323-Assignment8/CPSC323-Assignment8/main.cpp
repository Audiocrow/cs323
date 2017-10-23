#include <iostream>
#include <map>
#inclde <stack>
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

//Returns "success" if the word could be traced
//Otherwise returns the number of the failed spot on the table
string traceWord(string word, string& parsingTable, char firstState, map<char,int>& states, map<char,int>& terminals) {
	int state;
	stack<char> traceStack;
	char top;
	map::iterator<char,int> mapIt;
	//Pop traceStack and return what was popped
	char pop = [&]() {
		char temp = traceStack.top();
		traceStack.pop();
		return temp;
	};
	//Push onto traceStack
	void push = [&](char c) { traceStack.push(c); };
	traceStack.push('$');
	traceStack.push(firstState);
	for(int i=0; i<word.length(); i++) {
		//If a letter is not in the language, immedietly reject
		if(terminals.find(word[i]) == terminals.end())
			return "Invalid";
		top=pop();
		mapIt = states.find(top);
		//Keep looking until a terminal is popped
		while(mapIt != states.end()) {
			state = states.at(top);
			string str = parsingTable[state][terminals.at(word[i])];
			if(str.empty()) { return "Invalid"; }
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
			if(word[i] == '$')
				return "Valid.";
			cout << "Matched " << word[i] << ". Stack:" << printStack(traceStack) << endl;
		else return "Invalid.";
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
	map<char,int> parseRow = { {'E',0}, {'Q',1}, {'T',2}, {'R',3}, {'F',4} };
	map<char,int> parseCol = { {'a',0}, {'+',1}, {'-',3}, {'*',4}, {'/',5}, {'(',6}, {')',7}, {'$',8} };
	return 0;
}
