#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool PrimeTest(int n) {
	int i;
	for (i = 2; i <= sqrt(n); i++) 
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(void)
{
	FILE* fp;
	if((fp = fopen("result.txt","w")) == NULL)
		exit(EXIT_FAILURE);
	
	unsigned j, k;
	for(j = 2; j < 65535; j++) {
		if(PrimeTest(j)) {
			for(k = j; (j * k) < 65535; k++) {
				if(PrimeTest(k)) {
					fprintf(fp,"Prime:%u Prime:%u Product:%u\n", j, k, j * k);
				}
			}
		}
	}

	if(fclose(fp) == EOF)
		puts("The file close is failed.");
	
	
	return 0;
}
