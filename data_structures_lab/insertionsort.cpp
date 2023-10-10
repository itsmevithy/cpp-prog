#include<iostream>
using namespace std;

void InsertionSort(int *list, int last){
	int current=1, walker, key;
	for(;(current<last);current++){
		key=list[current];
		walker=current-1;
		for(;((walker>=0)&&(key<list[walker]));walker--){
			list[walker]+=list[walker+1];
			list[walker+1]=list[walker]-list[walker+1];
			list[walker]-=list[walker+1];		
		}
		list[walker+1]=key;
	}
}

int main(){
	int n, i;
	cout<<"Enter number of elements in the array: ";
	cin>>n;
	int arr[n];
	for(i=0; i<n; i++){
		cout<<"Enter element "<<i+1<<" :";
		cin>>arr[i];
	}
	cout<<"Before sorting: ";
	for(i=0; i<n; i++) cout<<arr[i]<<", ";
	InsertionSort(arr, n-1);	
	cout<<"\nAfter sorting: ";
	for(i=0; i<n; i++) cout<<arr[i]<<", ";
	cout<<endl;
}
