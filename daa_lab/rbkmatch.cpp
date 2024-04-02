#include<iostream>
using namespace std;

void rabinkarp_sm(string T, string P, int q, int d){
	int m=P.length();
	int n=T.length();
	int t=0, p=0, h=1;
		p=(p*d+P[0])%q;
		t=(t*d+T[0])%q;
	for(int i=1; i<m; i++){
		h=(h*d)%q;
		p=(p*d+P[i])%q;
		t=(t*d+T[i])%q;
	}
	for(int s=0, i; s<=(n-m); s++){
			//if(t!=p) continue;
			if(t==p){
			for(i=0; i<m; i++) if(P[i]!=T[s+i]) break;
			if(i==m) cout<<"Shift occured at "<<s<<endl;
			}
			if(s<n-m){
				t=(d*(t-T[s]*h)+T[s+m])%q;
				t=(t<0)?t+q:t;
			}
	}
}

int main(){
	string x, y;
	int q, d;
	cout<<"Enter a string: ";
	cin>>x;
	cout<<"Enter a pattern: ";
	cin>>y;
	cout<<"Choose a prime number: ";
	cin>>q;
	cout<<"Enter alphabet size: ";
	cin>>d;
	rabinkarp_sm(x, y, q, d);
}
