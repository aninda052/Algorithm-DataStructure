#include<bits/stdc++.h>
#define mx 1000
using namespace std;

vector<int>adjacency[mx+3];
bool visited[mx+3];
int level[mx+3],parent;

void bfs(int s){

    queue<int>q;
    q.push(s);
    level[s]=0;

    while(!q.empty()){
        parent=q.front();
        q.pop();
        visited[parent]=true;
        int j;
        for(int i=0;i<adjacency[parent].size();i++){
            int child = adjacency[parent][i];
            if(!visited[child]){
                visited[child] = true;
                level[child]= level[parent] + 1;
                q.push(child);

            }
        }

    }
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

    bfs(1);

    for(int i = 1;i<=node;i++){
        printf("Level Of %d is %d\n",i,level[i]);
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
1 4 */
