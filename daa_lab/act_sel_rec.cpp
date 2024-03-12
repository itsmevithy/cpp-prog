#include<iostream>
using namespace std;

void rec_act_sel(int* s, int* f, int k, int n){
	int m=k+1;
	while(m<=n && s[m]<f[k])
		m=m+1;
	if(m<=n){
		cout<<m+1<<", ";
		rec_act_sel(s, f, m, n);
	}
	else return;
}

int main(){
	int n;
	cout<<"Enter number of activities: ";
	cin>>n;
	int s[n], f[n];
	for(int i=0; i<n; i++){
		cout<<"Enter start time for activity "<<i+1<<": ";
		cin>>s[i];
	}
	for(int i=0; i<n; i++){
		cout<<"Enter finish time for activity "<<i+1<<": ";
		cin>>f[i];
	}
	cout<<"1, ";
	rec_act_sel(s, f, 0, n);
	cout<<endl;
}
