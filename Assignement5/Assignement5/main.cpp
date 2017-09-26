//Domingo, Daniel
//Edgar, Alexander
//Wulwick, Sean
#include <iostream>
#include <regex>
#include <string>

using namespace std;


int main() {
	regex expr("((W|w)=)?(a*)(a|b)(c*)\\$");
	string token;
	char repeat = 'y';
	bool ever = true;

	for (; ever;) {

		//asks for user input of language to compare
		cout << "Please give a word to compare with alphabet {a,b,c} (complete with '$') ";
		cin >> token;
		cin.ignore();

		//checks for '$' ending statement in language
		if (token.back() != '$') {
			cout << "Invalid expression please retype." << endl << endl;
		}
		else {
			////Removes the 'W=' if placed before the language
			//if ((token.front() == 'W' || token.front() == 'w') && token[1] == '=') {
			//	token.erase(0, 2);
			//}
			//compare statement on token
			if (regex_match(token, expr))
				cout << "token exists in language." << endl;
			else
				cout << "token does not exist in language." << endl;

			//ask user if they would like to continue
			do {
				cout << "try again?(y/n) ";
				cin >> repeat;
				cin.ignore();
				cout << endl;

				repeat = tolower(repeat);
				if (repeat == 'n')
					return 0;
			} while (repeat != 'y' && repeat != 'n');
		}
	}
}