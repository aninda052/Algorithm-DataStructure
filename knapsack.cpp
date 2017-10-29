#include<bits/stdc++.h>
#define mx 100005
using namespace std;
int dp[1005][35],cost[1005],wight[1005];
int n,x;

void initialize(int x){
    for(int i=0;i<=x;i++)
        for(int j=0;j<=32;j++)
            dp[i][j]=-1;
}

int knapsack(int i,int w,int capacity){

    if(dp[i][w]!=-1) return dp[i][w];
    if(i==n)return 0;
    if(w+wight[i]<=capacity){
        dp[i][w]=knapsack(i+1,w+wight[i],capacity)+cost[i];
    }
    else {
        dp[i][w]=0;
    }
    x=knapsack(i+1,w,capacity);
    dp[i][w]=max(dp[i][w],x);
    return dp[i][w];

}



int main() {

    int result,cap;

    printf("Number Of Elements : \n");

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter Cost And Waight Of element %d\n",i+1);
        scanf("%d %d",&cost[i],&wight[i]);

    }
    initialize(n+1);
    printf("Enter The Maximum Capacity : \n");
    scanf("%d",&cap);
    result=knapsack(0,0,cap);
    printf("%d\n",result);

    return 0;
}

/*Demo Input
3
72 17
44 23
31 24
26
*/

