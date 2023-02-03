// randomized quick sort
#include <iostream>
#include <cmath>
using namespace std;

void swap(int &a,int &b) {
    int x = a;
    a = b;
    b = x;
}

int partition(int arr[], int l , int r) {
    int random = (rand())%(r-l+1) + l;
    swap(arr[random],arr[r]);
    int pivot = arr[r];
    int i=l-1;
    for(int j=l ; j<=r ; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r) {
    if(l < r) {
        int p = partition(arr, l ,r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
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
    quickSort(arr,0,n-1);
    cout<<"After sorting:  \n";
    printArr(arr,n);

    return 0;
}
