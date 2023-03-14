#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int x) : key(x), left(NULL), right(NULL) {}
};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
    return;
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
    return;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void levelorder(Node *root)
{
    vector<vector<int>> ans;
    if (!root)
        return;
    vector<Node *> current;
    vector<Node *> next;

    current.push_back(root);
    while (current.size() > 0)
    {
        vector<int> level;
        for (int i = 0; i < current.size(); i++)
        {
            level.push_back(current[i]->key);
            if (current[i]->left)
                next.push_back(current[i]->left);
            if (current[i]->right)
                next.push_back(current[i]->right);
        }
        ans.push_back(level);
        current.clear();
        current = next;
        next.clear();
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

bool isBst(Node *root, Node *min, Node *max)
{
    if (!root)
        return true;
    if (max == root)
        max = root->right ? root->right : new Node(INT32_MAX);
    if (min == root)
        min = root->left ? root->left : new Node(INT32_MIN);
    if ((max && max->key <= root->key) || (min && min->key >= root->key))
        return false;
    return isBst(root->right, root, max) && isBst(root->left, min, root);
}

Node *lca(Node *root, int a, int b)
{
    if (a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    if (!root)
        return root;
    if (a < root->key && b > root->key)
        return root;
    else if (a > root->key && b > root->key)
        return lca(root->right, a, b);
    else
        return lca(root->left, a, b);
}

Node *find(Node *root, int x)
{
    if (!root)
        return root;
    if (root->key == x)
        return root;
    if (x > root->key)
        return find(root->right, x);
    else
        return find(root->left, x);
}

int height(Node *root)
{
    if (!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(right, left) + 1;
}

Node* pre(Node* root, int x){
    k
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(25);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(18);
    root->right->left->right->right = new Node(19);
    root->right->right->left = new Node(24);
    root->right->right->right = new Node(30);
    root->right->right->left->left = new Node(22);
    root->right->right->right->right = new Node(35);

    cout << "inorder" << endl;
    inorder(root);

    cout << endl;
    cout << "postorder" << endl;
    postorder(root);

    cout << endl;
    cout << "preorder" << endl;
    preorder(root);

    cout << endl;
    cout << "levelorder" << endl;
    levelorder(root);

    cout << "Is this a BST?" << endl;
    if (isBst(root, NULL, NULL))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << "LCA of 12 and 24" << endl;
    cout << lca(root, 12, 24)->key << endl;

    cout << "Finding 20 in BST" << endl;
    Node *f = find(root, 20);
    cout << f->key << endl;

    cout << "Height of BST is" << endl;
    cout << height(root) << endl;


    return 0;
}