/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/

#include<iostream>
using namespace std;

int linearSearch(int arr[], int x, int sz){
	for(int i=0;i<sz;i++){
		if(arr[i]==x)
			return i;
	}
	return -1;
}

int main(){
	cout<<"Enter array size : ";
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter array element sapareted by space : ";
	for(int i=0;i<n;i++) cin>>arr[i];
	  
	cout<<"Enter the element you want to search : ";
	int x;
	cin>>x;
	int res=linearSearch(arr,x,n);
	
	if(res==-1)
		cout<<"Index: "<<res<<endl<<"Element not found in the list"<<endl;
	else
		cout<<"Index: "<<res<<endl<<"Element found in the list"<<endl;

	return 0;
}

