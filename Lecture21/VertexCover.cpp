//Solution uploaded to: https://www.spoj.com/problems/PT07X/

/*
    Consider a node u:
    - if u is in the solution then its neighbours may or may not be in the solution
    - if u is not in the solution then all its neighbours must be in the solution

    Let VC(u,false) indicate the solution in case node u is not in the vertex cover; on the other 
    hand VC(u,true) indicates the solution in case u is in the vertex cover. 
    Let {v_1, ..., v_k} be u's neighbours, we have that:
    - VC(u, false) = VC(v_1, true) + ... + VC(v_k, true)
    - VC(u, true) = 1 + min(VC(v_1,true), VC(v_1,false)) + ... +  min(VC(v_k,true), VC(v_k,false))

    The result is min(VC(root,true), VC(root,false)).
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define SIZE 100001
int sol[SIZE][2];
vector<int> edges[SIZE];
int parent[SIZE]={0};


int VC(int node, bool b){

    if(sol[node][b] != -1) return sol[node][b];

    int res;

    if(b){
        res=1;
        for(int v: edges[node]){
            if(parent[node]==v) continue;
            else parent[v]=node;

            res += min(VC(v,true), VC(v,false));
        }
    }
    else{
        res=0;
        for(int v: edges[node]){
            if(parent[node]==v) continue;
            else parent[v]=node;

            res += VC(v,true);
        }
    }

    sol[node][b] = res;
    return res;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<SIZE; i++){
        sol[i][0] = -1;
        sol[i][1] = -1; 
    }

    int n,u,v;
    cin >> n;

    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    cout << min(VC(1,true), VC(1,false)) << endl;
  
    return 0;
}
