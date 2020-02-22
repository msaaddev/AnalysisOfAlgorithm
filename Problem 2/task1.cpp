/* ==============================================

        Author: Muhammad Saad
        Section: A
        Registration Number: 2018-CS-7
        Programming Language: C++
        Algorithms: Brute Force

=================================================*/

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
    int low = 0;
    int high = 0;
    int sum = 0;
    int element = 0;
};

/*
    Prototypes of functions used in the program
*/
void insertRandomValues(int array[], int size);
lowsHighsSum maximumSubArrayBruteForce(int array[], int low, int high);

int main()
{
    system("cls");
    // getting the size of the array from user and creating a dynamic array
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    cout << endl;
    int *array = new int[size];

    //declare a struct for storing brute force, recrusive, hybrid alogirthm results
    lowsHighsSum bruteForceResult, recursiveSum, hybridSum;

    //storing random values in the array
    srand(NULL);
    insertRandomValues(array, size);

    /*
        starting the clock then calling the recursive function and then stopping the clock to get the time taken.
    */
    auto startBruteForce = chrono::high_resolution_clock::now();
    bruteForceResult = maximumSubArrayBruteForce(array, 0, size);
    auto stopBruteForce = chrono::high_resolution_clock::now();
    double millisecond;

    if (size == 1)
    {
        // Displaying maximum sum of the subarray along with the low and high index values
        cout << "Maximum SubArray via Brute Force Algo: \n"
             << "Low: " << bruteForceResult.low << "\nHigh: " << bruteForceResult.high << "\nElement: " << bruteForceResult.element << endl;

        // Calculating the time taken by the brute force algorithm
        auto timeTakenByBruteForce = chrono::duration_cast<microseconds>(stopBruteForce - startBruteForce);
        millisecond = timeTakenByBruteForce.count() / 1000;

        // Displaying the time
        cout << "Time taken be brute force algorithm: " << fixed << millisecond << setprecision(5) << " milliseconds" << endl;
    }
    else
    {
        // Displaying maximum sum of the subarray along with the low and high index values
        cout << "Maximum SubArray via Brute Force Algo: \n"
             << "Low: " << bruteForceResult.low << "\nHigh: " << bruteForceResult.high << "\nSum: " << bruteForceResult.sum << endl;

        // Calculating the time taken by the brute force algorithm
        auto timeTakenByBruteForce = chrono::duration_cast<microseconds>(stopBruteForce - startBruteForce);
        millisecond = timeTakenByBruteForce.count() / 1000;

        // Displaying the time
        cout << "Time taken be brute force algorithm: " << fixed << millisecond << setprecision(5) << " milliseconds" << endl
             << endl;
    }

    // deleteing the array
    delete[] array;
}

void insertRandomValues(int array[], int size)
{
    std::random_device r;
    std::mt19937 eng(r());

    std::uniform_int_distribution<int> dist(-500, 500);

    for (int i = 0; i < size; i++)
    {
        array[i] = dist(eng);
    }
}

/* Function to calculate maximum sum of the sub array using brute force algorithm */

lowsHighsSum maximumSubArrayBruteForce(int array[], int low, int high)
{
    lowsHighsSum result; //declaring the lowsHighsSum struct variable to store result
    int size = high - low;
    int maxSum = -99999999;

    // finding the maximum sum and the indexes at which it lies
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

