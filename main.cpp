#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "Tree.h"

using namespace std;

void run_testcase(string testcasename) {
    ifstream testcase;
    testcase.open(testcasename);

    BinaryDimonTree *tree = new BinaryDimonTree();
    testcase >> *tree;
    //这一步完成了树的构建！
    long long int testNum = 0;
    testcase >> testNum;
    bool res = true;
    for (long long int i = 0; i < testNum; i++) {
        long long int x, y, z, w;
        testcase >> x;
        testcase >> y;
        //(x,y)是目标点
        testcase >> z;
        testcase >> w;
        //(z,w)是用户输入的离目标点最近的点
        TreeNode *node = tree->find_nearest_node(x, y);
        if (z == node->getX() && w == node->getY()) {

        }
        else {
            cout << "case:" << x << " " << y << ",";
            cout << "expect:" << z << " " << w << ",";
            cout << "actual:" << node->getX() << " " << node->getY() << endl;
            res = false;
            break;
        }
    }

    if (testNum <= 0) {
        cout << "Failed at " << testcasename << endl;
    }
    if (res) {
        cout << "pass at " << testcasename << endl;
    }
    delete tree;
    testcase.close();
}

int main() {
    /* You can change the testcase path as you like :) */
    /* run_testcase(<test_file_path>); */
    run_testcase("1.txt");
    run_testcase("2.txt");
    run_testcase("3.txt");
    run_testcase("4.txt");
    /* There are ten extra testcases on canvas */
    /* You are supposed to pass all of those ten testcases to get full grade */
    // for (int i = 1; i <= 10; ++i) {
    //     std::string grade_test_file = "tests/c" + std::to_string(i);
    //     run_testcase(grade_test_file);
    // }

    return 0;
}
