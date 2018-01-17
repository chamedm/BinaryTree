/*
 ============================================================================
 Name        : binaryTree.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "binaryTree.h"
#include <stdio.h>

int compareInts(TypeL t1, TypeL t2) {
	int *i1 = (int*) t1;
	int *i2 = (int*) t2;
	return *i1 - *i2;
}

void printInt(TypeL t) {
	int * pI = (int *) t;
	printf("%d", *pI);
}

int main(void) {
	Set s = set_create(compareInts, printInt);

	int n2=2;
	int n3=3;
	int n4=4;
	int n5=5;
	int n6=6;
	int n8=8;
	int n9=9;
	int n10=10;
	int n30=30;
	int n40=40;
	int n50=50;
	int n60=60;
	int n90=90;

	printf("INSERCION\n");

	//9 ser� la ra�z
	set_add(s, &n9);
	set_print(s);

	//6 ser� izq de 9
	set_add(s, &n6);
	set_print(s);

	//60 ser� der de 9
	set_add(s, &n60);
	set_print(s);

	//5 ser� izq de 6
	set_add(s, &n5);
	set_print(s);

	//8 ser� der de 6
	set_add(s, &n8);
	set_print(s);

	//3 ser� izq de 5
	set_add(s, &n3);
	set_print(s);

	//2 ser� izq de 3
	set_add(s, &n2);
	set_print(s);

	//4 ser� der de 3
	set_add(s, &n4);
	set_print(s);

	//30 ser� izq de 60
	set_add(s, &n30);
	set_print(s);

	//90 ser� der de 60
	set_add(s, &n90);
	set_print(s);

	//10 ser� izq de 30
	set_add(s, &n10);
	set_print(s);

	//50 ser� der de 30
	set_add(s, &n50);
	set_print(s);

	//40 ser� izq de 50
	set_add(s, &n40);
	set_print(s);


	//sea n el nodo a eliminar...
	printf("\n\nELIMINACION\n");

	//caso 3a (n tiene 2 hijos; el padre de m es n)
	set_remove(s, &n6);
	set_print(s);

	//caso 3b (n tiene 2 hijos; el padre de m NO es n NI la ra�z)
	set_remove(s, &n60);
	set_print(s);

	//caso 1 (n es hoja)
	set_remove(s, &n2);
	set_print(s);

	//caso 2b (n s�lo tiene hijo derecho)
	set_remove(s, &n3);
	set_print(s);

	//caso 1 (n es hoja)
	set_remove(s, &n8);
	set_print(s);

	//caso 2a (n s�lo tiene hijo izquierdo)
	set_remove(s, &n5);
	set_print(s);

	//caso 3 (n tiene 2 hijos; n es la ra�z)
	set_remove(s, &n9);
	set_print(s);

	//caso 2b (n s�lo tiene hijo derecho; n es la ra�z)
	set_remove(s, &n4);
	set_print(s);

	set_destroy(s);

	return 0;
}
