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

struct result
{
	char **ptrOfFirstArr;
	int **ptrOfSecondArr;
};

result lcsLength(string x, string y);
void printLCS(char **b, string x, int i, int j);

int main()
{
	string str1, str2;
	result r;
	cout << "Enter First String : ";
	cin >> str1;
	cout << "Enter Second String : ";
	cin >> str2;
	int i = str1.length();
	int j = str2.length();
	r = lcsLength(str1, str2);
	printLCS(r.ptrOfFirstArr, str1, i - 1, j - 1);
}

result lcsLength(string x, string y)
{
	int lenOfX = x.length();
	int lenOfY = y.length();

	char **firstArr = new char *[lenOfX];
	for (int i = 0; i < lenOfX; ++i)
		firstArr[i] = new char[lenOfY];

	int **secondArr = new int *[lenOfX + 1];
	for (int i = 0; i < lenOfX + 1; i++)
		secondArr[i] = new int[lenOfY + 1];

	for (int i = 0; i <= lenOfX; i++)
		secondArr[i][0] = 0;
	for (int i = 0; i <= lenOfY + 1; i++)
		secondArr[0][i] = 0;

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

	result r;
	r.ptrOfFirstArr = firstArr;
	r.ptrOfSecondArr = secondArr;
	return r;
}

void printLCS(char **b, string x, int i, int j)
{
	if (i == -1 || j == -1)
		return;
	if (b[i][j] == 'd')
	{
		printLCS(b, x, i - 1, j - 1);
		cout << x[i];
	}
	else if (b[i][j] == 't')
		printLCS(b, x, i - 1, j);
	else
		printLCS(b, x, i, j - 1);
}
