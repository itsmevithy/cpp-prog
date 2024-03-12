#include<iostream>
#include<climits>
using namespace std;

int count=0;

struct cell{
	int** m;
	int** s;
	cell(int **a, int **b){
		m=a;
		s=b;
	}
}; 

cell mat_chain_ord(int* p, int n){
	int **m= new int*[n+1];
	int **s=new int*[n+1];
	for(int i=0; i<=n; i++){
		m[i]=new int[n];
		s[i]=new int[n];
	}
	for(int i=0; i<=n; i++) m[i][i]=0;
	for(int l=1; l<n; l++)
		for(int i=1; i<=n-l; i++){
			int j=i+l;
			m[i][j]=INT_MAX;
			for(int k=i; k<j; k++){
				count+=1;
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	return cell(m, s);
}

void print_opt_order(int **s, int i, int j){
	if(i==j){
		cout<<"A["<<i-1<<"]";
		return;
	}
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
	int p[n+1];
	for(int i=0; i<=n; i++) cin>>p[i];
	cell c=mat_chain_ord(p, n);
	print_opt_order(c.s, 1, n);
	cout<<endl<<count<<endl;
}
