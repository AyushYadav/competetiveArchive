#include <iostream>
#include <algorithm>

using namespace std;

// #define listL linkedList

class listL{
public:
	int val;
	listL* next;
	listL(int data){
		this->val=data;
		this->next=NULL;
	}

	void static printL(listL *head){
		if(head==NULL)return ;
		while(head!=NULL){
			cout << head->val << " " ;
			head=head->next;
		}
	}

	void static addLast(listL *head, int data){
		listL *tmp=new listL(data);
		while(head->next!=NULL)head=head->next;
		head->next=tmp;
	}

};


int main(){

	listL *href=new listL::listL(1);
	ListL::addLast(href,2);
	ListL::addLast(href,3);
	ListL::addLast(href,4);
	ListL::printL();

	return 0;

}