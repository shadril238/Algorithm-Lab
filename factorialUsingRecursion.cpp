/*
	Shifat, Shadril Hassan (20-42451-1)
	Algorithm Lab
*/


#include<iostream>
using namespace std;

int factorial(int n){
	if(n>1)
		return n*factorial(n-1);
	else
		return 1;
}

int main(){
	cout<<"Enter a number you want to calculate factorial : ";
	int n;
	cin>>n;
	cout<<"Factorial of "<<n<<" is : "<<factorial(n)<<endl;
	
	return 0;	
}
