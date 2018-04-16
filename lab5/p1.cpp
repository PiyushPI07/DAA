#include <bits/stdc++.h>
using namespace std;

class node{
public:
	node* parent;
	int value;
	int rank;
	node(int a){
		this->value=a;
	}

};


class Set{
public:
	
	node* makeSet(int y){
		node *x = new node (y);
		x->parent= x;
		x->rank=0;
		return x;
	}

	node* findSet(node* x){
		if(x->parent==x)
			return x;
		node *temp=x;
		x=x->parent;
		temp->parent=findSet(x);
		return temp->parent;

	}

	node* Union(node* x,node* y){
		node* a=findSet(x);
		node* b=findSet(y);
		if(a->rank > b->rank){
			b->parent = a;
		}
		else {
			a->parent = b;
			if(b->rank == a->rank)
				b->rank++;
		}
		
	}
};



int main(){
	
}