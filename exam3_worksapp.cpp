#include <iostream>
#include <cmath>
#include <set>

using namespace std;


/*
Bugs: If any of the input matrix is equal then the program fails to converge to a solution 
The problem is perceivable NP-Hard and hence optimal solution is the brute force
*/



void min_bit_length(string full_str_array[],int arr[], int n, int r, int index,int data[], int i,int K);
int convert_number(int data[],string full_str,int len);
int min_pix(int data[],string full_str_array[], int n, int r, int K, int len);

int main(){
    int N, M, K;
    cin >> N >> M >> K;  
    if(K==2){
        cout << "1" << endl;
        return 0;
    }    
    string full_str_array[10];
    string full_str = "";
    string row = "";

    // Taking the input and convering the Matrix into a array by appending as string

    for(int j = 0;j < K;j++){
        full_str = "";
        for(int i = 0;i < N;i++){   // Taking the input
            cin >> row ;
            full_str+=row;
        }
        full_str_array[j] = full_str;
    }

    int lower_bound = (int)(ceil(log(K)));  // the lower bound on the number of bits required
    int upper_bound = K - 1;    // Upper bound on the number of bits required


    int arr[100];
    for(int i = 0;i < (N*M);i++){
        arr[i] = i; 
    }
    for(int r = lower_bound;r <= upper_bound;r++){ // checking for all combinations from lower to upper bound
        int data[r];
        min_bit_length(full_str_array, arr, N*M, r, 0, data, 0, K); // prints the minimum no of bits req
    }
    return 0;
}

void min_bit_length(string full_str_array[],int arr[], int n, int r, int index,int data[], int i,int K){
    if (index == r){
        int set_size = min_pix(data, full_str_array,n, r, K, r);
        if(set_size == K) { // is the set has no repetitions then we found our solution 
            cout << r << endl;  
            exit(0);
        }
        return;
    }
    if (i >= n) 
        return;
    data[index] = arr[i];
    min_bit_length(full_str_array,arr, n, r, index+1, data, i+1, K); // call recursively on the current and excluding the current
    min_bit_length(full_str_array,arr, n, r, index, data, i+1, K);
}



int min_pix(int data[],string full_str_array[], int n, int r, int K, int len){
    set<int> set_of_number; // set to store the values for the current bits
    for(int i = 0;i < K;i++){
        int number = convert_number(data,full_str_array[i], len);   // convert the given bits to their decimal base 10 representation
        set_of_number.insert(number); // insert in the set
    }
    int set_size = set_of_number.size();    // calculate the size of the set and return 
    return set_size;    
}


int convert_number(int data[],string full_str,int len){ // converts the given binary to its integer base
    int number = 0;
    int power_of_two = 1;
    for(int i=0;i<len;i++){
        if(full_str[data[i]]=='1') number+=1*power_of_two;
        else number+=0*power_of_two;
        power_of_two*=2;  
    }
    return number;
}


