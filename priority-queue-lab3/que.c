#include "que.h"

que newq(){
	que tmp;

	tmp.head = NULL;
	tmp.tail = NULL;
	return tmp;
}

int isemptyq(que q){
	if(q.head == NULL || q.tail == NULL)
		return 1;
	else
		return 0;
}

que delq(que q){

	if(isemptyq(q)){
		printf("queue already empty\n");
		return q;
	}
	else{
		//if there is only a single element
		if(q.head == q.tail){
			free(q.head);
			q.head = q.tail = NULL;
		}
		else{
			node * tmp = q.head;

			q.head = q.head->next;
			free(tmp);
		}
		return q;
	}
}

element front(que q){
	if(!isemptyq(q))
		return (q.head->e);
	else{
		element nul;
		nul.val = -365;
		return nul;
	}
}

que addq(que q,element el){
	

	node* tmp = malloc(sizeof(node));
	
	tmp->e.val = el.val;
	tmp->e.priority = el.priority;

	if(isemptyq(q)){
		tmp->next = NULL;
		q.head = tmp;
		q.tail = tmp;
	}
	else{
		tmp->next = NULL;
		q.tail->next=tmp;
		q.tail = tmp;
	}

//	printf("returning...\n");
	return q;
}

int lengthq(que q){

	node *tmp = q.head;
	int count = 0;

	while(tmp != NULL){
		count++;
		tmp = tmp->next;
	}
	return count;
}