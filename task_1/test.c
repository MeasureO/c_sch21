#include<stdio.h>

int main() {
	char name[20];
	printf("What is your name?\n");
	scanf("%19s", name);
	printf("%s\n", name);
	return 0;
}
