/*
Implement atoi

Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/

/* Intersting note:

#include <limits.h>
int a = <something>;
int x = <something>;
if ((x > 0) && (a > INT_MAX - x)) // `a + x` would overflow
if ((x < 0) && (a < INT_MIN - x)) // `a + x` would underflow
// ... same thing for subtraction, multiplication, and division
*/


#include<iostream>
#include<limits.h>

using namespace std;

int myAtoi(string str) {
	int l=0, num=0, mul=1, signCounter=0;
        bool stopper=false;
        int len=str.size();
        while(l < len && str[l] == ' ') {
                l++;
        }

        while(l < len) {
                if(str[l] >= '0' && str[l] <= '9' && !stopper) {
                        int n = (str[l] - '0');
                        if(num > ((INT_MAX-n)/10))
                                return (mul == 1 ? INT_MAX : INT_MIN);
                        num = num*10 + n;
                        l++;
                 }
                else if(str[l] == '+' || str[l] == '-') {
                        mul = 1 - 2 * (str[l] == '-');
                        signCounter++;
                        if(signCounter>1)
                            return 0;
                        l++;
                }
                else {
                        //return 0;
                        stopper=true;
                        l++;
                }
        }
        return num*mul;
}

int main()
{
string str;
cin >> str;
cout << myAtoi(str) << endl;
return 0;
}
