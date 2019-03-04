#include "multiq.h"

multiq createmq(int num){
	multiq mq;

	mq.count = num;
	for(int i=0; i<num ; i++){
		mq.arr[i] = newq();
	}

	return mq;
}

multiq addmq(multiq mq,element t){

	if(t.priority > mq.count || t.priority < 1 ){
		printf("ERROR: exceeded queue count.\n");
	}
	else{
		mq.arr[t.priority-1] = addq(mq.arr[t.priority-1],t);
	}

	return mq;
}

element nextmq(multiq mq){
	//mq.count-1 is max priority

	int pr = mq.count-1;
	while(isemptyq(mq.arr[pr])){
		pr--;
		if(pr == -1){
			printf("Maa chudi pdi hai\n");
			element ret;
			ret.val = -1;
			ret.priority = -1;
			return ret;
		}
	}
	//jo bhi pr baahar ayega usse return karna hai
	return front(mq.arr[pr]);
}

multiq delnextmq(multiq mq){
	int pr = mq.count-1;

	while(isemptyq(mq.arr[pr])){
//		printf("this one's empty: %d\n",pr );
		pr--;

		if(pr == -1){
			printf("mq is empty.\n");
			
			return mq;
		}
	}

	mq.arr[pr] = delq(mq.arr[pr]);

	return mq;
}

int isemptymq(multiq mq){

	int pr = mq.count-1;

	while(isemptyq(mq.arr[pr])){
		pr--;
		if(pr == -1){
			printf("multique is empty\n");
			return 1;
		}
	}
	return 0;
}

int sizemq(multiq mq){
	int net = 0;

	for(int i= mq.count-1 ; i>=0 ;i--){
		net += lengthq(mq.arr[i]);
	}
	return net;
}

int sizemqbyp(multiq mq, int p){

	if(p > mq.count || p <= 0 ){
		printf("ERROR: queue count exceeded");
		return -1;
	}

	return lengthq(mq.arr[p-1]);
}

que getq(multiq mq,int p){

	return mq.arr[p-1];
}