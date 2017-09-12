// Member Names:
// Alexander Edgar
// Daniel Domingo
// Sean Wulwick

int main() {
	char reservedWords[4][10] = { "cout<<", "for", "int", "while" };
	char special[8][3] = { "=", "*", "-", ";", "(", ")", "<=", "+" };
	regex expr("(.*?)(?:\s|$)"); //Anything followed by a space or endline
	while(1) {
		cout << "Continue(y/n)?";
		char c;
		cin >> c;
		cin.ignore();
		if(c != 'y' && c != 'Y') { break; }
	}
	return 0;
}
