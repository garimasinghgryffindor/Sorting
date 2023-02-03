// merge sort
#include <iostream>
using namespace std;

void swap(int &a,int &b) {
    int x = a;
    a = b;
    b = x;
}

void merge(int arr[],int l,int mid,int r) {
    int leftLen = mid-l+1;
    int rightLen = r-mid;
    int leftSubarray[leftLen], rightSubarray[rightLen];
    for(int i=0 ; i<leftLen ; i++) {
        leftSubarray[i] = arr[i+l];
    }
    for(int i=0 ; i<rightLen ; i++) {
        rightSubarray[i] = arr[mid+i+1]; 
    }

    int i=0 , j=0,k=l;

    while(i<leftLen && j<rightLen) {
        if(leftSubarray[i] <= rightSubarray[j]) {
            arr[k++] = leftSubarray[i++];
        } else {
            arr[k++] = rightSubarray[j++];
        }
    }

    while(i<leftLen) {
        arr[k++] = leftSubarray[i++];
    }
    while(j<rightLen) {
        arr[k++] = rightSubarray[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l >= r)
        return;
    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1 , r);
    merge(arr,l,mid,r);
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
    mergeSort(arr,0,n-1);
    cout<<"After sorting:  \n";
    printArr(arr,n);

    return 0;
}