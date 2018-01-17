/*
 * impSet.c
 *
 *  Created on: 19/04/2017
 *      Author: omar_
 */
#include "binaryTree.h"
#include <stdlib.h>
#include <stdio.h>


struct strNode{
	TypeL data;
	Node left, right, parent;
};

struct strSet{
	Node root;
	CompareFunc compareFunc;
	PrintFunc printFunc;
	int size;
};

void addLink(Node parent, Node child, Bool isLeftChild){

	if(isLeftChild)
		parent->left=child;
	else
		parent->right=child;
	if(child!=NULL)
		child->parent = parent;
}


void removeBranch (Set s, Node n, Bool isLeftChild){
	Node current = n;

	if(n->left==NULL && n->right==NULL){//Caso 1 (n es hoja)
		if(s->root==n)
			s->root = NULL;
		else{
			if(isLeftChild)
				addLink(n->parent, NULL,true);
			else
				addLink(n->parent, NULL, false);
		}
		free(n);
	}
	else if(n->left!=NULL && n->right==NULL){//Caso 2a (n, solo tiene hijo izq)
		if(s->root == n)
			s->root = n->left;
		else{
			if(isLeftChild)
				addLink(n->parent, n->left, true);
			else
				addLink(n->parent, n->left, false);
		}
		free(n);
	}
	else if(n->right!=NULL && n->left == NULL){//caso 2b (n solo tiene hijo derecho)
		if(s->root == n)
			s->root = n->right;
		else{
			if(isLeftChild)
				addLink(n->parent, n->right, true);
			else
				addLink(n->parent, n->right, false);
		}
		free(n);
	}
	else{//Caso 3
		current = current->left;
		while(current->right != NULL){
			current = current->right;
		}
		n->data = current->data;
		if(n == current->parent || s->root == current->parent){//Caso 3a (n tiene dos hijos; el padre de m es n)
			addLink(current->parent, current->left, true);
		}
		else// Caso 3b (n tiene dos hijos; el padre de m es no es n NI la raiz)
			addLink(current->parent, current->left, false);
		free(current);
	}
}

void destroy(Node n){
	if(n!=NULL){
		destroy(n->left);
		destroy(n->right);
		free(n);
	}
}

void print(Node n, PrintFunc pf){
	if(n!=NULL){
		printf("{");
		pf(n->data);
		print(n->left, pf );
		print(n->right, pf);
		printf("}");
	}
}

Set set_create(CompareFunc cf, PrintFunc pf){
	Set s = calloc(1,sizeof(struct strSet));
	s->compareFunc = cf;
	s->printFunc = pf;
	return s;
}

int set_size(Set s){
	return s->size;
}

Bool set_add(struct strSet* s, TypeL t){
	Node new = calloc(1,sizeof(struct strNode));
	Node current = s->root;
	new->data=t;
	Bool insert = false;

	if(s->root==NULL)
		s->root = new;
	else{
		while(!insert){
			if(s->compareFunc(t,current->data)==0)
				return false;
			else if(s->compareFunc(t,current->data) > 0){
				if(current->right==NULL){
					current->right = new;
					current->right->parent=current;
					insert = true;

				}
				else
					current = current->right;
			}
			else if(s->compareFunc(t,current->data) < 0){
				if(current->left==NULL){
					current->left = new;
					current->left->parent=current;
					insert = true;
				}
				else
					current = current->left;
			}
		}
	}
	s->size++;
	return true;
}


Bool set_contains(Set s, TypeL t){
	Node current = s->root;

	while(current!=NULL){
		if(s->compareFunc(t,current->data)==0)
			return true;
		else if(s->compareFunc(t,current->data) > 0)
			current = current->right;
		else if(s->compareFunc(t,current->data) < 0)
			current = current->left;
	}
	return false;
}

void set_destroy(Set s){
	destroy(s->root);
}

Bool set_remove(Set s, TypeL t){
	Node current = s->root;
	Bool isLeftChild;

	while(current!=NULL){
		if(s->compareFunc(t,current->data)==0){
			removeBranch(s, current, isLeftChild);
			s->size --;
			return true;
		}
		else if(s->compareFunc(t,current->data) > 0){
			current = current->right;
			isLeftChild = false;
		}
		else if(s->compareFunc(t,current->data) < 0){
			current = current->left;
			isLeftChild = true;
		}
	}
	return false;
}

void set_print(Set s){
	print(s->root, s->printFunc);
	printf("\n");
}
