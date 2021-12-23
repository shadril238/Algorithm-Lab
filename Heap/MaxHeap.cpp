///shadril238
#include<iostream>
using namespace std;
class MaxHeap{
	public:
		int heapSize;
		int *heap=NULL;
		MaxHeap(int heapSize){
			this->heapSize=heapSize;
			heap=new int[heapSize];
		}
		~MaxHeap(){
			delete[] heap;
		}
		void inputArray(){
			cout<<"Enter array elements : ";
			for(int i=0;i<heapSize;i++)
				cin>>heap[i];
		}
		void heapify(int index){
			int largest=index;
			int left= (2*index)+1;
			int right= (2*index)+2;
			if(left<heapSize && heap[left]>heap[largest]){
				largest=left;
			}
			if(right<heapSize && heap[right]>heap[largest]){
				largest=right;
			}
			if(index!=largest){
				swap(heap[index],heap[largest]);
				heapify(largest);
			}
		}
		void buildMaxHeap(){
			for(int i=(heapSize/2)-1;i>=0;i--){
				heapify(i);
			}
		}
		void printHeap(){
			cout<<"Max Heap : ";
			for(int i=0;i<heapSize;i++)
				cout<<heap[i]<<" ";
			cout<<endl;
		}
		
};
int main(){
	int n;
	cout<<"Enter array size : ";
	cin>>n;
	MaxHeap heap(n);
	heap.inputArray();
	heap.buildMaxHeap();
	heap.printHeap();
	
}
