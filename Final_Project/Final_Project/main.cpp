#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <stack>
#include <utility>

using namespace std;

#include "fileClean.h"
#include "parse.h"
#include "conversion.h"

int main() {
	ifstream ifile("./finalv1.txt");
	string v1_data((istreambuf_iterator<char>(ifile)), (istreambuf_iterator<char>()));
	ifile.close();
	
	string v2_data = fileClean(v1_data);

	if (parseFullString(v2_data))
	{
		conversion(v2_data);
	}

	
	system("pause");
	return 0;
}
