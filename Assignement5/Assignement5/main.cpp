//Domingo, Daniel
//Edgar, Alexander
//Wulwick, Sean
#include <iostream>
#include <regex>
#include <string>

using namespace std;


int main() {
	regex expr("(a*)(a|b)(c*)\\$");
	string token;
	char repeat = 'y';
	bool ever = true;
	
	for (; ever;) {
		cout << "Please give a language to compare (complete with '$') ";
		cin >> token;
		if (token.back() != '$') {
			cout << "Invalid expression please retype." << endl;
		}
		else {
			if (regex_match(token, expr)) {
				cout << "token exists in language." << endl
					<< "try again?(y/n) ";

			}
			else {
				cout << "token does not exist in language." << endl
					<< "try again?(y/n) ";
			}
			cin >> repeat;
			cout << endl;
			repeat = tolower(repeat);
			if (repeat == 'n')
				return 0;
		}
	}
}