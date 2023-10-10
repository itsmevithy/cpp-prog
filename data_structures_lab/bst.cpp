#include<iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

struct tree{
	int count;
	node *root;
};

node addBST(node *r, node *pNew){
	if(r==NULL){
		r=pNew;
		r->left=NULL;
		r->right=NULL;
		return *pNew;
	}
	if(pNew->data<r->data) return addBST(r->left, pNew);
	return addBST(r->right, pNew);
}

bool deleteBST(node *r, int target){
	if(r==NULL) return false;
	if(target<r->data) return deleteBST(r->left, target);
	else if(target>r->data) return deleteBST(r->right, target);
}

node searchBST(node *r, int key){
	node *temp;
	if(r==NULL) return *temp;
	if(key<r->data) return searchBST(r->left, key);
	else if(key>r->data) return searchBST(r->right, key);
	else return *r;
}

node findLargestBST(node *r){
	if(r->right==NULL) return *r;
	return findLargestBST(r->right);
}
node findSmallestBST(node *r){
	if(r->left==NULL) return *r;
	return findSmallestBST(r->left);
}
void preOrder(node* r){
	if(r!=NULL){
		cout<<r->data<<", ";
		preOrder(r->left);
		preOrder(r->right);
	}
}

void inOrder(node* r){
	if(r!=NULL){
		inOrder(r->left);
		cout<<r->data<<", ";
		inOrder(r->right);
	}
}

void postOrder(node* r){
	if(r!=NULL){
		postOrder(r->left);
		postOrder(r->right);
		cout<<r->data<<", ";
	}
}

int main(){
	tree *t=new tree;
	t->count=0;
	t->root=NULL;
	int choice, x;
	node *temp=new node;
	do{
		cout<<"Enter your choice: [0-Exit, 1-Insert, 2-Search, 3-Largest, 4-Smallest, 5-preOrder traversal, 6-inOrder traversal, 7-postOrder traversal]";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter element to insert: ";
				cin>>x;
				temp->data=x;
				cout<<addBST(t->root, temp).data<<endl;
				break;
			case 2:
				cout<<"Enter element to search: ";
				cin>>x;
				/*if(searchBST(t->root, x)!=NULL)*/ cout<<searchBST(t->root, x).data<<endl;
				//else cout<<"NOt found\n";
				break;
			case 3:
				cout<<findLargestBST(t->root).data;
				break;
			case 4:
				cout<<findSmallestBST(t->root).data;
				break;
			case 5:
				preOrder(t->root);
				cout<<endl;
				break;
			case 6:
				inOrder(t->root);
				cout<<endl;
				break;
			case 7:
				postOrder(t->root);
				cout<<endl;
				break;
			default:
				choice=0;
				break;
		}
	}while(choice);
}
