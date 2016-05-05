/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility) 

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows: 

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". */

#include <iostream>

using namespace std;

string convert(string text, int nRows)
{
	int len = text.size();
	string output = "";
	if(nRows >= len || nRows == 1)
		return text;
	for(int i=0; i < nRows; i++) {
		int run = i;
		output.push_back(text[run]);
		while(true) {
			int p1 = run + (2*nRows - 2) - 2*i;
			if(p1 > len-1)
				break;
			if(i!=0 && i!=(nRows-1))
				output.push_back(text[p1]);
			run = run + (2*nRows - 2);
			if(run > len-1)
				break;
			output.push_back(text[run]);
		}
	}
	return output;
}

int main()
{
	string text;
	int nRows;
	cin >> text;
	cin >> nRows;
	cout << convert(text, nRows);
	return 0;
}
