#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int score;

	printf("Enter your score: ");
	scanf("%d", &score);

	if (score >= 80)
	{
		printf("New project.\n");
	}
	else
	{
		printf("You are disqualified.\n")
	}
	return (0);
}
