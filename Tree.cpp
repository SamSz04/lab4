#include <cmath>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <queue>
#include <algorithm>
#include "Tree.h"

using namespace std;


ostream &operator<<(ostream &out, TreeNode &b) {
    cout << b.getX() << ',' << b.getY();
    return out;
}

int TreeNode::getX() {
    return data[0];
}

int TreeNode::getY() {
    return data[1];
}
TreeNode::~TreeNode() {
    vector<int>().swap(data);
    delete lchild;
    delete rchild;
    delete parent;
}

istream &operator>>(istream &in, BinaryDimonTree &Tree) {
        int i,j;
        vector<int> Node(2);
        in >> Tree.size;
        for(i=1;i<=Tree.size;++i)
        {
            for(j=0;j<2;++j){
                in >> Node[j];
            }
            (Tree.Points).push_back(Node);
        }
        Tree.buildTree();
        return in;
}

long long int distance(const vector<int>& a, const vector<int>& b) {
    long long int dist = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        long long int diff = a[i] - b[i];
        dist += diff * diff;
    }
    return dist;
}


BinaryDimonTree::BinaryDimonTree() {
    root = nullptr;
}

void BinaryDimonTree::buildTree(){
    root = createTreeNode(Points,0,Points.size());
}

TreeNode* BinaryDimonTree::createTreeNode(vector<vector<int>>&Points,int left,int right,int depth){
    if (left >= right) {
        return nullptr;
    }

    int dimUsed = depth % 2;
    int medianIndex = left + (right - left) / 2;

    auto cmp = [dimUsed](const vector<int>& a, const vector<int>& b) {
        return a[dimUsed] < b[dimUsed];
    };
    //这里使用 nth_element 函数，它基于 median of medians 算法。
    // 该算法可以在平均线性时间内找到第n小的元素。在构建KD树时，我们需要找到每个维度上的中位数，所以在构建树的过程中使用nth_element函数可以降低时间复杂度。

    nth_element(Points.begin() + left, Points.begin() + medianIndex, Points.begin() + right,cmp);

    TreeNode* node = new TreeNode(Points[medianIndex],dimUsed);

    node->lchild = createTreeNode(Points, left, medianIndex, depth + 1);
    node->rchild = createTreeNode(Points, medianIndex + 1, right, depth + 1);
    return node;
}


TreeNode* BinaryDimonTree::BinaryDimonTree::find_nearest_node(int x, int y) {
    TreeNode *nearNode = nullptr;
    vector<int> target(2);
    target[0] = x;
    target[1] = y;
    long long int min_distance = 10000000000;
    recur_search(root,target,min_distance,nearNode);
    return nearNode;
}

void BinaryDimonTree::recur_search(TreeNode *cur,vector<int>target, long long int &min_distance, TreeNode *&best) {
    if (!cur) return;

    long long int cur_dis = distance(cur->data,target);

    if (cur_dis < min_distance) {
        min_distance = cur_dis;
        best = cur;
    }
    else if (cur_dis == min_distance && cur->data[0] < best->data[0]) {
        best = cur;
    }
    else if (cur_dis == min_distance && cur->data[0] == best->data[0] && cur->data[1] < best->data[1]) {
        best = cur;
    }

    int axisDiff = target[cur->axis] - cur->data[cur->axis];
    TreeNode* primary = axisDiff < 0 ? cur->lchild : cur->rchild;
    TreeNode* secondary = axisDiff < 0 ? cur->rchild : cur->lchild;

    recur_search(primary, target, min_distance, best);

    if (axisDiff * axisDiff <= min_distance) {
        recur_search(secondary, target, min_distance, best);
    }

}

BinaryDimonTree::~BinaryDimonTree()
{
    root = nullptr;
    delete root;
}
