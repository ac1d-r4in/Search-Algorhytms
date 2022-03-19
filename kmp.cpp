#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string& s) {
    vector<int> pi(s.length(), 0);

    for (int i = 1; i < s.length(); i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            pi[i] = j + 1;
        } else {
            pi[i] = j;
        }
    }
    return pi;
}
int main() 
{
    string s, t;
    try
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (cin.fail() || s == "\n")
        throw 1;
        cout << "Enter line to find : ";
        getline(cin, t);
        if (cin.fail() || t == "\n")
        throw 1;
    }
    catch (int e)
    {
        if (e == 1)
            cout << "Empty input!" << endl;
        exit(e);
    }
    int count;
    vector<int> pi = prefix_function(t + '#' + s);
    int t_len = t.length();
    for (int i = 0; i < s.length(); i++)
    {
        if (pi[t_len + 1 + i] == t_len)
        {
            cout << "[" << i - t_len + 1 << ".." << i << "] is your line!" << endl;
            count++;
        }
    }
    if (count == 0)
        cout << "Line not found!\n";
    return 0;
}