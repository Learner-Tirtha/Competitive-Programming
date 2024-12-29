#include<iostream>
#include<unordered_map>
using namespace std;
int LengthOfLongestSubstring(string& str)
{
	int maxLength = 0;
	int start, end;
	start = end = 0;
	unordered_map<char, int> map;
	for (end = 0; end < str.length(); end++)
	{
		if (map.find(str[end]) != map.end() && map[str[end]]>=start)
		{
			start = map[str[end]] + 1;
		}
		map[str[end]] = end;
		maxLength = max(maxLength, end - start + 1);
	}
	return maxLength;
}
int main()
{
	string str;
	cout << "Enter the String:";
	getline(cin, str);
	int count = LengthOfLongestSubstring(str);
	return 0;
}