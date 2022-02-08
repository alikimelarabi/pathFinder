#include <iostream>
#include <string>
#include <cassert>
using namespace std;


// Returns the product of two positive integers, m and n,
// using only repeated addition.
int mult(unsigned int m, unsigned int n)
{
    if (m == 0)
        return 0;
    return n + mult(m-1, n);
}

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
//    countDigit(18838, 8) => 3
//    countDigit(55555, 3) => 0
//    countDigit(0, 0)     => 0
//


int countDigit(int num, int digit)
{
    if (num == 0)
        return 0;
    if (num % 10 == digit)
        return 1 + (countDigit(num / 10, digit));
    return countDigit(num / 10, digit);
}

/*
 Version that returns 1 for the call: countDigits(0,0)
 
int countDigit(int num, int digit)
{
    if (num == 0)
        return 1;
    if (num < 9 && num == digit) return 1;
    if (num < 9) return 0;
    if (num % 10 == digit)
        return 1 + (countDigit(num / 10, digit));
    return countDigit(num / 10, digit);
}
*/

// Returns a string where the same characters next each other in
// string n are separated by "**"
//
// Pseudocode Example:
//    pairStars("goodbye") => "go**odbye"
//    pairStars("yyuu")    => "y**yu**u"
//    pairStars("aaaa")    => "a**a**a**a"
//
string pairStars(string n)
{
    if (n.size() < 2)
        return n;
    // checks if first two characters equal
    if (n.substr(0,1) == n.substr(1,1))
        return n.substr(0,1) + "**" + pairStars(n.substr(1));
    return n.substr(0,1) + pairStars(n.substr(1));
}

// str contains a single pair of parenthesis, return a new string
// made of only the parenthesis and whatever those parensthesis
// contain.
//
//  Pseudocode Example:
//     subBrackets("abc[ghj]789") => "[ghj]"
//     subBrackets("[x]7")        => "[x]"
//     subBrackets("4agh[y]")     => "[y]"
//
string subBrackets(string str)
{
    if (str.empty())
        return str;
    unsigned long lastpos = str.size()-1;
    if (str.substr(0,1) == "[" &&  str.substr(lastpos, 1) == "]")
        return str;
    if (str.substr(0,1) == "[")
        return subBrackets(str.substr(0, str.size()-1));
    if (str.substr(lastpos, 1) == "]")
        return subBrackets(str.substr(1));
    return subBrackets(str.substr(1, str.size()-2));
}

// Return true if the sum of any combination of elements in the array
// a equals the value of the target.
//
//  Pseudocode Example:
//     comboSum([2, 4, 8], 3, 10) => true
//     comboSum([2, 4, 8], 3, 12) => true
//     comboSum([2, 4, 8], 3, 11) => false
//     comboSum([], 0, 0) 		=> true
//
bool comboSum(const int a[], int size, int target)
{
    if ((size == 0) && target == 0)
        return true;
    if (size == 0)
        return false;
    // if the rest of the array returns true then
    // return true, no need to add in first element
    if (comboSum(a+1, size -1, target))
        return true;
    
    // if it's true adding the first element then
    // the rest of the array must equal
    // target - first element
    return (comboSum(a+1, size-1, target - a[0]));
}

// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
	//If the start location is equal to the ending location, then we've
	//	solved the maze, so return true.
	//	Mark the start location as visted.
	//	For each of the four directions,
	//	If the location one step in that direction(from the start
	//		location) is unvisited,
	//	then call pathExists starting from that location(and
	//		ending at the same ending location as in the
	//		current call).
	//	If that returned true,
	//	then return true.
	//	Return false.

	//  If the start location is equal to the ending location, then we've
	//	solved the maze, so return true.
	if (sr == er && sc == ec)
	{
		return true;
	}

	//	Mark the start location as visted.
	maze[sr][sc] = 'V';

	//	For each of the four directions,
	//	If the location one step in that direction(from the start
	//		location) is unvisited,
	//	then call pathExists starting from that location(and
	//		ending at the same ending location as in the
	//		current call).
	//	If that returned true,
	//	then return true.
	// Go down
	if (sr >= 0 && sc >= 0 && sr < nRows - 1 && sc < nCols)
	{
		if (maze[sr + 1][sc] == '.')
		{
			if (pathExists(maze, nRows, nCols, sr + 1, sc, er, ec))
			{
				return true;
			}
		}
	}
	// Go right
	if (sr >= 0 && sc >= 0 && sr < nRows && sc < nCols - 1)
	{
		if (maze[sr][sc + 1] == '.')
		{
			if (pathExists(maze, nRows, nCols, sr, sc + 1, er, ec))
			{
				return true;
			}
		}
	}
	// Go up
	if (sr >= 1 && sc >= 0 && sr < nRows && sc < nCols)
	{
		if (maze[sr - 1][sc] == '.')
		{
			if (pathExists(maze, nRows, nCols, sr - 1, sc, er, ec))
			{
				return true;
			}
		}
	}
	// Go left
	if (sr >= 0 && sc >= 1 && sr < nRows && sc < nCols)
	{
		if (maze[sr][sc - 1] == '.')
		{
			if (pathExists(maze, nRows, nCols, sr, sc - 1, er, ec))
			{
				return true;
			}
		}
	}

	return false;
}