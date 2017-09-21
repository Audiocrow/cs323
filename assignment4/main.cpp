//dummy main to make new folder
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int main() {
	ifstream ifile("./data.txt");
	ofstream ofile("./newdata.txt");
	regex token("(//|int|;|,|=|\\+|\\d+(?:.\\d+)?|[a-zA-Z_]\\w*)");
	string line, temp;
	smatch match, tokMatch;
	bool shouldSpace=false, comment=false, foundType=false;
	while(ifile.good()) {
		getline(ifile, line);
		cout <<"DEBUG: Read '" << line << "'" << endl;
		while(regex_search(line, match, regex("(\\S+)"))) {
			cout << "DEBUG: Matched '" << match.str(1) << "'" << endl;
			//Break up different tokens
			shouldSpace=false;
			comment=false;
			foundType = true;
			temp = match.str(1);
			while(regex_search(temp, tokMatch, token)) {
				foundType = true;
				cout << "\tDEBUG: Matched '" << tokMatch.str(1) << "'" << endl;
				//Skip comments
				if(tokMatch.str(1).length() > 1 && tokMatch.str(1).at(0) == '/' && tokMatch.str(1).at(1) == '/') {
					comment=true;
					break;
				}
				if(shouldSpace)
					ofile << " ";
				ofile << tokMatch.str(1);
				if(tokMatch.str(1).compare(";") == 0) {
					ofile << endl;
					shouldSpace = false;
				}
				else shouldSpace = true;
				temp = tokMatch.suffix().str();
			}
			if(comment)
				break;
			//Something not specified in tokens was found, so print it anyway
			if(!foundType)
				ofile << match.str(1);
			line = match.suffix().str();
		}
		//ofile << endline;
		line.clear();
	}
	ofile.close();
	ifile.close();
	return 0;
}
