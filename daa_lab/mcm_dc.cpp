#include<iostream>
#include<climits>
using namespace std;

struct cell{
	int** m;
	int** s;
	cell(int **a, int **b){
		m=a;
		s=b;
	}
}; 

cell mat_chain_ord(int* p, int n){
	int *m[n];
	int *s[n];
	for(int i=1; i<=n; i++){
		m[n-i]=new int[n-i+1];
		s[n-i]=new int[n-i+1];
	}
	for(int i=0; i<n; i++) m[i][i]=0;
	for(int l=0; l<n-1; l++)
		for(int i=0; i<n-l; i++){
			int j=i+l;
			m[i][j]=INT_MAX;
			for(int k=i; k<j-1; k++){
				int q=m[i][k]+m[k][j]+p[i]*p[k+1]*p[j+1];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	return cell(m, s);
}

void print_opt_order(int **s, int i, int j){
	if(i==j) cout<<" A["<<i<<"] ";
	else{
		cout<<"(";
		print_opt_order(s, i, s[i][j]);
		print_opt_order(s, s[i][j]+1, j);
		cout<<")";
	}
}

int main(){
	int n;
	cout<<"Enter number of matrices to multiply: ";
	cin>>n;
	int p[n];
	for(int i=0; i<n; i++) cin>>p[i];
	cell c=mat_chain_ord(p, n);
	print_opt_order(c.s, 0, n-1);
}
