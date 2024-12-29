#include<iostream>
#include <unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    string str1, str2;
     cout << "Enter the String1 :";
    cin >> str1;
     cout << "Enter the String2 :";
    cin >> str2;
    unordered_map<char, int> str1_count(str1.length());
    unordered_map<char, int> str2_count(str2.length());
    for (int i = 0; i < str1.length(); i++)
    {
        str1_count[str1[i]]++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        if (str1_count.find(str2[i]) == str1_count.end())
        {
            cout << "NO";
            return 0;
        }
        else
        {
            str2_count[str2[i]]++;
            if (str2_count[str2[i]] > str1_count[str1[i]])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";


    return 0;

}
