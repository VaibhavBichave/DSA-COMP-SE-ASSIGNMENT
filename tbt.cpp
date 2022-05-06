#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *left , *right;
	bool lbit , rbit;
	node()
	{
		data=0;
		left=right=NULL;
		lbit=rbit=0;
	}

	node(int d)
	{
		data=d;
		left=right=NULL;
		lbit=rbit=0;
	}

	friend class TBT;

};

class TBT{

public:
	node *root , *dummy;

	TBT(){
		root=NULL;
		dummy = new node(999);
		dummy->left = dummy->right = dummy;
	}

	void insert(int d);
	void inorder();
};

void TBT::insert(int d){
	if(root==NULL){
		//create new node
		root = new node(d);
		root->left = root->right = dummy;
		cout<<"root inserted"<<endl;
		dummy->left=root;
		dummy->lbit=1;
	}
	else{
		node* temp=root;
		while(temp!=dummy){
		// while(temp->rbit==0 or temp->lbit==0){

			node *p=new node(d);

			//moving to left child
			if(d<temp->data){
				if(temp->lbit==0){
					p->left=temp->left;
                    p->right=temp;
					temp->left=p;
					temp->lbit=1;
					cout<<"Data inserted successfully "<<d<<"\n";
                    return;
				}
				else{
					temp=temp->left;
				}
			}

			//moving to right child
			if(d>temp->data){
				if(temp->rbit==0){
                    p->right=temp->right;
                    p->left=temp;
					temp->right=p;
					temp->rbit=1;
                    cout<<"Data inserted successfully "<<d<<"\n";
                    return;
				}
				else{
					temp=temp->right;
				}
			}
		}
	}
}


// This is preorder traversal of TBT
void TBT::inorder(){
	node *current = dummy->left;
	do{
		while (current->lbit){
			current = current->left;
		}
		cout << current->data << " ";

		while (current->rbit == 0){
			current = current->right;
			if (current == dummy){
				return;
			}
			cout << current->data << " ";
		}
		current = current->right;

	} while (current != dummy);
}

int main() {

//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	TBT t1;
	t1.insert(50);
	t1.insert(40);
	t1.insert(60);
	t1.insert(35);
	t1.inorder();

	return 0;
}