// insertion sort
#include <iostream>
using namespace std;

void swap(int &a,int &b) {
    int x = a;
    a = b;
    b = x;
}

void selectionSort(int arr[], int n) {
    for(int i=0 ; i<n-1 ; i++) {
        int min_idx = i;
        for(int j=i+1 ; j<n ; j++) {
            if(arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        if(i!= min_idx) {
            swap(arr[i],arr[min_idx]);
        }
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
    selectionSort(arr,n);
    cout<<"After sorting:  \n";
    printArr(arr,n);

    return 0;
}