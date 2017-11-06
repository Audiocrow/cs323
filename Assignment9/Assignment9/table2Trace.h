#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <regex>

using namespace std;

void printStack(stack<int>& myStack, map<int, char>& myMap) {
	stack<int> copy(myStack);
	vector<int> a;
	vector<int>::iterator it;
	if (!copy.empty()) {
		while (!copy.empty()) {
			a.insert(a.begin(), copy.top());
			copy.pop();
		}
		cout << "stack reads: ";
		for (it = a.begin(); it < a.end(); it++) {
			if (*it > 15)
				cout << ' ' << myMap.at(*it);
			else
				cout << ' ' << *it;
		}
	}
	else
		cout << "stack reads: empty";
	cout << endl;
}

template<size_t rows, size_t cols>
bool traceWord(string word, string(&parsingTable)[rows][cols], map<char, int>& NON_STATES, map<int, char>& LEFT_RULE, map<int, int>& RIGHT_RULE, map<int, char>& NON_STATES_REVERSE) {
	regex REDUCE("^R\\d{1,2}");
	regex SHIFT("^S\\d{1,2}");
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

	char _leftRule;
	char _wordChar;
	string _dopeMemes;
	
	stack<int> traceStack;
	
	auto pop = [&]() {
		int temp = traceStack.top();
		traceStack.pop();
		return temp;
	};
	
	auto push = [&](int x) {
		traceStack.push(x);
	};
	
	traceStack.push(0);
	_wordChar = word.at(_stringIndex);


	
	while(RUN) {

		_row = pop();
		if (_row > 15)
			break;

		if (NON_STATES.find(_wordChar) == NON_STATES.end())
		{
			cout << "Character '" << _wordChar << "' not in the language." << endl;
			break;
		}
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
			printStack(traceStack, NON_STATES_REVERSE);
		}
		else if (regex_match(_dopeMemes, SHIFT)) {
			_dopeMemes = _dopeMemes.substr(1, _dopeMemes.size());
			_wordChar = word.at(++_stringIndex);
			if (NON_STATES.find(_wordChar) == NON_STATES.end()) {
				cout << "Character '" << _wordChar << "' not in the language." << endl;
				RUN = false;
				break;
			}
			_pushItRealGood = stoi(_dopeMemes);
			push(_row);
			push(_col);
			push(_pushItRealGood);
			printStack(traceStack, NON_STATES_REVERSE);
		}
		else if (regex_match(_dopeMemes, ACCEPT)) {
			cout << word << " is accepted by the language." << endl;
			RUN = false;
			while (!traceStack.empty())
				_popDump = pop();
			return true;
		}
		else {
			cout << word << " is not accepted by the language." << endl;
			RUN = false;
		}
	}
	while (!traceStack.empty())
		_popDump = pop();
	return false;
}