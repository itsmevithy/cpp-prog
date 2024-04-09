#include<iostream>
#include<climits>
using namespace std;

struct edge{
	int f, t, w;
	edge* next;
};

struct vertex{
	char label;
	int d;
	vertex* pi;
};

class graph{
	int ec, vc;
	vertex *v;
	edge *efirst;
	edge* elast;
	public:
		graph(int a, int b){
			vc=a;
			ec=b;
			v=new vertex[vc];
		}
		void gInit(){
			cout<<"Initiating graph...\n";
			for(int i=0; i<vc; i++){
				cout<<"Enter label for vertex "<<i<<" : ";
				cin>>v[i].label;
			}
			efirst=elast=NULL;
			for(int i=0; i<ec; i++){
				edge *temp=new edge;
				do{
					cout<<"For edge, enter indices of from and to vertices: ";
					cin>>temp->f>>temp->t;
					if(temp->f>=vc||temp->t>=vc||temp->f<0||temp->t<0){
						cout<<"Invalid index entered. try again!!\n";
						continue;
					}
					break;
				}while(true);
				cout<<"Enter weight for edge: ";
				cin>>temp->w;
				temp->next=NULL;
				if(elast==NULL) efirst=temp;
				else elast->next=temp;
				elast=temp;
			}
		}
		void edgList(){
			cout<<"Printing edges...\n";
			for(edge* temp=efirst; temp; temp=temp->next){
				cout<<endl<<v[temp->f].label<<"-("<<temp->w<<")->"<<v[temp->t].label;
			}
			cout<<endl;
		}
		void initialize(int s){
			for(int i=0; i<vc; i++){
				v[i].d=INT_MAX;
				v[i].pi=-1;
			}
			v[s].d=0;
		}
		void relax(int p, int q, int w){
			if(v[q].d>v[p].d+w){
				v[q].d=v[p].d+w;
				v[q].pi=
			}
		}
};

int main(){
	int x, y;
	cout<<"Enter number of vertices: ";
	cin>>x;
	cout<<"Enter number of edges: ";
	cin>>y;
	graph g(x, y);
	g.gInit();
	g.edgList();
}
