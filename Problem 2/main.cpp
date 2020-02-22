#include <iostream>
#include <chrono>
#include <random>
using namespace std;

struct lowsHighsSum
{
    int low;
    int high;
    int sum;
    int element;
};

void randomArray(int array[], int size);
lowsHighsSum maximumSubArrayBruteForce(int array[], int size);
lowsHighsSum maximumCrossingSubArray(int array[], int low, int mid, int high);
lowsHighsSum maximumSubArrayRecursive(int array[], int low, int high);

int main()
{
    const int size = 1000000;
    lowsHighsSum bruteForceResult, recursiveSum;
    int *array = new int[size];

    randomArray(array, size);

    recursiveSum = maximumSubArrayRecursive(array, 0, size);
    cout << "Maximum SubArray via Recursive Algo: \n"
         << "Low: " << recursiveSum.low << "\nHigh: " << recursiveSum.high << "\nSum: " << recursiveSum.sum;

    cout << endl;

    bruteForceResult = maximumSubArrayBruteForce(array, size);

    cout << "Maximum SubArray via Brute Force Algo: \n"
         << "Low: " << bruteForceResult.low << "\nHigh: " << bruteForceResult.high << "\nSum: " << bruteForceResult.sum;
}

void randomArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand();
}

lowsHighsSum maximumSubArrayBruteForce(int array[], int size)
{
    lowsHighsSum result;
    int maxSum = -99999999;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum = sum + array[j];
            if (sum > maxSum)
            {
                maxSum = sum;
                result.low = i;
                result.high = j;
            }
        }
    }
    result.sum = maxSum;
    return result;
}

lowsHighsSum maximumCrossingSubArray(int array[], int low, int mid, int high)
{
    lowsHighsSum position;
    int leftSum = -999999999;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + array[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            position.low = i;
        }
    }

    int rightSum = -99999999;
    sum = 0;
    for (int i = mid + 1; i < high; i++)
    {
        sum = sum + array[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            position.high = i;
        }
    }

    position.sum = leftSum + rightSum;
    return position;
}

lowsHighsSum maximumSubArrayRecursive(int array[], int low, int high)
{
    lowsHighsSum position1, position2, position3, result;

    if (high == low)
    {
        result.low = low;
        result.high = high;
        result.element = array[low];
        return result;
    }
    else
    {
        int mid = (low + high) / 2;
        mid = floor(mid);

        position1 = maximumSubArrayRecursive(array, low, mid);
        position2 = maximumSubArrayRecursive(array, mid + 1, high);
        position3 = maximumCrossingSubArray(array, low, mid, high);

        if ((position1.sum >= position2.sum) && (position1.sum >= position3.sum))
        {
            return position1;
        }
        else if ((position2.sum >= position1.sum) && (position2.sum >= position3.sum))
        {
            return position2;
        }
        else
        {
            return position3;
        }
    }
}