#include<iostream>
using namespace std;

int* compute_prefix(string P){
	int m=P.length();
	int* p=new int[m+1];
	p[1]=0;
	int k=0;
	for(int q=2; q<=m; q++){
		while(k>0&&P[k]!=P[q-1])
			k=p[k];
		if(P[k]==P[q-1])
			k+=1;
		p[q]=k;
	}
	return p;
}

void kmp_matcher(string T, string P){
	int n=T.length();
	int m=P.length();
	int* p=compute_prefix(P);
	cout<<"Contents of p: ";
	for(int j=1; j<=m; j++) cout<<p[j]<<" ";
	cout<<endl;
	int q=0;
	for(int i=1; i<=n; i++){
		while(q>0 && P[q]!=T[i-1])
			q=p[q];
		if(P[q]==T[i-1])
			q+=1;
		if(q==m){
			cout<<"Pattern occurs with shift "<<i-m<<endl;
			q=p[q];
		}
	}
}

int main(){
	string x, y;
	cout<<"Enter string: ";
	cin>>x;
	cout<<"Enter pattern: ";
	cin>>y;
	kmp_matcher(x, y);
}
