// #include <map>
// #include <set>
// #include <list>
// #include <cmath>
// #include <ctime>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <string>
// #include <bitset>
#include <cstdio>
// #include <limits>
// #include <vector>
// #include <climits>
// #include <cstring>
#include <cstdlib>
// #include <fstream>
// #include <numeric>
// #include <sstream>
#include <iostream>
// #include <algorithm>
// #include <unordered_map>

using namespace std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;


//Creating a new node and putting it in the Binary search tree
//inp-- n
//root-- the root of the tree to be used for value storage
node* createRoot(int n){
    node *temp=(node*)(malloc(sizeof(node*)));
    temp->data=n;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

void createNode(node* root, int n){
    node *temp=(node*)(malloc(sizeof(node*)));
    temp->data=n;
    temp->right=NULL;
    temp->left=NULL;
    while(root){
        if(n<=root->data){
            if(root->left)
                root=root->left;
            else{
                root->left=temp;
                break;
            }
        }
        else{
            if(root->right)
                root=root->right;
            else{
                root->right=temp;
                break;
            }
        }
    }

}


void mirrorTree(node* root){
    if(root==NULL)
        return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    node* temp=root->left;
    root->left=root->right;
    root->right=temp;

}

void printTree(node* root){
    if(root==NULL)
        return;
    else{
        cout << root->data << "--";
        printTree(root->left);
        printTree(root->right);
    }    
}




int main(){
    node* root=createRoot(5);
    createNode(root,3);
    createNode(root,4);
    createNode(root,7);
    createNode(root,8);
    createNode(root,6);
    createNode(root,1);
    printTree(root);
    cout << "\n";
    mirrorTree(root);
    printTree(root);
    cout << "\n";
    return 1;

}