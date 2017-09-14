// Member Names:
// Alexander Edgar
// Daniel Domingo
// Sean Wulwick

#include <iostream>
#include <regex>
#include <set>
#include <string>

using namespace std;

int main() {
	const int NUM_RESERVED = 4;
	char reservedWords[NUM_RESERVED][10] = { "cout<<", "for", "int", "while" };
	const int NUM_SPECIAL = 8;
	char special[NUM_SPECIAL][3] = { "=", "*", "-", ";", "(", ")", "<=", "+" };
	regex expr("\\S+"); //Anything followed by a space or endline
	set<string> myTokens;
	while(1) {
		cout << "Enter a statement:";
		string input;
		getline(cin, input);
		//Separate all tokens by space/endline via regex
		for(auto myRegIt=sregex_iterator(input.begin(), input.end(), expr); myRegIt != sregex_iterator(); ++myRegIt) {
			string token = (static_cast<smatch>(*myRegIt)).str();
			//If we've already looked at this token, don't identify it again
			auto found = myTokens.emplace(token);
			if(!found.second) {
				continue;
			}
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
					//Check if the token is a number (doubles are ok)
					if(regex_match(token, regex("\\d+(?:.\\d+)?"))) {
						cout << "number";
						typeFound=true;
					}
					//Otherwise check if it is an identifier (at least one letter/underscore, then
					//any combination of letters, digits, and underscores)
					else if(regex_match(token, regex("[a-zA-Z_][a-zA-Z_\\d]*"))) {
						cout << "identifier";
						typeFound=true;
					}
				}			
			}
			if(!typeFound) { cout << "not identifier"; }
			cout << endl;
		}
		myTokens.clear();
		cout << "Continue(y/n)?";
		char c;
		cin >> c;
		cin.ignore();
		if(c != 'y' && c != 'Y') { break; }
	}
	return 0;
}
