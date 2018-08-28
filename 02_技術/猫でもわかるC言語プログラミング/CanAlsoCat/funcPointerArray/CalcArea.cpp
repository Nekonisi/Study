#define PI 3.14
#include <stdio.h>
#include <stdlib.h>

double triangle(){
	char str[32];
	double base, height;

	printf("Calculate the area of ​​the triangle.\n");
	printf("input Base value ... ");
	gets_s(str);
	base = atof(str);
	printf("input height value ... ");
	gets_s(str);
	height = atof(str);

	double area = (base * height) / 2.0;
	return area;
}

double trapezoid(){
	char str[32];
	double upperBase, bottom, height;

	printf("Calculate the area of ​​the trapezoid.\n");
	printf("input upperBase value ... ");
	gets_s(str);
	upperBase = atof(str);
	printf("input bottom value ... ");
	gets_s(str);
	bottom = atof(str);
	printf("input height value ... ");
	gets_s(str);
	height = atof(str);

	double area = ((upperBase + bottom) * height) / 2.0;
	return area;
}

double circle(){
	char str[32];
	double radius;

	printf("Calculate the area of ​​the circle.\n");
	printf("input radius value ... ");
	gets_s(str);
	radius = atof(str);

	double area = (radius*radius)*PI;
	return area;
}