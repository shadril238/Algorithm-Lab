/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/

//DFS 

#include<bits/stdc++.h>
using namespace std;

#define n 6

map<int,char> color;
map<int,int> st,ft;
int t=0;

void DFS_Visit(int V[6][6],int u){
	color[u]='G';
	t++;
	st[u]=t;
	for(int i=0;i<n;i++){
		if(V[u][i]==1 && color[i]=='W'){
			cout<<i<<" ";
			DFS_Visit(V,i);
		}
	}
	color[u]='B';
	t++;
	ft[u]=t;
	
}
void DFS(int V[6][6],int G){
	for(int i=0;i<n;i++){
		color[i]='W';
	}
	for(int i=G;i<n;i++){
		if(color[i]=='W' ){
			cout<<i<<" ";
			DFS_Visit(V,i);
		}
	}
}

int main(){
	int V[6][6]={{0,1,1,0,0,0},
 				{1,0,0,1,0,0},
 				{1,0,0,1,0,0},
 				{0,1,1,0,1,1},
 				{0,0,0,1,0,0},
 				{0,0,0,1,0,0}};
 	
 	
 	cout<<"Visited nodes are: ";
 	DFS(V,0);
 	cout<<endl;
	
}

