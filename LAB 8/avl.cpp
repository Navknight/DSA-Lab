#include "avl.h"
#include <bits/stdc++.h>

AVL ::AVL() : val(0), ltree(NULL), rtree(NULL), height(0) {}

AVL ::AVL(int x)
{
    val = x;
    ltree = NULL;
    rtree = NULL;
    height = 0;
}

int AVL::calcHeight(AVL *root)
{
    if (root == NULL)
        return -1;
    else
        return max(calcHeight(root->ltree), calcHeight(root->rtree)) + 1;
}

int AVL::balance(AVL *root)
{
    if (!root)
        return -1;
    else
        return calcHeight(root->rtree) - calcHeight(root->ltree);
}

void AVL::ll(AVL **root)
{
    AVL *xrl;
    AVL *rc = (*root)->rtree;
    xrl = rc->ltree;
    rc->ltree = *root;
    (*root)->rtree = xrl;
    *root = rc;
    (*root)->ltree->height = calcHeight((*root)->ltree);
    (*root)->height = calcHeight(*root);
}

void AVL::rr(AVL **root)
{
    AVL *temp;
    AVL *lc = (*root)->ltree;
    temp = lc->rtree;
    lc->rtree = *root;
    (*root)->ltree = temp;
    *root = lc;
    (*root)->rtree->height = calcHeight((*root)->rtree);
    (*root)->height = calcHeight(*root);
}

void AVL::insert(int x, AVL **root)
{
    if(*root == NULL)
        *root = new AVL(x);
    else if((*root)->val > x)
        insert(x, &((*root)->ltree));
    else    
        insert(x, &((*root)->rtree));
    (*root)->height = calcHeight(*root);

    int q = balance(*root);
    if(q >= 2){
        int c = balance((*root)->rtree);
        if(c >= 0)
            ll(&(*root));
        else{
            rr(&(*root)->rtree);
            ll(&(*root));
        }
    }
    else if(q == -2){
        int c = balance((*root)->ltree);
        if(c<=0)
            rr(&(*root));
        else{
            ll(&(*root)->ltree);
            rr(&(*root));
        }
    }
}   