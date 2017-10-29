#include<bits/stdc++.h>
#define mx 10000
using namespace std;

int edges,arr[mx+5];
pair<int,pair<int ,int> >p[mx+5];

int initial(){
    for(int i=0;i<=mx;i++){
        arr[i]=i;
    }
}

int root_find(int i){

    while(arr[i]!=i){
        i=arr[i];
    }
    return i;
}

int krushkal(pair<int,pair<int ,int> >p[]){
    initial();
    int mincost=0;
    for(int i=0;i<edges;i++){
        int u=p[i].second.first;
        int v=p[i].second.second;
        int X=root_find(u);
        int Y=root_find(v);
        if(X!=Y){
            mincost+=p[i].first;
            arr[X]=arr[Y];
        }
   }
   return mincost;
}
int main(){

    int node,u,v,weight,result;
    printf("Number Of Nodes : ");
    scanf("%d",&node);
    printf("Number Of edgess : ");
    scanf("%d",&edges);
    printf("Enter value From 1 To %d\n",node);
    for(int i=0;i<edges;i++){
        scanf("%d %d %d",&u,&v,&weight);
        p[i]=make_pair(weight,make_pair(u,v));
    }
    sort(p,p+edges);
    result=krushkal(p);
    printf("Minimum Cost = %d\n",result);

return 0;

}

/*Demo Input
5
7
1 2 5
2 3 9
2 4 2
4 5 11
5 1 4
3 5 1
2 5 3
*/
