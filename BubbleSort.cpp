/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/


#include<iostream>
using namespace std;

int* bubbleSort(int arr[],int n){
	for(int j=0;j<n-1;j++){ 
		bool flag=1;
		for(int k=0;k<n-1-j;k++){ 
			if(arr[k]>arr[k+1]){ 
				int temp=arr[k];
				arr[k]=arr[k+1];
				arr[k+1]=temp;
				flag=0;
			}
		}
		if(flag) break; 
	}
	return arr;
}

int main(){
	int n;
	cout<<"Enter array size : ";
	cin>>n;
	int arr[n];
	cout<<"Enter array elements saparated by space : ";
	for(int i=0;i<n;i++) cin>>arr[i];
	
	*arr=*bubbleSort(arr,n);
	
	cout<<"Sorted(Bubble) Element : ";
	for(int l=0;l<n;l++)
		cout<<arr[l]<<" ";
	cout<<endl;
	
	return 0;
}

