#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	ifstream ifile("./finalv1.txt");
	string v1_data((istreambuf_iterator<char>(ifile)), (istreambuf_iterator<char>()));
	ifile.close();
	//Remove comments
	v1_data = regex_replace(v1_data, regex("/\\*[^*]*\\*/"), "");
	//Ensure there is 1 space after each token
	regex token("(print|program|var|integer|begin|end\\.|\\(|\\)|:|,|=|[p-s][0-9p-s]*|\\d+)(?: |\\t)*");
	v1_data = regex_replace(v1_data, token, "$1 ");
	//Remove excess spaces
	v1_data = regex_replace(v1_data, regex("( |\\t)+"), " ");
	//Remove spaces at the end of a line
	v1_data = regex_replace(v1_data, regex("(?: |\\t)+(\\r\\n|\\r|\\n|$)"), "$1");
	//Remove spaces at the start of a line
	v1_data = regex_replace(v1_data, regex("(\\r\\n|\\r|\\n)(?: |\t)+"), "$1");
	//Remove empty lines
	v1_data = regex_replace(v1_data, regex("(\\r\\n|\\r|\\n)((?:\\r\\n|\\r|\\n)+)"), "$1");
	ofstream ofile("./finalv2.txt");
	ofile << v1_data;
	ofile.close();
	ofile = ofstream("./final_translated.cpp");
	if(v1_data.find("print") != string::npos) {
		cout << "#include <iostream>" << endl << "using namespace std;" << endl;
		ofile << "#include <iostream>" << endl << "using namespace std;" << endl;
	}
	//Change var declaration to C++ int declaration
	v1_data = regex_replace(v1_data, regex("var(?:\\r\\n|\\r|\\n)?([^:]+): integer ;"), "int $1;");
	//Add int main to the start and end of the program
	v1_data = regex_replace(v1_data, regex("program[^;]*;([^]+)end."), "int main() {$1return 0;\n}"); //[^] is sort of a C++ regex hack to have a . which also matches newline
	//Remove the "begin" line which is awkwardly after the variable declaration of the non-C++ code
	v1_data = regex_replace(v1_data, regex("begin(?:\\r\\n|\\r|\\n)"), "");
	//Change the prints to couts
	v1_data = regex_replace(v1_data, regex("print \\( ([^)]+) \\) ;"), "cout<<$1<<endl;");
	//Tab code blocks correctly
	size_t pos = v1_data.find("{");
	if(pos != string::npos) {
		string::iterator it = v1_data.begin()+pos+1;
		int numNested = 1;
		for(it; it!=v1_data.end(); ++it) {
			if(*it == '{')
				numNested++;
			else if(*it == '}')
				numNested--;
			else if(it>v1_data.begin() && (*(it-1) == '\n' || *(it-1) == '\r')) {
				for(int i=0; i<numNested; i++)
					it = v1_data.insert(it, '\t');
			}
		}
	}
	cout << v1_data;
	cout << endl << "//The above translation has been printed to final_translated.cpp" << endl;
	ofile << v1_data;
	ofile.close();
}
