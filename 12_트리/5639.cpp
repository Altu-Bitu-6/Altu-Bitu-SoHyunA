#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
struct nd {
    int data;
    nd* left =NULL;
    nd* right=NULL; 
};

void postorder(nd* node) {
    if (node->left) {
        postorder(node->left);
    }
    if (node->right) {
        postorder(node->right);
    }
    cout << node->data<<"\n";
}

void makeTree(nd* &node, nd* n) {
    if (node == NULL) {
        node=n;
        return;
    }
    if (n->data < node->data) {
        makeTree(node->left, n);
    }
    else {
        makeTree(node->right, n);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    nd* root = new nd(); cin >> root->data;
    
    int x;
    while (cin >> x) {
        nd* n = new nd(); n->data = x;
        makeTree(root, n);
    }

    postorder(root);

    return 0;
}