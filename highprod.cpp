#include<iostream>
using namespace std;

int main(){
	int a[20][20], i, j, k=0, p, q, hor[400], ver[400], sum1=1, sum2=1, max=1;
	for(i=0; i<20; i++)
		for(j=0; j<20; j++){
			cin>>a[i][j];
		}
	k=0;
	for(i=0; i<20; i++)
		for(j=0; j<17; j++){
			for(k=0; (k<4); k++){
				//cout<<a[i][j+k]<<" ";
				sum1*=a[i][j+k];
				sum2*=a[j+k][i];
			}
			//cout<<endl;
			max=(sum1>max)?sum1:max;
			max=(sum2>max)?sum2:max;
			sum1=sum2=1;
		}
	for(k=3; k<20; k++){
		for(j=0; j<=k-3; j++){
			q=0;
			for(p=j; (q<4); q++){
				i=k-p;
				sum1*=a[i][p++];
				//cout<<a[i][p++]<<" ";
			}
			max=(sum1>max)?sum1:max;
			sum1=1;
			//cout<<endl;
		}
	}
	for(k=18; k>=0; k--){
		for(j=0; j<=k-3; j++){
			q=0;
			for(p=j; (q<4); q++){
				i=k-p;
				sum2*=a[20-(p++)-1][20-i-1];
				//cout<<a[20-(p++)-1][20-i-1]<<" ";
			}
			max=(sum2>max)?sum2:max;
			sum2=1;
			//cout<<endl;
		}
	}
	cout<<max<<endl;
}
