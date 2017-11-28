void conversion(string data) {
	ofstream ofile("./final_translated.cpp");
	if (data.find("print") != string::npos) {
		cout << "#include <iostream>" << endl << "using namespace std;" << endl;
		ofile << "#include <iostream>" << endl << "using namespace std;" << endl;
	}
	//Change var declaration to C++ int declaration
	data = regex_replace(data, regex("var(?:\\r\\n|\\r|\\n)?([^:]+): integer ;"), "int $1;");
	//Add int main to the start and end of the program
	data = regex_replace(data, regex("program[^;]*;([^]+)end."), "int main() {$1return 0;\n}"); //[^] is sort of a C++ regex hack to have a . which also matches newline
																									  //Remove the "begin" line which is awkwardly after the variable declaration of the non-C++ code
	data = regex_replace(data, regex("begin(?:\\r\\n|\\r|\\n)"), "");
	//Change the prints to couts
	data = regex_replace(data, regex("print \\( ([^)]+) \\) ;"), "cout<<$1<<endl;");
	//Tab code blocks correctly
	size_t pos = data.find("{");
	if (pos != string::npos) {
		string::iterator it = data.begin() + pos + 1;
		int numNested = 1;
		for (it; it != data.end(); ++it) {
			if (*it == '{')
				numNested++;
			else if (*it == '}')
				numNested--;
			else if (it>data.begin() && (*(it - 1) == '\n' || *(it - 1) == '\r')) {
				for (int i = 0; i<numNested; i++)
					it = data.insert(it, '\t');
			}
		}
	}
	cout << data;
	cout << endl << "//The above translation has been printed to final_translated.cpp" << endl;
	ofile << data;
	ofile.close();
}