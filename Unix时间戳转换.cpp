#include <iostream>

const int cycle = 365+365+365+366;//四年为一个周期
const int monthOfYear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//平年
const int monthOfLeapYear[12] = {31,29,31,30,31,30,31,31,30,31,30,31};//闰年

int main(void)
{
	using namespace std;
	
	int unixTime;
	
	//读取输入
	cout << "请输入Unix时间戳：";
	cin >> unixTime;
	
	
	//调整时区
	int seconds = unixTime + 28800;
	
	
	//得到秒
	int minutes = seconds/60;
	seconds%=60;
	
	//得到分
	int hours = minutes/60;
	minutes%=60;
	
	//得到天 并加上一个平年 凑够一个完整的周期
	int days = hours/24;
	days += 365;
	
	//得到时
	hours%=24;
	
	//得到年的一部分
	int years = days/cycle;
	years*=4;
	
	//得到不足一个周期的天数
	days %= cycle;
	
	//判断不足天数的年数
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
	
	//加上1969年
	years+=1969;
	
	//判断是平年还是闰年
	const int *pMonths = (years%4==0 ? monthOfLeapYear:monthOfYear);
	
	//判断所处月数和天数
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
	
	//输出结果
	cout << years << '/' << months << '/' << days << ' ' << hours << ':' << minutes << ':' << seconds << endl;
	
	return 0;
}