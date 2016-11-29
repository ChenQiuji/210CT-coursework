#include<iostream>
using namespace std;
int main(){
	int a,b;
	int max=0;
	cout<<"please enter a number"<<endl;
	cin>>a;
	for(int i=1;i<a/2;i++){
		b=i*i;
		if(b<=a&&b>max)
		  max=b;
	}
	cout<<"the highest perfect square is "<<max;
	return 0;
} 
