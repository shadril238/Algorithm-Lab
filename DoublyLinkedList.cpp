///shadril238

#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *next,*prev;
};
//Linear Search
int search(struct node *&head,int val){
	int pos=1;
	struct node *temp=head;
	while(temp!=NULL){
		if(temp->data==val){
			return pos;
		}
		pos++;
		temp=temp->next;
	}
	return -1;
}
//counts the node of doubly linked list
int nodeCounter(struct node *head){
	int count=0;
	struct node *currNode=NULL;
	currNode=head;
	while(currNode!=NULL){
		count++;
		currNode=currNode->next;
	}
	return count;
}

//Insert element at the beginning of linked list
void insertAtBeg(struct node *&head,struct node *&newNode,struct node *&tail,int val){
	if(head==NULL){
		head=newNode;
		tail=head;
		tail->prev=NULL;
		tail->data=val;
		tail->next=NULL;
	}
	else{
		newNode->next=head;
		newNode->data=val;
		newNode->prev=NULL;
		head->prev=newNode;
		head=newNode;
		
	}
}
//Insert element at the end of linked list
void insertAtEnd(struct node *&head,struct node *&newNode,struct node *&tail,int val){
	if(head==NULL){
		head=newNode;
		tail=head;
		tail->prev=NULL;
	    	tail->data=val;
		tail->next=NULL;
	}
	else{
		newNode->next=NULL;
		newNode->data=val;
		newNode->prev=tail;
		tail->next=newNode;
		tail=newNode;
	}
}

//Insert element after a given position
void insertAfterPos(struct node *&head,struct node *&newNode,struct node *&tail,int val,int pos){
	if(head==NULL){
		head=newNode;
		tail=head;
		tail->prev=NULL;
		tail->data=val;
		tail->next=NULL;
	}
	else{
		struct node *temp1=NULL,*temp2=NULL;
		temp1=head;
		int p=pos;
		while(pos!=1){
			temp1=temp1->next;
			pos--;
		}
		if(p==nodeCounter(head)){
			insertAtEnd(head,newNode,tail,val);
			return;
		}
		temp2=temp1->next;
		newNode->data=val;
		newNode->next=temp2;
		newNode->prev=temp1;
		temp1->next=newNode;
		temp2->prev=newNode;	
	}
}
//Delete element from the beginning
void deleteFromBeg(struct node *&head){
	if(head==NULL){
		cout<<"Linked list is empty !"<<endl;
	}	
	else{
		struct node *temp=NULL;
		temp=head;
		head=head->next;
		delete(temp);
		temp=NULL;
		if(head==NULL){
			return;
		}
		head->prev=NULL;
	}
}
//Delete elements from the end
void deleteFromEnd(struct node *&tail){
	if(tail==NULL){
		cout<<"Linked list is empty !"<<endl;
	}
	else{
		struct node *temp=NULL;
		temp=tail;
		tail=tail->prev;
		delete(temp);
		temp=NULL;
		tail->next=NULL;	
	}	
}

//Delete the given position node from the linked list
void deleteGivenNode(struct node *&head, struct node *&tail,int pos){
	if(tail==NULL){
		cout<<"Linked list is empty !"<<endl;
	}
	else if(pos==1){
		deleteFromBeg(head);
	}
	else if(pos==nodeCounter(head)){
		deleteFromEnd(tail);
	}
	else{
		struct node *temp1=NULL,*temp2=NULL,*temp3=NULL;
		temp1=head;
		while(pos!=1){
			temp1=temp1->next;
			pos--;
		}
		temp2=temp1->prev;
		temp3=temp1->next;
		temp2->next=temp3;
		temp3->prev=temp2;
		delete(temp1);
		temp1=NULL;	
	}
}

//Display elements in General order
void displayInNormalOrder(struct node *head){
	if(head==NULL){
		cout<<"Linked list is empty !"<<endl;
		return;
	}
	struct node *temp=NULL;
	temp=head;
	cout<<"Elements of the linked list in general order: ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
//Display elements in reverse order
void displayInReverseOrder(struct node *tail){
	if(tail==NULL){
		cout<<"Linked list is empty !"<<endl;
		return;
	}
	cout<<"Elements of the linked list in reverse order: ";
	struct node *temp=NULL;
	temp=tail;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->prev;
	}
	cout<<endl;
}
int main(){
	struct node *head=NULL,*tail=NULL,*newNode=NULL;
	cout<<"What do you want to do? \n\t 1.Insert At the Beginning \n\t 2.Insert At the End \n\t 3.Insert After Given Position \n\t 4.Delete From the Beginning \n\t 5.Delete From the End \n\t 6.Delete a Given Position \n\t 7.Search Element From Linked List \n\t 8.Display In General Order \n\t 9.Display In Reverse Order \n\t 10.Exit"<<endl;
	int choice;
	bool flag=true;
	while(flag){
		cout<<"Enter choice : ";
		cin>>choice;
		switch(choice){
			case 1:{
				cout<<"Enter value : ";
				int val;
				cin>>val;
				newNode=new struct node();
				insertAtBeg(head,newNode,tail,val);
				break;
			}
			case 2:{
				cout<<"Enter value : ";
				int val;
				cin>>val;
				newNode=new struct node();
				insertAtEnd(head,newNode,tail,val);
				break;
			}
			case 3:{
				int val,pos;
				cout<<"Enter position : ";
				cin>>pos;
				if(pos>nodeCounter(head)){
					cout<<"Position not valid !"<<endl;
				}
				else{
					cout<<"Enter value : ";
					cin>>val;
					newNode=new struct node();
					insertAfterPos(head,newNode,tail,val,pos);
				}
				break;
			}
			case 4:{
				deleteFromBeg(head);
				break;
			}
			case 5:{
				deleteFromEnd(tail);
				break;
			}
			case 6:{
				cout<<"Enter position : ";
				int pos;
				cin>>pos;
				if(pos>nodeCounter(head)){
					cout<<"Position not valid !"<<endl;
				}
				else{
					deleteGivenNode(head,tail,pos);
				}
				break;
			}
			case 7:{
				cout<<"Enter value you want to search : ";
				int val;
				cin>>val;
				int pos=-1;
				pos=search(head,val);
				if(pos!=-1){
					cout<<"Element Found at Position "<<pos<<endl;
				}
				else{
					cout<<"Element Not Found..."<<endl;
				}
				break;
			}
			case 8:
				displayInNormalOrder(head);
				break;
			case 9:
				displayInReverseOrder(tail);
				break;
			default:
				flag=false;
		}
	}
	
}
