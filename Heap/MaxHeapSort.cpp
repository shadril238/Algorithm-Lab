
///shadril238
#include<iostream>
using namespace std;
class HeapSort{
	public:
		int heapSize;
		int *heap=NULL;
		HeapSort(int heapSize){
			this->heapSize=heapSize;
			heap=new int[heapSize];
		}
		~HeapSort(){
			delete[] heap;
		}
		void inputArray(){
			cout<<"Enter array elements : ";
			for(int i=0;i<heapSize;i++)
				cin>>heap[i];
		}
		void heapify(int size,int index){
			int largest=index;
			int left= (2*index)+1;
			int right= (2*index)+2;
			if(left<size && heap[left]>heap[largest]){
				largest=left;
			}
			if(right<size && heap[right]>heap[largest]){
				largest=right;
			}
			if(index!=largest){
				swap(heap[index],heap[largest]);
				heapify(size,largest);
			}
		}
		void heapSort(){
			for(int i=(heapSize/2)-1;i>=0;i--){
				heapify(heapSize,i);
			}
			for(int j=heapSize-1;j>=0;j--){
				swap(heap[0],heap[j]);
				heapify(j,0);
			}
		}
		void printHeap(){
			cout<<"Sorted Heap : ";
			for(int i=0;i<heapSize;i++)
				cout<<heap[i]<<" ";
			cout<<endl;
		}
		
};
int main(){
	int n;
	cout<<"Enter array size : ";
	cin>>n;
	HeapSort heap(n);
	heap.inputArray();
	heap.heapSort();
	heap.printHeap();
	
}
