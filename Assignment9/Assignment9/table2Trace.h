#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <regex>

using namespace std;

string printStack(stack<int>& myStack) {
	stack<int> copy(myStack);
	string result;
	while (!copy.empty()) {
		result += copy.top();
		copy.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}

template<size_t rows, size_t cols>
bool traceWord(string word, string(&parsingTable)[rows][cols], map<char, int>& NON_STATES, map<int, char>& LEFT_RULE, map<int, int>& RIGHT_RULE) {
	regex REDUCE("^R\\d{1,2}");
	regex SHIFT("^S\\d{1,2}");
	regex DIGITS("^\\d{1,2}");
	regex ACCEPT("ACC");
	
	bool RUN = true;

	int _stringIndex = 0
	int _row;
	int _col;
	int _pushItRealGood;
	int _ruleNumber;
	int _rightRule;
	int _popDump;

	char _leftRule;
	char _wordChar = word.at(_stringIndex);
	string _dopeMemes;
	
	stack<int> traceStack;
	
	map<char, int>::iterator mapIt;
	
	auto pop = [&]() {
		int temp = traceStack.top();
		traceStack.pop();
		return temp;
	};
	
	auto push = [&](int x) {
		traceStack.push(x);
	};
	
	traceStack.push(0);
	
	while(RUN) {

		_row = pop();
		if (_row > 15)
			break;
		_col = NON_STATES.at(_wordChar);

		_dopeMemes = parsingTable[_row][_col];

		switch (_dopeMemes) {
		case REDUCE:
			push(_row);
			_dopeMemes.replace('R', '');
			_ruleNumber = stoi(_dopeMemes);
			_leftRule = LEFT_RULE.at(_ruleNumber);
			_rightRule = RIGHT_RULE.at(_ruleNumber);
			for (int i = 0; i < 2 * _rightRule; i++)
				_popDump = pop();

			break;
		case SHIFT:
			break;
		case DIGIT:
			_pushItRealGood = stoi(_dopeMemes);
			push(_row);
			push(_col);
			push(_pushItRealGood);
			break;
		case ACCEPT:
			cout << word << " is accepted by the language." << endl;
			RUN = false;
			break;
		default:
			cout << "you done fucked up son." << endl;
			RUN = false;
			break;
		}

	}
	
}