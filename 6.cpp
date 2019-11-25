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

double segment_len(double x1, double  y1, double  x2, double  y2)
{
	double x_len = x2-x1;
	double y_len = y2-y1;
	return hypotenuse(x_len, y_len);
}

bool triangle(double a, double b, double c)
{
	if(a<b+c && b<c+a && c<a+b)
	{
		return true;
	}
	return false;
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

int task_13()
{
	double ab, ac, dc;
	cin>>ab>>ac>>dc;
	cout<<ab+ac+dc+hypotenuse(hypotenuse(ab, ac), dc)<<endl;
	return 0;
}

int task_16()
{
	double x1, x2, x3, y1, y2, y3;
	double len1, len2, len3;
	cout<<"Input the coordinates of the point #1"<<endl;
	cin>>x1>>y1;
	cout<<"Input the coordinates of the point #2"<<endl;
	cin>>x2>>y2;
	cout<<"Input the coordinates of the point #3"<<endl;
	cin>>x3>>y3;
	len1 = segment_len(0, 0, x1, y1);
	len2 = segment_len(0, 0, x2, y2);
	len3 = segment_len(0, 0, x3, y3);
	if(max(max(len1, len2), len3)==len1)
	{
		cout<<"Point with coordinates ("<<x1<<";"<<y1<<")";
	}
	else if(max(max(len1, len2), len3)==len2)
	{
		cout<<"Point with coordinates ("<<x2<<";"<<y2<<")";
	}
	else
	{
		cout<<"Point with coordinates ("<<x3<<";"<<y3<<")";
	}
	return 0;
}


int task_19()
{
	const int num_of_dots = 4;
	double x[num_of_dots], y[num_of_dots];
	int counter = 0;
	
	for (int i = 0; i < num_of_dots; ++i)
	{
		cout « "#" « i + 1 « endl;
		cout « "x" « i + 1 « ": ";
		cin » x[i];
		cout « "\ty" « i + 1 « ": ";
		cin » y[i];
	}
	
	int a, b, c;
	
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{	

				a = segment_len(x[i], y[i], x[j], y[j]);
				b = segment_len(x[j], y[j], x[k], y[k]);
				c = segment_len(x[i], y[i], x[k], y[k]);
				counter+=triangle(a,b,c);
			}
		}
	}

cout « "Number of triangles: " « count « endl;
return 0;
}

double f_1(double x, double a, double b)
{
	if(abs(x)<3)
	{
		return sin(x);
	}
	else if (abs(x)>=3 && abs(x)<9)
	{
		return sqrt(x*x+1)/sqrt(x*x+5);
	}
	return sqrt(x*x+1)-sqrt(x*x+5);
}

double f_4(double x, double a, double b)
{
	double expression = x*x-5*x;
	if(expression<0)
	{
		return a+b;
	}
	else if (expression>=0 && expression<10)
	{
		return a-b;
	}
	return a*b;
}

double f_7(double x, double a, double b)
{
	double expression = abs(x);
	if(expression<=1)
	{
		return x*x-1;
	}
	else if (expression>1 && expression<=2)
	{
		return 2*x-1;
	}
	return pow(x, 5)-1;
}

double f_10(double x, double a, double b)
{
	double expression = x;
	if(expression<=5)
	{
		return x*x+5;
	}
	else if (expression>5 && expression<20)
	{
		return 0;
	}
	return 1;
}

double f_13(double x, double a, double b)
{
	double expression = x;
	if(expression<0)
	{
		return 0.2*x*x-x-0.1;
	}
	else if (expression>0)
	{
		return x*x/(x-0.1);
	}
	return 0;
}

double f_16(double x, double a, double b)
{
	double expression = x;
	if(expression<93)
	{
		return a + b*x;
	}
	else if (expression>=93 && expression<=120)
	{
		return b-a*x;
	}
	return a*b*x;
}

double f_19(double x, double a, double b)
{
	double expression = abs(x);
	if(expression<M_PI/2)
	{
		return sin(x);
	}
	else if (expression>=M_PI/2 && expression<=M_PI)
	{
		return cos(x);
	}
	return 0;
}

int main()
{
	double a;
	double b;
	double h;
	int choice;
	cout<<"Choose task: ";
	cin>>choice;
	cout<<"Input segment's border"<<endl;
	do
	{
		cout<<"A= ";
		cin>>a;
		cout<<"B= ";
		cin>>b;
		if(a>b)
		{
			cout<<"Invalid input. Try again."<<endl;
		}
	}
	while(a>b);
	cout<<"Input step"<<endl;
	cout<<"h= ";
	cin>>h;
	for(double i = a;i <= b;i += h)
	{
		switch (choice)
		{
			case 1: cout<<"f("<<i<<")="<<f_1(i, a, b)<<endl;break;
			case 4: cout<<"f("<<i<<")="<<f_4(i, a, b)<<endl;break;
			case 7: cout<<"f("<<i<<")="<<f_7(i, a, b)<<endl;break;
			case 10: cout<<"f("<<i<<")="<<f_10(i, a, b)<<endl;break;
			case 13: cout<<"f("<<i<<")="<<f_13(i, a, b)<<endl;break;
			case 16: cout<<"f("<<i<<")="<<f_16(i, a, b)<<endl;break;
			case 19: cout<<"f("<<i<<")="<<f_19(i, a, b)<<endl;break;
			default: cout<<"Invalid input";break;
		}
	}
	return 0;
}
