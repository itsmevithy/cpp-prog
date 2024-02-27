#include<iostream>
using namespace std;

struct cell{
	int data;
	int dir;
    cell(){
        data=0;
        dir=0;
    }
};

int count=0;

void print_lcs(cell** b, string x, int i, int j){
	if(i==0||j==0) return;
	
	if (b[i][j].dir == 7){
		print_lcs(b, x, i-1, j-1);
		cout<<x[i-1];
	}
	else if(b[i][j].dir==8){
		print_lcs(b, x, i-1, j);
	}
	else print_lcs(b, x, i, j-1);
}

void lcs_length_bu(string x, string y){
	int m=x.length()+1;
	int n=y.length()+1;
    cell **b;
	b=new cell* [m];
	for(int i=0; i<m; i++) b[i]=new cell[n];
	for(int j=0; j<n; j++) b[0][j].data=0;
	for(int i=1; i<m; i++) b[i][0].data=0;
	for(int i=1; i<m; i++)
		for(int j=1; j<n; j++){
			count++;
			if(x[i-1]==y[j-1]){
				b[i][j].data=b[i-1][j-1].data+1;
				b[i][j].dir=7;
			}
			else if(b[i-1][j].data>b[i][j-1].data){
				b[i][j].data=b[i-1][j].data;
				b[i][j].dir=8;
			}
			else{
				b[i][j].data=b[i][j-1].data;
				b[i][j].dir=4;
			}
		}
	cout<<"(0, 0) ";
	cout<<"(0, 0) ";
	for(int i=0; i<n-1; i++) cout<<"("<<y[i]<<", "<<0<<") ";
    cout<<endl;
	for(int i=0; i<m; i++){
		if(i!=0) cout<<"(0, "<<x[i-1]<<") ";
		else cout<<"(0, 0) ";
		for(int j=0; j<n; j++) cout<<"("<<b[i][j].data<<", "<<b[i][j].dir<<") ";
		cout<<endl;
	}
//	return b;
    cout<<"The LCS of X and Y is : ";
	print_lcs(b, x, m-1, n-1);
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
	//cell** b=
	lcs_length_bu(x, y);
	cout<<endl;
}