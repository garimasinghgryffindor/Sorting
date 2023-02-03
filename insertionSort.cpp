// insertion sort
#include <iostream>
using namespace std;

void swap(int &a,int &b) {
    int x = a;
    a = b;
    b = x;
}

void insertionSort(int arr[], int n) {
    for(int i=1 ; i<n ; i++) {
        int j=i-1;
        int key = arr[i];
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArr(int arr[],int n) {
    cout<<"[  ";
    for(int i=0 ; i<n ; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<"]"<<endl;
}

int main()
{
    int arr[100];
    int n;
    cout<<"Enter the size of the array:   ";
    cin>>n;
    cout<<"Enter the elements:   ";
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i];
    }
    printArr(arr,n);
    insertionSort(arr,n);
    cout<<"After sorting:  \n";
    printArr(arr,n);

    return 0;
}