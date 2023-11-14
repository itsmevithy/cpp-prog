#include<iostream>
using namespace std;

struct graphArc{
	graphVertex *content;
	graphArc *nextArc;
};

struct graphVertex{
	char data;
	bool processed, inqueue;
	graphArc *firstArc;
	graphVertex *nextVertex;
};

struct node{
	graphVertex *vertex;
	node *link;
};

class queue{
	private:
	node *front, *rear;
	int count;
	public:
	queue(){
		count=0;
		rear=front=NULL;	
	}
	void enqueue(char dataIn){
		node *temp;
		temp->vertex->data=dataIn;
		temp->vertex->processed=false;
		if(front==NULL) rear=front=temp;
		else rear->link=temp;
		temp->link=NULL;
		count++;
	}
	graphVertex* dequeue(){
		node *temp=front;
		front=front->link;
		count--;
		graphVertex *v=temp->vertex;
		delete temp;
		return v;
	}
};

class graph{
	private:
		gv *first;
		int count;
	public:
		graph(){
			count=0; first=NULL;
		}
		void insertVertex(char dataIn){
			graphVertex* temp=new graphVertex;
			temp->data=dataIn;
			temp->processed=temp->inqueue=false;
			temp->firstArc=temp->nextVertex=NULL;
			if(first==NULL) first=temp;
			else{
				for(graphVertex *t=first; t->nextVertex!=NULL; t=t->nextVertex);
				t->nextVertex=temp;
			}			
			count++;
			cout<<"Done!\n";
		}
		bool insertArc(char x, char y){
			graphVertex *xt, *yt;
			for(xt=first; xt->nextVertex!=NULL&&xt->data!=x; xt=xt->nextVertex);
			for(yt=first; yt->nextVertex!=NULL&&yt->data!=y; yt=yt->nextVertex);
			if(xt==NULL||yt==NULL) return false;
			graphArc *xarc, *yarc;
			xarc->content=xt;
			yarc->content=yt;
			xarc->nextArc=yarc->nextArc=NULL;
			if(xt->firstArc==NULL) xt->firstArc=xarc;
			else{
				graphArc *xa;
				for(xa=xt->firstArc; xa->nextArc!=NULL; xa=xa->nextArc);
				xa->nextArc=xarc;
			}
			if(yt->firstArc==NULL) yt->firstArc=yarc;
			else{
				graphArc *ya;
				for(ya=yt->firstArc; ya->nextArc!=NULL; ya=ya->nextArc);
				ya->nextArc=yarc;
			}
		}
}
