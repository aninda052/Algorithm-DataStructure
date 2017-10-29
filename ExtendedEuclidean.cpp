#include<bits/stdc++.h>
using namespace std;


int  Extended_gcd(int a,int b,int *x,int *y){

    if(!b){
        *x=1,*y=0;
        return a;
    }
    int x1,y1;
    int gcd=Extended_gcd(b,a%b,&x1,&y1); //ax+by =gcd(a,b)
    *x=y1;
    *y=x1-((a/b)*y1);
    printf("%d %d\n",x1,y1);
    return gcd;
}

main() {
    int a=35,m=15,x,y;

    printf("GCD Of %d and %d is %d\n",a,m,Extended_gcd(a,m,&x,&y));
    printf("There Coefficients Are x = %d and y = %d\n",x,y);

    return 0;
}

