#include<iostream>
using namespace std;

void bubbleSort(int *list, int last){
	int current=0, walker;
	bool sorted=false;
	for(;((current<last)&&(sorted==false));current++){
		walker=last;
		sorted=true;
		for(;walker>current;walker--){
			if(list[walker]<list[walker-1]){
				sorted=false;
				list[walker]+=list[walker-1];
				list[walker-1]=list[walker]-list[walker-1];
				list[walker]-=list[walker-1];		
			}
		}
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
	bubbleSort(arr, n-1);	
	cout<<"\nAfter sorting: ";
	for(i=0; i<n; i++) cout<<arr[i]<<", ";
	cout<<endl;
}
