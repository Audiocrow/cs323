// Member Names:
// Alexander Edgar
// Daniel Domingo
// Sean Wulwick

#include <fstream>
#include <iostream>
#include <map>
#include <regex>

using namespace std;

//Reads a file and populates a string->string map of words
//to their respective expressions. Returns false if the file
//failed to be read.
bool populateWords(map<string,string>& words, string filename) {
	ifstream ifs;
	ifs.open(filename);
	if(!ifs.good()) {
		cout << " could not be opened for reading." << endl;
		return 0;
	}
	while(ifs.good()) {
		string line;
		getline(ifs, line);
		smatch match;
		//Match a word [identified by some combination of letters (at least 1)
		//followed by an optional combination of digits] with its expression
		//(anything following the = which follows the word)
		if(regex_match(line, match, regex("([a-zA-Z]+(?:\\d*)?)=(.*)"))) {
			if(match.str(1).length() > 0 && match.str(2).length() > 0)
				words.emplace(match.str(1), match.str(2));
		}
	}
	ifs.close();
	return true;
}

int main() {
	map<string,string> words;
	populateWords(words, "data.txt");
	//Test code to see if the map populates correctly:
	for(auto word : words) {
		cout << word.first << "=" << word.second << endl;
	}
	return 0;
}
