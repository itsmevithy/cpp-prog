#include<iostream>
using namespace std;

int count=0;

void print_lcs(int** c, string x, int i, int j){
	if(i==0||j==0) return;
	
	if (c[i][j]== 7){
		print_lcs(c, x, i-1, j-1);
		cout<<x[i-1];
	}
	else if(c[i][j]==8){
		print_lcs(c, x, i-1, j);
	}
	else print_lcs(c, x, i, j-1);
}


int lcs_length_td(string x, string y, int** b, int** c, int i, int j){
	if(b[i][j]>0){
		cout<<"\n1\n";
		if(i==0||j==0) b[i][j]=0;
		return b[i][j];
	}
	if(x[i]==y[j]){
		cout<<"\n2\n";
		b[i][j]=lcs_length_td(x, y, b, c, i-1, j-1)+1;
		cout<<"\n3\n";
		c[i][j]=7;
		return b[i][j];
	}
	
		cout<<"\n4\n";
	int t1=lcs_length_td(x, y, b, c, i-1, j);
	int t2=lcs_length_td(x, y, b, c, i, j-1);
	if(t1>t2){
		b[i][j]=t1;
		c[i][j]=8;
	}
	else{
		b[i][j]=t2;
		c[i][j]=4;
	}
	cout<<"\n6\n";
	return b[i][j];
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
	int m=x.length(), n=y.length();
	int** b;
	b=new int* [m+1];
	int** c;
	c=new int* [m+1];
	for(int i=0; i<=m; i++){
		b[i]=new int[n+1];
		c[i]=new int[n+1];
	}
	for(int j=0; j<n+1; j++) b[0][j]=0;
	for(int i=1; i<m+1; i++) b[i][0]=0;
	lcs_length_td(x, y, b, c, m, n);
	cout<<"(0, 0) ";
	cout<<"(0, 0) ";
	for(int i=0; i<n; i++) cout<<"("<<y[i]<<", "<<0<<") ";
	cout<<endl;
	for(int i=0; i<=m; i++){
		if(i!=0) cout<<"(0, "<<x[i-1]<<") ";
		else cout<<"(0, 0) ";
		for(int j=0; j<=n; j++) cout<<"("<<b[i][j]<<", "<<c[i][j]<<") ";
		cout<<endl;
	}
	cout<<endl;
	print_lcs(b, x, m, n);
}
