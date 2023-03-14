#include <bits/stdc++.h>
#include "rbtree.h"

RB::RB() : val({0, 0}), ltree(NULL), rtree(NULL), color(0), bheight(1) {}

RB::RB(double x, double y)
{
    val = {x, y};
    ltree = NULL;
    rtree = NULL;
    parent = NULL;
    color = 0;
    bheight = 1;
}

RB *RB::createNode(double x, double y)
{
    RB *temp = new RB(x, y);
    return temp;
}

int RB::calcHeight(RB *root)
{
    if (root == NULL)
        return 1;
    else
        return max(calcHeight(root->ltree), calcHeight((root)->rtree)) + (root)->color;
}

void RB::ll(RB **root)
{
    RB *rc = (*root)->rtree;
    RB *xrl = rc->ltree;
    rc->ltree = *root;
    (*root)->rtree = xrl;
    root = &(rc);
    (*root)->ltree->bheight = calcHeight((*root)->ltree);
    (*root)->bheight = calcHeight(*root);
}

void RB::rr(RB **root)
{
    RB *lc = (*root)->ltree;
    RB *xlr = lc->rtree;
    lc->ltree = *root;
    (*root)->ltree = xlr;
    root = &(lc);
    (*root)->rtree->bheight = calcHeight((*root)->rtree);
    (*root)->bheight = calcHeight(*root);
}

bool RB::checkRb(RB *root)
{
    if (root == NULL)
        return true;
    else if (root->color == 0 && (root->ltree->color == 0 || root->rtree->color == 0))
        return false;
    else if (root->ltree->bheight != root->rtree->bheight)
        return false;
    else
        return checkRb(root->ltree) && checkRb(root->rtree);
}

void RB::insert(double x, double y, RB **root)
{
    if (*root == NULL)
        *root = createNode(x, y);
    else if ((*root)->val.first > x)
    {
        insert(x, y, &(*root)->ltree);
        (*root)->ltree->parent = *root;
        if ((*root)->ltree->color == 0 && (*root)->color == 0)
            balance(root, 0);
    }
    else if ((*root)->val.first < x)
    {
        insert(x, y, &(*root)->rtree);
        (*root)->rtree->parent = *root;
        if ((*root)->rtree->color == 0 && (*root)->color == 0)
            balance(root, 1);
    }
    else
    {
        if ((*root)->val.second > y)
        {
            insert(x, y, &(*root)->ltree);
            (*root)->ltree->parent = *root;
            if ((*root)->ltree->color == 0 && (*root)->color == 0)
                balance(root, 0);
        }
        else
        {
            insert(x, y, &(*root)->rtree);
            (*root)->rtree->parent = *root;
            if ((*root)->rtree->color == 0 && (*root)->color == 0)
                balance(root, 1);
        }
    }
}

void RB::balance(RB **root, int loc)
{
    
}
