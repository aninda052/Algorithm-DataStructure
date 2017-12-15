#include<bits/stdc++.h>

using namespace std;

struct node {

    int value;
    node *left,*right;
    node(){
        left=NULL;
        right=NULL;
    }

} *root;

void Insert(int val){

    if(root==NULL){
        root = new node();
        root->value = val;
    }
    else{
        node *current = root,*parent;
        while(current!=NULL){
            if(current->value > val){
                parent = current;
                current = current->left;
            }
            else{
                parent = current;
                current = current->right;
            }
        }
        node *newNode = new node();
        newNode->value=val;
        if(parent->value > val){
            parent->left = newNode;
        }
        else{
            parent->right = newNode;
        }
    }
}

void print_preorder(node *current)
{
	if(current==NULL) return;
	cout<<current->value<<endl;
	print_preorder(current->left);
	print_preorder(current->right);

}

void delete_node(int val){
	node *current=root,*previous;

	while(current->value!=val){
		if(current->value > val){
            previous = current;
            current = current->left;
        }
        else{
            previous = current;
            current = current->right;
        }
    }

	if(current->left ==NULL){

        if(previous->value > val)
            previous->left = current->right;
        else
            previous->right = current->right;
		delete(current->left);
	}
	else if(current->right ==NULL){

		if(previous->value > val)
            previous->left = current->left;
        else
            previous->right = current->left;
        delete(current->right);
	}
	else{

        node *tmp=current->right;
        previous=current;
        while (tmp->left != NULL){
            previous = tmp;
            tmp = tmp->left;
        }


        current->value=tmp->value;
        previous->left= tmp->right;

        delete(tmp);
	}

}

main(){

    // Let us create following BST

    Insert(44);
    Insert(17);
    Insert(28);
    Insert(29);
    Insert(88);
    Insert(65);
    Insert(82);
    Insert(54);
    Insert(76);
    Insert(80);
    Insert(78);
    Insert(97);


    print_preorder(root);

    delete_node(78);

    cout<<endl;
    print_preorder(root);

    return 0;
}

