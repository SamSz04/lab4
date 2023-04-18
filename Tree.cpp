#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <limits.h>
#include <vector>
#include <queue>
#include <algorithm>

#include "Tree.h"

using namespace std;

/****************************************************************
 *                    Write your code below
 ****************************************************************/
ostream &operator<<(ostream &out, const TreeNode &b) {
    // TODO: Your code here
    return out;
}

int TreeNode::getX() {
    // TODO: Your code here
    return 0;
}

int TreeNode::getY() {
    // TODO: Your code here
    return 0;
}

TreeNode::~TreeNode() {
    // TODO: Your code here
}

istream &operator>>(istream &in, BinaryDimonTree &tree) {
    // TODO: Your code here
    return in;
}

BinaryDimonTree::BinaryDimonTree() {
    // TODO: Your code here
}

TreeNode *BinaryDimonTree::find_nearest_node(int x, int y) {
    // TODO: Your code here
    return nullptr;
}

void BinaryDimonTree::recur_search(TreeNode *cur, int x, int y, long long int &min_distance, TreeNode **guess) {
    // TODO: Your code here
}

BinaryDimonTree::~BinaryDimonTree()
{
    // TODO: Your code here
}
