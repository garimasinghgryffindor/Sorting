// bubble sort
#include <iostream>
using namespace std;

void swap(int &a,int &b) {
    int x = a;
    a = b;
    b = x;
}

void bubbleSort(int arr[], int n) {
    for(int i=0 ; i<n-1 ; i++) {
        for(int j=0 ; j<n-i-1 ; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void printArr(int arr[], int n) {
    cout<<"[  ";
    for(int i=0 ; i<n ; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<"]"<<endl;
}

int main() {
    int arr[100];
    int n;
    cout<<"Enter the size of the array:   ";
    cin>>n;
    cout<<"Enter the elements:   ";
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i];
    }
    printArr(arr,n);
    bubbleSort(arr,n);
    cout<<"After sorting:  \n";
    printArr(arr,n);

    return 0;
}