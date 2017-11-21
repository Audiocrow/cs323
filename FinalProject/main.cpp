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
}
