//dummy main to make new folder
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int main() {
	ifstream ifile("./data.txt");
	ofstream ofile("./newdata.txt");
	regex token("(int|;|,|=|+|[a-zA-Z_]\\w+");
	string line, temp;
	smatch match, tokMatch;
	bool firstPrint=false, comment=false;
	while(ifile.good()) {
		getline(ifile, line);
		cout <<"DEBUG: Read '" << line << "'" << endl;
		while(regex_search(line, match, regex("(\\S+)(;)?"))) {
			cout << "DEBUG: Matched '" << match.str(1) << "'";
			if(match.size() > 2) cout << " and '" << match.str(2) << "'";
			cout << endl;
			//Break up different tokens
			firstPrint=false;
			comment=false;
			temp = match.str(1);
			while(regex_search(temp, tokMatch, token)) {
				//Skip comments
				if(tokMatch.str(1).length() > 1 && tokMatch.str(1).at(0) == '/' && tokMatch.str(1).at(1) == '/') {
					comment=true;
					break;
				}
				if(!firstPrint)
					ofile << " ";
				ofile << tokMatch.str(1);
				firstPrint = true;
				temp = tokMatch.suffix().str();
			}
			if(comment)
				break;
			//Something unknown was found, print it as its own token
			if(!firstPrint)
				ofile << match.str(1);
			//Rather than a space, ; is followed by newline
			if(match.size() > 2 && match.str(2).at(0) == ';')
				ofile << endl;
			line = match.suffix().str();
		}
		//ofile << endline;
		line.clear();
	}
	ofile.close();
	ifile.close();
	return 0;
}
