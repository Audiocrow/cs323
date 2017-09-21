//dummy main to make new folder
#include <fstream>
#include <iostream>
#include <regex>


using namespace std;

int main() {
	ifstream ifile("data.txt");
	ofstream ofile("newdata.txt");
	regex identifier("([a-zA-Z_]\w*)");
	regex symbol("(int|;|,|=|+)");
	string line;
	smatch match, idMatch, symMatch;
	while(file.good()) {
		getline(ifile, line);
		while(regex_search(line, match, regex("(\S+)(\s+|//)"))) {
			//Skip comments
			if(match.str(1).compare("//") == 0)
				break;
			//Break up the word we matched by separate tokens - identifiers, symbols, etc.
			bool matched = false;
			while(regex_search(match.str(1), idMatch, identifier)) {
				ofile << idMatch.str(1);
				matched = true;
			}
			if(!matched)
				ofile << match.str(1);
			if(match.str(2).compare("\n") == 0 || match.str(2).compare("\r") == 0 || match.str(2).compare("\n\r") == 0 || match.str(2).compare("\r\n") == 0)
				ofile << endl;
			//Skip comments
			else if(match.str(2).compare("//") == 0)
				break;
			else ofile << " ";
			match = match.suffix().str();
		}
		line.clear();
	}
	ifile.close();
	ofile.close();
	return 0;
}
