#include <stdio.h>

/**
*main - Entry point
*
*Return: Always 0
*
*/

int main(void)
{
	int menu;

	printf("Welcome to my calculator! please select an option!\n");

	printf("Enter a number from the list below\n\n");
	printf("1. Addition\n");
	printf("2. Subtract\n");
	printf("3. Multiply\n");
	printf("4. Divide\n");
	printf("0. Quit\n");

	printf("Enter Your choice: ");
	scanf("%d", &menu);

	printf("\n");
if (menu == 1)
{
	printf("Enter your additon here: \n");
}
else if (menu == 2)
{
	printf("Enter your Subtraction here: ");
}
else if (menu == 3)
{
	printf("Enter your multipication here: ");
}
else if (menu == 4)
{
	printf("Enter your divison here: ");
}
else if (menu == 0)
{
	printf("Bye!\n");
	return (0);
}
return (0);
}
