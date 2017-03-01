#include <iostream>

const int cycle = 365+365+365+366;//����Ϊһ������
const int monthOfYear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//ƽ��
const int monthOfLeapYear[12] = {31,29,31,30,31,30,31,31,30,31,30,31};//����

int main(void)
{
	using namespace std;
	
	int unixTime;
	
	//��ȡ����
	cout << "������Unixʱ�����";
	cin >> unixTime;
	
	
	//����ʱ��
	int seconds = unixTime + 28800;
	
	
	//�õ���
	int minutes = seconds/60;
	seconds%=60;
	
	//�õ���
	int hours = minutes/60;
	minutes%=60;
	
	//�õ��� ������һ��ƽ�� �չ�һ������������
	int days = hours/24;
	days += 365;
	
	//�õ�ʱ
	hours%=24;
	
	//�õ����һ����
	int years = days/cycle;
	years*=4;
	
	//�õ�����һ�����ڵ�����
	days %= cycle;
	
	//�жϲ�������������
	if(days >= 365 && days < 365+365)
	{
		years+=1;
		days-=365;
	}
	else if(days >= 365+365 && days < 365+365+365)
	{
		years+=2;
		days-=365+365;
	}
	else if(days >= 365+365+365 && days < 365+365+365+366)
	{
		years+=3;
		days-=365+365+365;
	}
	
	//����1969��
	years+=1969;
	
	//�ж���ƽ�껹������
	const int *pMonths = (years%4==0 ? monthOfLeapYear:monthOfYear);
	
	//�ж���������������
	int months;
	for(int i = 0,j = 0,k = *pMonths;i<12;i++)
	{
		if(days >= j && days < k)
		{
			months = i+1;
			days = days-j+1;
			break;
		}
		j += *(pMonths+i);
		k += *(pMonths+i+1);
	}
	
	//������
	cout << years << '/' << months << '/' << days << ' ' << hours << ':' << minutes << ':' << seconds << endl;
	
	return 0;
}