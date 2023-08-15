#include<iostream>
using namespace std;

bool recursiveSeqSearch(int *list, int index, int last, int &locn, int target){
	bool found;
	int looker;
	if(index>last){
		locn=-1;
		return false;
	}
	if(target==list[index]){
		locn=index;
		return true; 
	}
	return recursiveSeqSearch(list, index+1, last, locn, target);
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
	bool res=recursiveSeqSearch(arr, 0,  n-1, location, target);
	if(res)
		cout<<"Element found at "<<location<<" index.\n";
	else
		cout<<"Element not found.\n";
}
