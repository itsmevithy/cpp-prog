#include<iostream>
using namespace std;

struct itm{
	float w, v, vbw;
};

struct ND{ 
	int lvl;
	float wu, vg, ub;
	ND *left, *right, *parent; 
};

struct node{
	ND data;
	node *fore;
	node *back;
};

struct head{
	int count;
	node *first;
	node *last;
};

class Heap{
	private:
		int n;
		ND  *arr;
	public:
		int indx;
		Heap(int size){
			n=size;
			arr=new ND[n];
			indx=0;
		}
		Heap(ND *a, int size){
			n=size;
			arr=new ND[n];
			for(int i=0; i<n; i++){
				arr[i]=a[i];
				//maxheap_up(i);
			}
			heapify(0, n/2);
		}
		void enqueue(ND a){
			arr[indx]=a;
			maxheap_up(indx++);
		}
		ND dequeue(){
			ND temp=arr[0];
			arr[0]=arr[indx-1];
			arr[indx--]=new ND;
			heapify(0, indx/2);
			return temp;
		}
		void heapify(int ind, int lastp){
			if(ind>lastp) return;
			int n1=2*ind+1, n2=n1+1;
			while(ind<lastp && (arr[ind].ub<arr[n1].ub||arr[ind].ub<arr[n2].ub)){
				int maxn=(arr[n1].ub>arr[n2].ub)?n1:n2;
				swap(arr[maxn], arr[ind]);
				ind=maxn;
				n1=2*ind+1, n2=n1+1;
			}
			for(int i=0; i<n/2; i++) if(arr[i].ub<arr[2*i+1].ub||arr[i].ub<arr[2*i+2].ub){
				heapify(i, n/2);
				break;
			}
		}
		void swap(int &x, int&y){
			ND temp=x;
			x=y;
			y=temp;
		}
		void maxheap_down(int ind, int last){
			int n1=2*ind+1, n2=n1+1;
			while(ind<=last && (arr[ind].ub<arr[n1].ub||arr[ind].ub<arr[n2].ub)){
				int maxn=(arr[n1].ub>arr[n2].ub)?n1:n2;
				swap(arr[maxn], arr[ind]);
				ind=maxn;
				n1=2*ind+1, n2=n1+1;
			}
		}
		void maxheap_up(int ind){
			if(ind<=0) return;
			int par=(ind-1)/2;
			while(ind>0 && arr[ind].ub>arr[par].ub){
				swap(arr[ind], arr[par]);
				maxheap_up(par);
			}
		}
		ND* sort(){
			int* a=new ND[n];
			for(int i=0; i<n; i++){
				swap(a[i], arr[0]);
				heapify(0, (i-1)/2);
			}
			return a;
		}
		void print(){
			int p=2; 
			cout<<"The max heap is, \n";
			for(int i=0; i<n; i++){
				if(i+1==p){
					cout<<endl;
					p*=2;
				}
				cout<<arr[i]<<"\t";
			}
			cout<<endl;
			int *a=sort();
			cout<<"The sorted array is, ";
			for(int i=0; i<n; i++) cout<<a[i]<<" ";
			cout<<endl;
		}
};

nd bf_bb_knapsack(itm* item, float wl){
	ND root, nd;
	int size=sizeof(item)/sizeof(itm);
	root.wu=root.vg=0;
	root.ub=wl*item[0].vbw;
	root.lvl=0;
	root.left=root.parent=root.right=NULL;
	Heap q(size);
	q.enqueue(root);
	int clvl=0;
	while(clvl<n && q.indx>0){
		nd=q.dequeue();
		ND lchild, rchild;
		
		lchild.wu=nd.wu+item[clvl].w;
		if(lchild.wu<=wl){
			lchild.vg=nd.vg+item[clvl].v;
			lchild.parent=nd;
			lchild.lvl=nd.lvl+1;
			if(clvl==size-1)
				lchild.ub=lchild.vg;
			else
				lchild.ub=lchild.vg+(wl-lchild.wu)*item[clvl].vbw;
			lchild.left=lchild.right=NULL;
			nd.left=lchild;
			q.enqueue(lchild);
		}
		
		rchild.wu=nd.wu;
		rchild.vg=nd.vg;
		rchild.parent=nd;
		rchild.lvl=nd.lvl+1;
		if(clvl==size-1)
			rchild.ub=rchild.vg;
		else
			rchild.ub=rchild.vg+(wl-rchild.wu)*item[clvl].vbw;
		rchild.left=rchild.right=NULL;
		nd.left=rchild;
		q.enqueue(rchild);		
	}
	return nd;
}

void rec_print(ND nn){
	if(!nn.parent) return;
	rec_print(nn.parent);
	if(nn==nn.parent.left)
		cout<<nn.lvl<<", ";
}
