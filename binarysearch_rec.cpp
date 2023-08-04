#include<iostream>
using namespace std;

bool recursiveBinarySearch(int *list, int first, int last, int target, int &locn){
	int looker, begin=0, end=last, mid;
	if(first>last){
		locn-=1;
		return false;
	}
	else{
		mid=(first+last)/2;
		if(target<list[mid])
			return recursiveBinarySearch(list, first, mid-1, target, locn);
		else if(target>list[mid])
			return recursiveBinarySearch(list, mid+1, last, target, locn);
		else{
			locn=mid;
			return true;
		}
	} 		
}

int main(){
	int n, i, j, temp, target, location;
	cout<<"Enter number of elements in the array: ";
	cin>>n;
	int arr[n];
	for(i=0; i<n; i++){
		cout<<"Enter element ", i+1, ": ";
		cin>>arr[i];
	}
	for(i=0; i<n; i++)
		for(j=0; j<(n-i-1); j++)
			if(arr[j]>arr[j+1]){
				arr[j]+=arr[j+1];
				arr[j+1]=arr[j]-arr[j+1];
				arr[j]-=arr[j+1];
			}
	cout<<"Scanning and sorting complete. The array is now, ";
	for(i=0; i<n; i++) cout<<arr[i]<<", ";
	cout<<"\nEnter target element: ";
	cin>>target;
	bool res=recursiveBinarySearch(arr, 0, n-1, target, location);
	if(res)
		cout<<"Element found at "<<location<<" index.\n";
	else
		cout<<"Element not found.\n";
}
