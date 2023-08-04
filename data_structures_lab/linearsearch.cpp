#include<iostream>
using namespace std;

bool seqSearch(int *list, int last, int target, int &locn){
	bool found;
	int looker;
	for(looker=0;((looker<last)&&(target!=list[looker]));looker++);
	locn=looker;
	if(target==list[looker]) found=true;
	else found=false;
	return found;
}

int main(){
	int n, i, target, location;
	cout<<"Enter number of elements in the array: ";
	cin>>n;
	int arr[n];
	for(i=0; i<n; i++){
		cout<<"Enter element ", i+1, ": ";
		cin>>arr[i];
	}
	cout<<"Scanning complete. Enter target element: ";
	cin>>target;
	bool res=seqSearch(arr, n-1, target, location);
	if(res)
		cout<<"Element found at "<<location<<" index.\n";
	else
		cout<<"Element not found.\n";
}
