#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>
using namespace std;
using namespace std::chrono;

/*
A struct to store multiple values which then can be returned from a function at once
*/

struct lowsHighsSum
{
    int low;
    int high;
    int sum;
    int element;
};

/*
    Prototypes of functions used in the program
*/
void randomArray(int array[], int size);
lowsHighsSum maximumSubArrayBruteForce(int array[], int size);
lowsHighsSum maximumCrossingSubArray(int array[], int low, int mid, int high);
lowsHighsSum maximumSubArrayRecursive(int array[], int low, int high);

/*
    Main Function
*/

int main()
{

    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    cout << endl;

    lowsHighsSum bruteForceResult, recursiveSum;
    int *array = new int[size];

    srand(NULL);
    randomArray(array, size);

    auto startRecursive = chrono::high_resolution_clock::now();
    recursiveSum = maximumSubArrayRecursive(array, 0, size);
    auto stopRecursive = chrono::high_resolution_clock::now();

    cout << "Maximum SubArray via Recursive Algo: \n"
         << "Low: " << recursiveSum.low << "\nHigh: " << recursiveSum.high << "\nSum: " << recursiveSum.sum << endl;

    auto timeTakenByRecursiveAlgo = chrono::duration_cast<microseconds>(stopRecursive - startRecursive);
    double millisecond = timeTakenByRecursiveAlgo.count() / 1000;

    cout << "Time taken be recursive algorithm: " << fixed << millisecond << setprecision(5) << " milliseconds" << endl;

    cout << endl;

    auto startBruteForce = chrono::high_resolution_clock::now();
    bruteForceResult = maximumSubArrayBruteForce(array, size);
    auto stopBruteForce = chrono::high_resolution_clock::now();

    cout << "Maximum SubArray via Brute Force Algo: \n"
         << "Low: " << bruteForceResult.low << "\nHigh: " << bruteForceResult.high << "\nSum: " << bruteForceResult.sum << endl;

    auto timeTakenByBruteForce = chrono::duration_cast<microseconds>(stopBruteForce - startBruteForce);
    millisecond = timeTakenByBruteForce.count();
    cout
        << "Time taken be brute force algorithm: " << fixed << millisecond << setprecision(5) << endl;

    delete array;
}

/* Function to insert random numbers in the array */

void randomArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand();
}

/* Function to calculate maximum sum of the sub array using brute force algorithm */

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

/* Function which calculates left and right sum of the array from a particular mid point */

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

/* Function to calculate maximum sum of the sub array using recursive algorithm */

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