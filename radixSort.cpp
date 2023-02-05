// radix sort
// between 0 and 9

#include <iostream>
using namespace std;
#define RANGE 10
#define MAX 100

void swap(int &a,int &b) {
    int x = a;
    a = b;
    b = x;
}

int getMax(int arr[], int n) {
    int maxm = 0;
    for(int i=0 ; i<n ; i++) {
        maxm = max(arr[i], maxm);
    }

    return maxm;
}

void countingSort(int arr[], int place, int n) {
    int count[RANGE]={0,0,0,0,0,0,0,0,0,0};

    int output[n];

    for(int i=0 ; i<n ; i++) {
        count[(arr[i]/place)%10]++;
    }

    // cummulating
    for(int i=1 ; i<RANGE ; i++) {
        count[i] = count[i-1] + count[i];
    }

    for(int i=n-1 ; i>=0 ; i--) {
        int index = (arr[i]/place)%10;
        int pos = count[index]-1;
        output[pos] = arr[i];
        count[index]--;
    }

    for(int i=0 ; i<n ; i++) {
        arr[i] = output[i];
    }

}

void radixSort(int arr[], int n) {
    int max = getMax(arr,n);

    for(int i=1 ; max/i>0 ; i*=10) {
        countingSort(arr, i, n);
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
    int arr[MAX];
    int n;
    cout<<"Enter the size of the array:   ";
    cin>>n;
    cout<<"Enter the elements :   ";
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i];
    }
    printArr(arr,n);
    radixSort(arr,n);
    cout<<"After sorting:  \n";
    printArr(arr,n);

    return 0;
}