#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void getNumsSeperatedWithNewLine(vector<int> &nums, string s)
{
    size_t n = s.length();
    size_t i;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 92)
        {
            string currNum = s.substr(0, i);
            nums.push_back(stoi(currNum));
            s.erase(0, i+2);
            getNumsSeperatedWithNewLine(nums,s);
            break;
        }
    }
    if(i == n)
        nums.push_back(stoi(s));
}

void getNumsSeperatedWithComma(vector<int> &nums, string &s, string &delimeter)
{
    size_t pos = 0;
    while ((pos = s.find(delimeter)) != string::npos)
    {
        string currNum = s.substr(0, pos);
        //// getting numbers seperated by newLine
        getNumsSeperatedWithNewLine(nums, currNum);
        s.erase(0, pos + delimeter.length());
    }
    
    getNumsSeperatedWithNewLine(nums,s);
    
}

int add(string &s)
{
    if (s == "")
        return 0;
    vector<int> nums;
    string delimeter = ",";

    //// getting numbers seperated by comma
    getNumsSeperatedWithComma(nums, s, delimeter);
    

    return accumulate(nums.begin(), nums.end(), 0);
}

int main()
{
    string s;
    getline(cin, s);

    cout << add(s) << endl;

    return 0;
}
