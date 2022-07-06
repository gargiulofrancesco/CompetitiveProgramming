//solution uploaded to: https://codeforces.com/problemset/problem/277/A

/*
    Each employee is a node and there exists an edge (u,v) if u and v
    have at least one language in common. Count the number of connected
    components ncc and report ncc-1. The only exception is verified when 
    every employee knows zero languages, in which case the result is equal
    to the number of employees.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


const int SIZE = 101;
vector<int> edges[SIZE];
bool visited[SIZE]={0};


void visit(int u){
    visited[u]=true;
    for(int v: edges[u]){
        if(!visited[v]) visit(v);
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n,m, k, lang;
    cin >> n >> m;

    set<int> languages[SIZE];
    for(int i=0; i<n; i++){
        cin >> k;
        for(int j=0; j<k; j++){
            cin >> lang;
            languages[i].insert(lang);
        }
    }

    //set edges
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int tlang: languages[i]){
                if(languages[j].find(tlang)!=languages[j].end()){
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                    break;
                }
            }
        }
    }
    

    int res=0;
    bool allZeroLanguages = true;
    for(int i=0; i<n; i++){

        if(!languages[i].empty()) allZeroLanguages=false;
        
        if(!visited[i]){
            visit(i);
            res++;
        }
    }


    if(allZeroLanguages) cout << n;
    else cout << res-1;



    return 0;
}
