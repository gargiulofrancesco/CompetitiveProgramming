//solution uploaded to: https://codeforces.com/problemset/problem/510/C

/*
    Build a graph where alphabet characters are nodes and there exists an edge
    (u,v) if it is required for u to lexicographically preceed v.
    
    Try to topologically sort the graph: if there exists a cycle then there is
    no solution; otherwise output the resulting linear ordering.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<int> edges[26];
char color[26];
string res="";
bool cycle=false;


void DFSvisit(int u){
    color[u] = 'g';
    for(int v: edges[u]){
        if(color[v]=='w') DFSvisit(v);
        else if(color[v]=='g') cycle=true;
    }

    color[u]='b';

    char c = 'a'+u;
    res=c+res;
}


void topologicalsort(){
    for(int i=0; i<26; i++) color[i]='w';
    
    for(int u=0; u<26; u++){
        if(color[u]=='w') DFSvisit(u);
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string A[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    //set precedence relations as edges between alphabat characters
    for(int i=1; i<n; i++){

        if(A[i-1]==A[i]) continue;

        //if A[i] is a prefix of A[i-1] then there is no solution
        if((A[i].size()<A[i-1].size()) && A[i]==A[i-1].substr(0,A[i].size())){
            cout << "Impossible";
            return 0;
        }

        for(int j=0; j<min(A[i-1].size(), A[i].size()); j++){

            if(A[i-1][j]!=A[i][j]){
                int c1 = A[i-1][j]-'a';
                int c2 =  A[i][j]-'a';
                edges[c1].push_back(c2);
                break;
            }
        }
    }


    topologicalsort();
    if(cycle) cout << "Impossible";
    else cout << res;


    return 0;
}
