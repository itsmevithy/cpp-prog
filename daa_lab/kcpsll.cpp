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

struct node{
	ND* data;
	node *link;
};

struct head{
	int count;
	node *first;
};

class SLL{
	public:
		head *list;
		void createList(){
			list=new head();
			list->count=0;
			list->first=NULL;
		}
		bool insertNode(ND* dataIn){
			node *pNew=new node;
			if(pNew==NULL) return false;
			else{
				pNew->data=dataIn;
				pNew->link=NULL;
			}
			node *pPre=NULL, *pLoc=NULL;
			if(searchList(pPre, pLoc, dataIn)) return false;
			if(pPre==NULL){
				pNew->link=list->first;
				list->first=pNew;
			}
			else{
				pNew->link=pPre->link;
				pPre->link=pNew;
			}
			(list->count)++;
			return true;
		}
		bool deleteNode(ND* target){
			node *pPre, *pLoc;
			if(!searchList(pPre, pLoc, target)) return false;
			if(pPre==NULL) list->first=pLoc->link;
			else pPre->link=pLoc->link;
			delete pLoc;
			(list->count)--;
			return true;
		}
		bool searchList(node *&pPre, node *&pLoc, ND* target){
			pPre=NULL;
			pLoc=list->first;
			while((pLoc!=NULL)&&(target->ub < (pLoc->data->ub))){
				pPre=pLoc;
				pLoc=pLoc->link;
			}
			if(pLoc==NULL) return false;
			else if(target==pLoc->data) return true;
			else return false;
		}
		bool retrieveNode(ND* key, ND* &dataOut){
			node *pPre, *pLoc;
			if(searchList(pPre, pLoc, key)){
				pLoc->data=dataOut;
				return true;
			}
			return false;
		}
		bool emptyList(){
			return (list->first==NULL)?true:false;
		}
		int listCount(){
			return list->count;
		}
		void getNext(){
			node *temp=list->first;
			while(temp!=NULL){
				cout<<temp->data<<", ";
				temp=temp->link;
			}
			cout<<endl;
		}
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
	SLL q;
	q.createList();
	q.insertNode(root);
	int clvl=0;
	while(clvl<size && !q.emptyList()){
		nd=q.list->first->data;
		q.deleteNode(q.list->first->data);
		//cout<<"\n Values of extracted nd are, lvl="<<nd->lvl<<" wu="<<nd->wu<<" vg="<<nd->vg<<" ub="<<nd->ub<<endl;
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
			//q.push_back(lchild);
			q.insertNode(lchild);
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
		//q.push_back(rchild);
		q.insertNode(rchild);
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
