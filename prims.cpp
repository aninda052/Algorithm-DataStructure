#include <bits/stdc++.h>
#define mx 1000
using namespace std;

bool visited[mx+3];
vector< pair<int,int> >adjacency[mx+3];
multiset< pair<int,int> >s;
pair<int,int>p;

int prim(int x){
    int minimumCost = 0;
    s.insert({0,x});
    while(!s.empty()){
        p=*s.begin();
        s.erase(s.begin());
        int parent=p.second;
        if(visited[parent])continue;
        visited[parent]=true;
        minimumCost += p.first;
        for(int i = 0;i < adjacency[parent].size();i++){
            int child = adjacency[parent][i].second;
            int weight=adjacency[parent][i].first;
            if(!visited[child])
                s.insert({weight,child});
        }
    }
    return minimumCost;
}

int main(){

    int node,edges,u,v,weight,result;
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
    result = prim(1);
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
