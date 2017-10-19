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

using namespace std;


typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

node* newNode(int data){
	node* temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void insertBST(node* root,int data){
	if(root==NULL)return;
	node* temp=newNode(data);
	while(root!=NULL){
		if(root->data<data){
			if(root->right==NULL){
				root->right=temp;
				break;
			}else root=root->right;
		}else{
			if(root->left==NULL){
				root->left=temp;
				break;
			}
			else root=root->left;
		}
	}
}

void Inorder(node* root){
	if(root==NULL)return;
	Inorder(root->left);
	cout << root->data << "--" ;
	Inorder(root->right);
}

int heightTree(node* root){
	if(root==NULL)return 0;
	int lheight=heightTree(root->left);
	int rheight=heightTree(root->right);
	return lheight>=rheight?lheight+1:rheight+1;
}

void printLevel(node* root, int h){
	if(root==NULL)return;
	if(h==1 && root){
		cout << root->data << "--";
		return;
	}
	printLevel(root->left,h-1);
	printLevel(root->right,h-1);

}

void LevelOrder(node* root){
	if(root==NULL)return;
	int height=heightTree(root);
	for(int i=1;i<=height;i++){
		cout << "Level :" << i << "-->> ";
		printLevel(root,i);
		cout << "|" <<endl;

	}
}


int main(){
	node* ref=newNode(4);
	ref->left=newNode(2);
	ref->right=newNode(5);
	insertBST(ref,1);
	insertBST(ref,3);
	insertBST(ref,6);
	insertBST(ref,7);
	Inorder(ref);
	cout << "|\n";
	LevelOrder(ref);
	cout << "|\n";
	return 0;
}