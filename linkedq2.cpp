
int maxElement(vector < int > arr) {
    
    int n= arr.size();
    sort(arr.begin(),arr.end());
    cout<<" sadsa"<<endl;
    int mini = arr[0]*arr[1];
    int i=n-1;
    while(arr[i]>=mini){      
        for(int j=0; j<i-1;j++){
            if(!arr[i]%arr[j]){
                int e = arr[i]/arr[j];
                cout<<e<<endl;
                if(binary_search(arr.begin(),arr.end(),e)){
                    return arr[i];
                }
            }
        }
        i--;
    }
    
    return -1;
}
