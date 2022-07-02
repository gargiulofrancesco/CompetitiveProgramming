//solution uploaded to: https://codeforces.com/problemset/problem/86/D

/*
    Use Mo's algorithm to sort queries in order to solve them efficiently:
    divide the range [0,n] in blocks of size sqrt(n). Each query (i,j) belongs
    to the block containing i. Queries inside the same block are sorted by
    increasing j.
    
    Solve queries following this order by taking advantage of the eventual overlap 
    between consecutive ranges.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct query{
    ll l;
    ll r;
    ll id;
};

//sorts queries according to Mo's algorithm
ll blocksize;
bool blocksort(query q1, query q2){
    if(q1.l/blocksize == q2.l/blocksize) return q1.r < q2.r;
    else return q1.l < q2.l;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,t,l,r;
    scanf("%lld%lld", &n,&t);
    
    ll A[n];
    for(int i=0; i<n; i++){
        scanf("%lld", &A[i]);
    }

    //reading queries data and sorting them
    query Q[t];
    for(int i=0; i<t; i++){
        scanf("%lld %lld", &l,&r);
        Q[i]={l-1,r-1,i};
    }
    blocksize=ceil(sqrt(n));
    sort(Q, Q+t, blocksort);


    ll res[t]={0};
    ll val=0, actl=Q[0].r+1, actr=Q[0].r, ql, qr, x;
    ll map[1000001]={0};
    
    //processing queries
    for(int i=0; i<t; i++){
        ql=Q[i].l;
        qr=Q[i].r;

        //add to the left
        while(actl>ql){
            actl--;
            x=A[actl];

            val -= map[x] * map[x] * x;
            map[x]++;
            val += map[x] * map[x] * x;
        }
        //remove from the left
        while(actl<ql){
            x=A[actl];
            val -= map[x] * map[x] * x;
            map[x]--;
            val += map[x] * map[x] * x;
            actl++;
        }
        
        //remove from the right
        while(actr>qr){
            x=A[actr];
            val -= map[x] * map[x] * x;
            map[x]--;
            val += map[x] * map[x] * x;
            actr--;
        }
        //add to the right
        while(actr<qr){
            actr++;
            x=A[actr];
            val -= map[x] * map[x] * x;
            map[x]++;
            val += map[x] * map[x] * x;
        }

        res[Q[i].id]=val;
    }

    for(int i=0; i<t; i++){
        printf("%llu\n", res[i]);
    }


    return 0;
}
