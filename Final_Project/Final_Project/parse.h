#define OFFSET 69

template<size_t rows, size_t cols>
bool WordParse(stack<int>& myStack,
	string(&parsingTable)[rows][cols],
	string word,
	unordered_map<string, int>& WORD_STRING,
	unordered_map<char, int>& WORD_CHAR,
	unordered_map<int, string>& ERRORS,
	unordered_map<int, pair<string, int>>& RULES);

void nextWord(string &Language, string &nextWord)
{
	
	size_t pos = Language.find(" ");
	nextWord = Language.substr(0, pos);
	Language = Language.substr(pos + 1);
}

bool LanguageParse(string Language)
{
	
	string parsingTable[69][48]{
		{ "S2","","","","S7","S11","","S18","S19","","","","S20","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","S16","","","","1","6","","","5","","","8","9","10","12","13","14","15","68","17","4","3" },
		{ "","","","ACC","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","S30","S31","S32","S33","","","","","","34","","","","","","","","","","","","","","","","3" },
		{ "","","","","","","R3","R3","R3","R3","R3","R3","S20","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","","R3","R3","R3","","","35","","","","","","","","","","","","","","4","3" },
		{ "","","","","","","R7","R7","R7","R7","R7","R7","S20","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","","R7","R7","R7","","","66","","","","","","","","","","","","36","","4","3" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","","S37","","","","","","","E3","","","","","","","","","","","","" },
		{ "","","","","","","S38","R24","R24","R24","R24","S39","","","","","","","","","","","","","","","","R24","R10","R24","","","","","E2","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","","","R11","","","","","","","","","","","","","","","","","","" },
		{ "","","","R12","","S11","","","","","","","","","","","","","","","","","S30","S31","S32","S33","","","","","","6","","","","","40","8","9","10","","","","","","","","3" },
		{ "","","","R14","","R14","","","","","","","","","","","","","","","","","R14","R14","R14","R14","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","R15","","R15","","","","","","","","","","","","","","","","","R15","R15","R15","R15","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","S41","","","","","","","","","","","","","","E4","","","","","","","" },
		{ "","","","","","","","S42","S43","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R20","R20","S44","S45","","","","","","","","","","","","","","","","","R20","","R20","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R23","R23","R23","R23","","","","","","","","","","","","","","","","","R23","","R23","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R25","R25","R25","R25","","","","","","","","","","","","","","","","","R25","","R25","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","S18","S19","","","","S20","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","S16","","","","","6","","","","","","","","","46","13","14","15","68","17","4","3" },
		{ "","","","","","","","","","","","","S20","S21","S22","S23","S24","S25","S26","S27","S28","S29","","","","","","","","","","","","","","","","","","","","","","","67","","4","" },
		{ "","","","","","","","","","","","","R31","R31","R31","R31","R31","R31","R31","R31","R31","R31","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","R32","R32","R32","R32","R32","R32","R32","R32","R32","R32","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","","R33","R33","R33","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","","R34","R34","R34","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","","R35","R35","R35","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","","R36","R36","R36","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","","R37","R37","R37","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","","R38","R38","R38","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","","R39","R39","R39","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","","R40","R40","R40","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","","R41","R41","R41","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","","R42","R42","R42","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","","R43","R43","R43","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","","R44","R44","R44","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","","R45","R45","R45","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","","R46","R46","R46","","","","","","","","","","","","","","","","","","" },
		{ "","E1","","","","","","","","","","","","","","","","","","","","","","","","","","","","S47","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R2","R2","R2","R2","R2","R2","","","","","","","","","","","","","","","","R2","R2","R2","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R29","R29","R29","R29","","","","","","","","","","","","","","","","","R29","","R29","","","","","","","","","","","","","","","","","","" },
		{ "","","","","S7","","","","","","","","","","","","","","","","","","","","","","","","","R11","","","","","","48","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","S30","S31","S32","S33","","","","","","6","","","65","","","","","","","","","","","","","3" },
		{ "","","","","","","","S18","S19","","","","","","","","","","","","","","S30","S31","S32","S33","S16","","","","","6","","","","","","","","","49","13","14","15","68","17","","3" },
		{ "","","","R13","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","S30","S31","S32","S33","","","","","","50","","","","","","","","","","","","","","","","3" },
		{ "","","","","","","","S18","S19","","","","","","","","","","","","","","S30","S31","S32","S33","S16","","","","","6","","","","","","","","","","51","14","15","68","17","","3" },
		{ "","","","","","","","S18","S19","","","","","","","","","","","","","","S30","S31","S32","S33","S16","","","","","6","","","","","","","","","","52","14","15","68","17","","3" },
		{ "","","","","","","","S18","S19","","","","","","","","","","","","","","S30","S31","S32","S33","S16","","","","","6","","","","","","","","","","","53","15","68","17","","3" },
		{ "","","","","","","","S18","S19","","","","","","","","","","","","","","S30","S31","S32","S33","S16","","","","","6","","","","","","","","","","","54","15","68","17","","3" },
		{ "","","","","","","","S42","S43","","","","","","","","","","","","","","","","","","","S55","","E5","","","","","","","","","","","","","","","","","","" },
		{ "","S56","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","E1","","","","","","","","","","","","","","","","","","","","","","","","","","","S57","","","","","","","","","","","","","","","","","","" },
		{ "","","","E1","","","","S42","S43","","","","","","","","","","","","","","","","","","","","","S64","","","","","","","E1","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","S58","","E5","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R18","R18","S44","S45","","","","","","","","","","","","","","","","","R18","","R18","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R19","R19","S44","S45","","","","","","","","","","","","","","","","","R19","","R19","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R21","R21","R21","R21","","","","","","","","","","","","","","","","","R21","","R21","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R22","R22","R22","R22","","","","","","","","","","","","","","","","","R22","","R22","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R26","R26","R26","R26","","","","","","","","","","","","","","","","","R26","","R26","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","S30","S31","S32","S33","","","","","","6","","59","5","","","","","","","","","","","","","3" },
		{ "","","R8","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","E1","","","","","","","","","","","","","","","","","","","","","","","","","","S60","","","","","","","E1","","","","","","","","","","","" },
		{ "","","S61","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","R16","R16","","","","","","","","","","","","","","","","","","R16","R16","R16","R16","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","S11","","","","","","","","","","","","","","","","","S30","S31","S32","S33","","","","","","6","","","","","62","8","9","10","","","","","","","","3" },
		{ "","","","S63","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","R1","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","R17","R17","","","","","","","","","","","","","","","","","","R17","R17","R17","R17","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","","R9","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R5","R5","R5","R5","R5","R5","","","","","","","","","","","","","","","","R5","R5","R5","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R27","R27","R27","R27","","","","","","","","","","","","","","","","","R27","","R27","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R28","R28","R28","R28","","","","","","","","","","","","","","","","","R28","","R28","","","","","","","","","","","","","","","","","" }
	};
	
	unordered_map<string, int> WORD_STRINGS{
		{"program"		,69	},{	"var"		,70	},{	"begin"		,71	},{	"end."		,72	},{"integer",73	},{	"print"		,74	},
		{"<prog>"		,99	},{	"<id>"		,100},{	"<id'>"		,101},{"<dec-list>"	,102},{"<dec>"	,103},{"<type>"		,104},
		{"<stat-list>"	,105},{	"<stat>"	,106},{"<write>"	,107},{"<assign>"	,108},{"<expr>"	,109},{"<term>"		,110},
		{"<factor>"		,111},{	"<number>"	,112},{"<number'>"	,113},{	"<sign>"	,114},{"<digit>",115},{"<letter>"	,116}
	};

	unordered_map<char, int>WORD_CHARS{
		{',',75},{'+',76},{'-',77},{'*',78},{'/',79},{'=',80},{'0',81},{'1',82},
		{'2',83},{'3',84},{'4',85},{'5',86},{'6',87},{'7',88},{'8',89},{'9',90},
		{'p',91},{'q',92},{'r',93},{'s',94},{'(',95},{')',96},{':',97},{';',98}
	};

	unordered_map<int, pair<string, int>> RULES{
		{ 1,{ "<prog>"		,8 } },{ 2,{ "<id>"		,2 } },{ 3,{ "<id>"		,1 } },{ 4,{ "<id'>"		,2 } },
		{ 5,{ "<id'>"		,2 } },{ 6,{ "<id'>"	,1 } },{ 7,{ "<id'>"	,1 } },{ 8,{ "<dec-list>"	,4 } },
		{ 9,{ "<dec>"		,3 } },{10,{ "<dec>"	,1 } },{11,{ "<type>"	,1 } },{12,{ "<stat-list>"	,1 } },
		{13,{ "<stat-list>"	,2 } },{14,{ "<stat>"	,1 } },{15,{ "<stat>"	,1 } },{16,{ "<write>"		,5 } },
		{17,{ "<assign>"	,4 } },{18,{ "<expr>"	,3 } },{19,{ "<expr>"	,3 } },{20,{ "<expr>"		,1 } },
		{21,{ "<term>"		,3 } },{22,{ "<term>"	,3 } },{23,{ "<term>"	,1 } },{24,{ "<factor>"		,1 } },
		{25,{ "<factor>"	,1 } },{26,{ "<factor>"	,3 } },{27,{ "<number>"	,2 } },{28,{ "<number>"		,1 } },
		{29,{ "<number'>"	,2 } },{30,{ "<number'>",1 } },{31,{ "<sign>"	,1 } },{32,{ "<sign>"		,1 } },
		{33,{ "<digit>"		,1 } },{34,{ "<digit>"	,1 } },{35,{ "<digit>"	,1 } },{36,{ "<digit>"		,1 } },
		{37,{ "<digit>"		,1 } },{38,{ "<digit>"	,1 } },{39,{ "<digit>"	,1 } },{40,{ "<digit>"		,1 } },
		{41,{ "<digit>"		,1 } },{42,{ "<digit>"	,1 } },{43,{ "<letter>"	,1 } },{44,{ "<letter>"		,1 } },
		{45,{ "<letter>"	,1 } },{46,{ "<letter>"	,1 } }
	};

	unordered_map<int, string> ERRORS{
		{1, "Expected ';'"},{2, "Expected ','"},{3, "Expected ':'"},{4, "Expected '('"},{5, "Expected ')'"}
	};

	regex REDUCE("^R\\d{1,2}");
	regex SHIFT("^S\\d{1,2}");
	regex ACCEPT("ACC");
	regex ERROR("^E\\d");

	bool ever = true;
	bool program = false;
	bool var = false;
	bool begin = false;
	bool end = false;

	int row;
	int col;
	int ruleNumber;
	int rightRule;
	int stringIndex = 0;
	size_t pos;

	char currentWordChar;
	string _leftRule;
	string currentWord;
	string tableString;
	string errorString;

	stack<int> traceStack;

	auto pop = [&]() {
		int temp = traceStack.top();
		traceStack.pop();
		return temp;
	};

	auto push = [&](int x) {
		if (x == 68)
			program = true;
		if (x == 69)
			var = true;
		if (x == 70)
			begin = true;
		if (x == 71)
			end = true;
		traceStack.push(x);
	};

	replace(Language.begin(), Language.end(), '\n', ' ');
	
	nextWord(Language, currentWord);
	push(0);

	for (;ever;) {
		
		row = pop();
		if (row > OFFSET - 1)
		{
			break;
		}

		if (WORD_STRINGS.find(currentWord) == WORD_STRINGS.end())
		{
			if (!WordParse(traceStack, parsingTable, currentWord, WORD_STRINGS, WORD_CHARS, ERRORS, RULES)) 
			{
				cout << "unknown identifier" << endl;
				break;
			}
			continue;
		}

		col = WORD_STRINGS.at(currentWord);

		tableString = parsingTable[row][col - OFFSET];

		if (regex_match(tableString, REDUCE)) {
			ruleNumber = stoi(tableString.substr(1, tableString.size()));
			_leftRule = RULES.at(ruleNumber).first;
			col = WORD_STRINGS.at(_leftRule);
			rightRule = RULES.at(ruleNumber).second;
			for (int i = 0; i <(2 * rightRule) - 1; i++)
				traceStack.pop();
			row = pop();
			tableString = parsingTable[row][col - OFFSET];
			push(row);
			push(col);
			push(stoi(tableString));
		}
		else if (regex_match(tableString, SHIFT)) {
			tableString = tableString.substr(1, tableString.size());
			push(row);
			push(col);
			push(stoi(tableString));
			nextWord(Language, currentWord);
		}
		else if (regex_match(tableString, ACCEPT) && program && var && begin && end) {
			while (!traceStack.empty())
				traceStack.pop();
			return true;
		}
		else if (regex_match(tableString, ERROR)) {
			tableString = tableString.substr(1, tableString.size());
			ruleNumber = stoi(tableString);
			cout << ERRORS.at(ruleNumber) << endl;
			ever = false;
		}
		else {
			cout << "invalid expression" << endl;
			ever = false;
		}
	}
	while (!traceStack.empty())
	{
		traceStack.pop();
	}
	if (!program)
	{
		cout << "'program' is expected" << endl;
	}
	if (!var)
	{
		cout << "'var' is expected" << endl;
	}
	if (!begin)
	{
		cout << "'begin' is expected" << endl;
	}
	if (!end)
	{
		cout << "'end.' is expected" << endl;
	}
	return false;
}

template<size_t rows, size_t cols>
bool WordParse(stack<int>& myStack, 
					string (&parsingTable)[rows][cols], 
					string word,
					unordered_map<string, int>& WORD_STRING,
					unordered_map<char, int>& WORD_CHAR,
					unordered_map<int, string>& ERRORS,
					unordered_map<int, pair<string, int>>& RULES)
{
	regex REDUCE("^R\\d{1,2}");
	regex SHIFT("^S\\d{1,2}");
	regex ERROR("^E\\d");

	bool RUN = true;

	int _stringIndex = 0;
	int _row;
	int _col;
	int _tempCol;
	int _pushFinal;
	int _ruleNumber;
	int _rightRule;
	int _popDump;

	char _wordChar;
	string _leftRule;
	string _tableString;

	stack<int> traceStack;

	auto pop = [&]() {
		int temp = traceStack.top();
		traceStack.pop();
		return temp;
	};

	auto push = [&](int x) {
		traceStack.push(x);
	};

	_wordChar = word.at(_stringIndex);

	while (RUN) {

		_row = pop();
		if (_row > OFFSET - 1)
			break;

		if (WORD_CHAR.find(_wordChar) == WORD_CHAR.end())
		{
			break;
		}
		_col = WORD_CHAR.at(_wordChar);

		_tableString = parsingTable[_row][_col - OFFSET];

		if (regex_match(_tableString, REDUCE)) {
			_ruleNumber = stoi(_tableString.substr(1, _tableString.size()));
			_leftRule = RULES.at(_ruleNumber).first;
			_tempCol = WORD_STRING.at(_leftRule);
			_rightRule = RULES.at(_ruleNumber).second;
			for (int i = 0; i <(2 * _rightRule) - 1; i++)
				_popDump = pop();
			_row = pop();
			_tableString = parsingTable[_row][_tempCol - OFFSET];
			_pushFinal = stoi(_tableString);
			push(_row);
			push(_tempCol);
			push(_pushFinal);
		}
		else if (regex_match(_tableString, SHIFT)) {
			_tableString = _tableString.substr(1, _tableString.size());
			if (_stringIndex < word.size())
				_wordChar = word.at(++_stringIndex);
			else
				return true;
			if (WORD_CHAR.find(_wordChar) == WORD_CHAR.end()) {
				break;
			}
			_pushFinal = stoi(_tableString);
			push(_row);
			push(_col);
			push(_pushFinal);
		}
		else if (regex_match(_tableString, ERROR)) {
			_tableString = _tableString.substr(1, _tableString.size());
			_ruleNumber = stoi(_tableString);
			cout << ERRORS.at(_ruleNumber) << endl;
		}
		else {
			cout << "invalid expression" << endl;
			RUN = false;
		}
	}
	return false;
}