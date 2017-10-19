#include <iostream>

using namespace std;


typedef struct node{
	char data;
	struct node* left;
	struct node* right;
}node;
node* createRoot(char n){
    node *temp=(node*)(malloc(sizeof(node*)));
    temp->data=n;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}


int arr[26];

bool isOperator(char ch){
	if(ch=='+' || ch=='-')return true;
	return false;
}


void convertExpression(node* root, int mult){
	char ch=root->data;
	if(isOperator(ch)){
		convertExpression(root->left,mult);
		if(ch=='-')mult*=-1;
		convertExpression(root->right,mult);
	}else
		arr[ch-'a']+=mult;	
}
	
int main(){
	for(int i=0;i<26;i++)arr[i]=0;
	node* root=createRoot('+');
	root->left=createRoot('+');
	root->right=createRoot('+');
	root->left->left=createRoot('a');
	root->left->right=createRoot('b');
	root->right->left=createRoot('c');
	root->right->right=createRoot('d');
	convertExpression(root,1);
	for(int i=0;i<26;i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}