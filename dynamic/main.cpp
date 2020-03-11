#include <iostream>
using namespace std;

int count = 0;
int cutRod(int n, int p[]);
int main()
{
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

    int *r = new int[n];
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

    else if (q = -999999999)
        for (int i = 0; i < n; i++)
            q = max(q, (p[i] + memoizedCutRodAux(p, n - i - 1, r)));

    r[n] = q;
    return q;
}
