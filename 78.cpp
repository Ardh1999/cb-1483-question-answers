#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MAX 100005
#define mod 1000000007
#define sp fixed<<setprecision(12)
using namespace std;
    

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

pair<bool, int> heightBalancedOptimized(TreeNode* root) {
    pair<bool, int> val; // object that will be eventually returned by the function

    if (root == NULL) {
        val.first = true;
        val.second = -1;
        return val;
    }

    pair<bool, int> leftPair = heightBalancedOptimized(root->left);
    pair<bool, int> rightPair = heightBalancedOptimized(root->right);

    bool leftBalance = leftPair.first;
    bool rightBalance = rightPair.first;

    int leftHeight = leftPair.second;
    int rightHeight = rightPair.second;

    int myHeight = max(leftHeight, rightHeight) + 1;
    val.second = myHeight;

    if (leftBalance == false or rightBalance == false) {
        val.first = false;
        return val;
    }

    int diff = abs(leftHeight - rightHeight);

    if (diff > 1) {
        val.first = false;
    } else {
        val.first = true;
    }

    return val;
}

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

TreeNode* create_tree(){
    string t;
    cin>>t;
    //cout<<t<<" ";
    if(t=="false"){
        return NULL;
    }
    int data;
    cin >> data;
    //cout<<data<<" ";
    // if the data is not -1
    TreeNode* root1 = new TreeNode(data);
    

    root1->left =  create_tree(); // will return me the address of my leftchild node
    root1->right =  create_tree(); // will return me the adress of rightchild node

    return root1;
}

TreeNode* built_tree(){
    int data;
    cin>>data;
    //cout<<data<<" ";
    TreeNode* root=new TreeNode(data);
    root->left=create_tree();
    root->right=create_tree();

    return root;
}

bool identical(TreeNode* root1,TreeNode* root2){
    if(root1==NULL and root2==NULL){
        return true;
    }
    if(root1==NULL or root2==NULL){
        return false;
    }
    return identical(root1->left,root2->left) and identical(root1->right,root2->right);
}

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

void verticalTraversal(TreeNode* root) {
        if(root==NULL){
            return ;
        }
        map<int,vector<pair<int,int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto node=q.front();
            mp[node.second.second].push_back({node.second.first,node.first->val});
            q.pop();
            if(node.first->left!=NULL){
                q.push({node.first->left,{node.second.first+1,node.second.second-1}});
            }
            if(node.first->right!=NULL){
                q.push({node.first->right,{node.second.first+1,node.second.second+1}});
            }
        }
        for(auto it:mp){
            vector<pair<int,int>> temp=it.second;
            for(auto x:temp){
                cout<<(x.second)<<' ';
            }
            cout<<"\n";
        }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;
    int n;
    cin>>n;
    TreeNode* root=NULL;
    root=create_levelorder();
    //preorder(root);
    verticalTraversal(root);
    

    return 0;
    
}