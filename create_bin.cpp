#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char filename[20];
	int number;
	cin >> filename;
	fstream from(filename, ios::in);
	cin >> filename;
	fstream file(filename, ios::out | ios::binary);
	while(!from.eof())
	{
		from >> number;
		file.write((char*)&number, sizeof(number));
	}
	return 0;
}
