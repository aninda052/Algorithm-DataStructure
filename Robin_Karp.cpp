#include <bits/stdc++.h>
using namespace std;

int Hash(const string &s, int m,int  B,int  M){
    int  h = 0 , power = 1;
    for(int i = m-1;i>=0;i--){
        h = h + (s[i] * power) % M;
        h = h % M;
        power = (power * B)%M;
    }
    return h;
}

int match(const string &text, const string &pattern) {

    int n = text.size();
    int m = pattern.size();
    if(n < m)return -1;
    if(m == 0 or n == 0)
        return -1;

    int  B = 347, M = 1000000000+7;

    //Calculate B^(m-1)
    int  power = 1;
    for(int i=1;i<=m-1;i++)
        power = (power * B) % M;

    int  hash_text = Hash(text, m, B, M);
    int  hash_pattern = Hash(pattern, m, B, M);

    if(hash_text == hash_pattern){
        return 0;
    }

    for(int i=m;i<n;i++){

        hash_text = (hash_text - (power * text[i-m]) % M) % M;
        hash_text = (hash_text + M) % M; //take care of M of negative value
        hash_text = (hash_text * B) % M;
        hash_text = (hash_text + text[i]) % M;

        if(hash_text==hash_pattern){
            return i - m + 1;
        }
    }
    return -1;
}


int main() {
    cout<<match("bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba", "babaaa")<<endl;
    return 0;
}
