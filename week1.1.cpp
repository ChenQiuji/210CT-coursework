#include<iostream>
#include<cstdlib>
#include<ctime>
#define n 8
using namespace std;

int main(){
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	srand(time(0));
	
	int j,b; 
	for(int i=0;i<n;i++){
		j=rand()%n;
		b=a[i];
		a[i]=a[j];
		a[j]=b;
	}
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	
	return 0;
} 
