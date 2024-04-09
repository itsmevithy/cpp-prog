#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int count=0;

void rabinkarp_sm(string T, string P, int q, int d){
	int m=P.length();
	int n=T.length();
	int t=0, p=0, h=1;
		p=(p*d+P[0])%q;
		t=(t*d+T[0])%q;
	for(int i=1; i<m; i++, count++){
		h=(h*d);
		p=(p*d+P[i])%q;
		t=(t*d+T[i])%q;
	}
	h=h%q;
	cout<<"H value: "<<h<<endl;
	for(int s=0, i; s<=(n-m); s++, count++){
			//if(t!=p) continue;
			if(t==p){
			for(i=0; i<m; i++, count++) if(P[i]!=T[s+i]) break;
			if(i==m) cout<<"Shift occured at "<<s<<endl;
			}
			if(s<n-m){
				t=(d*(t-T[s]*h)+T[s+m])%q;
				t=(t<0)?t+q:t;
			}
	}
}

bool prime(int x){
	for (int i=2; i<=sqrt(x); i++) if(x%i==0) return false;
	return true;
}

int main(){
	string x, y;
	int q, d;
	cout<<"Enter a string: ";
	cin>>x;
	cout<<"Enter a pattern: ";
	cin>>y;
	
	vector<char> alpha;
	for(int i=0; i<x.length(); i++) alpha.push_back(x[i]);
	sort(alpha.begin(), alpha.end());
	auto it=unique(alpha.begin(), alpha.end());
	alpha.erase(it, alpha.end());
	
	cout<<"Chosen alphabet: ";
	for(auto& element: alpha) cout<<element<<" ";
	cout<<"\nSize: "<<alpha.size()<<endl;
	
	q=alpha.size();
	for(int i=q; ; i++) if(prime(i)){
		q=i;
		break;
	}
	
	cout<<"Chosen prime number: "<<q<<endl;
	rabinkarp_sm(x, y, q, alpha.size());
	cout<<"\ncount: "<<count<<endl;
}
