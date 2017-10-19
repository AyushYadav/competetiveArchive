#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

int ccount1=0;
int ccount2=0;
bool compare(int a,int b){ccount1++; return a>b?true:false;}

void insertionSort(int arr[], int n){
   int i, key, j;
   for (i = 1; i < n; i++){
       key = arr[i];
       j = i-1;
       while (j >= 0 && compare(arr[j],key)){
       		ccount2++;
           	arr[j+1] = arr[j];
           	j = j-1;
       	}
		arr[j+1] = key;
   	}
}

void printArray(int arr[], int n){
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

int main(){
	int t;
	cin >> t;
	for(int p=1;p<=t;p++){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0;i<n;i++)cin >> arr[i];
		insertionSort(arr, n);
		cout << ccount1 << " " << ccount2 << endl;
		cout << (ccount1-ccount2) << endl;
		ccount1=0;
		ccount2=0;
	}
	return 0;
}