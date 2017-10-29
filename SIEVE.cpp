#include<bits/stdc++.h>
#define mx 999999
using namespace std;

bool arr[mx+5];
vector<int>primes;

void sieve (){

    primes.push_back(2);
    for(int i = 4;i <= mx;i += 2){
        arr[i] = true ;
    }
    for(int i = 3;i <= mx;i += 2){
        if(!arr[i]){
            primes.push_back(i) ;
            for(int j = i;j<=mx;j+=i){
                arr[j] = true ;
            }
        }
    }

}


main(){

    sieve();
    printf("Number of Primes Between 1 to 999999 is %d\n",primes.size());
    int x;

    printf("Number of Primes : ");
    scanf("%d",&x);

    for(int i = 0;i < x;i++){
        printf("%d. %d\n",i+1,primes[i]);
    }

}
