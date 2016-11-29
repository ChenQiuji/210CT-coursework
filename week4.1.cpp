#include<iostream>
#include<string>
using namespace std;
string* reverse(string*a,int begin,int end);
int main(){
	int num_of_words;//1
	cout<<"please enter the number of words"<<endl;
	cin>>num_of_words;//1
	string str[num_of_words];//1
	for(int i=0;i<num_of_words;i++){//num_of_words
		cin>>str[i];
	}
	reverse(str,0,num_of_words-1);//call for num_of_words/2 times
	for(int i=0;i<num_of_words;i++)//num_of_words
	{
	   cout<<str[i]<<" ";
    }
    return 0;
}
string* reverse(string*a,int begin,int end){//num_of_words/2
	if((end-begin)<=1) return a;
	string b=a[begin];//swap a[begin] and a[end] 
	a[begin]=a[end];
	a[end]=b;
	reverse(a,begin+1,end-1);
}

//BigO O(n)=n;
