#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>

using namespace std;

map<char, int> NON_STATES{
	{'a', 16},	{'+', 17},	{'-', 18},	{'*', 19},	{'/', 20}, 
	{'(', 21},	{')', 22},	{'$', 23},	{'E', 24 },	{'T', 25 },
	{'F', 26 }
};

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

