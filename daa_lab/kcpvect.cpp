#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct itm{
	float w, v, vbw;
};

struct ND{ 
	int lvl;
	float wu, vg, ub;
	ND *left, *right, *parent; 
};

bool ndcomp(ND* a, ND* b){
	return (b->ub > a->ub);
}

ND* bf_bb_knapsack(itm* item, float wl, int size){
	ND *root=new ND, *nd=new ND;
	root->wu=root->vg=0;
	root->ub=wl*item[0].vbw;
	root->lvl=0;
	root->left=root->parent=root->right=NULL;
	vector<ND*> q;
	q.push_back(root);
	int clvl=0;
	while(clvl<size && !q.empty()){
		sort(q.begin(), q.end(), ndcomp);
		nd=q.back();
		q.pop_back();
		cout<<"\n Values of extracted nd are, lvl="<<nd->lvl<<" wu="<<nd->wu<<" vg="<<nd->vg<<" ub="<<nd->ub<<endl;
		clvl=nd->lvl+1;
		ND *lchild=new ND, *rchild=new ND;
		//cout<<"So far so good!\n";
		lchild->wu=nd->wu+item[clvl].w;
		//cout<<nd->wu+item[clvl].w<<endl;
		//cout<<"So far so good!\n";
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
			q.push_back(lchild);
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
		nd->right=rchild;
		q.push_back(rchild);
	}
	return nd;
}

void rec_print(ND* nn){
	if(!nn||!nn->parent) return;
	rec_print(nn->parent);
	if(nn->ub==nn->parent->left->ub)
		cout<<nn->lvl<<", ";
}

void bb_knapsack_sol(itm* &item, float wl, int size){
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
	for(int i=0; i<size; i++) cout<<item[i].v<<"\t";
	cout<<"\nW: ";
	for(int i=0; i<size; i++) cout<<item[i].w<<"\t";
	cout<<"\nB: ";
	for(int i=0; i<size; i++) cout<<item[i].vbw<<"\t";
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
	cout<<endl;
}
