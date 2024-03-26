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
			if(indx==0) return ND(); 
			ND temp=arr[0];
			arr[0]=arr[indx-1];
			//arr[indx--];
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
		void swap(ND &x, ND &y){
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
			ND* a=new ND[n];
			for(int i=0; i<n; i++){
				swap(a[i], arr[0]);
				heapify(0, (i-1)/2);
			}
			return a;
		}
		/*
		void print(){
			int p=2; 
			cout<<"The max heap is, \n";
			for(int i=0; i<n; i++){
				if(i+1==p){
					cout<<endl;
					p*=2;
				}
				cout<<arr[i].vbw<<"\t";
			}
			cout<<endl;
			int *a=sort();
			cout<<"The sorted array is, ";
			for(int i=0; i<n; i++) cout<<a[i]<<" ";
			cout<<endl;
		}*/
};

ND* bf_bb_knapsack(itm* item, float wl, int size){
	ND *root, *nd;
	root->wu=root->vg=0;
	root->ub=wl*item[0].vbw;
	root->lvl=0;
	root->left=root->parent=root->right=NULL;
	Heap q(size);
	q.enqueue(*root);
	int clvl=0;
	while(clvl<size && q.indx>0){
		*nd=q.dequeue();
		ND *lchild, *rchild;
		
		lchild->wu=nd->wu+item[clvl].w;
		if(lchild->wu<=wl){
			lchild->vg=nd->vg+item[clvl].v;
			lchild->parent=nd;
			lchild->lvl=nd->lvl+1;
			if(clvl==size-1)
				lchild->ub=lchild->vg;
			else
				lchild->ub=lchild->vg+(wl-lchild->wu)*item[clvl].vbw;
			lchild->left=lchild->right=NULL;
			nd->left=lchild;
			q.enqueue(*lchild);
		}
		
		rchild->wu=nd->wu;
		rchild->vg=nd->vg;
		rchild->parent=nd;
		rchild->lvl=nd->lvl+1;
		if(clvl==size-1)
			rchild->ub=rchild->vg;
		else
			rchild->ub=rchild->vg+(wl-rchild->wu)*item[clvl].vbw;
		rchild->left=rchild->right=NULL;
		nd->left=rchild;
		q.enqueue(*rchild);		
	}
	return nd;
}

void rec_print(ND* nn){
	if(!nn||!nn->parent||!nn->parent->left) return;
	rec_print(nn->parent);
	if(nn->ub==nn->parent->left->ub)
		cout<<nn->lvl<<", ";
}

void bb_knapsack_sol(itm *item, float wl, int size){
	for(int i=0; i<size; i++)
		item[i].vbw=item[i].v/item[i].w;
	for(int i=0 ; i<size; i++)
		for(int j=0; j<size-i+1; j++)
			if(item[i].vbw<item[i+1].vbw){
				itm temp=item[j];
				item[j]=item[j+1];
				item[j+1]=temp;
			}
	cout<<"\nV: ";
	for(int i=0; i<size; i++) cout<<item[i].v<<" ";
	cout<<"\nW: ";
	for(int i=0; i<size; i++) cout<<item[i].w<<" ";
	cout<<"\nB: ";
	for(int i=0; i<size; i++) cout<<item[i].vbw<<" ";
	ND* nn=bf_bb_knapsack(item, wl, size);
	cout<<"\nTotal profit is: "<<nn->ub<<"\nItems in knapsack are, ";
	rec_print(nn);
}

int main(){
	int n;
	cout<<"Enter number of items: ";
	cin>>n;
	itm* item=new itm[n];
	for(int i=0; i<n; i++){
		cout<<"Enter weight of item "<<i+1<<" :";
		cin>>item[i].w;
		cout<<"Enter value of item "<<i+1<<" :";
		cin>>item[i].v;
	}
	float wl;
	cout<<"Enter WL: ";
	cin>>wl;
	bb_knapsack_sol(item, wl, n);
}
