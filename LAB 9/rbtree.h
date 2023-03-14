#ifndef RB_H
#define RB_H
#include <bits/stdc++.h>
using namespace std;
class RB
{
    pair<double, double> val;
    RB* ltree;
    RB* rtree;
    RB* parent;
    int color; //black = 1; red = 0;
    int bheight;

public:
    RB();
    RB(double x, double y);
    RB* createNode(double x, double y);
    void ll(RB **root);
    void rr(RB **root);
    int calcHeight(RB *root);
    bool checkRb(RB *root);
    void insert(double x, double y, RB **root);
    void balance(RB **root, int loc);
};

#endif