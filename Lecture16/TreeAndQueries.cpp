//solution uploaded to: https://codeforces.com/problemset/problem/375/D

/*
    Use an Euler tour to linearize the tree. 
    For each node v store the range [i,j] containing the nodes of the tree rooted in v.
    Each query (v,k) can be solved by computing the solution on v's range. This means that
    we can sort these range queries according to Mo's algorithm to obtain a O((n+m)sqrt(n)) 
    time solution.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct query{
    ll v;
    ll k;
    ll id;
    ll res;
};

const ll SIZE = 100001; //max n size
ll block;
vector<ll> edges[SIZE];

//maps each node to its range (i,j) in the tree's linear representation
pair<ll,ll> noderange[SIZE];

//use an Euler tour to linearize the tree
vector<ll> et;
bool visited[SIZE]={0};
ll pos=0;
void eulertour(ll node){
    visited[node]=true;

    et.push_back(node);
    noderange[node].first=pos;
    pos++;

    for(ll u: edges[node]){
        if(!visited[u]) eulertour(u);
    }
    noderange[node].second=pos-1;
}

//sorts queries (v,k) according to v's range
bool blocksort(query q1, query q2){
    pair<ll,ll> r1=noderange[q1.v], r2=noderange[q2.v];

    if(r1.first/block == r2.first/block) return r1.second < r2.second;
    else return r1.first < r2.first;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;

    scanf("%lld%lld", &n,&m);

    ll color[n+1];
    for(int i=1; i<=n; i++){
        scanf("%lld", &color[i]);
    }

    for(int i=0; i<n-1; i++){
        ll u,v;
        scanf("%lld%lld", &u,&v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    query Q[m];
    for(int i=0; i<m; i++){
        ll v,k;
        scanf("%lld%lld", &v,&k);
        Q[i]={v,k,i,0};
    }

    //linearize the tree
    eulertour(1);
    //sort queries according to Mo's algorithm
    block = sqrt(ceil(et.size()));
    sort(Q, Q+m, blocksort);

    //processing queries
    ll freq[SIZE]={0};
    ll res[SIZE]={0};
    ll curr_l=1+noderange[Q[0].v].second, curr_r=noderange[Q[0].v].second;

    for(int i=0; i<m; i++){
        pair<ll,ll> p = noderange[Q[i].v];
        ll l = p.first, r=p.second;

        //add to the left
        while(curr_l>l){
            curr_l--;
            ll col = color[et.at(curr_l)];
            freq[col]++;
            res[freq[col]]++;
        }
        //remove from the left
        while(curr_l<l){
            ll col = color[et.at(curr_l)];
            res[freq[col]]--;
            freq[col]--;
            curr_l++;
        }
        //remove from the right
        while(curr_r>r){
            ll col = color[et.at(curr_r)];
            res[freq[col]]--;
            freq[col]--;
            curr_r--;
        }
        //add to the right
        while(curr_r<r){
            curr_r++;
            ll col = color[et.at(curr_r)];
            freq[col]++;
            res[freq[col]]++;
        }

        Q[i].res = res[Q[i].k];
    }


    sort(Q, Q+m, [](query q1, query q2){return q1.id<q2.id;});
    for(int i=0; i<m; i++){
        printf("%llu\n", Q[i].res);
    }


    return 0;
}
