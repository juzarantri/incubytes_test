#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int add(string &s){
    if(s == "") return 0;
    vector<int> nums;
    size_t pos = 0;
    string delimeter = ",";
    while((pos = s.find(delimeter)) != string::npos){
        string currNum = s.substr(0,pos);
        nums.push_back(stoi(currNum));
        s.erase(0,pos+delimeter.length());
    }
    nums.push_back(stoi(s));
    return accumulate(nums.begin(),nums.end(),0);
}

int main()
{
    string s;
    std::cin >> s;
    
    cout << add(s) << endl;

    return 0;
}
