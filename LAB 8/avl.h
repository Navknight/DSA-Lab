#ifndef AVL_H
#define AVL_H

#include <bits/stdc++.h>

using namespace std;

class AVL
{
    int val;
    AVL *ltree;
    AVL *rtree;
    int height;

    public:
        AVL();
        AVL(int x);
        int calcHeight(AVL *root);
        int balance(AVL *root);
        void ll(AVL **root);
        void rr(AVL **root);
        void insert(int x, AVL **root);
};

#endif