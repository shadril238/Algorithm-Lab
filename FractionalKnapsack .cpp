/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/


#include<bits/stdc++.h>
using namespace std;

class Item{
	public:
		string itemName;
		double benefit,weight,valIndex;
		Item(){
			itemName="";
			benefit=0.0f;
			weight=0.0f;
			valIndex=0.0f;
		}
		Item(string itemName,double benefit,double weight,double valIndex){
			this->itemName=itemName;
			this->benefit=benefit;
			this->weight=weight;
			this->valIndex=valIndex;
		}
		bool operator < (const Item &I) const{ //Comparator
			return valIndex < I.valIndex;
		}
};

int main(){
	priority_queue<Item> items; //Declaring Priority Queue
	
	int n,capacity;
	cout<<"Enter the number of items : ";
	cin>>n;
	cout <<"Enter the weight capacity : ";
	cin>>capacity;
	cout<<"Enter the data for all the items : "<<endl;
	for(int i=0;i<n;i++){
		cout<<'\t'<<i+1<<". Enter item name : ";
		string name;
		cin>>name;
		cout<<'\t'<<i+1<<". Enter item benefit : ";
		double benefit,weight,valIndex;
		cin>>benefit;
		cout<<'\t'<<i+1<<". Enter item weight : ";
		cin>>weight;
		valIndex=benefit/weight;
		cout<<endl;
		
		Item item(name,benefit,weight,valIndex); 
		items.push(item); // Pushing data to priority queue
	}
	
	double totalWeight=0,totalBenefit=0,xi=0,j=0;
	//Implementing fractional knapsack algorithm
	cout<<"Items that are selected :"<<endl;
	while(totalWeight < capacity){ 
		Item i=items.top();
		items.pop();
		xi=min(i.weight,capacity-totalWeight);
		totalWeight+=xi;
		totalBenefit+=(xi*i.valIndex);
		cout<<++j<<" . Item Name : "<<i.itemName<<" , Item Benefit : "<<i.benefit<<" , Item Weight : "<<i.weight<<" , Item Value Index : "<<i.valIndex<<" , Item Chosen : "<<xi<<endl;
	}
	cout<<endl;
	
	cout<<"Total Benefit (Max) : "<<totalBenefit<<endl;
}
