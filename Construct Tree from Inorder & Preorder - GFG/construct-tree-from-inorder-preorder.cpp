//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    Node *constructTree(int in[],int pre[],int l,int r,int n)
    {
        if(l>r)
        return NULL;
        if(index>=n)
        return NULL;
        int val=pre[index++];
        Node *root=new Node(val);
        int pos = 0;
        
        for(int i=l; i<=r; i++){
            if(in[i] == val){
                pos = i;
                break;
            }
        }
        root->left=constructTree(in,pre,l,pos-1,n);
        root->right=constructTree(in,pre,pos+1,r,n);
        return root;
    }
    public:
    map<int,int>mp;
    int index=0;
    Node* buildTree(int in[],int pre[], int n)
    {
        for(int i=0;i<n;i++)
        mp[in[i]]=i;
        return constructTree(in,pre,0,n-1,n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends