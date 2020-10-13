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
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                val=node->val;
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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;


    TreeNode* root=NULL;
    root=create_levelorder();
    rightSideView(root);
    

    return 0;
    
}
