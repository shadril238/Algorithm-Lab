/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/

#include<iostream>
#include<climits>
using namespace std;

void merge(int arr[], int l, int m, int h){
	int n1=m-l+1;
	int n2=h-m;
	int L[n1+1], R[n2+1];
	
	for(int i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(int j=0;j<n2;j++)
		R[j]=arr[m+j+1];
		
	L[n1]=INT_MAX;
	R[n2]=INT_MAX;
	
	int i=0,j=0;
	for(int k=l;k<=h;k++){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}	
		else{
			arr[k]=R[j];
			j++;
		}		
	}	
}

void mergeSort(int arr[], int l, int h){
	if(l<h){
		int m=(l+h)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,h);
		merge(arr,l,m,h);
	}
}


int main(){
	cout<<"Enter the size of the array : ";
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter array elements saparated by space : ";
	for(int i=0;i<n;i++) cin>>arr[i];
	
	mergeSort(arr,0,n-1);
	cout<<"Array after Merge Sort : ";
	for(int i=0;i<n;i++) 
		cout<<arr[i]<<" ";
	cout<<endl;
	
	return 0;
}

