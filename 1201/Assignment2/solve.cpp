#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
node *newNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void lsum(node *r, int &sum)
{
    if (!r)
    {
        return;
    }
    if (!r->left && !r->right)
    {
        sum += r->data;
    }

    lsum(r->left, sum);
    lsum(r->right, sum);
}
int main()
{
    node *root = newNode(2);
    root->left = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->left->right->right = newNode(11);
    root->left->right->left = newNode(5);
    root->right = newNode(5);
    root->right->right = newNode(9);
    root->right->right->left = newNode(4);
    int sum = 0;
    lsum(root, sum);
    cout << "Sum of the Leaf nodes : " << sum << endl;
}