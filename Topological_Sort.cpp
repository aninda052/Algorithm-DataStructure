#include<bits/stdc++.h>
#define mx 10000
using namespace std;

vector<int> adjacency[mx+2];
bool visited[mx+2];
vector<pair<int,int> >finishing;
int Time=0;

int DFS(int source){
    Time+=1;
    visited[source]=true;
    for(int i=0;i<adjacency[source].size();i++){
        int child = adjacency[source][i] ;
        if(visited[child]==false){
            DFS(child);
        }
    }
    Time+=1;
    finishing.push_back(make_pair(Time,source));

}



int main (){

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
            DFS(i);
        }
    }

    sort(finishing.begin(),finishing.end());
    printf("The Sorted List  : \n");
    for(int i=finishing.size()-1;i>=0;i--){
        printf("%d ",finishing[i].second);
    }
    return 0;
}

/* Demo Input
6
8
1 2
3 2
2 4
2 5
2 6
4 5
6 5
6 4
*/
