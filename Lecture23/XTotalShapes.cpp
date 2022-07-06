//solution uploaded to: http://practice.geeksforgeeks.org/problems/x-total-shapes/0

/*
    Consider each character 'X' as a node. Each node is connected to its
    adjacent cells in the grid ('O's are not considered nodes). Visit the 
    graph and return the its number of connected components.  
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
    //set nodes of a connected component as visited
    void visit(vector<vector<char>>& grid, int i, int j){
        //set node as visited
        grid.at(i).at(j)='-';
    
        int n = grid.size();
        int m = grid.at(0).size();
        
        
        if(i-1>=0 && grid.at(i-1).at(j)=='X') visit(grid, i-1, j);
        if(i+1<n && grid.at(i+1).at(j)=='X') visit(grid, i+1, j);
        if(j-1>=0 && grid.at(i).at(j-1)=='X') visit(grid, i, j-1);
        if(j+1<m && grid.at(i).at(j+1)=='X') visit(grid, i, j+1);
    }
    
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid.at(0).size();
    
        int res=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid.at(i).at(j)=='X'){
                    visit(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
