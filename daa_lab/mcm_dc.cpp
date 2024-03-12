#include<iostream>
#include<climits>
using namespace std;

int count=0;

int rec_mat_chain(int* p, int **s, int i, int j){
	if(i==j) return 0;
	int t=INT_MAX;
	for(int k=i; k<j; k++){
		count+=1;
		int q=rec_mat_chain(p, s, i, k)+rec_mat_chain(p, s, k+1, j)+(p[i-1]*p[k]*p[j]);
		if(q<t){
			t=q;
			s[i][j]=k;
		}
	}
	return t;
}

void print_opt_order(int **s, int i, int j){
	if(i==j) cout<<"A["<<i-1<<"]";
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
	int **s=new int*[n+1];
	for(int i=0; i<=n; i++){
		s[i]=new int[n+1];
	}
	int m=rec_mat_chain(p, s, 1, n);
	print_opt_order(s, 1, n);
	cout<<endl<<count<<endl;
}
