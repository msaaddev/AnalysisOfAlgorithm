#include <iostream>
using namespace std;

int count = 0;
int cutRod(int n, int p[]);
int main()
{
}

/*
    Cut Rod Recursive Approach
*/
int cutRod(int n, int p[])
{
    if (n == 0)
        return 0;
    int q = -999999999;
    for (int i = 0; i < n; i++)
    {
        if (q < (p[i] + cutRod(n - i, p)))
            q = p[i] + cutRod(n - i, p);
    }
    return q;
}

/*
    Cut Rod Dynamic Approach
*/
int memoizedCutRod(int p[], int n)
{

    int *r = new int[n];
    for (int i = 0; i < n; i++)
        r[i] = -999999999;
    return memoizedCutRodAux(p, n, r);
}

int memoizedCutRodAux(int p[], int n, int r[])
{
    int q = -999999999;

    if (r[n] >= 0)
        return r[n];
    if (n == 0)
        q = 0;
    else if (q = -999999999)
        for (int i = 0; i < n; i++)
        {
            if (q < (p[i] + memoizedCutRodAux(p, n - i, r)))
                q = p[i] + memoizedCutRodAux(p, n - i, r);
        }
    return q;
}
