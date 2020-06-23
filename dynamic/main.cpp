#include <iostream>
using namespace std;

/*
    Function declarations
*/
int recursiveCount = 0;
int dynamicCount = 0;
int max(int a, int b);
int cutRod(int n, int p[]);
int memoizedCutRod(int p[], int n);
int memoizedCutRodAux(int p[], int n, int r[]);

int main()
{
    // variable declaration
    int p[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int num;

    // value for the length of rod
    cout << "What length of rod do you need. Enter from 1 to 10: ";
    cin >> num;

    // recursive function called
    cout << "\nRecursive" << endl;
    cout << "Price of " << num << " pieces should be: " << cutRod(num, p) << endl;
    cout << "Number of times recursive cut rod function called: " << recursiveCount;

    cout << "\n\nDynamic Function" << endl;
    cout << "Price of " << num << " pieces should be: " << memoizedCutRod(p, num) << endl;
    cout << "Number of times dynamic cut rod function called: " << dynamicCount;
}

/*
    Max function
*/
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
/*
    Cut Rod Recursive Approach
*/
int cutRod(int n, int p[])
{
    recursiveCount++;
    int q = -999999999;
    if (n == 0)
        return 0;
    for (int i = 0; i < n; i++)
        q = max(q, (p[i] + cutRod(n - i - 1, p)));
    return q;
}

/*
    Cut Rod Dynamic Approach
*/
int memoizedCutRod(int p[], int n)
{

    int *r = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
        r[i] = -999999999;
    return memoizedCutRodAux(p, n, r);
}

int memoizedCutRodAux(int p[], int n, int r[])
{
    dynamicCount++;
    int q = -999999999;

    if (r[n] >= 0)
        return r[n];
    if (n == 0)
        q = 0;
    else
        for (int i = 0; i < n; i++)
            q = max(q, (p[i] + memoizedCutRodAux(p, n - i - 1, r)));
    r[n] = q;
    return q;
}
