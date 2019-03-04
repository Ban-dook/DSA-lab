#include "multiq.h"
#include <sys/time.h>

int main()
{
	struct timeval t1,t2;

	FILE *input = fopen("input10000.txt","r");
	

	multiq test = createmq(10);
		printf("created test\n");

	gettimeofday(&t1,NULL);
	printf("%ld\n",t1.tv_usec);

	element testelement;
		while(fscanf(input,"%d,%d\n",&testelement.val,&testelement.priority) != EOF){
	//		printf("no problem in while loop\n");
			test = addmq(test , testelement );
		}

	element eee;
	while(!isemptymq(test)){
		eee = nextmq(test);
//		printf("%d %d\n",eee.val ,eee.priority);
		test = delnextmq(test);
	}
	

	gettimeofday(&t2,NULL);

	printf("%ld\n",t2.tv_usec);
	double elt = (t2.tv_sec - t1.tv_sec)*1000 + (t2.tv_usec - t1.tv_usec)/1000;
	printf("elapsed time(milli sec): %lf\n",elt);


	fclose(input);
	return 0;
}