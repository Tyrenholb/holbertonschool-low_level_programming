#include <stdio.h>

/**
*main - Entry point
*
*Return: Always 0
*
*/

int main(void)
{
	int menu = 1;
	int A = 0;
	int B = 0;

	printf("Welcome to my calculator! please select an option!\n");
while (menu != 0)
{
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
	printf("Choice: 1 \n");
	printf("A: ");
	scanf("%d", &A);
	printf("B: ");
	scanf("%d", &B);
	printf("Result: %d\n", A + B);
}
else if (menu == 2)
{
printf("Choice: 2 \n");
	printf("A: ");
	scanf("%d", &A);
	printf("B: ");
	scanf("%d", &B);
	printf("Result: %d\n", A - B);
}
else if (menu == 3)
{
printf("Choice: 3 \n");
	printf("A: ");
	scanf("%d", &A);
	printf("B: ");
	scanf("%d", &B);
	printf("Result: %d\n", A * B);
}
else if (menu == 4)
{
printf("Choice: 4 \n");
	printf("A: ");
	scanf("%d", &A);
	printf("B: ");
	scanf("%d", &B);
	printf("Result: %d\n", A / B);

}
else if (menu == 0)
{
	printf("Bye!\n");
	return (0);
}
else
{
	printf("Invalid choice");
}
}
return (0);
}
