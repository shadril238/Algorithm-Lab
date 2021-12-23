///shadril238

#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
class Node{
	public:
		int data;
		Node *right,*left;
		Node(){
			data=0;
			right=NULL;
			left=NULL;
		}
		Node(int data){
			this->data=data;
			right=NULL;
			left=NULL;
		}
};

class Bst{
	public:
		Node *newNode;
		Bst(){
			newNode=NULL;
		}
		void insert(Node *&root,int val){
			if(root==NULL){
				newNode=new Node(val);
				root=newNode;
				return;
			}
			else if(val<root->data){
				insert(root->left,val);
			}
			else{
				insert(root->right,val);
			}
			
		}
		int findMin(Node *&root){
			Node *temp=root;
			while(temp->left!=NULL){
				temp=temp->left;
			}
			return temp->data;
		}
		void preOrder(Node *&root){
			if(root==NULL){
				return;
			}
			cout<<root->data<<" ";
			preOrder(root->left);
			preOrder(root->right);
		}
		void inOrder(Node *&root){
			if(root==NULL){
				return;
			}
			inOrder(root->left);
			cout<<root->data<<" ";
			inOrder(root->right);
		}
		void postOrder(Node *&root){
			if(root==NULL){
				return;
			}
			postOrder(root->left);
			postOrder((root)->right);
			cout<<(root)->data<<" ";
		}
		bool search(Node *&root,int val){
			if(root==NULL){
				return false;
			}
			else if(root->data==val){
				return true;
			}
			else if(val>root->data)
				search(root->right,val);
			else
				search(root->left,val);
		}
		void deleteNode(Node *&root,int val){
			if(root==NULL)
				return;
			else if(val<root->data){
				deleteNode(root->left,val);
			}
			else if(val>root->data){
				deleteNode(root->right,val);
			}
			else if(val==root->data){
				if(root->left==NULL && root->right==NULL){
					free(root);
					root=NULL;
				}
				else if(root->left==NULL){
					Node *temp=root;
					root=root->right;
					free(temp);	
					temp=NULL;
				}
				else if(root->right==NULL){
					Node *temp=root;
					root=root->left;
					free(temp);	
					temp=NULL;
				}
				else{
					root->data=findMin(root->right);
					deleteNode(root->right,root->data);
				}
			}
		}
		
};
int main(){
	Node *root=NULL;
	Bst tree;
	cout<<"What do you want to do? \n\t 1.Insert \n\t 2.Delete \n\t 3.Traverse- PreOrder \n\t 4.Traverse- InOrder \n\t 5.Traverse- PostOrder \n\t 6.Search \n\t 7.Exit"<<endl;
	int choice;	
	bool flag=true;
	while(flag){
		cout<<"Enter choice : ";
		cin>>choice;
		switch(choice){
			case 1:{
				cout<<"Enter value you want to insert : ";
				int val;
				cin>>val;
				if(tree.search(root,val)==1){
					cout<<"Can't insert ! Duplicate value found..."<<endl;
				}
				else{
					tree.insert(root,val);
				}
				break;
			}
			case 2:{
				cout<<"Enter value you want to delete : ";
				int val;
				cin>>val;
				tree.deleteNode(root,val);
				break;
			}
			case 3:{
				cout<<"PreOrder : ";
				tree.preOrder(root);
				cout<<endl;
				break;
			}
			case 4:{
				cout<<"InOrder : ";
				tree.inOrder(root);
				cout<<endl;
				break;
			}
			case 5:{
				cout<<"PostOrder : ";
				tree.postOrder(*&root);
				cout<<endl;
				break;
			}
			case 6:{
				cout<<"Enter value you want to search : ";
				int val;
				cin>>val;
				if(tree.search(root,val))
					cout<<"Found !"<<endl;
				else
					cout<<"Not Found !"<<endl;
				break;
			}
			case 7:{
				flag=false;
				break;
			}
		}
	}
		
	
}
