#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
using namespace std;

struct Node
{
    int num;
    Node *left, *right;
};

const int MAXN = 40;
int n, inorder[MAXN], postorder[MAXN];
unordered_map<int, int> idx;

Node *restore(int t, int l, int r)
{
    if (l > r) return nullptr;
    int i = idx[postorder[t]];
    Node *root = new Node({postorder[t]});
    root->left = restore(t-(r-i)-1, l, i-1);
    root->right = restore(t-1, i+1, r);
    return root;
}

void travel(Node *root)
{
    if (root == nullptr) return;
    printf("%d ", root->num);
    travel(root->left);
    travel(root->right);
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &inorder[i]);
        idx[inorder[i]] = i;
    }
    for (int i=0; i<n; i++)
        scanf("%d", &postorder[i]);
    travel(restore(n-1, 0, n-1));
    return 0;
}