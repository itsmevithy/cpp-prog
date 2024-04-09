#include<iostream>
using namespace std;

int count=0;

int* compute_prefix(string P){
	int m=P.length();
	int* p=new int[m+1];
	p[1]=0;
	int k=0;
	for(int q=2; q<=m; q++, count++){
		while(k>0&&P[k]!=P[q-1]){
			k=p[k];
			count++;
		}
		if(P[k]==P[q-1])
			k+=1;
		p[q]=k;
	}
	cout<<"\nPreprocessing count: "<<count<<endl;
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
	for(int i=1; i<=n; i++, count++){
		while(q>0 && P[q]!=T[i-1]){
			q=p[q];
			count++;
		}
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
	cout<<"\ncount: "<<count<<endl;
}
