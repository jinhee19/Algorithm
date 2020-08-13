#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pre;
vector<int> post;

struct Node{
    int num;
    int x;
    int y;
    Node* left;
    Node* right;
};

void preorder(Node* root){
    if(root == NULL) return;
    pre.push_back(root->num);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    post.push_back(root->num);
    
}

bool compare(Node a, Node b){
    if(a.y == b.y)
        return a.x < b.x;
    else
        return a.y > b.y;
}

void decidechild(Node* parent, Node* child){
    if(child->x < parent-> x){
        if(parent->left == NULL) parent->left = child;
        else 
            decidechild(parent->left, child);
    }
    else{
        if(parent->right == NULL) parent->right = child;
        else
            decidechild(parent->right, child);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> nodes;
    
    for(int i = 0 ; i < nodeinfo.size(); i++){
        nodes.push_back({i+1, nodeinfo[i][0], nodeinfo[i][1]});
    }
    
    // 규칙대로 노드들을 정렬
    sort(nodes.begin(), nodes.end(), compare);
    
    // parent, child 노드 결정
    Node* root = &nodes[0];
    for(int i = 1 ; i < nodes.size();i++){
        decidechild(root, &nodes[i]);
    }
    
    // 전위 순회, 후위 순회 함
    preorder(root);
    postorder(root);
    
   // answer에 집어넣음
    answer.push_back(pre);
    answer.push_back(post);

    
    return answer;
}
