#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MAX 100005
#define mod 1000000007
#define sp fixed<<setprecision(12)
using namespace std;
/*
vector<int> primes;

bool is_prime[MAX];

void sieve(){
    is_prime[0]=is_prime[1]=true;
    for(int i=4;i<MAX;i+=2){
        is_prime[i]=true;
    }
    for(int i=3;i*i<MAX;i+=2){
        if(!is_prime[i]){
            for(int j=i*i;j<MAX;j+=i){
                is_prime[j]=true;
            }
        }
    }
    
    for(int i=0;i<MAX;i++){
        if(!is_prime[i]){
            primes.push_back(i);
        }
    }
}
*/

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* builtTree(TreeNode* root) {
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    // if the data is not -1
    if (root == NULL) {
        root = new TreeNode(data);
    }

    root->left =  builtTree(root->left); // will return me the address of my leftchild node
    root->right =  builtTree(root->right); // will return me the adress of rightchild node

    return root;
}

int height(TreeNode* root) {
    //BASE CASE
    if (root == NULL) {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int totalHeight = max(leftHeight, rightHeight) + 1;
    return totalHeight;
}

class DiaHeight {
public:
    int diameter;
    int height;
};

// Time: O(n)
DiaHeight diameterOptimized(TreeNode* root) {
    DiaHeight val;
    if (root == NULL) {
        val.diameter = 0;
        val.height = -1;

        return val;
    }

    // update the height and diameter of val object and then return

    DiaHeight leftPair = diameterOptimized(root->left);
    DiaHeight rightPair = diameterOptimized(root->right);

    int leftDiameter = leftPair.diameter;
    int rightDiameter = rightPair.diameter;

    int leftHeight = leftPair.height;
    int rightHeight = rightPair.height;

    int myDiameter = leftHeight + 2 + rightHeight;

    int maxDiameter = max(myDiameter, max(leftDiameter, rightDiameter));
    val.diameter = maxDiameter;

    val.height = max(leftHeight, rightHeight) + 1;
    return val;
}


vector<int> bstkey;
void preorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);   
}

TreeNode* create_levelorder(){
    int data;
    cin>>data;
    TreeNode* root=new TreeNode(data);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        int data1,data2;
        cin>>data1>>data2;
        if(data1==-1){
            temp->left=NULL;
        }else{
            temp->left=new TreeNode(data1);
            q.push(temp->left);
        }
        if(data2==-1){
            temp->right=NULL;
        }else{
            temp->right=new TreeNode(data2);
            q.push(temp->right);
        }
        
    }
    return root;
}

void rightSideView(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;
        if(root!=NULL){
            q.push(root);
        }
        while(!q.empty()){
            int len=q.size();
            int val;
            int f=0;
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                if(f==0){
                    val=node->val;
                    f=1;
                }
                
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            v.push_back(val);
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
}
void leftprint(TreeNode* root){
    if(root==NULL){
        return;
    }
    leftprint(root->left);
    cout<<root->val<<" ";
}
void rightprint(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    rightprint(root->right);
}
void topview(TreeNode* root){
    leftprint(root->left);
    cout<<root->val<<" ";
    rightprint(root->right);
}


int preOrderIndex = 0;
TreeNode* builtTreeFromPreorderInorder(int pre[], int in[], int start, int end) {
	// base CASE
	if (start > end) {
		return NULL;
	}

	int data = pre[preOrderIndex];
	TreeNode* root = new TreeNode(data);

	int mid;

	for (int i = start; i <= end; i++) {
		if (in[i] == data) {
			mid = i;
			break;
		}
	}

	preOrderIndex++;

	root->left = builtTreeFromPreorderInorder(pre, in, start, mid - 1);
	root->right = builtTreeFromPreorderInorder(pre, in, mid + 1, end);

	return root;
}

class TreeDetail {
public:
	bool bst;
	int size;
	int minValue;
	int maxValue;
};

TreeDetail largestBSTinBinaryTree(TreeNode* root) {
	TreeDetail val; // object that will be returned by the function

	if (root == NULL) {
		val.bst = true;
		val.size = 0;
		val.minValue = INT_MAX;
		val.maxValue = INT_MIN;
		return val;
	}

	TreeDetail leftDetail = largestBSTinBinaryTree(root->left);
	TreeDetail rightDetail = largestBSTinBinaryTree(root->right);

	// leftBST and rightBST and root value > maxValue on left and root < minValue on right
	if (leftDetail.bst == false or rightDetail.bst == false or root->val > rightDetail.minValue or root->val < leftDetail.maxValue) {
		// I'm not a bst
		val.bst = false;
		val.size = max(leftDetail.size, rightDetail.size);
		return val;
	}

	// if i'm here that means I am a BST
	val.bst = true;
	val.size = leftDetail.size + rightDetail.size + 1;

	// before returning I've to update my minValue as well as maxValue

	int myMinValue;
	if (root->left == NULL) {
		myMinValue = root->val;
	} else {
		myMinValue = leftDetail.minValue;
	}

	int myMaxValue;
	if (root->right == NULL) {
		myMaxValue = root->val;
	} else {
		myMaxValue = rightDetail.maxValue;
	}

	val.minValue = myMinValue;

	val.maxValue = myMaxValue;

	return val;
}

TreeNode* built_bst(int a[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    TreeNode* root=new TreeNode(a[mid]);
    root->left=built_bst(a,s,mid-1);
    root->right=built_bst(a,mid+1,e);
    return root;
}

TreeNode* build_tree(){
    int n,k;
    cin>>n>>k;
    TreeNode* root=new TreeNode(n);
    if(k==0){
        return root;
    }else if(k==1){
        root->left=build_tree();
        return root;
    }else{
        root->left=build_tree();
        root->right=build_tree();
        return root;
    }
}


TreeNode* builtBST(TreeNode* root, int data) {
	if (root == NULL) {
		root = new TreeNode(data);
		return root;
	}

	if (data > root->val) {
		root->right = builtBST(root->right, data);
	} else {
		root->left = builtBST(root->left, data);
	}

	return root;
}

vector<int> bstkeyinrange;
void preOrder(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);   
}

void inorder(TreeNode* root,int l,int r){
    if(root==NULL){
        return;
    }
    inorder(root->left,l,r);
    int ans=root->val;
    if(ans>=l and ans<=r){
        bstkeyinrange.pb(ans);
    }
    inorder(root->right,l,r);
}

TreeNode* create_tree(){
    string t;
    cin>>t;
    if(t=="false"){
        return NULL;
    }
    int data;
    cin >> data;
    // if the data is not -1
    TreeNode* root1 = new TreeNode(data);
    

    root1->left =  create_tree(); // will return me the address of my leftchild node
    root1->right =  create_tree(); // will return me the adress of rightchild node

    return root1;
}

TreeNode* built_tree(){
    int data;
    cin>>data;
    TreeNode* root=new TreeNode(data);
    root->left=create_tree();
    root->right=create_tree();

    return root;
}

void zigzag_print(TreeNode* root){
    queue<TreeNode*> q;
        if(root!=NULL){
            q.push(root);
        }
        int ct=1;
        while(!q.empty()){
            int len=q.size();
            vector<int> v;
            
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                v.pb(node->val);
                
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            if(ct&1){
                for(int i=0;i<len;i++){
                    cout<<v[i]<<" ";
                }
            }else{
                for(int i=len-1;i>=0;i--){
                    cout<<v[i]<<" ";
                }
            }
            ct++;
            
        }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;
   
   TreeNode* root=NULL;
   root=built_tree();
   zigzag_print(root);
    
    return 0;
    
}
