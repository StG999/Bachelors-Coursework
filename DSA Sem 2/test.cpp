#include <iostream>
#include <string.h>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void addData(int arr[])
{
    for(int i=0; i<5; i++)
    {
        arr[i] = i*10;
    }
}

int main() {
    // string tmp, s;
    // getline(cin, s);
    
    // for(int i=1; i<s.length()-1; i++)
    // {
    //     tmp.push_back(s[i]);
    // }
    // cout<<endl<<tmp;

    // string s;
    // // cin>>s;
    // // cout<<s;


    // getline(cin, s);

    // s[5] = '$';
    // cout<<s;

    // char s[11];
    // gets(s);

    // char tmp[strlen(s)+1];
    // strcpy(tmp, s);
    // // cout<<tmp;

    // // s[0] = '$';
    // printf("%s", tmp);

    // int a[2] = {5, 10};

    // cout<<"a: "<<a[0]<<" b: "<<a[1]<<endl<<"swapping"<<endl;
    // swap(a[0], a[1]);
    // cout<<"a: "<<a[0]<<" b: "<<a[1]<<endl;

    // string a[2] = {"abc", "xyz"};
    // cout<<a[0][2]<<" "<<a[1][0];

    // string a;
    // // cout<<sizeof(a)<<endl;
    // a = "abc";
    // // cout<<sizeof(a);
    // // cout<<a.substr(1)<<endl;
    // // cout<<stoi(a.substr(0, 2)) + 4;
    // // cout<<int(a[0] - 49);

    // string c = a.substr(0, 1);
    // a.erase(0,1);
    // cout<<a<<endl;
    // // cout<<"b: "<<b<<endl;
    // cout<<"c: "<<c;

    // for(int i=1; i<=50; i++)
    //     cout<<i<<" ";

    // int a = 10, b= 99;
    // cout<<a<<' '<<b<<endl;
    // swap(a, b);
    // cout<<a<<' '<<b;

    // int ans[3][5];
    // for(int i=0; i<5; i++)
    // {
    //     ans[0][i] = i;
    //     ans[1][i] = i*5;
    // }

    // addData(ans[2]);

    // for(int i=0; i<5; i++)
    // {
    //     cout<<ans[0][i]<<" "<<ans[1][i]<<" "<<ans[2][i]<<endl;
    // }

    string a = "hello", b = "abh";
    // cout<<a.substr(1);

    a[0] == b[2] ? cout<<"yes" : cout<<"no";
}