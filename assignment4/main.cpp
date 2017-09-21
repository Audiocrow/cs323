//dummy main to make new folder
#include <fstream>
#include <iostream>
#include <regex>


using namespace std;

int main() {
	ifstream ifile("data.txt");
	ofstream ofile("newdata.txt");
	string line;
	smatch match;
	while(file.good()) {
		getline(ifile, line);
		//Skip commented lines
		if(line.at(0) == '/' && line.at(1) == '/')
			continue;
		while(regex_search(line, match, regex("(\S+)(\s+)"))) {
			ofile << match.str(1);
			if(match.str(2).compare("\n") == 0 || match.str(2).compare("\r") == 0 || match.str(2).compare("\n\r") == 0 || match.str(2).compare("\r\n") == 0)
				ofile << endl;
			else ofile << " ";
			match = match.suffix().str();
		}
		line.clear();
	}
	ifile.close();
	ofile.close();
	return 0;
}
