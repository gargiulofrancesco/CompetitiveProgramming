//solution uploaded to: https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

/*
    For each node u having both children, compute the current path value 
    as: u.data + leftpath + rightpath, where
    - leftpath is the maximum path value from u to a leaf in u.left
    - rightpath is the maximum path value from u to a leaf in u.right
    
    The result is given by the maximum of such paths.
    The only special case is when the root node has a single child: in
    this case root can be an end of the maximum path.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


class Solution {
public:
    int result=INT_MIN;

    int visit(Node* root){
        //root is a leaf
        if(root->left==NULL && root->right==NULL) return root->data;

        //root has a single child
        if(root->left==NULL) return root->data + visit(root->right);
        if(root->right==NULL) return root->data + visit(root->left);
        
        //maximum path value from root to a leaf in its left subtree
        int leftpath=visit(root->left);
        //maximum path value from root to a leaf in its right subtree
        int rightpath=visit(root->right);

        //maximum path value from leaf to leaf having root as LCA
        int pvalue = root->data + leftpath + rightpath;
        if(pvalue>result) result=pvalue;
        
        return root->data + std::max(leftpath, rightpath);
    }

    int maxPathSum(Node* root)
    {
        //handling the special case of root being one of the ends of maxpath
        int rootendpath=INT_MIN;
        if(root->left==NULL){
            rootendpath=root->data+visit(root->right);
        }
        else if(root->right==NULL){
            rootendpath=root->data+visit(root->left);
        }
        
        visit(root);
        
        return max(result, rootendpath);
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends
