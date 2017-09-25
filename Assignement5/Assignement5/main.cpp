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

		//asks for user input of language to compare
		cout << "Please give a language to compare (complete with '$') ";
		cin >> token;

		//checks for '$' ending statement in language
		if (token.back() != '$') {
			cout << "Invalid expression please retype." << endl << endl;
		}
		else {
			//compare statement on token
			if (regex_match(token, expr))
				cout << "token exists in language." << endl;
			else
				cout << "token does not exist in language." << endl;

			//ask user if they would like to continue
			do {
				cout << "try again?(y/n) ";
				cin >> repeat;
				cout << endl;

				repeat = tolower(repeat);
				if (repeat == 'n')
					return 0;
			} while (repeat != 'y' && repeat != 'n');
		}
	}
}