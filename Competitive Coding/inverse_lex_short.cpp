#include <bits/stdc++.h>
using namespace std;
int arr[1010];
int main(){
int t,n,first,last,nosa,nosb;
string s;
scanf("%d",&t);
while(t--){
   cin >> s;
   n = s.size();
   nosa = 0;
   nosb = 0;
   for(int i=0;i<n;i++){
    if(s[i]=='a')
        nosa++;
    else
        nosb++;
   }
   if(nosa == n ||  nosb == n){
    printf("0,0\n");
    continue;
   }
   memset(arr,0,sizeof arr);
   for(int i=0;i<n;i++){
     if(s[i] == 'b'){
       first = i;
       break;
     }
   }
   arr[first] = 0;
   for(int i=first+1;i<n;i++){
     if(s[i] == 'a')
        arr[i] = arr[i-1]+1;
    else
        arr[i] = min(0,arr[i-1]-1);
   }
   int maxi = -1;
   int last;
   for(int i=first+1;i<n;i++){
     if(maxi<arr[i]){
        maxi = arr[i];
        last = i;
     }
   }
   printf("%d,%d\n",first,last);
}
return 0;
}
