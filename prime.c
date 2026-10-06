/* MERA-400 PRIME SEARCH TEST */
/* trwgQ26xxx, 04.10.2026 */

/* Finds a defined number of primes from 2 and prints the last one */

#include <stdio.h>
#include <math.h>

/* Number of primes to search */
#define SEARCH_COUNT 2000

/* Counter for number of checks performed */
long check_count = 0;

/* Helper function to check if number is prime or not */
int Is_prime(number)
int number;
{
	int i, limit;

	/* Numbers below 2 are not prime */
	if(number < 2)
		return 0;

	/* Check for divisors up to square root of number */
	limit = (int)sqrt((float)number);
	/* Check for divisors up to half of the number */
	/* limit = number / 2; */

	for(i = 2; i <= limit; i++){
		/* Increment check counter */
		check_count++;

		/* Check if number is divisible by i */
		if((number % i) == 0)
			return 0;
	}

	/* Number is prime */
	return 1;
}

int main()
{
	int i = 2, primes_count = 0, last_prime_found = 0;

	/* Start */
	printf("MERA-400 PRIME SEARCH TEST. trwgQ26xxx, 04.10.2026\r\n");
	printf("Searching for %d primes...\r\n", (int)SEARCH_COUNT);

	/* Search up to defined number */
	while(primes_count < SEARCH_COUNT){
		/* Check if given number is prime */
		if(Is_prime(i)){
			/* It is, store it */
			last_prime_found = i;
			/* and increment number of primes found */
			primes_count++;
		}

		/* Advance to next number */
		i++;
	}

	/* End */
	printf("Done. %dth prime is %d. %ld total divide checks.\r\n",
		(int)SEARCH_COUNT,
		last_prime_found,
		check_count);

	return 0;
}
