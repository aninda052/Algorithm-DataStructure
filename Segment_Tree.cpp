#include<bits/stdc++.h>
#define mx 100
using namespace std;

int arr[mx],tree[mx*3];

int init(int node, int start, int End){

    if(start==End){
        return tree[node]=arr[start];

    }
    int left=node*2;
    int right=left+1;
    int mid=(start+End)/2;
    return tree[node]=init(left,start,mid)+init(right,mid+1,End);

}

int query(int node,int start, int End,int i,int j){

    if(i<=start && End<=j)return tree[node];
    if(j<start || End<i) return 0;
    int left=node*2;
    int right=left+1;
    int mid=(start+End)/2;
    return query(left,start,mid,i,j)+query(right,mid+1,End,i,j);

}

int update(int node, int start,int End,int index,int newvalue){

    if(index<=start && index>=End)return tree[node]=newvalue;
    if(index<start || index>End)return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(start+End)/2;
    return tree[node]=update(left,start,mid,index,newvalue)+update(right,mid+1,End,index,newvalue);
}

main(){

    int N=5;
    printf("Enter %d Elements \n",N);
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    init(1,0,N-1);

    int res=query(1,0,N-1,0,N-1);
    printf("%d\n",res);

    int new_val,Index;
    printf("Enter a Index And a New Value \n");
    scanf("%d %d",&Index,&new_val);
    update(1,0,N-1,Index,new_val);

    res=query(1,0,N-1,0,N-1);
    printf("%d\n",res);



return 0;}
