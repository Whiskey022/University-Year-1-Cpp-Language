#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <array>

//library for timing
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    /*int arraySize = 20;
    float array[arraySize] = {2.1, -10.0e-30f * 10.0e-30f, -numeric_limits<double>::max(), 0, nan(""),
                      nan("12"), rand(), 1.1, 1, numeric_limits<double>::max(),
                      2.1, -10.0e-30f * 10.0e-30f, -numeric_limits<double>::max(), 0, nan(""),
                      nan("12"), rand(), 1.1, 1, numeric_limits<double>::max()};*/


    int arraySize = 10000;
    float array[arraySize];
    for(int i=0; i<arraySize; i++)
        array[i] = rand();

    int countFirstLoop = 0;
    int countSecondLoop = 0;
    int countSwaps = 0;


    //start execution timer
    clock_t startcputime = clock();

    //start real world timer
    auto wcts = system_clock::now();

    //Bubble sorting algorithm

    //boolean to check if swap was made
    //breaks the loop when the array is checked and no swaps were made
    bool swapped=true;

    //repeats the loop 'arraySize' times
    //or until no swaps were necessary (array already sorted)

    for (int i=arraySize-1; i>0 && swapped; i--){

        //assign swapped value to false before checking the array values
        swapped = false;

        countFirstLoop++;

        //comparison and swapping loop
        for (int j=0; j<i; j++){

            countSecondLoop++;

            if(array[j]>array[j+1] ||                                 //checks if a value before is bigger than one in front
               (array[j]!=array[j] && array[j+1]==array[j+1])  ||     //checks if it is a NaN and the number in front is not
               //checks if both values are zeros, and then if the first one is positive and the second one is negative
               (array[j]==0.0 && array[j+1]==0 && signbit(array[j])==0 && signbit(array[j+1])==1)){

                countSwaps++;

                //if any of those 3 conditions where true, swap done
                float temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;

                //memorising that the swap was done
                swapped = true;
            }
        }
    }

    //time saved for execution time
    double cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;

    //time saved for real world time
    duration<double> wctduration = (system_clock::now() - wcts);

/*
    //printing out the array
    cout<<"Sorted array: "<<endl;
    for (int i=0; i<arraySize; i++){
        cout<<array[i]<<", ";
    }
    cout<<endl<<endl<<endl;
*/

    cout << "Amount of values: " << arraySize << endl;
    cout << "First for loop counter: " << countFirstLoop << endl;
    cout << "Second for loop counter: " << countSecondLoop << endl;
    cout << "Swaps counter: " << countSwaps << endl << endl;
    cout << "Execution time: " << cpu_duration <<" seconds"<<endl;
    cout << "Real world time: " << wctduration.count() <<" seconds"<<endl;


    return 0;
}
