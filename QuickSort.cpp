/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/

#include<iostream>
using namespace std;

int partition(int arr[], int start, int end){
	int i = start+1;
	int piv = arr[start];
	
	for(int j = start+1; j<end; j++){
		if(arr[j]<piv){
			swap(arr[i], arr[j]);
			i++;
			
		}
	}
	swap(arr[start], arr[i-1]);
	return i-1;
}

void quick_sort(int arr[], int start, int end){
	
	if(start<end){
		int piv_pos =  partition(arr, start, end);
		quick_sort(arr,start, piv_pos-1);
		quick_sort(arr, piv_pos+1, end);
	}
	
}

void print_array(int arr[], int size){
	for(int i=0; i<size; i++) cout << arr[i] <<  ' ' ;
	cout << endl;
	
}

int main(){ 

	int size; 
	cout << "Enter size :";
	cin >> size;
	int arr[size];
	cout << "Enter the elements in the array :";
	for(int i=0; i<size; i++)
		cin >> arr[i];
	quick_sort(arr, 0, size);
	cout<<"Sorted array : ";
	print_array(arr,size);
	return 0;

}
