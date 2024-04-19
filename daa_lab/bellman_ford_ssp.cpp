#include<iostream>
#include<climits>
using namespace std;

struct edge{
	int f, t, w;
	edge* next;
};

struct vertex{
	char label;
	unsigned int d;
	int pi;
};

class graph{
	int ec, vc;
	vertex *v;
	edge *efirst;
	edge* elast;
	int source;
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
			source=s;
			for(int i=0; i<vc; i++){
				v[i].d=INT_MAX;
				v[i].pi=-1;
			}
			v[s].d=0;
		}
		void printPath(int x){
			if(v[x].pi==-1||x==source){
				cout<<v[source].label;
				return;
			}
			printPath(v[x].pi);
			cout<<"-"<<v[x].d<<"->"<<v[x].label;
		}
		void relax(int p, int q, int w){
			if(v[q].d>v[p].d+w){
				cout<<v[q].label<<"("<<v[q].d<<") is greater than "<<v[p].label<<"("<<v[p].d<<") + "<<w<<", so changing..\n";
				v[q].d=v[p].d+w;
				v[q].pi=p;
			}
		}
		bool bellman_ford(int s){
			initialize(s);
			for(int i=1; i<vc; i++)
				for(edge* temp=efirst; temp; temp=temp->next)
					relax(temp->f, temp->t, temp->w);
			for(edge* temp=efirst; temp; temp=temp->next)
				if(v[temp->t].d>v[temp->f].d+temp->w)
					return false;
			for(int i=0; i<vc; i++){
				cout<<"Parent of "<<v[i].label<<": "<<v[v[i].pi].label<<endl;
			}
			return true;
		}
};

int main(){
	int x, y, s;
	cout<<"Enter number of vertices: ";
	cin>>x;
	cout<<"Enter number of edges: ";
	cin>>y;
	graph g(x, y);
	g.gInit();
	g.edgList();
	cout<<"Enter source vertex index: ";
	do{
		cin>>s;
		if(s<x && s>=0) break;
		cout<<"Enter valid index!!"<<endl;
	}while(true);
	if(!g.bellman_ford(s)){
		cout<<"Path does not exist!\n";
		return 0;
	}
	do{
		cout<<"Enter destination vertex index, or enter -1 to quit: ";
		cin>>s;
		if(s>=x || s<0) break;
		cout<<"The path from source to destination is, \n";
		g.printPath(s);
		cout<<endl;
	}while(true);
}
