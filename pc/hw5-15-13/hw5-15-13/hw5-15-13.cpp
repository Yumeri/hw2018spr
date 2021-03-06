// hw5-15-13.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define PI 3.141592654f

double randf() {
	return (double)rand() / RAND_MAX;
}

double buffon_laplace() {
	unsigned int in_rect = 0;
	unsigned int total = 0;


	//假设a=b=l=1
	for (int i = 0; i < 1e6; i++) {
		//针尖位置
		double p0_x = randf();
		double p0_y = randf();
		//角度
		double theta = randf() * 2 * PI;
		//针尾位置
		double p1_x = p0_x + cos(theta);
		double p1_y = p0_y + sin(theta);
		if (p1_x >= 0.0f && p1_x <= 1.0f && p1_y >= 0.0f && p1_y <= 1.0f)in_rect++;
		total++;
	}
	double pro = 1 - (double)in_rect / total;
	return 3.0f / pro;
}
int main()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 3; i++) {
		clock_t start = clock();
		double pi = buffon_laplace();
		clock_t t = clock() - start;
		printf("|%d|%lf|\n", t, pi);
	}
	
    return 0;
}

