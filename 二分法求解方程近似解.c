#include <stdio.h>
#include <math.h>

#define Precision 0.1 //精确值

double F(double x)
{
	return pow(x,3.0) + 1.1*pow(x,2.0) + 0.9*x - 1.4; //函数解析式
}

int main(void)

{
	double a = 0.0; //左闭区间
	double b = 1.0; //右闭区间
	double c; //储存区间中点
	while(1)
	{
		c = (a+b)*0.5;//取中点
		
		if(F(a)*F(c) < 0.0) //如果[左闭区间,中点]内有零点
		{
			b = c; //那么则取中点作为右闭区间
		}
		else if(F(b)*F(c) < 0.0) //如果[中点,右闭区间]内有零点
		{
			a = c; //则取中点作为左闭区间
		}
		else if(F(c)==0.0) //如果中点使得函数F(x)=0
		{
			a = b = c;
			break; //则此为方程解，跳出循环
		}
		else
		{
			a = b = -999.9999;
			break; //这个区间内没有解，扯个毛啊，输出-999.9999
		}
		
		if(fabs(a-b)<Precision) //如果|a-b|<精确值，也就是达到了精确值
		{
			break; //跳出循环
		}
	}
	
	printf("方程近似解为：%.10lf\n",a); //输出左闭区间，取其为方程近似解
	printf("方程近似解为：%.10lf\n",b); //输出右闭区间，取其为方程近似解
	getchar();
	
	return 0;
	
}