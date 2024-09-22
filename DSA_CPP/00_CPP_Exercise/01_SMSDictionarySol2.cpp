#include <iostream>
#include <cstring>
using namespace std;
char A[][9]={{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
class Dictionary 
{
    public:
    int inverMap(char ch)
    {
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<strlen(A[i]);j++)
            {
                if (ch==A[i][j]) 
                 return i+2;
            }
        }
        return 0;
    }
    void sort(int a[],int n)
    {
        int i,j,key;
		for (i=1;i<n;i++)
		{	key=a[i];
			for (j=i-1;j>=0&&a[j]<key;j--)
			{
				a[j+1]=a[j];
			}
			a[j+1]=key;
		}
    }
    int maxTyped(int a[],int n)
    {
        int c,temp,hold=0,key=0;
        for (int i=0;i<n;i++)
        {
            temp=a[i]; c=0;
            for (int j=i;j<n;j++)
            {
                if (temp==a[j] )
                    c++;
                else
                {
                    if (c>hold)
                    {
                        key=temp;
                        hold=c;
                    }
                    i=j-1; break;
                }
            }
        }
        return key;
    }
    
    
};
int main()
    {
        Dictionary ob;
        int n=1;
        cin>>n;
        char word[n][20];
        int number[n];
        for (int i=0;i<n;i++)
        {
            cin>>word[i];
        }
        for (int i=0;i<n;i++)
        {
            int d=0;
            for (int j=0;j<strlen(word[i]);j++)
            {
                d=d*10+ob.inverMap(word[i][j]);
            }
            number[i]=d;
        }
        ob.sort(number,n);
        cout<<endl<<ob.maxTyped(number,n);
    }