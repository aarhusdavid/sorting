#include <iostream>

using namespace std;

class sortMain
{
    public:
        sortMain();
        ~sortMain();

        void bubbleSort(double arr[], int size);
        void selectionSort(double arr[], int size);
        void insertSort(double arr[], int size);
        void quickSort(double arr[],int l,int u);
        void printArray(double arr[], int size);

};
