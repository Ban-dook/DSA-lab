#include <stdio.h>
#include <stdlib.h>

enum boolean{
	false,true
};


struct elem{
	int val;
	int priority;
};
typedef struct elem element;

struct linked{
	element e;
	struct linked *next;
};
typedef struct linked node;

struct queue{
	node * head;
	node * tail;
};
typedef struct queue que;

//declarations
que newq();
int isemptyq(que q);
que delq(que q);
element front(que q);
que addq(que q,element el);
int lengthq(que q);
