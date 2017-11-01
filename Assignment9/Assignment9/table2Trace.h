#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <regex>

using namespace std;

void printStack(stack<int>& myStack) {
	stack<int> copy(myStack);
	vector<int> a;
	vector<int>::iterator it;
	while (!copy.empty()) {
		a.insert(a.end(), copy.top());
		copy.pop();
	}
	cout << "stack reads: ";
	for (it = a.begin(); it < a.end(); it++) {
		cout << ' ' << *it;
	}
	cout << endl;
}

template<size_t rows, size_t cols>
bool traceWord(string word, string(&parsingTable)[rows][cols], map<char, int>& NON_STATES, map<int, char>& LEFT_RULE, map<int, int>& RIGHT_RULE) {
	regex REDUCE("^R\\d{1,2}");
	regex SHIFT("^S\\d{1,2}");
	regex DIGITS("^\\d{1,2}");
	regex ACCEPT("ACC");
	
	bool RUN = true;

	int _stringIndex = 0;
	int _row;
	int _col;
	int _tempCol;
	int _pushItRealGood;
	int _ruleNumber;
	int _rightRule;
	int _popDump;

	smatch _sm;

	char _leftRule;
	char _wordChar = word.at(_stringIndex);
	string _dopeMemes;
	
	stack<int> traceStack;
	
	//map<char, int>::iterator mapIt;
	
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

		_dopeMemes = parsingTable[_row][_col - 16];

		if (regex_match(_dopeMemes, REDUCE)) {
			push(_row);
			_dopeMemes = _dopeMemes.substr(1, _dopeMemes.size());
			_ruleNumber = stoi(_dopeMemes);
			_leftRule = LEFT_RULE.at(_ruleNumber);
			_tempCol = NON_STATES.at(_leftRule);
			_rightRule = RIGHT_RULE.at(_ruleNumber);
			for (int i = 0; i <(2 * _rightRule); i++)
				_popDump = pop();
			_row = pop();
			_dopeMemes = parsingTable[_row][_tempCol - 16];
			_pushItRealGood = stoi(_dopeMemes);
			push(_row);
			push(_tempCol);
			push(_pushItRealGood);
			printStack(traceStack);
		}
		else if (regex_match(_dopeMemes, SHIFT)) {
			_dopeMemes = _dopeMemes.substr(1, _dopeMemes.size());
			_wordChar = word.at(++_stringIndex);
			_pushItRealGood = stoi(_dopeMemes);
			push(_row);
			push(_col);
			push(_pushItRealGood);
			printStack(traceStack);
		}
		else if (regex_match(_dopeMemes, DIGITS)) {
			_pushItRealGood = stoi(_dopeMemes);
			push(_row);
			push(_col);
			push(_pushItRealGood);
			printStack(traceStack);
		}
		else if (regex_match(_dopeMemes, ACCEPT)) {
			cout << word << " is accepted by the language." << endl;
			RUN = false;
			return true;
		}
		else {
			cout << "you done fucked up son." << endl;
			RUN = false;
		}
	}
	return false;
}