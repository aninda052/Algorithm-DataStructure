#include<bits/stdc++.h>
#define mx 1000
using namespace std;

vector<int>adjacency[mx+3];
bool visited[mx+3];
int dis_tm[mx+3],fin_tm[mx+3],parent,Time=0;


 void DFS(int parent){
    Time+=1;
    dis_tm[parent]=Time;
    visited[parent]=true;
    for(int i=0;i<adjacency[parent].size();i++){
        int child=adjacency[parent][i];
        if(!visited[child]){
            DFS(child);

        }
    }
    Time+=1;
    fin_tm[parent]=Time;


 }

main (){

    int node,edges,u,v;

    printf("Number Of Nodes : ");
    scanf("%d",&node);
    printf("Number Of edgess : ");
    scanf("%d",&edges);
    printf("Enter value From 1 To %d\n",node);

    for(int i = 1;i <= edges;i++ ){
        printf("Enter edges %d -> ",i);
        scanf("%d %d",&u,&v);
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }

    DFS(1);

    for(int i = 1;i<=node;i++){
        printf("Node %d -> Start Time : %d , Finising Time : %d\n",i,dis_tm[i],fin_tm[i]);
    }

    return 0;
}

/*Demo Input
5
7
1 2
2 3
2 4
3 4
5 1
3 5
1 4
*/

