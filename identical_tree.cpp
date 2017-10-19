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

struct node{
    int data;
    struct node* left;
    struct node* right;
};


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



int checkIdentical(node* t1,node* t2){
    if(t1==t2)
        return 1;
    else if(t1!=NULL && t2!=NULL){
        if( (t1->data==t2->data) && (checkIdentical(t1->left,t2->left)) && (checkIdentical(t1->right,t2->right))){
            return 1;
        }
    }
    return 0;
}



int main(){
    node* root=createRoot(5);
    createNode(root,3);
    createNode(root,4);
    createNode(root,7);
    createNode(root,8);
    createNode(root,6);
    createNode(root,1);
    node* root1=NULL;//createRoot(5);
    // createNode(root1,3);
    // createNode(root1,4);
    // createNode(root1,7);
    // createNode(root1,8);
    // createNode(root1,6);
    // createNode(root1,10);
    int ret_che=checkIdentical(root, root1);
    if(ret_che==1)
        cout << "identical" << "\n";
    else
        cout << "different"<< "\n";
    return 0;
}
