/* ==============================================

        Author: Muhammad Saad
        Section: A
        Registration Number: 2018-CS-7
        Programming Language: C++
        Algorithm: Activity Selection
		Approach: Dynamic

=================================================*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void dynamicActivitySelector(int s, int f[], int n);
void printActivities(int **c, int **act, int i, int j);

int main()
{
}

void dynamicActivitySelector(int s[], int f[], int n)
{
	int j, k;
	int **c = new int *[n + 2];
	for (int i = 0; i < n + 2; i++)
		c[i] = new int[i];

	int **act = new int *[n + 2];
	for (int i = 0; i < n + 2; i++)
		act[i] = new int[i];

	for (int i = 0; i < n + 1; i++)
	{
		c[i][i] = 0;
		c[i][i + 1] = 0;
	}

	c[n + 2][n + 2] = 0;

	for (int l = 2; l < n + 2; l++)
	{
		for (int i = 0; i < n - l + 1; i++)
		{
			j = i + l;
			c[i][j] = 0;
			k = j - 1;
			while (f[i] < f[j])
			{
				if ((f[i] <= s[k]) && (f[k] <= s[j]) && (c[i][k] + c[k][j] + 1 > c[i][j]))
				{
					c[i][j] = c[i][k] + c[k][j] + 1;
					act[i][j] = k;
				}
				k = k - 1;
			}
		}
	}
	cout << "A maximum size set of mutually compatible activities has size: " << c[0][n + 2];
	cout << "The set contains ";

	printActivities(c, act, 0, n + 2);
}

void printActivities(int **c, int **act, int i, int j)
{
	int k;
	if (c[i][j] > 0)
	{
		k = act[i][j];
		cout << k;
		printActivities(c, act, i, k);
		printActivities(c, act, k, j);
	}
}
