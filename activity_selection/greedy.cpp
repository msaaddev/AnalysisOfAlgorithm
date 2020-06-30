/* ==============================================

        Author: Muhammad Saad
        Section: A
        Registration Number: 2018-CS-7
        Programming Language: C++
        Algorithm: Activity Selection
		Approach: Greedy

=================================================*/

#include <iostream>
#include <string>
using namespace std;

/* A struct to store result */

struct result
{
	string *arr;
	int size;
};

/* prototype of function */

result greedyActivitySelection(int s[], int f[], string act[], int size);

int main()
{
	/* varaible declarations */
	int numOfActivities;
	cout << "Enter total number of activities: ";
	cin >> numOfActivities;
	int *s = new int[numOfActivities];
	int *f = new int[numOfActivities];
	string *act = new string[numOfActivities];
	string *scheduleAct;
	result r;

	/* Activity information */

	for (int i = 0; i < numOfActivities; i++)
	{
		cout << "\nEnter name of Activity " << i + 1 << " : ";
		cin >> act[i];

		cout << "Enter start time of Activity " << i + 1 << " : ";
		cin >> s[i];

		cout << "Enter finish time of Activity " << i + 1 << " : ";
		cin >> f[i];
	}

	r = greedyActivitySelection(s, f, act, numOfActivities);

	/* printing the activites */

	cout << "\nScheduled Activities: ";
	for (int i = 0; i < r.size; i++)
	{
		cout << r.arr[i] << " ";
	}
}

/**
 *
 *
 * @param {s} – integer array that stores start time of an activity
 * @param {f} - integer array that stores finish time of an activity
 * @param {act} - string array that stores name of the activities
 * @param {size} - integer that stores total number of activities
 * @return {r} - instance of result struct that stores pointers of scheduled activities and size
 */

result greedyActivitySelection(int s[], int f[], string act[], int size)
{
	/* declaration of variables */
	result r;
	string *scheduledAct = new string[size];
	scheduledAct[0] = act[0];
	int k = 1, i = 1;

	/* calculating scheduled activities */
	for (int m = 2; m < size; m++)
		if (s[m] > f[k])
		{
			scheduledAct[i] = act[m];
			i++;
			k = m;
		}

	r.arr = scheduledAct;
	r.size = i;
	return r;
}
