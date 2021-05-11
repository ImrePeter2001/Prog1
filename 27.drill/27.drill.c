#include <stdio.h>

void f(char *p, int x)
{
	printf("p is %s and x is %d\n", p, x);
}

int main()
{
	printf("Hello, world!\n");

	char h[] = "Hello";
	char w[] = "world!";

	printf("%s, %s\n", h, w);


	f("Szia", 1);
	f("Lajos", 2);
	f("kutyáidat, sétáltatod?", 3);

	return 0;
}