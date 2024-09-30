#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int  main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n;
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
      arr[i]=k;
      k+=1;
      // cout<<arr[i]<<" ";
    }
    int ind=n/2;
    cout<<ind<<" ";
   int sum1=0;
   for(int i=0;i<=ind-1;i++){
    sum1+=arr[i];
   }
   int  sum2=0;
   for(int i=ind;i<n;i++){
    sum2+=arr[i];
   }
    cout<<abs(sum1-sum2)<<endl;
  }
}