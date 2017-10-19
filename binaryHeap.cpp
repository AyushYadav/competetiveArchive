#include <iostream>

using namespace std;

class Heap{
	int *harr;	// array to hold the MinHeap
	int cap; 	// stores the capacity of the heap i.e. max size of the heap array
	int size; 	// points to the index of the last element in the heap
public:
	Heap(int capacity);
	void heapify(int);
	void swap(int i, int j){
		int temp=harr[i];
		harr[i]=harr[j];
		harr[j]=temp;
	};
	void insertHeap(int);
	int leftChild(int i){return 2*i;}
	int rightChild(int i){return (2*i)+1;}
	int parent(int i){
		if(i%2==0)return i/2;
		else return (i-1)/2;
	}
	int min(){return harr[1];}
	int popMin(){
		int tmp=harr[1];
		harr[1]=harr[size];
		size--;
		heapify(1);
		return tmp;
	}
};

Heap::Heap(int capacity){
	cap=capacity;
	harr=new int[cap+1];	// Elements are stored and indexed from [1 .. cap]
	size=0;
}

void Heap::insertHeap(int key){
	if(size==cap){
		cout << "Overflow!\n";
		return;
	}
	size++;
	int j=size;
	harr[j]=key;
	int i = parent(size);
	while(i>=1 && harr[j]<harr[i]){
		swap(j,i);
		j=i;
		i=parent(i);
	}
}

void Heap::heapify(int i){
	int l=leftChild(i);
	int r=rightChild(i);
	int smallest=i;
	if(l>size && r >size)return;
	if(l<=size && harr[l]<harr[i])smallest=l;
	if(r<=size && harr[r]<harr[smallest])smallest=r;
	if(smallest!=i){
		swap(smallest,i);
		heapify(smallest);
	}
}

int main(){
	Heap h(10);
	h.insertHeap(3);
	h.insertHeap(2);
	h.insertHeap(4);
	cout << h.min() << " ";
	h.popMin();
	cout << h.min() << " ";
	cout << endl;
 	return 0;
}
