///shadril238
#include<iostream>
using namespace std;
class HeapInsertion{
	public:
		int heapSize;
		int *heap=NULL;
		HeapInsertion(int heapSize){
			this->heapSize=heapSize;
			 memoryAlloc(heapSize);
		}
		~HeapInsertion(){
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
		void memoryAlloc(int newSize){
			if(heap==NULL){
				heap=new int[newSize];
				return;
			}
			int *temp=new int[newSize];
			for(int i=0;i<newSize;i++)
				temp[i]=heap[i];
			delete[] heap;
			this->heapSize=newSize;
			heap=temp;
			delete[] temp;
			temp=NULL;	
		}
		void insert(int val){
			int newSize=heapSize+1;
			memoryAlloc(newSize);
			heap[heapSize-1]=val;
			buildMaxHeap();
		}
		void printHeap(){
			cout<<"Max Heap : ";
			for(int i=0;i<heapSize;i++)
				cout<<heap[i]<<" ";
			cout<<endl;
		}
		
};
int main(){
 	cout<<"Enter array size : ";
 	int n;
 	cin>>n;
 	HeapInsertion heap(n);
 	heap.inputArray();
 	while(1){
 		cout<<"Do you want to insert new element in the heap?(1/0)";
 		bool dec;
 		cin>>dec;
 		if(dec){
 			int val;
 			cout<<"Insert value : ";
 			cin>>val;
 			heap.insert(val);
 			cout<<"/t Do you want to print heap elements?(1/0)";
 			cin>>dec;
 			if(dec){
 				heap.printHeap();
			}
			else continue;
		}
		else{
			heap.printHeap();
		}
		
 		
	}
 	
 	
 }
