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
		getline(ifs, line, '$');
		line += "$";
		smatch match;
		//Match a word [identified by some combination of letters (at least 1)
		//followed by an optional combination of digits] with its expression
		//(anything following the = which follows the word)
		if(regex_match(line, match, regex("\\s*([a-zA-Z]+(?:\\d*)?)=([^\\s]*)"))) {
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
	//Using -1 as a "null state" sentinel:
	const int table[][2] = { {1,3},
							{1,2},
							{-1,-1},
							{-1,3} };
	//Evaluate each word:
	for(auto word : words) {
		int state=0;
		int done=0; //0=not done, 1=invalid, 2=valid
		for(int i=0; i<word.second.length(); i++) {
			switch(word.second.at(i)) {
				case 'a':
					state = table[state][0];
					if(state == -1) done=1;
					break;
				case 'b':
					state = table[state][1];
					if(state == -1) done=1;
					break;
				case '$':
					if(state == 2 || state == 3)
						done=2;
					else done=1;
					break;
				default:
					done=1;
					break;
			}
			if(done != 0) { break; }
		}
		if(done == 1)
			cout << word.first << " is invalid." << endl;
		else cout << word.first << " is valid." << endl;
	}
	return 0;
}
