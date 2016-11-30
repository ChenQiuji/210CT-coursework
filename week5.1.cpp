#include<iostream>
using namespace std;
int sub_seq(int *a,int first,int last,int *b);
int main(){
	int n;
	cout<<"please enter the number of array"<<endl; 
	cin>>n;
    int a[n],b[2];
    cout<<"please enter the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    b[0]=1;//b[0]=max_length
    b[1]=0;//b[1]=output_startpoint
    sub_seq(a,0,n,b);
    for(int i=b[1];i<b[0]+b[1];i++){
    	cout<<a[i]<<" ";
    }
    return 0;
}
int sub_seq(int *a,int first,int last,int *b){
	if(first>last)return *b;//return an array with max length and startpoint
	else{
         int i;
         int count=1;
         for(i=first+1;i<last;i++){//compare with the former one
    	   if(a[i]>a[i-1])count++;
    	   else if(a[i]<a[i-1]) break;
         }
         if(b[0]<count){
           b[0]=count;//b[0]=max length
           b[1]=first;//b[1]=output_startpoint
         }
    return sub_seq(a,count+first,last,b);
    }
        
    }

