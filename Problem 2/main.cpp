/* ==============================================

        Author: Muhammad Saad
        Section: A
        Registration Number: 2018-CS-7
        Programming Language: C++
        Algorithms: Brute Force, Recursive, Hybrid

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
lowsHighsSum maximumCrossingSubArray(int array[], int low, int mid, int high);
lowsHighsSum maximumSubArrayRecursive(int array[], int low, int high);
lowsHighsSum maxmimmSubArrayHybrid(int array[], int low, int high);

/*
    Main Function
*/

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

    auto startRecursive = chrono::high_resolution_clock::now();

    recursiveSum = maximumSubArrayRecursive(array, 0, size);
    auto stopRecursive = chrono::high_resolution_clock::now();
    double millisecond;

    if (size == 1)
    {
        // Displaying maximum sum of the subarray along with the low and high index values
        cout << "Maximum SubArray via Recursive Algo: \n"
             << "Low: " << recursiveSum.low << "\nHigh: " << recursiveSum.high << "\nElement: " << recursiveSum.element << endl;

        // Calculating the time taken by the recursive algorithm
        auto timeTakenByRecursiveAlgo = chrono::duration_cast<microseconds>(stopRecursive - startRecursive);
        millisecond = timeTakenByRecursiveAlgo.count() / 1000;

        // Displaying the time
        cout << "Time taken be recursive algorithm: " << fixed << millisecond << setprecision(5) << "  milliseconds" << endl;
    }
    else
    {
        // Displaying maximum sum of the subarray along with the low and high index values
        cout << "Maximum SubArray via Recursive Algo: \n"
             << "Low: " << recursiveSum.low << "\nHigh: " << recursiveSum.high << "\nSum: " << recursiveSum.sum << endl;

        // Calculating the time taken by the recursive algorithm
        auto timeTakenByRecursiveAlgo = chrono::duration_cast<microseconds>(stopRecursive - startRecursive);
        double millisecond = timeTakenByRecursiveAlgo.count() / 1000;

        // Displaying the time
        cout << "Time taken be recursive algorithm: " << fixed << millisecond << setprecision(5) << " milliseconds" << endl;
    }

    cout << endl;

    /*
        starting the clock then calling the hybrid function and then stopping the clock to get the time taken.
    */

    auto startHybrid = chrono::high_resolution_clock::now();
    hybridSum = maxmimmSubArrayHybrid(array, 0, size);
    auto stopHybrid = chrono::high_resolution_clock::now();

    // Displaying maximum sum of the subarray along with the low and high index values
    cout << "Maximum SubArray via Hybrid Algo: \n"
         << "Low: " << hybridSum.low << "\nHigh: " << hybridSum.high << "\nSum: " << hybridSum.sum << endl;

    // Calculating the time taken by the Hybrid algorithm
    auto timeTakenByHybridAlgo = chrono::duration_cast<microseconds>(stopHybrid - startHybrid);
    millisecond = timeTakenByHybridAlgo.count() / 1000;

    // Displaying the time
    cout << "Time taken be Hybrid algorithm: " << fixed << millisecond << setprecision(5) << " milliseconds" << endl
         << endl;

    /*
        starting the clock then calling the recursive function and then stopping the clock to get the time taken.
    */
    auto startBruteForce = chrono::high_resolution_clock::now();
    bruteForceResult = maximumSubArrayBruteForce(array, 0, size);
    auto stopBruteForce = chrono::high_resolution_clock::now();

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

/* Function to insert random numbers in the array */

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

/* Function which calculates left and right sum of the array from a particular mid point */

lowsHighsSum maximumCrossingSubArray(int array[], int low, int mid, int high)
{
    lowsHighsSum position; //declaring a lowsHighsSum variable to store low, high and sum value
    int leftSum = -999999999;
    int sum = 0;

    //calculating the sum of the left side of the array
    for (int i = mid; i > low; i--)
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
    //calculating the sum of the right side of the array
    for (int i = mid + 1; i < high; i++)
    {
        sum = sum + array[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            position.high = i;
        }
    }

    // calculating the cross sum
    position.sum = leftSum + rightSum;
    return position;
}

/* Function to calculate maximum sum of the sub array using recursive algorithm */

lowsHighsSum maximumSubArrayRecursive(int array[], int low, int high)
{
    //declaring lowsHighsSum struct variable to store different results
    lowsHighsSum position1, position2, position3, result;

    if (high == low) //returing in case of one element
    {
        result.low = low;
        result.high = high;
        result.element = array[low];
        return result;
    }
    else
    {
        float mid = (low + high) / 2; //finding the mid of the array
        mid = floor(mid);             //flooring it in case of point number

        position1 = maximumSubArrayRecursive(array, low, mid);      //dividing the left side of array
        position2 = maximumSubArrayRecursive(array, mid + 1, high); //dividing the right side of array

        //calculating the cross sum of the divided arrays
        position3 = maximumCrossingSubArray(array, low, mid, high);

        //finding maximum cross sum of the array
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

lowsHighsSum maxmimmSubArrayHybrid(int array[], int low, int high)
{
    if ((high - low) <= 40)
    {
        return maximumSubArrayBruteForce(array, low, high);
    }
    else
    {
        //declaring lowsHighsSum struct variable to store different results
        lowsHighsSum position1, position2, position3;
        float mid = (low + high) / 2; //finding the mid of the array
        mid = floor(mid);             //flooring it in case of point number

        position1 = maxmimmSubArrayHybrid(array, low, mid);      //dividing the left side of array
        position2 = maxmimmSubArrayHybrid(array, mid + 1, high); //dividing the right side of array

        //calculating the cross sum of the divided arrays
        position3 = maximumCrossingSubArray(array, low, mid, high);

        //finding maximum cross sum of the array
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