#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>

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

class table2 {

public:
	template <size_t rows, size_t cols>
	bool traceWord(string word, string(&parsingTable)[rows][cols], char firstState, int& states, );

};