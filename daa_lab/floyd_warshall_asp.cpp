#include<iostream>

using namespace std;

class graph{
	public:
		int n, **w, **d, **p;
		
		graph(int x, int y){
			int a, b, c;
			n=x;
			w=new int*[n];
			d=new int*[n];
			p=new int*[n];
			for(int i=0; i<n; i++){
				w[i]=new int[n];
				d[i]=new int[n];
				p[i]=new int[n];
				for(int j=0; j<n; j++) w[i][j]=999;
				w[i][i]=0;
			}
			for(int i=0; i<y; i++){
				while(x){
					cout<<"Enter from vertex index (starts from 1): ";
					cin>>b;
					if(b<=0||b>n){
						cout<<"Invalid vertex entered.. Retry!!\n";
						continue;			
					}
					cout<<"Enter to vertex index: ";
					cin>>c;
					if(c<=0||c>n){
						cout<<"Invalid vertex entered.. Retry!!\n";
						continue;			
					}
					if(b==c){
						cout<<"Self vertex entered.. Retry!!\n";
						continue;
					}
					cout<<"Enter weight: ";
					cin>>a;
					w[b-1][c-1]=a;
					break;
				}
			}
		}
		void initialize(){
			int x, y, e;
			cout<<"Enter number of edges";

			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++){
					d[i][j]=w[i][j];
					p[i][j]=(i==j||w[i][j]>=999)?-1:(i+1);
				}
		}
		void floyd_warshall(){
			for(int k=0; k<n; k++)
				for(int i=0; i<n; i++)
					for(int j=0; j<n; j++)
						if(p[i][k]!=-1&&p[k][j]!=-1&&d[i][j]>d[i][k]+d[k][j]){
							d[i][j]=d[i][k]+d[k][j];
							p[i][j]=p[k][j];
						}
		}
		void printl(){
			cout<<"\nW:-\n";
			for(int i=0; i<n; i++){
				cout<<"|\t";
				for(int j=0; j<n; j++)
					cout<<w[i][j]<<"\t";
				cout<<"|\n";
			}
			cout<<"\nD:-\n";
			for(int i=0; i<n; i++){
				cout<<"|\t";
				for(int j=0; j<n; j++)
					cout<<d[i][j]<<"\t";
				cout<<"|\n";
			}
			cout<<"\nP:-\n";
			for(int i=0; i<n; i++){
				cout<<"|\t";
				for(int j=0; j<n; j++)
					cout<<p[i][j]<<"\t";
				cout<<"|\n";
			}
		}
};

int main(){
	int n, e;
	cout<<"Enter number of vertices and edges: ";
	cin>>n>>e;
	graph g(n, e);
	g.initialize();
	g.floyd_warshall();
	g.printl();
}
