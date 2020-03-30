#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string tolower(string a)
{
	string b = a;
	for(int i = 0;i < b.length();i++)
	{
		if((b[i] >= 'A') && (b[i] <= 'Z'))
		{
			b[i] = b[i] + 32;
		}
	}
	return b;
}

short int_len(int number)
{
	short len = 0;
	do
	{
		number = number / 10;
		len++;
	}
	while(number != 0);

	return len;
}

short double_len(double number)
{
	short len = 0;
	int int_part = int(number);
	double float_part = number - int_part;

	do
	{
		int_part = int_part / 10;
		len++;
	}
	while(int_part != 0);

	if(float_part == 0)
	{
		return len;
	}

	while(float_part >= 0.0000001)
	{
		float_part = float_part * 10;
		float_part = float_part - int(float_part);
		len++;
	}

	return len + 1; // dot character
}

struct worker
{
	public:
		void input_worker();
		int number;
		string name;
		string position;
		int year;
		double salary;
};

void worker::input_worker()
{
	cout<<"Input number:"<<endl; cin>>number;
	cout<<"Input name:"<<endl; cin.ignore(); getline(cin, name);
	cout<<"Input position:"<<endl; cin.ignore(); getline(cin, position);
	cout<<"Input year:"<<endl; cin>>year;
	cout<<"Input salary:"<<endl; cin>>salary;
}

void swap(worker & a, worker & b)
{
	worker temp = new worker;
	temp = a;
	a = b;
	b = temp;
	delete temp;
}

int max(int a, int b)
{
	if(a < b)
	{
		return b;
	}
	return a;
}

void input_array(worker * array, int size)
{
	for(int i = 0;i < size;i++)
	{
		array[i].input_worker();
	}
}

void alphabetic_sort(worker * array, int size)
{
	int max_len;
	bool change;

	for(int i = 0;i < size;i++)
	{
		for(int j = i + 1;j < size;j++)
		{
			change = false;
			max_len = max(array[i].name.length(), array[j].name.length());
			for(int letter = 0;letter < max_len;letter++)
			{
				if(tolower(array[i].name)[i] > tolower(array[i].name)[j])
				{
					change = true;
					break;
				}
			}
			if(!change && (array[i].name.length() > array[j].name.length()))
			{
				change = true;
			}
			if(change)
			{
				swap(array[i], array[j]);
			}
		}
	}
}

void workers_table(worker * array, int size)
{
	const int year_len = 4;

	string field[5] = {"Number", "Name", "Position", "Year", "Salary"};

	short field_len = 0;

	for(int i = 0;i < 5;i++)
	{
		field_len += field[i].length();
	}

	short max_number_len = field[0].length();
	short max_name_len = field[1].length();
	short max_pos_len = field[2].length();
	short max_salary_len = field[4].length();

	short curr_number_len;
	short curr_name_len;
	short curr_pos_len;
	short curr_salary_len;
	for(int i = 1;i < size;i++)
	{
		curr_number_len = int_len(array[i].number);
		if(curr_number_len > max_number_len)
		{
			max_number_len = curr_number_len;
		}
		curr_name_len = array[i].name.length();
		if(curr_name_len > max_name_len)
		{
			max_name_len = curr_name_len;
		}
		curr_pos_len = array[i].position.length();
		if(curr_pos_len > max_pos_len)
		{
			max_pos_len = curr_pos_len;
		}
		curr_salary_len = double_len(array[i].number);
		if(curr_salary_len > max_salary_len)
		{
			max_salary_len = curr_salary_len;
		}
	}

	short table_length =
		max_salary_len +
		max_pos_len +
		max_name_len +
		max_number_len +
		year_len +
		6;

	if(field_len > table_length)
	{
		table_length = field_len;
	}

	for(int i = 0; i < table_length; i++) cout<<'-';

	cout<<endl;

	cout<<'|'<<setw(max_number_len)<<field[0];
	cout<<'|'<<setw(max_name_len)<<field[1];
	cout<<'|'<<setw(max_pos_len)<<field[2];
	cout<<'|'<<setw(year_len)<<field[3];
	cout<<'|'<<setw(max_salary_len)<<field[4]<<'|'<<endl;

	for(int i = 0; i < table_length; i++) cout<<'-';

	cout<<endl;

	cout.fill(' ');
	for(int i = 0;i < size;i++)
	{
		cout<<'|'<<setw(max_number_len)<<array[i].number;
		cout<<'|'<<setw(max_name_len)<<array[i].name;
		cout<<'|'<<setw(max_pos_len)<<array[i].position;
		cout<<'|'<<setw(year_len)<<array[i].year;
		cout<<'|'<<setw(max_salary_len)<<array[i].salary<<'|'<<endl;
		for(int i = 0; i < table_length; i++) cout<<'-';
		cout<<endl;
	}


	cout<<endl;
}

worker search(int number, worker * array, int size)
{
	for(int i = 0;i < size;i++)
	{
		if(array[i].number == number)
		{
			return array[i];
		}
	}
}

int main()
{
	int size;
	cout<<"Input workers quantity: "; cin>>size;
	worker * group = new worker[size];
	input_array(group, size);
	alphabetic_sort(group, size);
	workers_table(group, size);
	delete [] group;
	return 0;
}
