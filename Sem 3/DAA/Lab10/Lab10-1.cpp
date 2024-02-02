#include <bits/stdc++.h>
using namespace std;

int bruteforce(string text, string pattern)
{
    int length_text = text.length();
    int length_pattern = pattern.length();
    if (length_pattern > length_text)
    {
        return -1;
    }
    int t = 0;
    int p = 0;
    while (t < length_text)
    {
        if (text[t] == pattern[0])
        {
            int temp = t;
            while (temp < length_text && p < length_pattern && text[temp] == pattern[p])
            {
                temp++;
                p++;
            }
            if (p == length_pattern)
            {
                return t;
            }
            p = 0;
        }
        t++;
    }
    return -1;
}

int main()
{
    string a = "leetcode";
    string b = "tco";
    cout << "index of pattern is ";
    cout << bruteforce(a, b) << endl;
}