#include "main.h"
#include <stdio.h>
/**
 * sqrt_helper - finds the natural square root of a number
 * @n: number to find the square root of
 * @guess: current number being tested
 *
 * Return: natural square root of n, or -1 if none exists
 */
int sqrt_helper(int n, int guess)
{
if (guess * guess == n)
return (guess);
if (guess * guess > n)
return (-1);

return (sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find the square root of
 *
 * Return: natural square root of n, or -1 if none exists
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);

return (sqrt_helper(n, 0));
}
