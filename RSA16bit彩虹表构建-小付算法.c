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
	bool isPrime = false;
	unsigned int prime[2] = {2,2};
	unsigned int product;
	FILE* fp;
	
	if((fp = fopen("result.txt","w")) == NULL)
		exit(EXIT_FAILURE);
		
	
	while(prime[0]*2 <= 65535)
	{
		if((product = prime[0]*prime[1]) <= 65535)
		{
			fprintf(fp,"Prime:%u Prime:%u Product:%u\n",prime[0],prime[1],product);
			while(!isPrime)
			{
				prime[1]++;
				isPrime = PrimeTest(prime[1]);
			}
			isPrime = false;
		}
		else
		{
			
			while(!isPrime)
			{
				prime[0]++;
				isPrime = PrimeTest(prime[0]);
			}
			isPrime = false;
			prime[1] = prime[0];
		}
	}
	
	if(fclose(fp) == EOF)
		puts("The file close is failed.");
	
	
	return 0;
}
