#include <iostream>
using namespace std;
#define MAX 100

// HEAP INSERTION

void swap(int&a,int&b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int n , int i) {
    int c1 = 2*i + 1;
    int c2 = 2*i + 2;
    int maxm = i;
    if(c1 < n && arr[c1] > arr[maxm]) {
        maxm = c1;
    }
    if(c2 < n && arr[c2] > arr[maxm]) {
        maxm = c2;
    }

    if(i!=maxm) {
        swap(arr[i],arr[maxm]);
        heapify(arr,n,maxm);
    }
}

void percolateUp(int arr[],int n,int i) {
    int parent = (i-1)/2;
    if(arr[parent] < arr[i]) {
        swap(arr[parent],arr[i]);
        percolateUp(arr,n,parent);
    }
}

void insert(int arr[],int&n,int x) {
    n++;
    arr[n-1] = x;
    percolateUp(arr,n,n-1);
}

//int extractMax(int arr[], int &n) {
//    swap(arr[0],arr[n-1]);
//    n--;
//    heapify(arr,n,0);
//    return arr[n];
//}

void buildHeap(int arr[], int n) {
    for(int i=n/2 ; i>=0 ; i--) {
        heapify(arr,n,i);
    }
}

void print(int arr[], int n) {
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
    cout<<"Enter the length of array:   ";
    cin>>n;
    cout<<"Enter the elements:   ";
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i];
    }

    buildHeap(arr,n);
    print(arr,n);

    //int res = extractMax(arr,n);
    //cout<<"Max:   "<<res<<endl;
    //print(arr,n);
    int x;
    cout<<"Enter the element you want to insert:  ";
    cin>>x;
    insert(arr,n,x);
    print(arr,n);

    return 0;
}