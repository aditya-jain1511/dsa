#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    string s="((a+b^d)/(e-f)+g)";
    int l=s.length();
    char ar1[l];//operators
    char ar2[l];//operand and final
    char ar[l];
    int t1=-1;
    int t2=-1;
    for (int i=0;i<l;i++)
    {
        if (s[i]== '(')
        {
            ar1[++t1]=s[i];
            //cout <<"1"<<endl;
        }
        else if (s[i]== '^')
        {
            ar1[++t1]=s[i];
            //cout <<"2"<<endl;
        }
        else if (s[i]== '*')
        {
            if (ar1[t1]=='^')
            {
                ar2[++t2]=ar1[t1];
                ar1[t1]=s[i];
                //cout <<"3"<<endl;
            }
            else
            {
                ar1[++t1]=s[i];
                //cout <<"4"<<endl;
            }
        }
        else if (s[i]== '/')
        {
            if (ar1[t1]=='^'||ar1[t1]=='*')
            {
                ar2[++t2]=ar1[t1];
                ar1[t1]=s[i];
                //cout <<"5"<<endl;
            }
            else
            {
                ar1[++t1]=s[i];
                //cout <<"6"<<endl;
            }
        }
        else if (s[i]== '+')
        {
            if (ar1[t1]=='^'||ar1[t1]=='*'||ar1[t1]=='/')
            {
                ar2[++t2]=ar1[t1];
                ar1[t1]=s[i];
                //cout <<"7"<<endl;
            }
            else
            {
                ar1[++t1]=s[i];
                //cout <<"8"<<endl;
            }
        }
        else if (s[i]== '-')
        {
            //cout << ar1[t1]<<endl;
            if (ar1[t1]=='^'||ar1[t1]=='*'||ar1[t1]=='/'||ar1[t1]=='+')
            {
                ar2[++t2]=ar1[t1];
                ar1[t1]=s[i];
                //cout <<"9"<<endl;
            }
            else
            {
                ar1[++t1]=s[i];
                //cout <<"10"<<endl;
            }
        }
        else if (s[i]== ')')
        {
            while(ar1[t1]!='(')
            {
                ar2[++t2]=ar1[t1];
                --t1;
                //cout <<"11"<<endl;
            }
            --t1;
            //cout << ar1[t1]<<endl;
        }
        else
        {
            ar2[++t2]=s[i];
            //cout <<"12"<<endl;
        }
    }
    for(int i=0;i<=t2;i++)
    {
        cout << ar2[i];
    }
    cout << endl;
    return 0;
}