#include "que.h"
#define MAX 10

struct multique{
	que arr[MAX];
	int count;
};
typedef struct multique multiq;


// declarations
multiq createmq(int num);
multiq addmq(multiq mq,element t);
element nextmq(multiq mq);
multiq delnextmq(multiq mq);
int isemptymq(multiq mq);
int sizemq(multiq mq);
int sizemqbyp(multiq mq,int p);
que getq(multiq mq,int p);
