#include "main.h"
#include <stdio.h>
/**
 * prime_helper - checks if a number has any divisors
 * @n: number to check
 * @divisor: current divisor being tested
 *
 * Return: 1 if n is prime, otherwise 0
 */
int prime_helper(int n, int divisor)
{
if (divisor * divisor > n)
return (1);

if (n % divisor == 0)
return (0);

return (prime_helper(n, divisor + 1));
}

/**
 * is_prime_number - checks if an integer is a prime number
 * @n: number to check
 *
 * Return: 1 if n is prime, otherwise 0
 */
int is_prime_number(int n)
{
if (n <= 1)
return (0);

return (prime_helper(n, 2));
}
