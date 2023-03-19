#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/* Kurosh Kuchekali
10 September 2022 */

int main() 
{
    //all variables are initialized
    int a, b, c, d, e, g, h, j, k, m, r, n, p, y;
    
    //scans the user's given year
    cout << "Enter Year Here\n";
    cin >> y;

    //runs the algorithm to find the month and day of Easter for the given year
    a = y % 19;
		
	b = y / 100;
	c = y % 100;
		
	d = b / 4;
	e = b % 4;
		
	g = (8 * b + 13) / 25;
		
	h = (19 * a + b - d - g + 15) % 30;
		
	j = c / 4;
	k = c % 4;
		
	m = (a + 11 * h) / 319;
		
	r = (2 * e + 2 * j - k - h + m + 32) % 7;
		
	n = (h - m + r + 90) / 25;
		
	p = (h - m + r + n + 19) % 32;

    //beacause Easter can only happen between March and April
    //there is one condition it checks and if the month does not equal 3
    //then it will be April
    if (n == 3) 
    {
        printf("Easter will be on March %d", p);
    }
    else 
    {
        printf("Easter will be on April %d", p);
    }
    return 0;
}