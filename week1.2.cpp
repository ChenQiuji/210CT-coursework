#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"please enter a number"<<endl; 
	cin>>n;
	int count=0;
	int remain;
	for(int i=n;i>=5;i--){
		remain=i;
        while(remain%5==0){//count how many five in a number ,times
        	remain=remain/5;
			count++;
        }  	
	}
	cout<<"There are "<<count<<" 0s in a factorial number" <<endl;
	return 0;
} 

