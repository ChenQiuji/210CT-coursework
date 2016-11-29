#include<iostream>
using namespace std;
bool prime(int a,int b);
int main()
{
    int n,h;
    cout<<"please enter a number"<<endl;
    cin>>n;
    h=n/2;
    cout<<boolalpha<<prime(n,h);
}
bool prime(int a,int b)
{
	if(a<2) return false;//the negative number and 1 are not prime;  
    if(b==1)return true;//basic condition
    else
    {
        int remain=a%b;
        if(remain==0) return false;
        return prime(a,b-1);
    }
}
