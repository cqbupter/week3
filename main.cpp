#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string num2str(int num)
{
    string res = "";
    while(num)
    {
        res = char(num % 10 + '0') + res;
        num /= 10;
    }
    return res;
}

string func(string s)
{
   map<char, int> ch_num;
   for(size_t j = 0; j < s.size(); ++j)
   {
       ++ch_num[s.at(j)];
   }
   map<char, int>::const_iterator it = ch_num.begin();
   char m_ch = it->first;
   int num = it->second;
   while(it != ch_num.end())
   {
       if(it->second > num)
       {
           m_ch = it->first;
           num = it->second;
       }
       ++it;
   }
   string res(1, m_ch);
   res += " " + num2str(num);
   return res;
}

int main()
{
    int line;
    cin >> line;
//    vector<string> res;
    string *res = new string[line];
    for(int i = 0; i < line; ++i)
    {
        string s;
        cin >> s;
       //res.push_back(func(s));
       *(res + i) = func(s);
    }
 /*   for(vector<string>::const_iterator it = res.begin();
    it != res.end(); ++it)
    {
        cout << *it << endl;
    }*/
    for(int i = 0; i < line; ++i)
    {

       cout << *(res + i) << endl;
    }

}
