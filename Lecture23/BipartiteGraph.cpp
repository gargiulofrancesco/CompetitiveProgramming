//solution uploaded to: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

/*
  A graph is bipartite if it doesn't contain any odd cycle.
  Use a DFS on the graph and check for back edges. During the DFS color each node as follows:
  - white, if it wasn't discovered yet
  - gray, if it was discovered and it's being processed (i.e. it's in the stack)
  - black, if it was discovered and processed
  Moreover, keep track of the position in the stack of the (actual) gray nodes. When a back edge 
  (u,v) is found, check if the number of nodes in the stack between u and v is odd
 
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    vector<char> color;
    vector<int> stackdepth;
    bool res = true;

    void DFSvisit(int V, vector<int>adj[], int u, int sdepth){
        color.at(u) = 'g';
        stackdepth.at(u) = sdepth;
        
        for(int v: adj[u]){
            if(color.at(v)=='g'){
                //cycle detected, verify its length
                int clen = 1+sdepth-stackdepth.at(v);
                if(clen%2==1) res=false;
            }
            else if(color.at(v)=='w'){
                DFSvisit(V, adj, v, sdepth+1);
            }
        }
    
        color[u]='b';
    }

	bool isBipartite(int V, vector<int>adj[]){
    	// Code here
    	color.resize(V,'w');
    	stackdepth.resize(V,0);
    	
      for(int u=0; u<V; u++){
          if(color.at(u)=='w') DFSvisit(V, adj, u, 0);
      }
        
      return res;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
