#include <iostream>
#include <cmath>

using namespace std;

double min(double a, double b)
{
	if(a<b)
	{
		return a;
	}
	return b;
}

double max(double a, double b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}

double f(double a)
{
	return cos(2*a)+sin(a-3);
}

double f(int a)
{
	return sqrt(a) + a;
}

int f1(int a)
{
	if(a%5==0)
	{
		return a/5;
	}
	return a+1;
}

double hypotenuse(double a, double b)
{
	return sqrt(a*a+b*b);
}

double segment_len(double x1, y1, x2, y2)
{
	double x_len = x2-x1;
	double y_len = y2-y1;
	return sqrt(x_len*x_len+y_len*y_len);
}

int task_1()
{
	double a, b, c, d;
	cin>>a>>b>>c>>d;
	cout<<min(min(a, b), min(c, d))<<endl;
	return 0;
}

int task_4()
{
	double a, b;
	cin>>a>>b;
	if(min(f(a), f(b))==f(a))
	{
		cout<<a<<endl;
	}
	else
	{
		cout<<b<<endl;
	}
	return 0;
}

int task_7()
{
	cout<<(f(6)+f(13)+f(21))/2<<endl;
	return 0;
}

int task13()
{
	double ab, ac, dc;
	cin>>ab>>ac>>dc;
	cout<<ab+ac+dc+hypotenuse(hypotenuse(ab, ac), dc)<<endl;
	return 0;
}

int main()
{

}
