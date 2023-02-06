// bucket sort 2.0     P.S. there's a 1.0 as well

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

    double min = *min_element(arr.begin() , arr.end());
    double max = *max_element(arr.begin() , arr.end());

    double range = (max - min)/n;    

    // sorting the array elements into buckets
    for(int i=0 ; i<arr.size() ; i++) {
        double difference = (arr[i] - min)/range - (int)((arr[i] - min)/range);

        if(difference==0 && arr[i] != min) {
            // for edge cases except for very first range element
            // eg. (0-10) elements  &  range = 4
            // so buckets be ->  (0-2.5) , (2.5-5.0) , (5.0-7.5), (7.5-10.0)
            // obviously extreme elements would not in two buckets
            // (0)/2.5=0   (2.5)/2.5=1  (5.0)/2.5=2  (7.5)/2.5=3  (10)/2.5=4
            // so we will keep the edges elements in the previous i.e; index-1 only
            // if and only if the element is not the first extreme
            buckets[(int)((arr[i]-min)/range) - 1].push_back(arr[i]);
        } else {
            buckets[(int)((arr[i]-min)/range)].push_back(arr[i]);
        }
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

// input   9.8 0.6 10.1 1.9 3.07 3.04 5.0 8.0 4.8 7.68

int main()
{
    vector<double>vec;
    int n;
    cout<<"Enter the size of the array:   ";
    cin>>n;
    vec.resize(n);
    cout<<"Enter the elements (floating point) :   ";
    for(int i=0 ; i<n ; i++) {
        cin>>vec[i];
    }
    printArr(vec,n);
    bucketSort(vec,n);
    cout<<"After sorting:  \n";
    printArr(vec,n);

    return 0;
}