#include <iostream>
#include <fstream>

using namespace std;


void task_1_txt()
{
	char output_name[20];
	char filename[20];
	cout << "Input name of the output file: " << endl; cin >> output_name;
	cout << "Input name of the input file: " << endl; cin >> filename;
	fstream output(output_name, ios::out);
	fstream file(filename, ios::in);
	int number;
	while(!file.eof())
	{
		file >> number;
		if(number > 0)
		{
			output << number << ' ';
		}
	}
	file.clear();
	file.seekg(0, ios_base::beg);
	while(!file.eof())
	{
		file >> number;
		if(number < 0)
		{
			output << number << ' ';
		}
	}
	output << endl;
}

void task_1_bin()
{
	char output_name[20];
	char filename[20];
	cout << "Input name of the output file: " << endl; cin >> output_name;
	cout << "Input name of the input file: " << endl; cin >> filename;
	fstream output(output_name, ios::out | ios::binary);
	fstream file(filename, ios::in | ios::binary);
	int number;
	while(!file.eof())
	{
		file.read((char*)&number, sizeof(int));
		cout << number << ' ';
		if(number > 0)
		{
			output.write((char*)&number, sizeof(int));
		}
	}
	file.clear();
	file.seekg(0, ios_base::beg);
	while(!file.eof())
	{
		file.read((char*)&number, sizeof(int));
		cout << number << ' ';
		if(number < 0)
		{
			output.write((char*)&number, sizeof(int));
		}
	}
}

void task_2()
{
	char filename[20];
	cin >> filename;
	char symbol;
	int size = 0;
	int num_of_lines = 0;
	int min_len = 1000;
	int temp_len = 0;
	int max_len = 0;
	int max_index = 0;
	int min_index = 0;
	int cur_index = 0;

	fstream file(filename, ios::in);
	while(file.get(symbol))
	{
		size++;
		if(symbol == '\n')
		{
			if(temp_len > max_len)
			{
				max_len = temp_len;
				max_index = cur_index;
			}
			if(temp_len < min_len)
			{
				min_len = temp_len;
				min_index = cur_index;
			}
			num_of_lines++;
			temp_len = 0;
			cur_index++;
		}
		temp_len++;
	}
	cur_index = 0;

	char * shortest_line = new char[min_len];

	file.clear();
	file.seekg(0, ios_base::beg);
	while(cur_index != min_index)
	{
		while(!file.eof())
		{
			file.get(symbol);
			if(symbol == '\n')
			{
				file.get(symbol);
				cur_index++;
				break;
			}
		}
	}
	for(int i = 0;i < min_len;i++)
	{
		file.get(shortest_line[i]);
	}

	file.close();
	file.open(filename, ios::app);
	file << endl << "Size of file: " << size << " bytes" << endl;
	file << "Number of lines: " << num_of_lines << " lines" << endl;
	file << "Number of symbols: " << size << " symbols" << endl;
	file << "Index of the longest line: " << max_index+1 << endl;
	file << "Shortest line: '";
	file.write(shortest_line, min_len);
	file << "' and its size:" << min_len << endl;
	file.close();
	delete [] shortest_line;
}

void task_3()
{
	const char * input_name{"input.txt"};
	const char * output1_name{"output1.txt"};
	const char * output2_name{"output2.txt"};

	fstream input(input_name, ios::in);
	fstream output1(output1_name, ios::out);
	fstream output2(output2_name, ios::out);

	int cur_pos = 0;
	int len;
	int temp_len = 0;
	int cur_line = 0;
	char symbol;
	cin >> len;

	while(input.get(symbol))
	{
		if(symbol != '\n')
		{
			temp_len++;
			output1.put(symbol);
		}
		else
		{
			output1 << '\t' << cur_line+1 << '\t' << temp_len << endl;
			if(temp_len > len)
			{
				input.seekg(cur_pos, ios::beg);
				for(int i = 0;i <= temp_len;i++)
				{
					input.get(symbol);
					output2.put(symbol);
				}
			}
			++cur_pos += temp_len;
			temp_len = 0;
			cur_line++;
		}
	}
	input.close();
	output1.close();
	output2.close();
}

void task_4()
{
	const int size = 10;
	int matrix[size][size];
	const char * input_name{"input.txt"};
	const char * output_name{"output.txt"};
	fstream file(input_name, ios::in);
	fstream output(output_name, ios::out);
	bool ascending;

	for(int i = 0;i < size;i++)
	{
		for(int j = 0;j < size;j++)
		{
			file >> matrix[i][j];
		}
	}

	for(int i = 0;i < size;i++)
	{
		ascending = true;
		for(int j = 0;j < size-1;j++)
		{
			if(matrix[i][j] >= matrix[i][j+1])
			{
				ascending = false;
				break;
			}
		}
		if(ascending)
		{
			for(int j = 0;j < size;j++)
			{
				output << matrix[i][j] << ' ';
			}
			output << endl;
		}
	}
	file.close();
	output.close();
}

int main()
{
	task_4();
	return 0;
}
