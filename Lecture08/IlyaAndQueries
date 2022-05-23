//solution uploaded to: https://codeforces.com/contest/313/problem/B

/*
  Compute a binary vector B[n] such that if s_k = s_k+1 then B[k]=1,
  otherwise B[k]=0. B[0]=0 because the string starts from s_1.
  query(l,r) is answered in constant time as B[r-1]-B[l-1].
  
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m,l,r,n;
    string str;
    cin >> str;
    n=str.size();

    //binary vector B
    ll B[n]={0};
    for(int i=0; i<n-1; i++){
        if(str[i]==str[i+1]) B[i+1]=1;
    }

    //compute the prefix sums over B
    for(int i=1; i<n; i++){
        B[i]+=B[i-1];
    }

    //handling queries
    cin >> m;
    while(m--){
        cin >> l >> r;
        cout << B[r-1]-B[l-1] << endl;
    }


    return 0;
}
