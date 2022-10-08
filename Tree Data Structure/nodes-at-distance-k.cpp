#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
// same as burning of the binary Tree

// 1. store parent nodes

// 2. reach and get the starting node 

// 2. apply bfs using visited array and queue starting from the node found in prev step

// dist == target__dist ? return vector__ans;


vector<int> get__ans(TreeNode* start__node, int target__dist, unordered_map<TreeNode*, TreeNode*> parents){

    int dist = 0;

    queue<TreeNode*> q;

    q.push(start__node);

    

    unordered_map<TreeNode*, int> vis;

    vis[start__node] = 1;

    

    vector<int> ans;

    

    while(!q.empty()){

        int sz = q.size();

        bool is__node__exist = false;

        

        for(int i = 0; i < sz; i++){

            TreeNode* node = q.front();

            q.pop();

            

            if(node->left && !vis[node->left]){

                if(dist == target__dist - 1){

                    ans.push_back(node->left->val);

                }

                q.push(node->left);

                vis[node->left] = 1;

                is__node__exist = true;

            }

            if(node->right && !vis[node->right]){

                if(dist == target__dist - 1){

                    ans.push_back(node->right->val);

                }

                q.push(node->right);

                vis[node->right] = 1;

                is__node__exist = true;

            }

            if(parents[node] && !vis[parents[node]]){

                if(dist ==  target__dist - 1){

                    ans.push_back(parents[node]->val);

                }

                q.push(parents[node]);

                vis[parents[node]] = 1;

                is__node__exist = true;

            }

        }

        

        if(is__node__exist == true) dist++;

        if(dist == target__dist) return ans;

    }

    

    return ans;// redundant

}


TreeNode* store__parents__and__get__start(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*> &parents){

    // level order traversal to get the parents of each TreeNode

    queue<TreeNode*> q;

    q.push(root);

    TreeNode* start__node;

    

    while(!q.empty()){

        int sz = q.size();

        

        for(int i = 0; i < sz; i++){

            TreeNode* node = q.front();

            q.pop();

            

            if(node->val == start)  start__node = node;

            

            if(node->left) {

                parents[node->left] = node;

                q.push(node->left);

            }

            if(node->right) {

                parents[node->right] = node;

                q.push(node->right);

            }

        }

    }   

    

    return start__node; 

}


vector<int> distanceK(TreeNode* root, int start, int target__dist) {

    unordered_map<TreeNode*, TreeNode*> parents;

    TreeNode* start__node = store__parents__and__get__start(root, start, parents);

    vector<int> ans = get__ans(start__node, target__dist, parents);

    return ans;

}