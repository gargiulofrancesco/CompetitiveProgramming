//solution uploaded to: https://codeforces.com/contest/427/problem/C

/*
    Junctions are nodes and roads are directed edges.
    The minimum number of checkposts is obtained by building a checkpost
    in each strongly connected component of the graph. The cost should be
    minimum so we should build, in each SCC, a checkpost in a minimum cost
    node. Finally, the number of distinct optimal solutions is given by 
    the product of the number of minimum cost nodes in each SCC.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


const ll SIZE = 100001;
const ll MOD = 1000000007;
ll n;
ll cost[SIZE];
vector<ll> edges[SIZE];
//transposed matrix
vector<ll> Tedges[SIZE];
bool visited[SIZE];
deque<ll> nodesOrder;
//for each SCC store a pair (min_cost, min_cost_frequency)
vector<pair<ll,ll>> SCCres;


//dfs ordering nodes by decreasing finish time
void finishTimeSort(ll u){
    visited[u]=true;

    for(ll v: edges[u]){
        if(!visited[v]) finishTimeSort(v);
    }

    nodesOrder.push_front(u);
}

//visit SCC and compute the minimum cost in each SCC and its frequency 
pair<ll,ll> SCC(ll u, pair<ll,ll> res){
    visited[u]=true;
    if(cost[u] == res.first) res.second++;
    else if(cost[u] < res.first) res={cost[u], 1};

    for(ll v: Tedges[u]){
        if(!visited[v]){
            res = SCC(v,res);
        }
            
    }

    return res;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%llu", &n);

    for(ll i=1; i<=n; i++){
        scanf("%llu", &cost[i]);
    }

    ll m,u,v;
    scanf("%llu", &m);
    for(ll i=0; i<m; i++){
        scanf("%llu %llu", &u, &v);
        edges[u].push_back(v);
        Tedges[v].push_back(u);
    }

    //execute a standard dfs
    for(int i=1; i<=n; i++) visited[i]=false;

    for(ll i=1; i<=n; i++){
        if(!visited[i]) finishTimeSort(i);
    }


    /*
        compute SCCs and, for each of them, store the minimum cost
        tmin among its nodes and how many tmin cost nodes in contains
    */
    memset(visited, false, sizeof(visited));
    for(ll u: nodesOrder){
        if(!visited[u]){
            SCCres.push_back(SCC(u, {LLONG_MAX, 0}));
        }
    }

    //compute results
    ll totalcost=0, nways=1;
    for(pair<ll,ll> p: SCCres){
        totalcost+=p.first;
        nways = ((nways%MOD) * (p.second%MOD)) % MOD;
    }

    printf("%llu %llu", totalcost, nways); 


    return 0;
}
