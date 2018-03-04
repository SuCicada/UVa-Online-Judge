#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char *s="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char c;
    while((int)(c=getchar())!=EOF)
    {
        char *p;
        if(p=strchr(s,c))
            cout<<*(p-1);
        else
            cout<<c;
    }
    return 0;
}
