#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

#include "sortMain.h"

// https://www.geeksforgeeks.org/converting-strings-numbers-cc/
// https://www.geeksforgeeks.org/quick-sort/
// https://www.codingbot.net/2013/01/quick-sort-algorithm-and-c-code.html
// https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--

using namespace std;



void sortMain::bubbleSort(double myArray[], int size)
{
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size; ++i)
    {
        int temp = 0;
        for(int j = 0; j < size - 1; ++j)
        {
            if(myArray[j] > myArray[j+1])
            {
                temp = myArray[j+1];
                myArray[j+1] = myArray[j];
                myArray[j] = temp;
            }
        }
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "BubbleSort Elapsed time: " << elapsed.count() << " s\n";


}

void sortMain::selectionSort(double arr[], int size)
{
    auto start = std::chrono::high_resolution_clock::now();
    int i,j,minIndex,tmp;

    for(i = 0; i < size - 1; ++i)
    {
        minIndex = i;
        for(j = i + 1; j < size; ++j)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "SelectionSort Elapsed time: " << elapsed.count() << " s\n";

}

void sortMain::insertSort(double arr[], int size)
{
    auto start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < size; ++j)
    {
        double temp = arr[j];
        int k = j;
        while(k > 0 && arr[k - 1] >= temp)
        {
            arr[k] = arr[k - 1];
            --k;
        }
        arr[k] = temp;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "InsertSort Elapsed time: " << elapsed.count() << " s\n";
}

void sortMain::quickSort(double arr[],int low,int high)
{
    int pivot,j,i;
    double temp;
    if(low < high)
    {
        pivot = low;
        i = low;
        j = high;

        while(i < j)
        {
            while( (arr[i] <= arr[pivot]) && (i<high) )
            {
                i++;
            }

            while(arr[j] > arr[pivot])
            {
                j--;
            }

            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }

}


sortMain::sortMain()
{

}

sortMain::~sortMain()
{

}

void sortMain::printArray(double arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << endl;
    }
}



int main(int argc, char** argv)
{

    //stores command line argument; acts as scanner class from java
    string file_name = argv[1];

    string strand;
    string strand2;
    ifstream infile;
    //enables reading file
    infile.open(file_name);
    //while loop that checks each line of file
    getline(infile, strand);
    int size;
    size = stoi(strand);
    double bubblearray[size];
    double selectarray[size];
    double insertarray[size];
    double quickarray[size];

    double newNum;
    int arrayLength = 0;
    while(infile.peek() != EOF)
    {
        getline(infile, strand2);
        stringstream ss(strand2);
        ss >> newNum;
        // cout << newNum << endl;
        bubblearray[arrayLength] = newNum;
        selectarray[arrayLength] = newNum;
        insertarray[arrayLength] = newNum;
        quickarray[arrayLength] = newNum;



        ++arrayLength;
    }



    sortMain m;

    cout << endl;

    m.bubbleSort(bubblearray, size); //CPU spike for longer period of time
    m.selectionSort(selectarray, size); //CPU spike
    m.insertSort(insertarray,size); //CPU spike

    auto start = std::chrono::high_resolution_clock::now();
    m.quickSort(quickarray, 0, size); //almost no spike in CPU
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "QuickSort Elapsed time: " << elapsed.count() << " s\n";

    cout << endl;

    // m.printArray(insertarray, size);


    return 0;
}
