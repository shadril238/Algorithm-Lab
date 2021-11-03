/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a,pair<int,int> &b){
	return a.second<b.second;
}

int main(){
	int totalActivity,activityCounter=1;
	cout<<"Enter the number of total activity : ";
	cin>>totalActivity;
	int activity[totalActivity];
	
	vector<pair<int,int>> v;
	
	for(int i=0;i<totalActivity;i++){
		cout<<"Enter starting time for activity "<<i+1<<" : ";
		int startTime,endTime;
		cin>>startTime;
		cout<<"Enter ending time for activity "<<i+1<<" : ";
		cin>>endTime;
		
		v.push_back({startTime,endTime});	
	}
	sort(v.begin(),v.end(),cmp);
	
	int x=v[0].first;
	int y=v[0].second;
	
	cout<<"Selected activities after applying greedy approch : "<<endl;
	cout<<"( "<<x<<" , "<<y<<" )"<<" ";
	for(int i=1;i<totalActivity;i++){
		if(v[i].first>=y){
			x=v[i].first;
			y=v[i].second;
			activityCounter++;
			cout<<"( "<<x<<" , "<<y<<" )"<<" ";
		}
	}
	cout<<endl;
	cout<<"Total number of activity after applying greedy approch : "<<activityCounter<<endl;
	
}
