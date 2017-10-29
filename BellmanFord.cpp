#include<bits/stdc++.h>
#define mx 2000
using namespace std;

int Distance[mx+5];
struct X{
    int u,v,W;
}adjacency[mx+5];

int BellmanFord(int N,int M){

    fill(Distance,Distance+mx,10000000);//initializing
    bool neg_cycle=true;
    Distance[0]=0;
    for(int i=1;i<=N-1;i++){
        for(int j=0;j<M;j++){
            int parents=adjacency[j].u;
            int child=adjacency[j].v;
            int weight=adjacency[j].W;
            if(Distance[child]>Distance[parents]+weight){
                Distance[child]=Distance[parents]+weight;
            }
        }
    }

    for(int i=0;i<M;i++){
        int parents=adjacency[i].u;
        int child=adjacency[i].v;
        int weight=adjacency[i].W;
        if(Distance[child]>Distance[parents]+weight){
            neg_cycle=false;
        }
    }
    return neg_cycle;


}
main (){

    int node,edges,u,v,weight;

    printf("Number Of Nodes : ");
    scanf("%d",&node);
    printf("Number Of edgess : ");
    scanf("%d",&edges);
    printf("Enter value From 1 To %d\n",node);

        for(int i=0;i<edges;i++){
            printf("Enter edges %d And It's Weight-> ",i+1);
            scanf("%d %d %d",&adjacency[i].u,&adjacency[i].v,&adjacency[i].W);
        }

    bool result = BellmanFord(node,edges);
    if(result) printf("There is a Negative Cycle");
    else printf("There is no Negative Cycle");

return 0;}

