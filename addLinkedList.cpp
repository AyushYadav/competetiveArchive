#include <iostream>

using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node* createHead(int key){
	node* temp=(node*)malloc(sizeof(node));
	temp->data=key;
	temp->next=NULL;
	return temp;
}
node* push(node** head_ref, int key){
	node* head=*head_ref;
	node* temp=(node*)malloc(sizeof(node));
	temp->data=key;
	temp->next=head;
	*head_ref=temp;
	return *head_ref;
} 
void printList(node* head_ref){
	while(head_ref!=NULL){
		cout << head_ref->data << " ";
		head_ref=head_ref->next;
	}
	cout << endl;
}
int size(node* head){
	if(head==NULL)return 0;
	return 1+size(head->next);
}
node* addSameSize(node* n1,node* n2,node **result,int *carry){
	if(n1==NULL)return NULL;
	addSameSize(n1->next,n2->next,result,carry);
	int sum=n1->data+n2->data+(*carry);
	*carry=sum/10;
	*result=push(result,sum%10);
	return *result;
}
node *addExtra(node* n1,node **result, int *carry, int jump){
	if(jump==0)return NULL;
	addExtra(n1->next,result,carry,--jump);
	int sum=n1->data+(*carry);
	*result=push(result,sum%10);
	*carry=sum/10;
	return *result;
}

node* addDifferentSize(node* n1,node* n2,node** result,int *carry,int s1,int s2){
	int jump=s1-s2;
	node * tmp=n1;
	while(jump!=0){
		tmp=tmp->next;
		jump--;
	}
	addSameSize(tmp,n2,result,carry);
	addExtra(n1,result,carry,s1-s2);
	return *result;		
}

node* addLL(node* n1, node* n2){
	int s1=size(n1);
	int s2=size(n2);
	int carry=0;
	node* results=NULL;
	if(s1==s2)
		results=addSameSize(n1,n2,&results,&carry);		
	else if(s1>s2)
		results=addDifferentSize(n1,n2,&results,&carry,s1,s2);
	else if(s2>s1)
		results=addDifferentSize(n2,n1,&results,&carry,s2,s1);
	if(carry>0)results=push(&results,carry);
	return results;	
}

int main(){
	node* head_ref=createHead(6);
	head_ref=push(&head_ref,5);
	head_ref=push(&head_ref,4);
	head_ref=push(&head_ref,3);
	head_ref=push(&head_ref,3);
	head_ref=push(&head_ref,3);
	head_ref=push(&head_ref,4);
	head_ref=push(&head_ref,4);
	printList(head_ref);
	node* head_ref1=createHead(6);
	head_ref1=push(&head_ref1,5);
	head_ref1=push(&head_ref1,4);
	head_ref1=push(&head_ref1,3);
	printList(head_ref1);
	node* res=addLL(head_ref,head_ref1);
	printList(res);
	return 0;
}