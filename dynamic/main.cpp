#include <iostream>
using namespace std;

int count = 0;
int cutRod(int n, int p[]);
int main()
{
}

/*
    Cut Rod recurssive function
*/
int cutRod(int n, int p[])
{
    if (n == 0)
        return 0;
    int q = -999999999;
    for (int i = 0; i < n; i++)
    {
        if (q < (p[i] + cutRod(n - 1, p)))
            q = p[i] + cutRod(n - 1, p);
    }
    return q;
}
