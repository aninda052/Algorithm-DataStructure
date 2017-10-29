#include<bits/stdc++.h>
using namespace std;

int arr[50000],Size[5000];

void init(int x){
    for(int i=1;i<=x;i++){
        arr[i]=i;
        Size[i]=1;
    }
}
int root_find(int n){
    if(arr[n]==n)return n;
    arr[n]=root_find(arr[n]); // modified : arr[n]=root_find(arr[arr[n]]);
    return arr[n];
}
void Union(int a,int b){

   int x,y;
   x=root_find(a);
   y=root_find(b);
   if(Size[x]<Size[y]){
    arr[x]=y;
    Size[y]+=Size[x];
   }
   else{
    arr[y]=x;
    Size[x]+=Size[y];
   }

}

main(){

    init(10);
    Union(1,2);
    Union(3,1);
    Union(3,5);
    Union(4,5);
    printf("SIze Of 1 is %d\n",Size[1]);


}
