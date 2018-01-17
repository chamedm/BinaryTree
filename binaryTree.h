/*
 * binaryTree.h
 *
 *  Created on: 25 abr. 2017
 *      Author: Chavez
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

	typedef void* TypeL;
	typedef int (*CompareFunc) (TypeL, TypeL);
	typedef void (*PrintFunc) (TypeL);
	typedef struct strNode* Node;
	typedef struct strSet* Set;
	typedef enum {false, true} Bool;

	Set set_create(CompareFunc cf, PrintFunc pf);
	int set_size(Set);
	Bool set_add(Set s, TypeL t);
	Bool set_contains(Set s, TypeL t);
	void set_destroy(Set s);
	Bool set_remove(Set s, TypeL t);
	void set_print(Set s);

#endif /* BINARYTREE_H_ */
