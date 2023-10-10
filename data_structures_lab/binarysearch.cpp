#include<iostream>
using namespace std;

bool seqSearch(int *list, int last, int target, int &locn){
	bool found;
	int looker, begin=0, end=last, mid;
	while(begin<=end){
		mid=(begin+end)/2;
		if(target>list[mid])
			begin=mid+1;
		else if(target<list[mid])
			end=mid-1;
		else begin=end+1;
	}
	locn=mid;
	found=(target==list[mid])?true:false;
	return found;
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
	bool res=seqSearch(arr, n-1, target, location);
	if(res)
		cout<<"Element found at "<<location<<" index.\n";
	else
		cout<<"Element not found.\n";
}
