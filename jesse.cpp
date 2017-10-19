#include "iostream"
#include "climits"

using namespace std;

class MinHeap{
    int cap;
    int size;
    int *harr;
public:
    MinHeap(int capacity);

    int parent(int i){
        if(i%2==0)return i/2;
        else return ((i-1)/2);
    }

    int rightChild(int i){return ((2*i)+1);}

    int leftChild(int i){return (2*i);}

    void insert(int i);

    int getMin(){return harr[1];}

    void popMin();

    void swap(int i, int j){
        int t=harr[i];
        harr[i]=harr[j];
        harr[j]=t;
    }

    void heapfy(int i);
};

MinHeap::MinHeap(int capacity){
    cap=capacity;
    size=0;
    harr=new int[cap];
}

void MinHeap::insert(int i){
    if(size==cap){
        //cout<<"Heap Full\n";
        return;
    }
    size++;
    harr[size]=i;
    i=size;
    while(i>1 && harr[i]<harr[parent(i)]){
        swap(i,parent(i));
        i=parent(i);
    }   
}

void MinHeap::heapfy(int i){
    int l=leftChild(i);
    int r=rightChild(i);
    int s=i;
    if(l>size && r>size) return;
    if(harr[i]<harr[l] && harr[i]<harr[r])return;
    if(harr[l]<harr[r] && harr[l]<harr[i])s=l;
    else s=r;
    swap(s,i);
    heapfy(s);
}

void MinHeap::popMin(){
    harr[1]=harr[size];
    size--; 
    heapfy(1);
}

int main(){
    int n,k;
    cin >> n >> k;
    MinHeap h(n);
    for(int i=0;i<n;i++){
        int x=0;
        cin >> x;
        h.insert(x);
    }
    int flag=0;
    int steps=0;
    int j=0;
    while((flag==0) && (j<(n-1))){
        int e=h.getMin();
        if(e<k){
            h.popMin();
            int f=h.getMin();
            h.popMin();
            f=(2*f)+e;
            steps++;
            j++;
            h.insert(f);
            
            
        }else{
            flag=1;
            break;
        }


    }
    
    if(flag==1)
        cout << steps; 
    else{
        // h.popMin();
        // h.popMin();
        // cout <<  steps <<"\n";
        int t=h.getMin();
        h.popMin();
        int te=h.getMin();
        te=t+(2*te);
        // cout << t << "\n"; 
        // h.popMin();
        // h.popMin();
        
        // t=h.getMin();
        // cout << t << "\n"; 
        // cout << t << "\n";  
        if(te>=k){
           cout << steps;
        }else
            cout << -1;
    
       
           // cout << -1;
       // else cout << steps;
    }
    
    return 0;
    
}
//Works Fine
