/* ==============================================

        Author: Muhammad Saad
        Section: A
        Registration Number: 2018-CS-7
        Programming Language: C++
        Algorithm: Longest Common Subsequence

=================================================*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
 * struct to get multiple values from function
 */

struct result
{
	char **ptrOfFirstArr;
	int **ptrOfSecondArr;
};

/*
 * prototype of functions
 */

result lcsLength(string x, string y);
void printLCS(char **b, string x, int i, int j);

int main()
{
	// declaring two strings and two integers
	string firstString, secondString;
	int i, j;
	result r;
	cout << "Enter any string: ";
	cin >> firstString;
	cout << "Enter another string : ";
	cin >> secondString;

	// storing length of both strings
	i = firstString.length();
	j = secondString.length();

	// getting length of longest subsequence
	r = lcsLength(firstString, secondString);

	// printing longest subsequence
	cout << "\nLongest Common Subsequence: ";
	printLCS(r.ptrOfFirstArr, firstString, i - 1, j - 1);
}

/**
 *
 *
 * @param {x} – string
 * @param {y} - string
 * @return {r} - instance of result struct that stores pointers of dynamic array
 */

result lcsLength(string x, string y)
{
	// length of strings
	int lenOfX = x.length();
	int lenOfY = y.length();

	// creating a 2D array
	char **firstArr = new char *[lenOfX];
	for (int i = 0; i < lenOfX; ++i)
		firstArr[i] = new char[lenOfY];

	int **secondArr = new int *[lenOfX + 1];
	for (int i = 0; i < lenOfX + 1; i++)
		secondArr[i] = new int[lenOfY + 1];

	// filling the array with 0
	for (int i = 0; i <= lenOfX; i++)
		secondArr[i][0] = 0;
	for (int i = 0; i <= lenOfY + 1; i++)
		secondArr[0][i] = 0;

	// finding the length of longest common subsequence
	for (int i = 1; i <= lenOfX; i++)
	{
		for (int j = 1; j <= lenOfY; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				secondArr[i][j] = secondArr[i - 1][j - 1] + 1;
				firstArr[i - 1][j - 1] = 'd';
			}
			else if (secondArr[i - 1][j] >= secondArr[i][j - 1])
			{
				secondArr[i][j] = secondArr[i - 1][j];
				firstArr[i - 1][j - 1] = 't';
			}
			else
			{
				secondArr[i][j] = secondArr[i][j - 1];
				firstArr[i - 1][j - 1] = 'l';
			}
		}
	}

	// storing the result in the instance of result struct
	result r;
	r.ptrOfFirstArr = firstArr;
	r.ptrOfSecondArr = secondArr;
	return r;
}

/**
 *
 *
 * @param {b} – char double pointer
 * @param {x} - string
 * @param {i} - length of first input string
 * @param {j} - length of second input string
 */

void printLCS(char **b, string x, int i, int j)
{
	// return if strings are empty
	if (i == -1 || j == -1)
		return;

	// calling & printing recusively printLCS if found diagonal
	if (b[i][j] == 'd')
	{
		printLCS(b, x, i - 1, j - 1);
		cout << x[i];
	}
	// calling recusively printLCS if found top
	else if (b[i][j] == 't')
		printLCS(b, x, i - 1, j);

	// calling & printing recusively printLCS if found top
	else
		printLCS(b, x, i, j - 1);
}
