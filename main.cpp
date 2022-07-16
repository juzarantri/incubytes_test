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
            s.erase(0, i + 2);
            getNumsSeperatedWithNewLine(nums, s);
            break;
        }
    }
    if (i == n)
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

    getNumsSeperatedWithNewLine(nums, s);
}

void checkNegativeNums(vector<int> &negNums, string &s, string &delimeter)
{
    size_t pos = 0;
    while ((pos = s.find(delimeter)) != string::npos)
    {
        string currNum = s.substr(0, pos);

        //// getting numbers seperated by newLine
        getNumsSeperatedWithNewLine(negNums, currNum);
        s.erase(0, pos + delimeter.length());
    }

    getNumsSeperatedWithNewLine(negNums, s);
}

void getDelemiter(string &s, string &delimeter)
{

    if (s[0] == 47 && s[1] == 47)
    {
        delimeter = s[2];
        s.erase(0, 5);
    }
}

void add(string &s)
{
    if (s == "")
    {
        cout << 0 << endl;
        return;
    }
    vector<int> nums;
    //// getting the delimeter
    string delimeter = ",";
    getDelemiter(s, delimeter);

    //// getting numbers seperated by comma
    getNumsSeperatedWithComma(nums, s, delimeter);

    // return accumulate(nums.begin(), nums.end(), 0);
    vector<int> negNums;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            negNums.push_back(nums[i]);
        }
        else
        {
            sum += nums[i];
        }
    }
    try
    {
        if (negNums.size() == 0)
        {
            cout << sum << endl;
        }
        else
        {
            throw ("negatives not allowed");
        }
    }
    catch (const char* s)
    {
        cout << s << endl;
        for(int i = 0; i < negNums.size(); i++){
            cout << negNums[i] << endl;
        }
        exit(0);
    }
}

int main()
{
    string s;
    getline(cin, s);

    add(s);

    return 0;
}
