#include <iostream>

using namespace std;

typedef struct node{
	int data;
	struct node* next;
}node;

/*
1-- to create the head
2-- to add a node to the given linked list at the end
3-- to add the node before the head
4-- to add the node to the 'i' position in the linked list
5-- print the linked list
6-- reverse the linked list
7-- delete a given key
*/


// to create the head of the LL
node* creatHead(int key){
	node* temp=(node*)malloc(sizeof(node));
	temp->data=key;
	temp->next=NULL;
	return temp;
}

// add the node to the end of the LL
void pushLL(node** head_ref,int key){
	node *temp=(node*)malloc(sizeof(node));
	temp->data=key;
	temp->next=NULL;
	node* head=*head_ref;
	while(head!=NULL && (head)->next!=NULL){
		head=(head)->next;
	}
	(head)->next=temp;
	return;
}

// add the node at the starting of the LL
node* pushTop(node** head, int key){
	node **temp_head=head;
	node *temp=(node*)malloc(sizeof(node));
	temp->data=key;
	temp->next=*temp_head;
	//*head=temp;
	return temp;
}

// put the element at the pos[0..n-1] with value = key
node* addPosition(node **head, int pos, int key){
	if(pos==0 && head!=NULL)
		return pushTop(head,key);
	node* tmp=*head;
	int count=0;
	node *prev=*head;
	while(count<pos && head!=NULL){
		prev=*head;
		*head=(*head)->next;
		count++;
	}
	node *temp=(node*)malloc(sizeof(node));
	temp->data=key;
	temp->next=prev->next;
	prev->next=temp;
	return tmp;
}

// delete a given key *Key present given*
node* deleteKey(node **head_ref, int key){
	if(((*head_ref)->next==NULL && (*head_ref)->data==key) )
		return NULL;
	node* head=*head_ref;
	node* prev=*head_ref;
	while(head!=NULL){
		if((head)->data==key){
			if(head->next==NULL){
				prev->next=NULL;
				return *head_ref;
			}
			break;
		}
		else{
			prev=head;
			head=head->next;
		} 
	}
	node *temp=(head)->next;
	(head)->data=(head)->next->data;
	(head)->next=(head)->next->next;
	free(temp);
	return *head_ref;
}

// Print the ll
void printLL(node *head){
	while(head!=NULL){
		cout << head->data << " " ;
		head=head->next;
	}
	cout << endl;
}

void reverse(node** head){
	if(head==NULL || (*head)->next==NULL)return;
	node* prev=NULL;
	node* current=*head;
	node* next;
	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*head=prev;
}

int main(){
	node *head_ref=creatHead(10);
	pushLL(&head_ref,30);
	pushLL(&head_ref,40);
	printLL(head_ref);
	head_ref=addPosition(&head_ref,1,20);
	printLL(head_ref);
	head_ref=deleteKey(&head_ref,10);
	if(head_ref)printLL(head_ref);
	else cout << "Empty\n";
	reverse(&head_ref);
	printLL(head_ref);
	return 0;
}