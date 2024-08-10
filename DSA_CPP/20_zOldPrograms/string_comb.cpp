#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int compare(const void *a,const void * b)
{
    return (*(char*)a-*(char*)b);
}
int main()
{
char str[]="ABC";
char b[]="ba";
char c[10];
qsort(b,strlen(b),sizeof(char),compare);
int p=strlen(str);
int l=strlen(b);
int k,m;
for(int i=0;i<=p-l;i++)
{
    m=0;
    for(int j=i;j<i+l;j++)
    {c[m++]=str[j];
    
    }
    qsort(c,l,sizeof(char),compare);
    cout<<endl;
    for(k=0;k<l;k++)
    {   if(c[k]!=b[k]) break;  }
    if(k==l)
    cout<<"string is found at location i=  "<<i;
}
return 0;
}