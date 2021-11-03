/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/


#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int l, int r){
	int m=(l+r)/2;
	
	if(l<=r){
		if(n==arr[m]) 
			return m;
		else if(arr[m]>n)
			return binarySearch(arr,n,l,m-1);
		else
			return binarySearch(arr,n,m+1,r);
	}
	
	return -1;
}

int main(){
	cout<<"Enter the size of the array : ";
	int sz,n;
	cin>>sz;
	int arr[sz];
	cout<<"Enter array elements saparated by space : ";
	for(int i=0;i<sz;i++) cin>>arr[i];
	cout<<"Enter the element you want to search : ";
	cin>>n;
	int indx=binarySearch(arr,n,0,sz-1);
	if(indx>=0)
		cout<<"Element "<<arr[indx]<<" found in the array !"<<endl;
	else 
		cout<<"Element not found in the array !"<<endl;
		
	
	return 0;
}
