// bucket sort 1.0     P.S. there's a 2.0 as well
// elements within "ra*nge" from "0.0" to 1.0

#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
#define RANGE 10
#define MAX 100

void swap(int &a,int &b) {
    int x = a;
    a = b;
    b = x;
}

void bucketSort(vector<double>&arr, int n) {
    vector<double> buckets[n];

    // sorting the array elements into buckets
    for(int i=0 ; i<arr.size() ; i++) {
        int index = arr[i]*n;
        buckets[index].push_back(arr[i]);
    }

    // sorting the elements within individual buckets
    for(int i=0 ; i<n ; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<buckets[i].size() ; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

void printArr(vector<double> arr,int n) {
    cout<<"[  ";
    for(int i=0 ; i<n ; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<"]"<<endl;
}

// input 0.897 0.565 0.656 0.1234 0.665 0.3434 

int main()
{
    vector<double>vec;
    int n;
    cout<<"Enter the size of the array:   ";
    cin>>n;
    vec.resize(n);
    cout<<"Enter the elements between 0.0 and 1.0 :   ";
    for(int i=0 ; i<n ; i++) {
        cin>>vec[i];
    }
    printArr(vec,n);
    bucketSort(vec,n);
    cout<<"After sorting:  \n";
    printArr(vec,n);

    return 0;
}