/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/
//BFS


#include<bits/stdc++.h>
using namespace std;

#define n 6

queue<int> Q;
map<int,char> color,par;
map<int,int> level;

void BFS(int V[6][6],int G){
	for(int i=0;i<n;i++){
		color[i]='W';
	}
	cout<<G<<" ";
	color[G]='G';
	Q.push(G);
	level[G]=0;
	
	while(!Q.empty()){
		int i=Q.front();
		Q.pop();
		for(int j=0;j<n;j++){
			if(V[i][j]==1 && color[j]=='W'){
				cout<<j<<" ";
				level[j]=level[i]+1;
				par[j]=i;
				color[j]='G';
				Q.push(j);
			}
		}
		color[i]='B';
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
 	BFS(V,0);
 	cout<<endl;
}
