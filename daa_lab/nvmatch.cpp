#include<iostream>
using namespace std;

int main(){
	string x, y;
	cout<<"Enter a string: ";
	cin>>x;
	cout<<"Enter a pattern:";
	cin>>y;
	int n=x.length();
	int m=y.length();
	for(int s=0, i; s<n-m+1; s++){
		for(i=0; i<m; i++)
			if(x[i+s]!=y[i]) break;
		if(i==m) cout<<"Matching occured at shift "<<s<<endl;
	}	
}
