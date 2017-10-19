/*
Given two lists sorted in increasing order, create and return a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

For example, let the first linked list be 1->2->3->4->6 and second linked list be 2->4->6->8, then your function should create and return a third list as 2->4->6.
*/
#include "stdc++.h"
using namespace std;
struct node
{
int val;
struct node *next;
};
void push(struct node **root,int data)
{
    node *newnode=new node();
    struct node *prev;
    prev=*root;
    newnode->val=data;
    newnode->next=NULL;
    if(*root==NULL)
    {
        *root=newnode;
        return;
    }
    while(prev->next!=NULL)
        prev=prev->next;

    prev->next=newnode;
}
void print(struct node *ptr)
{
    if(ptr==NULL)
    {
        cout<<"NO"<<endl;
        return;
    }
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
void intersection(struct node **head1,struct node **head2,struct node **head3);

int main()
{
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *head3=NULL;
    int t,n1,n2;
    cin>>t;
    while(t--)
    {
struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *head3=NULL;
  cin>>n1>>n2;
    int k;
    for(int i=0;i<n1;i++)
    {
        cin>>k;

  push(&head1,k);
    }

    for(int i=0;i<n2;i++)
        {
            cin>>k;
            push(&head2,k);
         
        }
       
          intersection(&head1,&head2,&head3);
   print(head3);
  
    }
}




/* The structure of the Linked list Node is as follows:
struct node {
    int val;
    struct node* next;
}; */
struct node* addNode(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->val=x;
    temp->next=NULL;
    return temp;
}


void intersection(struct node **head1, struct node **head2, struct node **head3){
    // cout << "Start" << endl;
    struct node *tmp=NULL;
    while((*head1)!=NULL && (*head2)!=NULL){
        // cout << (*head1)->val << " " ;
        if((*head1)->val == (*head2)->val){
            if(tmp!=NULL){
                tmp->next=addNode((*head1)->val);
                tmp=tmp->next;
            }else{
                tmp=addNode((*head1)->val);   
                *head3=tmp; 
            }
            (*head1)=(*head1)->next;
            (*head2)=(*head2)->next;
                
        }
        else if((*head1)->val < (*head2)->val) (*head1)=(*head1)->next;
        else if((*head1)->val > (*head2)->val) (*head2)=(*head2)->next;
        
    }
    // cout << "End" << endl;
    return;
}



/*
1 
5 4 
1 2 3 4 6 
2 4 6 8

*/




