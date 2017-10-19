#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define ll long long int

using namespace std;


ll merge(int a[],int temp[], int first, int mid, int last){
    ll inversions=0;
    int i=first,j=mid,k=first;
    while(i<mid && j<=last){
        if(a[i]<=a[j])temp[k++]=a[i++];
        else{
            temp[k++]=a[j++];
            inversions+=(mid-i);
        }
    }
    while(i<mid)temp[k++]=a[i++];
    while(j<=last)temp[k++]=a[j++];
    for(int t=first;t<=last;t++)
        a[t]=temp[t];
    return inversions;
}

ll mergeSort(int a[], int temp[],int first, int last){
    ll invert=0;
    if(first<last){
        int mid=(last+first)/2;
        invert+=mergeSort(a,temp,first,mid);
        invert+=mergeSort(a,temp,mid+1,last);
        invert+=merge(a,temp,first,mid+1,last);
    }
    return invert;
}

ll count_inversions(vector<int> a) {
    int *temp=(int *)malloc(a.size()*sizeof(int));
    int ar[a.size()];
    for(int i=0;i<a.size();i++)
        ar[i]=a[i];
    return mergeSort(ar,temp,0,a.size()-1);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}
