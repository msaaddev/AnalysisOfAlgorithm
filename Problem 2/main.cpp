#include <iostream>
#include <ctime>
#include <random>
using namespace std;

void RandomArray(int array[], int size);
int maximumSubArrayBruteForce(int array[]);

int main()
{
}

void RandomArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand();
}

int maximumSubArrayBruteForce(int array[], int size)
{
    int maxSum = -99999999;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum = sum + array[j];
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}
