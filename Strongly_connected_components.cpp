#include<bits/stdc++.h>
#define mx 10000
using namespace std;

vector<int> adjacency[mx+2];
bool visited[mx+2];
vector<pair<int,int> >finishing;
int Time=0;

int DFS1(int source){
    Time+=1;
    visited[source]=true;
    for(int i=0;i<adjacency[source].size();i++){
        int child = adjacency[source][i] ;
        if(visited[child]==false){
            DFS1(child);
        }
    }
    Time+=1;
    finishing.push_back(make_pair(Time,source));

}

int DFS2(int source){

    visited[source]=true;
    for(int i=0;i<adjacency[source].size();i++){
        int child = adjacency[source][i] ;
        if(visited[child]==false){
            DFS2(child);
        }
    }
}
main(){

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
    }

    for(int i=1;i<=node;i++){
        if(!visited[i]){
            DFS1(i);
        }
    }

    sort(finishing.begin(),finishing.end());
    fill(visited,visited+node+2,false);

    int Num_SCC=0;
    for(int i=0;i<finishing.size();i++){
        int X=finishing[i].second;
        if(!visited[X]){
            DFS2(X);
            ++Num_SCC;

        }
     }

    printf("Number Of SCC : %d\n",Num_SCC);

    return 0;
}

/*Demo Input
7
8
1 2
2 3
3 4
4 5
5 6
6 7
3 1
7 5
 */
