#include<iostream>
using namespace std;
char deletevowel(char*a,char*b,int i,int j,int n);
int main()
{
    int n;
    cout<<"please enter the number of characters"<<endl; 
    cin>>n;
    char *p=new char[n];
    cout<<"please enter the words"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    char *q=new char[n];//store the words after deletion
    deletevowel(p,q,0,0,n);
    int len=sizeof(q);
    for(int i=0;i<len;i++)
    {
        cout<<q[i];
    }
    return 0;
}
char deletevowel(char*a,char*b,int i,int j,int n)
{
    if(i==n) return *b;//basic condition
    else
    {
        if(a[i]!='a'&&a[i]!='e'&&a[i]!='i'&&a[i]!='o'&&a[i]!='u')
        {
            b[j]=a[i];
            return deletevowel(a,b,i+1,j+1,n);
        }
        else return deletevowel(a,b,i+1,j,n);
    }

}
