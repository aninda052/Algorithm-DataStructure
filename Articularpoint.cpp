#include<bits/stdc++.h>
#define mx 1000
using namespace std;
int Distance[mx+3],low[mx+3],parent[mx+3],Time;
bool visited[m+3],artpoint[mx+3];
vector<int>adjacency[mx+3];

 void initial(int X){

    for(int i=1;i<=X;i++){
        parent[i]=i;
        visited[i]=artpoint[i]=false;
        low[i]=0;
    }
    Time=0;

 }

 void articulationPoint(int u){

    visited[u]=true;
    low[u]=Distance[u]=++Time;
    int child=0;
    for(int i=0;i<adjacency[u].size();i++){
        int v=adjacency[u][i];
        if(!visited[v]){
            parent[v]=u;
            child++;
            articulationPoint(v);
            low[u]=min(low[u],low[v]);
            if(parent[u]==u && child>1 && !artpoint[u]){
                artpoint[u]=true;
            }
            if(parent[u]!=u && Distance[u]<=low[v] && !artpoint[u]){
                artpoint[u]=true;
            }
        }
        else if(parent[u]!=v){
            low[u]=min(low[u],Distance[v]);
        }

    }


 }

main (){

    int node,edges,x,y;

    printf("Number Of Nodes : ");
    scanf("%d",&node);
    printf("Number Of edgess : ");
    scanf("%d",&edges);
    printf("Enter value From 1 To %d\n",node);

    for(int i = 1;i <= edges;i++ ){
        printf("Enter edges %d -> ",i);
        scanf("%d %d",&x,&y);
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }

    initial(node);
    articulationPoint(1);

    for(int i = 1;i<=node;i++){
        if(artpoint[i]){
            printf("%d\n",i);
        }
    }

    return 0;
}

/*Demo Input
5
4
2 1
1 3
5 4
4 1
 */
