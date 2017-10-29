#include<bits/stdc++.h>
#define mx 10000
using namespace std;

vector< pair<int,int> >adjacency[mx+3];
pair<int,int>p;
multiset< pair<int,int> >s;
bool visited[mx];
int Distance[mx];

void initial(){

    for(int i=0;i<mx;i++){
        visited[i] = false;
        Distance[i] = 100000000;
    }

}

void Dijkstra(){

    initial();

    Distance[1]=0;
    s.insert({0,1});
    while(!s.empty()){
        p=*s.begin();
        s.erase(s.begin());
        int parent=p.second;
        if(visited[parent])continue;
        visited[parent]=true;
        for(int i=0;i<adjacency[parent].size();i++){

            int child=adjacency[parent][i].second;
            int weight=adjacency[parent][i].first;

            if(Distance[parent]+weight<Distance[child]){
                Distance[child]=Distance[parent]+weight;
                s.insert({Distance[child],child});
            }
        }
    }

}

main (){

    int node,edges,u,v,weight;

    printf("Number Of Nodes : ");
    scanf("%d",&node);
    printf("Number Of edgess : ");
    scanf("%d",&edges);
    printf("Enter value From 1 To %d\n",node);

    for(int i = 1;i <= edges;i++ ){
        printf("Enter edges %d And It's Weight-> ",i);
        scanf("%d %d %d",&u,&v,&weight);
        adjacency[u].push_back(make_pair(weight,v));
        adjacency[v].push_back(make_pair(weight,u));
    }
    Dijkstra();
    for(int i = 1;i<=node;i++){
        printf("Distance From 1 To %d Is %d\n",i,Distance[i]);
    }

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

