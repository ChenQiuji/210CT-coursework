#include<iostream>
using namespace std;
bool binerysearch(int *a,int low,int high,int first,int last);
int main(){
    int n,low,high;
    cout<<"please enter the number of array"<<endl;
    cin>>n;
    int *L=new int[n];
    cout<<"please enter the array"<<endl;
    for(int i=0;i<n;i++){
      cin>>L[i];
    }
    cout<<"please enter low and high"<<endl;
    cin>>low>>high;
    cout<< boolalpha << binerysearch(L,low,high,0,n-1);
    return 0;
}
bool binerysearch(int *a,int low,int high,int first,int last){
    if(first>last) return false;
    else{
        int mid=(first+last)/2;
        if (a[mid]>=low && a[mid]<=high) return true;
        else if(mid<low)  binerysearch(a,low,high,mid+1,last);
        else if(mid>high) binerysearch(a,low,high,first,mid-1);
    }

}
