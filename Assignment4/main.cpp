//dummy main to make new folder
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int main() {
	ifstream ifile("./data.txt");
	ofstream ofile("./newdata.txt");
	regex token("(//|int|;|,|=|\\+|\\d+(?:.\\d+)?|[a-zA-Z_]+[\\w\\d<>]*)");
	string line;
	smatch match;
	bool shouldSpace=false, foundType=false;
	while(ifile.good()) {
		getline(ifile, line);
		shouldSpace = false;
		foundType = false;
		//Find tokens
		while(regex_search(line, match, token)) {
			foundType = true;
			//Skip comments
			if(match.str(1).length() > 1 && match.str(1).at(0) == '/' && match.str(1).at(1) == '/')
				break;
			//We print a space before the token if this token isn't the first on this line
			if(shouldSpace)
				ofile << " ";
			ofile << match.str(1);
			//If this token was a ; then print a newline
			if(match.str(1).compare(";") == 0) {
				ofile << endl;
				shouldSpace = false; //Next token won't need a space affix
			}
			else shouldSpace = true;
			line = match.suffix().str();
		}
		//Something not specified in tokens was found, so print it anyway
		if(!foundType)
			ofile << match.str(1);
		line.clear();
	}
	ofile.close();
	ifile.close();
	return 0;
}
