#include "stdc++.h"
using namespace std;

int main() {
	int t;
	cin >>t;
	while(t--){
	    int n1,n2;

	    cin >> n1 >> n2;
	    string s1,s2;
	    cin >> s1;
	    cin >> s2;
	    sort(s1.begin(),s1.end());
	    sort(s2.begin(),s2.end());
	    int i1=0,i2=0;
	    string ans="";
	    while(i1<n1 && i2<n2){
	        if(s1[i1]==s2[i2]){
	            ans+=s1[i1];
	            i1++;
	            i2++;
	        }
	        else if(s1[i1]<s2[i2])i1++;
	        else if(s1[i1]>s2[i2])i2++;
	    }
	    cout << ans << endl;
	}
	return 0;
}


/*

http://www.practice.geeksforgeeks.org/problem-page.php?pid=700351#show-last-Point
 Tree node structure  used in the program
 struct Node
 {
     int data;
     struct Node* left, *right;
};

bool isBST(Node *root){
    static Node* prev=NULL;
    if(root){
        if(!isBST(root->left))return false;
        if(prev && prev->data>=root->data)return false;
        prev=root;
        return isBST(root->right);
    }
    return true;
}

int sizeTree(Node* root){
    if(root==NULL)return 0;
    return 1+sizeTree(root->left)+sizeTree(root->right);
}
void printInOrder(Node* root){
    if(root==NULL)return;
    printInOrder(root->left);
    cout << root->data << "-" ;
    printInOrder(root->right);
}

int largestBst(Node *root){
	// printInOrder(root);
	if(isBST(root))return sizeTree(root);
	return max(largestBst(root->left),largestBst(root->right));
}

*/


