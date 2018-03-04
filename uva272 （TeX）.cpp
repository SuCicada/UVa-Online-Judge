#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
    int o=1;
    char c;

    while((c=getchar())!=EOF)
    {
        if(c=='"')
        {
            printf("%s",o?"``":"''");
            o=!o;
        }
        else
            printf("%c",c);
    }
    return 0;
}
