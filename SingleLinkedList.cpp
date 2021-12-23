///shadril238
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *link;
};
//Linear Searching
int search(struct node *&head,int val){
	int pos=1;
	struct node *temp=head;
	while(temp!=NULL){
		if(temp->data==val){
			return pos;
		}
		pos++;
		temp=temp->link;
	}
	return -1;
}
//Counts the node of Linked List
int nodeCounter(struct node *head){
	int count=0;
	struct node *currNode=NULL;
	currNode=head;
	while(currNode!=NULL){
		count++;
		currNode=currNode->link;
	}
	return count;
}
//Insert element at Beginning
void insertAtBeg(struct node *&head,struct node *&newNode,int value,struct node *&currentNode){
	if(head==NULL){
		newNode->data=value;
		newNode->link=NULL;
		head=newNode;
		currentNode=head;
	}
	else{
		newNode->data=value;
		newNode->link=head;
		head=newNode;
	}
}
//Insert element at End
void insertAtEnd(struct node *&head,struct node *&newNode,int value,struct node *&currentNode){
	if(head==NULL){
		newNode->data=value;
		newNode->link=NULL;
		head=newNode;
		currentNode=head;
	}
	else{
		newNode->data=value;
		newNode->link=NULL;
		currentNode->link=newNode;
		currentNode=currentNode->link;
	}
}

//Insert element at Given Position
void insertAfterGivenNode(struct node *&head,struct node *&newNode,int value,struct node *&currentNode,int position){
	if(head==NULL){
		newNode->data=value;
		newNode->link=NULL;
		head=newNode;
		currentNode=head;
	}
	else if(position==1){
		insertAtBeg(head,newNode,value,currentNode);
	}
	else if(position==nodeCounter(head)){
		insertAtEnd(head,newNode,value,currentNode);
	}
	else{
		struct node *nodeInPosition=NULL;
		nodeInPosition=head;
		while(position!=1){
			nodeInPosition=nodeInPosition->link;
			position--;
		}
		newNode->data=value;
		newNode->link=nodeInPosition->link;
		nodeInPosition->link=newNode;
	}
}

//Delete element from Beginning
void deleteFromBeg(struct node *&head){
	if(head==NULL){
		cout<<"Linked list is empty !"<<endl;
	}	
	else{
		struct node *temp=head;
		head=head->link;
		delete(temp);
		temp=NULL;
	}
}
//Delete element from end
void deleteFromEnd(struct node *&head,struct node *&currentNode){
	if(head==NULL){
		cout<<"Linked list is empty !"<<endl;
	}	
	else if(head->link==NULL){
		delete(head);
		head=NULL;
	}
	else{
		struct node *temp=head,*temp2=head;
		while(temp->link!=NULL){
			temp2=temp;
			temp=temp->link;
		}
		temp2->link=NULL;
		currentNode=temp2;
		delete(temp);
		temp=NULL;
	}
}

//Delete the given node from linked list
void deleteGivenNode(struct node *&head,struct node *&currentNode,int pos){
	if(head==NULL){
		cout<<"Linked list is empty !"<<endl;
	}
	else if(pos==1){
		deleteFromBeg(head);
	}
	else if(pos==nodeCounter(head)){
		deleteFromEnd(head,currentNode);
	}
	else{
		struct node *temp=head,*temp2=head;
		while(pos!=1){
			temp2=temp;
			temp=temp->link;
			pos--;
		}
		temp2->link=temp->link;
		delete(temp);
		temp=NULL;
	}
	
}
//Display linked list element
void displayElement(struct node *head){
	if(head==NULL){
		cout<<"Linked list is empty !"<<endl;
		return;
	}
	cout<<"Elements of the linked list : ";
	struct node *disp=NULL;
	disp=head;
	while(disp!=NULL){
		cout<<disp->data<<" ";
		disp=disp->link;
	}
	cout<<endl;
}
int main(){
	struct node *head=NULL,*newNode=NULL,*currentNode=NULL;
	cout<<"What do you want to do? \n\t 1.Insert At the Beginning \n\t 2.Insert After Given Node \n\t 3.Insert At the End \n\t 4.Delete From the Beginning \n\t 5.Delete a Given Node \n\t 6.Delete From the End \n\t 7.Search Element From Linked List \n\t 8.Display \n\t 9.Exit "<<endl;
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
				insertAtBeg(head,newNode,val,currentNode);
				break;
			}
			case 2:{
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
					insertAfterGivenNode(head,newNode,val,currentNode,pos);
				}
				break;
			}
			case 3:{
				cout<<"Enter value : ";
				int val;
				cin>>val;
				newNode=new struct node();
				insertAtEnd(head,newNode,val,currentNode);
				break;
			}
			case 4:{
				deleteFromBeg(head);
				break;
			}
			case 5:{
				cout<<"Enter position : ";
				int pos;
				cin>>pos;
				if(pos>nodeCounter(head)){
					cout<<"Position not valid !"<<endl;
				}
				else{
					deleteGivenNode(head,currentNode,pos);	
				}
				break;
			}
			case 6:{
				deleteFromEnd(head,currentNode);
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
				displayElement(head);
				break;
			case 9:
				flag=false;
				break;
		}
	}
	
}
