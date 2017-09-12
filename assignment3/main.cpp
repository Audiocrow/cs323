// Member Names:
// Alexander Edgar
// Daniel Domingo
// Sean Wulwick

#include <exception>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	const int NUM_RESERVED = 4;
	char reservedWords[NUM_RESERVED][10] = { "cout<<", "for", "int", "while" };
	const int NUM_SPECIAL = 8;
	char special[NUM_SPECIAL][3] = { "=", "*", "-", ";", "(", ")", "<=", "+" };
	regex expr("([^ ]+)(?:\\s|$)"); //Anything followed by a space or endline
	while(1) {
		cout << "Enter a statement:";
		string input;
		getline(cin, input);
		//Separate all tokens by space/endline via regex
		for(auto myRegIt=sregex_iterator(input.begin(), input.end(), expr); myRegIt != sregex_iterator(); ++myRegIt) {
			string token = (static_cast<smatch>(*myRegIt)).str();
			//Check if this token is a reserved word
			cout << token << "\t";
			bool typeFound=false;
			for(int i=0; i<NUM_RESERVED; i++) {
				if(token.compare(reservedWords[i]) == 0) {
					cout << "reserved word";
					typeFound=true;
					break;
				}
			}
			if(!typeFound) {
				//Check if this token is a special symbol
				for(int i=0; i<NUM_SPECIAL; i++) {
					if(token.compare(special[i]) == 0) {
						cout << "special symbol";
						typeFound=true;
						break;
					}
				}
				if(!typeFound) {
					//Attempt to cast the token into a number - if it succeeds, it is a number
					try {
						double value = stod(token);
						cout << "number";
						typeFound=true;
					}
					catch(invalid_argument&) {
						//Check if the token starts with some amount or mix of letters and underscores
						if(regex_match(token, regex("(?:\\w|_)+.*"))) {
							cout << "identifier";
							typeFound=true;
						}
					}
				}			
			}
			if(!typeFound) { cout << "not identifier"; }
			cout << endl;
		}
		cout << "Continue(y/n)?";
		char c;
		cin >> c;
		cin.ignore();
		if(c != 'y' && c != 'Y') { break; }
	}
	return 0;
}
