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
using namespace std;

/* prototypes of functions */

void dynamicActivitySelector(int s[], int f[], int n);
void printActivities(int **c, int **act, int i, int j);

int main()
{
	/* variable declarations */
	int numOfActivities;
	cout << "\nEnter total number of activities: ";
	cin >> numOfActivities;
	int *s = new int[numOfActivities];
	int *f = new int[numOfActivities];

	/* getting input values from user */

	for (int i = 0; i < numOfActivities; i++)
	{
		cout << "\nEnter start time of Activity " << i + 1 << " : ";
		cin >> s[i];

		cout << "Enter finish time of Activity " << i + 1 << " : ";
		cin >> f[i];
	}

	/* executing activity selection using dynamic approach */

	dynamicActivitySelector(s, f, numOfActivities);
}

/**
 *
 *
 * @param {s} – integer array that stores start time of an activity
 * @param {f} - integer array that stores finish time of an activity
 * @param {n} - integer that stores total number of activities
 */

void dynamicActivitySelector(int s[], int f[], int n)
{
	/* variable & 2D dynamic array declaration */
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

	c[n + 1][n + 1] = 0;

	/* calculating scheduled activities */
	for (int l = 2; l < n + 1; l++)
	{
		for (int i = 0; i < n - l + 1; i++)
		{
			j = i + l;
			c[i][j] = 0;
			k = j - 1;
			while (f[i] < f[k])
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
	cout << "\nA maximum size set of mutually compatible activities has size: " << c[0][n + 1];
	cout << "\nThe set contains ";

	printActivities(c, act, 0, n + 1);
}

/**
 *
 *
 * @param {c} – 2d integer array
 * @param {act} - 2d integer array containing the activites
 * @param {i} - starting index
 * @param {j} - ending index
 */

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
