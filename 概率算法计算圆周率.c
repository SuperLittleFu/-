#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000000000

int main(void)
{
	srand((unsigned int)time(NULL));
	clock_t start = clock();
	int count = 0;
	for(int i=0;i<N;i++)
	{
		int x = rand();
		int y = rand();
		
		if((x*x+y*y) < (RAND_MAX*RAND_MAX))
			count++;
		
	}
	
	printf("%lf\n",4*(double)count/(double)N);
	clock_t end = clock();
	printf("%lf",(double)(end - start)/(double)CLOCKS_PER_SEC);
	
	getchar();
	
	return 0;
	
}