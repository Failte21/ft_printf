#define MAP(a, b, c, d, e) (a - b) * (e - d) / (c - b) + d

#include <stdio.h>

int main()
{
	float coord = 0.172;
	int red;
	
	red = MAP(coord, 0, 1, 0, 255);
	printf("%d\n", red);
}
