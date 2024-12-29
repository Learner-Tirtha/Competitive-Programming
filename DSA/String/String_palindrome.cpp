#include<iostream>
#include<vector>
using namespace std;
int main()
{
	string str;
	cout << "Enter the String :";
	cin >> str;
	for (int i = 0; i<int(str.length() / 2); i++)
	{
		if (str[i] != str[str.length() - i-1])
		{
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 0;
}