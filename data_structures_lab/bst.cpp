#include<iostream>
using namespace std;


class BST{
	public:
		int data;
		BST *left, *right, *r;
	BST(){
		data=0;
		left=right=NULL;
	}
	BST(int x){
		left=right=NULL;
		data=x;
		cout<<"done\n";
	}
	BST* addBST(BST *t, int x){
		if(!t) return new BST(x);
		if(x<(t->data)) t->left= addBST(t->left, x);
		else t->right= addBST(t->right, x);	
		return t;
	}

	bool deleteBST(BST *&r, int dltKey){
		if(r==NULL) return false;
		if(dltKey<r->data) return deleteBST(r->left, dltKey);
		else if(dltKey>r->data) return deleteBST(r->right, dltKey);
		else{
			if(r->left==NULL){
				r=r->right;
				return true;}
			else if(r->right==NULL){
			       	r=r->left;
				return true;}
			else{
				r->data=findLargestBST(r->left).data;
				return deleteBST(r->left, r->data);
			}
		}
	}

	BST searchBST(BST *r, int key){
		if(r==NULL||key>this->findLargestBST(r).data||key<this->findSmallestBST(r).data){	
			cout<<"not found.\n";
			return *r;
		}
		if(key<r->data) return searchBST(r->left, key);
		else if(key>r->data) return searchBST(r->right, key);
		else if(key==r->data){
			cout<<"found\n";
			return *r;
		}
		return *r;
	}

	BST findLargestBST(BST *r){
		if(r->right==NULL) return *r;
		return findLargestBST(r->right);
	}
	BST findSmallestBST(BST *r){
		if(r->left==NULL) return *r;
		return findSmallestBST(r->left);
	}
	void preOrder(BST *r){
		if(r!=NULL){
			cout<<r->data<<", ";
			preOrder(r->left);
			preOrder(r->right);
		}
	}

	void inOrder(BST *r){
		if(r!=NULL){
			inOrder(r->left);
			cout<<r->data<<", ";
			inOrder(r->right);
		}
	}

	void postOrder(BST *r){
		if(r!=NULL){
			postOrder(r->left);
			postOrder(r->right);
			cout<<r->data<<", ";
		}
	}
};
int main(){
	BST b, *root=NULL;
	int choice, x;
	do{
		cout<<"Enter your choice: [0-Exit, 1-Insert, 2-Search, 3-Largest, 4-Smallest, 5-preOrder traversal, 6-inOrder traversal, 7-postOrder traversal, 8-delete]";
		cin>>choice;
		switch(choice){
			case 1:{
				cout<<"Enter element to insert: ";
				cin>>x;
				root=b.addBST(root, x);
				break;}
			case 2:
				cout<<"Enter element to search: ";
				cin>>x;
				b.searchBST(root, x);
				break;
			case 3:
				cout<<"The largest is "<<b.findLargestBST(root).data<<endl;
				break;
			case 4:
				cout<<"The smallest is "<<b.findSmallestBST(root).data<<endl;
				break;
			case 5:
				b.preOrder(root);
				cout<<endl;
				break;
			case 6:
				b.inOrder(root);
				cout<<endl;
				break;
			case 7:
				b.postOrder(root);
				cout<<endl;
				break;
			case 8:
				cout<<"Enter element to delete: ";
				cin>>x;
				if(b.deleteBST(root, x)) cout<<"Done.\n";
				else cout<<"Failed.\n";
				break;
			default:
				choice=0;
				break;
		}
	}while(choice);
}
