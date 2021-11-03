/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/


#include<iostream>
using namespace std;

int *insertionSort(int a[],int n){
	for(int i=1;i<n;i++){
		int key=a[i];
		int j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	return a;
}

int main(){
	int n;
	cout<<"Enter array size : ";
	cin>>n;
	int arr[n];
	cout<<"Enter array elements saparated by space : ";
	for(int i=0;i<n;i++) cin>>arr[i];
	
	*arr=*insertionSort(arr,n);
	
	cout<<"Sorted(Insertion) Element : ";
	for(int l=0;l<n;l++)
		cout<<arr[l]<<" ";
	cout<<endl;
	
	return 0;
}
