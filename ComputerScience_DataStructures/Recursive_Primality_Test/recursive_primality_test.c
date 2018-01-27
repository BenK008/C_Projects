#include <stdio.h>
#include <math.h>
#include <stdint.h>

int recursive_prime_test(uint32_t, double);

int main()
{
	uint32_t num;
	double sqrt_flr_num;
	printf("Please enter a number to test for primality: ");
	scanf("%u",&num);
	
	if (num == 1)
	{
		printf("\n%u is not prime, and it never will be.\n",num);
		return 0;
	}
	
	sqrt_flr_num = floor(sqrt(num));
	
	int p_num = recursive_prime_test(num, sqrt_flr_num);
	if (p_num == 1)
	{
		printf("\n%u is prime.\n",num);
	}
	else
	{
		printf("%u is not a prime number.\n",num);
	}
	return 0;
}

int recursive_prime_test(uint32_t test_num, double test_sqrt_num)
{
	if (test_sqrt_num == 1)
	{
		return 1;
	}
	else
	{
		if (test_num % (uint32_t)test_sqrt_num == 0)
		{
		    printf("\n%u divides %u; thus, ",(uint32_t)test_sqrt_num,test_num);
			return 0;
		}
		else
		{
			recursive_prime_test(test_num, test_sqrt_num - 1);
		}
	}
}