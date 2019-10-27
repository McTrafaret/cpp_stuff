#include <iostream>
#include <cmath>

using namespace std;

/* Задание 1
 *
void task1_1(int number)
{
	while (number>=10)
	{
		cout<<number<<endl;
		number-=2;
	}
}

void task1_2(int number)
{
	do
	{
		cout<<number<<endl;
		number-=2;
	}
	while(number>=10);
}

void task1_3(int number)
{
	for(number; number>=10; number-=2)
	{
		cout<<number<<endl;
	}
}

int task1()
{
	int number = 60;
	int answer;
	cin>>answer;

	switch(answer)
	{
		case 1: task1_1(number);break;
		case 2: task1_2(number);break;
		case 3: task1_3(number);break;
	}
	return 0;
}
*/

/* Задание 2
 *
double function(double x)
{
	double y;
	if (x>=-10&&x<=0)
	{
		y = (-x-6)/2;
	}
	else if (x>=0&&x<=3)
	{
		y = -sqrt(9-x*x);
	}
	else if (x>=3&&x<=6)
	{
		y = sqrt(9-((x-6)*(x-6)));
	}
	else
	{
		return 4;
	}

	return y;
}

int task2()
{
	double xs, xe, dx;
	double y;
	cout<<"Input start x: ";
	cin>>xs;
	cout<<"Input end x: ";
	cin>>xe;
	cout<<"Input step: ";
	cin>>dx;
	for(double i=xs; i<=xe; i+=dx)
	{
		y = function(i);
		if (y == 4)
		{
			break;
		}
		cout<<y<<endl;
	}
	return 0;
}
*/

/* Задание 3
 *
int task3()
{
	int shots=10;
	double x,y,R;
	cout<<"Input radius: ";
	cin>>R;
	for (int i=0; i<=shots; i++)
	{
		cout<<"Input x: ";
		cin>>x;
		cout<<"Input y: ";
		cin>>y;
		if ((abs(x)<=R)&&(abs(y)<=R))
		{
			if ((pow((x-R), 2)+pow((y+R), 2)<=R*R)&&(pow((x+R), 2)+pow((y-R), 2)>=R*R))
			{
				cout<<"Miss"<<endl;
			}
			else
			{
				cout<<"Hit"<<endl;
			}
		}
		else
		{
			cout<<"Miss"<<endl;
		}
	}
}
*/

/* Задание 4
 *
int task4()
{
	double s;
	int n;
	s = 0;
	cout<<"Input N: ";
	cin>>n;
	for(int i = 1; i<=n; i++)
	{
		s+=(1.0*(i+1))/i;
	}
	cout<<s<<endl;
	return 0;
}
*/

int main()
{
	double xs, xe, dx, e, row;
	cout<<"Input start x: ";
	cin>>xs;
	cout<<"Input end x: ";
	cin>>xe;
	cout<<"Input step: ";
	cin>>dx;
	cout<<"Input accuracy: ";
	cin>>e;
	for(xs; xs<=xe; xs+=dx)
	{
		if (abs(xs)>=1)
		{
			cout<<"|x| should be above 1";
			break;
		}
		row = 0;
		double previous=0;
		double present;
		for (int n=0;;n++)
		{
			present=(pow(xs, 2*n+1))/(2*n+1);
			if (abs(present-previous)<=e)
			{
				break;
			}
			else
			{
				row += present;
				previous = present;
			}
		}
		cout<<"ln((1+"<<xs<<")/(1-"<<xs<<"))"<<"="<<row<<endl;
	}
	return 0;
}
