#include <stdio.h>
#include <math.h>

#define Precision 0.1 //��ȷֵ

double F(double x)
{
	return pow(x,3.0) + 1.1*pow(x,2.0) + 0.9*x - 1.4; //��������ʽ
}

int main(void)

{
	double a = 0.0; //�������
	double b = 1.0; //�ұ�����
	double c; //���������е�
	while(1)
	{
		c = (a+b)*0.5;//ȡ�е�
		
		if(F(a)*F(c) < 0.0) //���[�������,�е�]�������
		{
			b = c; //��ô��ȡ�е���Ϊ�ұ�����
		}
		else if(F(b)*F(c) < 0.0) //���[�е�,�ұ�����]�������
		{
			a = c; //��ȡ�е���Ϊ�������
		}
		else if(F(c)==0.0) //����е�ʹ�ú���F(x)=0
		{
			a = b = c;
			break; //���Ϊ���̽⣬����ѭ��
		}
		else
		{
			a = b = -999.9999;
			break; //���������û�н⣬����ë�������-999.9999
		}
		
		if(fabs(a-b)<Precision) //���|a-b|<��ȷֵ��Ҳ���Ǵﵽ�˾�ȷֵ
		{
			break; //����ѭ��
		}
	}
	
	printf("���̽��ƽ�Ϊ��%.10lf\n",a); //���������䣬ȡ��Ϊ���̽��ƽ�
	printf("���̽��ƽ�Ϊ��%.10lf\n",b); //����ұ����䣬ȡ��Ϊ���̽��ƽ�
	getchar();
	
	return 0;
	
}