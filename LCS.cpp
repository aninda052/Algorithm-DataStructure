#include<bits/stdc++.h>
using namespace std;

int dp[105][105];
string string1,string2;
bool visited[105][105];

int LCS(int i,int j,int len1,int len2){

    if(i==len1 || j==len2)return 0;

    if(visited[i][j])return dp[i][j];
    if(string1[i]==string2[j])dp[i][j]= 1+LCS(i+1,j+1,len1,len2);
    else{
        dp[i][j]=max(LCS(i,j+1,len1,len2),LCS(i+1,j,len1,len2));
    }
    visited[i][j]=true;
    return dp[i][j]=ans;

}
 void print_sol(int i,int j,int len1,int len2){

    if(i==len1 || j==len2) return ;

    if(string1[i]==string2[j]){
        cout<<string1[i];
        print_sol(i+1,j+1,len1,len2);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1])print_sol(i+1,j,len1,len2);
        else print_sol(i,j+1,len1,len2);
    }
 }

main(){

    cout<<"Enter Two String "<<endl;
    cin>>string1>>string2;
    int len1 =string1.length();
    int len2 =string2.length();
    LCS(0,0,len1,len2);
    cout<<"The LCS Of Given Two Strings is"<<endl;
    print_sol(0,0,len1,len2);


return 0;}

