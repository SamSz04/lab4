#ifndef C_BINARYDIMEN_TREE_H
#define C_BINARYDIMEN_TREE_H

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/****************************************************************
 *                    Write your code below
 ****************************************************************/
class TreeNode
{
  friend ostream &operator<<(ostream &out, TreeNode &b);
  friend class BinaryDimonTree;

private:
  vector<int> data;  //分别保存横坐标X和纵坐标Y
  int axis;         //使用的轴（x轴或y轴，用0，1表示）
  TreeNode *lchild;
  TreeNode *rchild;
  TreeNode *parent;
public:
  TreeNode(vector<int> val,int ax,TreeNode *l = nullptr,TreeNode *r = nullptr,TreeNode *p = nullptr)
  {
      data = val;
      axis = ax;
      lchild = l;
      rchild = r;
      parent = p;
  }
  int getX();  /* DO NOT CHANGE */
  int getY();  /* DO NOT CHANGE */
  ~TreeNode(); /* DO NOT CHANGE */
};


class BinaryDimonTree
{
    friend istream &operator>>(istream &in, BinaryDimonTree &tree); /* DO NOT CHANGE */
    friend long long int distance(const vector<int>& a, const vector<int>& b);
private:
  TreeNode *root;
  int size;
  vector<vector<int>> Points;

public:
  /* methods */
  BinaryDimonTree();          /* DO NOT CHANGE */
  void buildTree();
  TreeNode* createTreeNode(vector<vector<int>>&Points,int left,int right,int depth=0);
  TreeNode *find_nearest_node(int x, int y);  /* DO NOT CHANGE */
  void recur_search(TreeNode *cur,vector<int>target, long long int &min_distance, TreeNode *&best);
  ~BinaryDimonTree();
};

#endif //C_BINARYDIMEN_TREE_H
