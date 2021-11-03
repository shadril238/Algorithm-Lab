/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
	
	//Implementing Coin Changing Problem Greedy Algorithm
	int ncd,amt,sum=0,amtC;
	cout<<"Enter amount to change : ";
	cin>>amt; 
	amtC=amt;
	cout<<"Enter number of Coin Denominations : ";
	cin>>ncd;
	map<int,int,greater<int>> cd;
	cout<<"Enter Coin Denominations saparated by space : ";
	for(int i=0;i<ncd;i++){
		int x;
		cin>>x;
		if(x<=amt){
			int total=amt/x;
			cd.insert({x,total});
			sum+=total;
			amt%=x;
		}	
	}
	
	//sort(cd,cd+ncd,greater<int>());
	for(auto u : cd){
		amtC-=(u.first*u.second);
		cout<<"Coin : "<<u.first<<" , Choose : "<<u.second<<" , So remaining : "<<amtC<<endl;
	}
	cout<<"Solution : "<<sum<<" coins"<<endl;
	
	
}
