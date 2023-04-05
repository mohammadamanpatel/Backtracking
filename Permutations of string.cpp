#include<iostream>
using namespace std;
void permutations(string &s,int i)
{
    //base case
    if(i>=s.length())
    {
      cout<<s<<" ";
      return;
    }
    //ek case
    for(int j=i;j<s.length();j++)
    {
        swap(s[j],s[i]);
        permutations(s,i+1);
        swap(s[j],s[i]);
    }
}
int main()
{
    string s = "abc";
    int n = s.length();
    int i = 0;
    permutations(s,i);
}
