// counting sort
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

void countingSort(int arr[], int n) {
    int frequencies[RANGE];
    for(int i=0 ; i<RANGE ; i++) {
        frequencies[i] = 0;
    }

    for(int i=0 ; i<n ; i++) {
        frequencies[arr[i]]++;
    }
    int cummulative[RANGE];
    cummulative[0] = frequencies[0];
    for(int i=1 ; i<RANGE ; i++) {
        cummulative[i] = cummulative[i-1] + frequencies[i];
    }

    int x = 0;
    for(int i=0 ; i<RANGE ; i++) 
    {
        if(i==0) 
        {
            for(int j=0 ; j<cummulative[0] ; j++) 
            {
                arr[x++] = i;
            }
        } 
        else 
        {
            int num = cummulative[i]-cummulative[i-1];
            for(int j=0 ; j<num ; j++)
            {
                arr[x++] = i;
            }
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
    int arr[MAX];
    int n;
    cout<<"Enter the size of the array:   ";
    cin>>n;
    cout<<"Enter the elements between 0 and 9 :   ";
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i];
    }
    printArr(arr,n);
    countingSort(arr,n);
    cout<<"After sorting:  \n";
    printArr(arr,n);

    return 0;
}