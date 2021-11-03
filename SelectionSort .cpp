/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/


#include<iostream>
using namespace std;

int* selectionSort(int arr[], int n){
	int minIndx;
	for(int i=0;i<n-1;i++){
		minIndx=i;
		for(int j=i+1;j<n;j++){
			if(arr[minIndx]>arr[j]){
				minIndx=j;
			}
		}
		swap(arr[i],arr[minIndx]);
	}
	return arr;
}

int main(){
	cout<<"Enter the size of the array : ";
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter array elements saparated by space : ";
	for(int i=0;i<n;i++) cin>>arr[i];
	
	cout<<"Array after selection sort : ";
	*arr=*selectionSort(arr,n);
	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	return 0;
}
