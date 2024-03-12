#include<iostream>
using namespace std;

void greedy_act_sel(int* s, int* f, int n){
	int k=0;
	cout<<"1, ";
	for(int m=1; m<n; m++)
		if(s[m]>=f[k]){
			cout<<m+1<<", ";
			k=m;	
		}
}

int main(){
	int n;
	cout<<"Enter number of activities: ";
	cin>>n;
	int s[n], f[n];
	cout<<"Enter start times: ";
	for(int i=0; i<n; i++){
		//cout<<"Enter start time for activity "<<i+1<<": ";
		cin>>s[i];
	}
	
	cout<<"Enter finish times: ";
	for(int i=0; i<n; i++){
		//cout<<"Enter finish time for activity "<<i+1<<": ";
		cin>>f[i];
	}
	greedy_act_sel(s, f, n);
	cout<<endl;
}
