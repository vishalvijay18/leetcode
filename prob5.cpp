/*Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.*/

//Note: There are 2 ways to solve this problem.
//1. Using DP, but it will require O(n2) space.
//2. Using expandAtMiddle approach, as with this we don't require extra space.

#include <iostream>

using namespace std;

int expandAtMiddle(string s, int start, int end)
{ 
        while(start >= 0 && end < s.size() && s[start] == s[end]) {
                start--;
                end++;
        }

        return end - start - 1;
}

string longestPalindrome(string s)
{
	int maxLen=0;
	string palindrome;

	for(int i=0; i < s.size(); i++) {
		int len1 = expandAtMiddle(s,i,i);
		int len2 = expandAtMiddle(s,i,i+1);
		int bigLen = (len1 >= len2 ? len1 : len2);
		if(bigLen > maxLen) {
			maxLen = bigLen;
			if(bigLen%2 != 0) {	
				cout << (i-(bigLen/2)) << " " << bigLen << endl;
				palindrome = s.substr(i-(bigLen/2), bigLen);	
			}
			else {
				cout << (i-((bigLen-1)/2)) << " " << bigLen << endl;
				palindrome = s.substr(i-((bigLen-1)/2), bigLen);
			}
		}	
	}

	return palindrome;
}

int main()
{
	string input;
	cin >> input;
	cout << input << endl;
	cout << longestPalindrome(input) << endl;	
	return 0;
}
