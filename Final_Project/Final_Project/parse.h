#define OFFSET			69
#define SHIFT_SUCCESS	0
#define REDUCE_SUCCESS  1
#define ACCEPT_FINAL	2
#define FAIL			-1

template<size_t rows, size_t cols>
int WordParse(bool charByChar, string currentWord, stack<int> &traceStack, string(&parsingTable)[rows][cols],
	unordered_map<string, int> &WORD_STRINGS, unordered_map<char, int> &WORD_CHARS,
	unordered_map<int, pair<string, int>> &RULES, unordered_map<int, string> &ERRORS);

void nextWord(string &Language, string &nextWord)
{
	size_t pos = Language.find(" ");
	nextWord = Language.substr(0, pos);
	if (nextWord != "$")
	{
		Language = Language.substr(pos + 1);
	}
}

bool LanguageParse(string Language)
{
	
	string parsingTable[69][49]
	{
		{ "S2","","","","S7","S11","","S19","S20","","","","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","S34","S16","","","","","1","6","","","5","","","8","9","10","12","13","14","15","18","17","4","3" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","ACC","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","S31","S32","S33","S34","","","","","","","35","","","","","","","","","","","","","","","","3" },
		{ "","","","","","","R3","R3","R3","R3","R3","R3","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","S34","","R3","R3","R3","","","","36","","","","","","","","","","","","","","4","3" },
		{ "","","","","","","R7","R7","R7","R7","R7","R7","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","S34","","R7","R7","R7","","","","37","","","","","","","","","","","","38","","4","3" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","","S39","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","S40","R24","R24","R24","R24","S41","","","","","","","","","","","","","","","","R24","R10","R24","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","","","R11","","","","","","","","","","","","","","","","","","","" },
		{ "","","","R12","","S11","","","","","","","","","","","","","","","","","S31","S32","S33","S34","","","","","","","6","","","","","42","8","9","10","","","","","","","","3" },
		{ "","","","R14","","R14","","","","","","","","","","","","","","","","","R14","R14","R14","R14","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","R15","","R15","","","","","","","","","","","","","","","","","R15","R15","R15","R15","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","S43","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","S44","S45","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R20","R20","S46","S47","","","","","","","","","","","","","","","","","R20","","R20","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R23","R23","R23","R23","","","","","","","","","","","","","","","","","R23","","R23","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R25","R25","R25","R25","","","","","","","","","","","","","","","","","R25","","R25","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","S19","S20","","","","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","S34","S16","","","","","","6","","","","","","","","","48","13","14","15","18","17","4","3" },
		{ "","","","","","","","","","","","","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","","","","","","","","","","","","","","","","","","","","","","","","49","","4","" },
		{ "","","","","","","","R28","R28","R28","R28","","","","","","","","","","","","","","","","","R28","","R28","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","R31","R31","R31","R31","R31","R31","R31","R31","R31","R31","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","R32","R32","R32","R32","R32","R32","R32","R32","R32","R32","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","R33","","R33","R33","R33","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","R34","","R34","R34","R34","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","R35","","R35","R35","R35","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","R36","","R36","R36","R36","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","R37","","R37","R37","R37","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","R38","","R38","R38","R38","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","R39","","R39","R39","R39","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","R40","","R40","R40","R40","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","R41","","R41","R41","R41","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","R42","","R42","R42","R42","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","R43","","R43","R43","R43","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","R44","","R44","R44","R44","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","R45","","R45","R45","R45","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","R46","","R46","R46","R46","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","","","S50","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R2","R2","R2","R2","R2","R2","","","","","","","","","","","","","","","","R2","R2","R2","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","R5","R5","R5","R5","R5","R5","","","","","","","","","","","","","","","","R5","R5","R5","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R29","R29","R29","R29","","","","","","","","","","","","","","","","","R29","","R29","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","S7","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","51","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","S31","S32","S33","S34","","","","","","","6","","","52","","","","","","","","","","","","","3" },
		{ "","","","","","","","S19","S20","","","","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","S34","S16","","","","","","6","","","","","","","","","53","13","14","15","18","17","4","3" },
		{ "","","","R13","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","S31","S32","S33","S34","","","","","","","54","","","","","","","","","","","","","","","","3" },
		{ "","","","","","","","S19","S20","","","","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","S34","S16","","","","","","6","","","","","","","","","","55","14","15","18","17","4","3" },
		{ "","","","","","","","S19","S20","","","","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","S34","S16","","","","","","6","","","","","","","","","","56","14","15","18","17","4","3" },
		{ "","","","","","","","S19","S20","","","","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","S34","S16","","","","","","6","","","","","","","","","","","57","15","18","17","4","3" },
		{ "","","","","","","","S19","S20","","","","S21","S22","S23","S24","S25","S26","S27","S28","S29","S30","S31","S32","S33","S34","S16","","","","","","6","","","","","","","","","","","58","15","18","17","4","3" },
		{ "","","","","","","","S44","S45","","","","","","","","","","","","","","","","","","","S59","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R27","R27","R27","R27","","","","","","","","","","","","","","","","","R27","","R27","","","","","","","","","","","","","","","","","","","" },
		{ "","S60","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","","","S61","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","","R9","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","S44","S45","","","","","","","","","","","","","","","","","","","","","S62","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","S63","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R18","R18","S46","S47","","","","","","","","","","","","","","","","","R18","","R18","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R19","R19","S46","S47","","","","","","","","","","","","","","","","","R19","","R19","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R21","R21","R21","R21","","","","","","","","","","","","","","","","","R21","","R21","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R22","R22","R22","R22","","","","","","","","","","","","","","","","","R22","","R22","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","R26","R26","R26","R26","","","","","","","","","","","","","","","","","R26","","R26","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","S31","S32","S33","S34","","","","","","","6","","64","5","","","","","","","","","","","","","3" },
		{ "","","R8","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","R17","","R17","","","","","","","","","","","","","","","","","R17","R17","R17","R17","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","","","S65","","","","","","","","","","","","","","","","","","","" },
		{ "","","S66","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","R16","","R16","","","","","","","","","","","","","","","","","R16","R16","R16","R16","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","S11","","","","","","","","","","","","","","","","","S31","S32","S33","S34","","","","","","","6","","","","","67","8","9","10","","","","","","","","3" },
		{ "","","","S68","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","" },
		{ "","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","R1","","","","","","","","","","","","","","","","","","" }
	};
	string currentWord;

	int changer;
	
	stack<int> traceStack;

#pragma region unordered_maps
	unordered_map<string, int> WORD_STRINGS
	{
		{"program"		,69	},{	"var"		,70	},{	"begin"		,71	},{	"end."		,72	},{"integer",73	},{	"print"		,74	},
		{"<prog>"		,100},{	"<id>"		,101},{	"<id'>"		,102},{"<dec-list>"	,103},{"<dec>"	,104},{"<type>"		,105},
		{"<stat-list>"	,106},{	"<stat>"	,107},{"<write>"	,108},{"<assign>"	,109},{"<expr>"	,110},{"<term>"		,111},
		{"<factor>"		,112},{	"<number>"	,113},{"<number'>"	,114},{	"<sign>"	,115},{"<digit>",116},{"<letter>"	,117}
	};

	unordered_map<char, int>WORD_CHARS
	{
		{',',75},{'+',76},{'-',77},{'*',78},{'/',79},{'=',80},{'0',81},{'1',82},
		{'2',83},{'3',84},{'4',85},{'5',86},{'6',87},{'7',88},{'8',89},{'9',90},
		{'p',91},{'q',92},{'r',93},{'s',94},{'(',95},{')',96},{':',97},{';',98},{'$',99}
	};

	unordered_map<int, pair<string, int>> RULES
	{
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

	unordered_map<int, string> ERRORS
	{
		{1, "Expected ';'"},{2, "Expected ','"},{3, "Expected ':'"},{4, "Expected '('"},{5, "Expected ')'"}
	};

#pragma endregion
	
#pragma region bool
	bool ever = true;
	bool charByChar = false;
#pragma endregion

	replace(Language.begin(), Language.end(), '\n', ' ');
	Language.append(" $ ");
	
	nextWord(Language, currentWord);
	traceStack.push(0);

	for (; ever;) 
	{

		if (WORD_STRINGS.find(currentWord) == WORD_STRINGS.end())
		{
			charByChar = true;
			changer = WordParse(charByChar, currentWord, traceStack, parsingTable,
				WORD_STRINGS, WORD_CHARS, RULES, ERRORS);
			charByChar = false;
		}
		else
		{
			changer = WordParse(charByChar, currentWord, traceStack, parsingTable,
				WORD_STRINGS, WORD_CHARS, RULES, ERRORS);
		}

		switch (changer) 
		{
		case SHIFT_SUCCESS:
			nextWord(Language, currentWord);
			break;
		case REDUCE_SUCCESS:
			break;
		case ACCEPT_FINAL:
			ever = false;
			break;
		case FAIL:
			cout << "invalid expression." << endl;
			ever = false;
			break;
		default:
			cout << "something went wrong..." << endl;
			ever = false;
			break;
		}

		
	}
	while (!traceStack.empty())
	{
		traceStack.pop();
	}
	if (changer == ACCEPT_FINAL)
	{
		return true;
	}
	return false;
		
}

template<size_t rows, size_t cols>
int WordParse(bool charByChar, string currentWord, stack<int> &traceStack, string(&parsingTable)[rows][cols],
	unordered_map<string, int> &WORD_STRINGS, unordered_map<char, int> &WORD_CHARS,
	unordered_map<int, pair<string, int>> &RULES, unordered_map<int, string> &ERRORS)
{

#pragma region bool
	static bool isProgramPresent = false;
	static bool isVarPresent = false;
	static bool isBeginPresent = false;
	static bool isEndPresent = false;
#pragma endregion

#pragma region values
	static int row;
	static int col;
	static int reduceCol;
	static int ruleNumber;
	static int rightRule;
	static int stringIndex;
#pragma endregion

#pragma region words
	static string _leftRule;
	static string tableString;
	static string errorString;
#pragma endregion

#pragma region stack_commands
	static auto pop = [&]() {
		int temp = traceStack.top();
		traceStack.pop();
		return temp;
	};

	static auto push = [&](int x) {
		if (x == 68)
			isProgramPresent = true;
		if (x == 69)
			isVarPresent = true;
		if (x == 70)
			isBeginPresent = true;
		if (x == 71)
			isEndPresent = true;
		traceStack.push(x);
	};
#pragma endregion

#pragma region regex
	static regex REDUCE("^R\\d{1,2}");
	static regex SHIFT("^S\\d{1,2}");
	static regex ACCEPT("ACC");
	static regex ERROR("^E\\d");
#pragma endregion

	if (charByChar)
	{
		stringIndex = 0;
		col = WORD_CHARS.at(currentWord.at(stringIndex));
	}
	else
	{
		col = WORD_STRINGS.at(currentWord);
	}


	for (int i = 0; i < currentWord.length();)
	{
		row = pop();
		if (row > OFFSET - 1)
		{
			return FAIL;
		}

		tableString = parsingTable[row][col - OFFSET];

		if (regex_match(tableString, REDUCE)) 
		{
			try
			{
				ruleNumber = stoi(tableString.substr(1, tableString.size()));
				_leftRule = RULES.at(ruleNumber).first;
				reduceCol = WORD_STRINGS.at(_leftRule);
				rightRule = RULES.at(ruleNumber).second;
				for (int i = 0; i < (2 * rightRule) - 1; i++)
					traceStack.pop();
				row = pop();
				tableString = parsingTable[row][reduceCol - OFFSET];
				push(row);
				push(reduceCol);
				push(stoi(tableString));
			}
			catch (exception ex)
			{
				if (ruleNumber == 2)
				{
					ruleNumber == 4;
				}
				if (ruleNumber == 3)
				{
					ruleNumber = 6;
				}
				if (ruleNumber == 7)
				{
					ruleNumber = 30;
				}
				_leftRule = RULES.at(ruleNumber).first;
				reduceCol = WORD_STRINGS.at(_leftRule);
				rightRule = RULES.at(ruleNumber).second;
				for (int i = 0; i < (2 * rightRule) - 1; i++)
					traceStack.pop();
				row = pop();
				tableString = parsingTable[row][reduceCol - OFFSET];
				push(row);
				push(reduceCol);
				push(stoi(tableString));
			}
			if (!charByChar)
			{
				return REDUCE_SUCCESS;
			}
		}
		else if (regex_match(tableString, SHIFT))
		{
			tableString = tableString.substr(1, tableString.size());
			push(row);
			push(col);
			push(stoi(tableString));
			if ((charByChar && i == currentWord.length() - 1) || !charByChar)
			{
				return SHIFT_SUCCESS;
			}
			else
			{
				i++;
				col = WORD_CHARS.at(currentWord.at(++stringIndex));
			}
			
		}
		else if (regex_match(tableString, ACCEPT)/* && isProgramPresent && isVarPresent && isBeginPresent && isEndPresent*/)
		{
			return ACCEPT_FINAL;
		}
		else if (regex_match(tableString, ERROR)) 
		{
			tableString = tableString.substr(1, tableString.size());
			ruleNumber = stoi(tableString);
			cout << ERRORS.at(ruleNumber) << endl;
			i = currentWord.length();
		}
		else
		{
			if (!isProgramPresent)
			{
				cout << "'program' is expected." << endl;
			}
			if (!isVarPresent)
			{
				cout << "'var' is expected." << endl;
			}
			if (!isBeginPresent)
			{
				cout << "'begin' is expected." << endl;
			}
			if (!isEndPresent)
			{
				cout << "'end.' is expected." << endl;
			}
			i = currentWord.length();
		}
	}
	return FAIL;
}