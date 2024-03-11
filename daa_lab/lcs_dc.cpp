#include<iostream>
using namespace std;

int count=0;

void print_lcs(int** c, string x, int i, int j){
	if(i==0||j==0){
		return;
	}	
	if (c[i][j]== 7){
		print_lcs(c, x, i-1, j-1);
		cout<<x[i-1];
	}
	else if(c[i][j]==8){
		print_lcs(c, x, i-1, j);
	}
	else print_lcs(c, x, i, j-1);
}


int lcs_dc(string x, string y, int** c, int i, int j){
	count+=1;
	if(i==0||j==0){
		return 0;
	}
	if(x[i-1]==y[j-1]){
		c[i][j]=7;
		return lcs_dc(x, y, c, i-1, j-1)+1;
	}	
	else{
		int t1=lcs_dc(x, y, c, i-1, j);
		int t2=lcs_dc(x, y, c, i, j-1);
		if(t1>=t2){
			c[i][j]=8;
			return t1;
		}
		else{
			c[i][j]=4;
			return t2;
		}
	}
}

int main(){
//	int m, n;
//	cout<<"Enter sizes of set X and set Y: ";
//	cin>>m>>n;
	string x, y;
	cout<<"Enter string X: ";
	cin>>x;
	cout<<"Enter string Y: ";
	cin>>y;
	int m, n;
	m=x.length();
       	n=y.length();
	int** c;
	c=new int* [m+1];
	for(int i=0; i<=m; i++){
		c[i]=new int[n+1];
	}
	lcs_dc(x, y, c, m, n);
	cout<<"(0, 0) ";
	cout<<"(0, 0) ";
	for(int i=0; i<n; i++) cout<<"("<<y[i]<<", "<<0<<") ";
	cout<<endl;
	for(int i=0; i<=m; i++){
		if(i!=0) cout<<"(0, "<<x[i-1]<<") ";
		else cout<<"(0, 0) ";
		for(int j=0; j<=n; j++) cout<<"("<<"0"<<", "<<c[i][j]<<") ";
		cout<<endl;
	}
	cout<<endl;
	print_lcs(c, x, m, n);
	cout<<endl<<count<<endl;
	for(int i=0; i<=m; i++){
		delete[] c[i];
	}
	delete[] c;
}
