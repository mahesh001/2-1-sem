#include<iostream>
using namespace std;
class BTreeNode
{
    int keys;  
    int d;     
    BTreeNode **C; //child pointer
    int n;     
    bool leaf; 
public:
    BTreeNode(int _t, bool _leaf);   
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(int k);  
friend class BTree;
};
class BTree
{
    BTreeNode *root; 
    int d; //degree
public:
    BTree(int _t)
    {  root = NULL;  d = _t; }
    void traverse()
    {  if (root != NULL) root->traverse(); }
    BTreeNode* search(int k)
    {  return (root == NULL)? NULL : root->search(k); }
    void insert(int k);
};
BTreeNode::BTreeNode(int t1, bool leaf1)
{
    d = t1;
    leaf = leaf1;
    keys = new int[2*d-1];
    C = new BTreeNode *[2*d];
    n = 0;
}
void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (leaf == false)
            C[i]->traverse();
        cout << " " << keys[i];
    }
    if (leaf == false)
        C[i]->traverse();
}
BTreeNode *BTreeNode::search(int k)
{
    int i = 0;
    while (i < n && k > keys[i])
        i++;
    if (keys[i] == k)
        return this;
    if (leaf == true)
        return NULL;
    return C[i]->search(k);
}
void BTree::insert(int k[])
{
    if (root == NULL)
    {
        root = new BTreeNode(d, true);
        root->keys[0] = k; 
        root->n = 1;  
    }
    else 
    {
        if (root->n == 2*d-1)
        {
            BTreeNode *s = new BTreeNode(d, false);
            s->C[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);
            root = s;
        }
        else  
            root->insertNonFull(k);
    }
}
void BTreeNode::insertNonFull(int k)
{
    int i = n-1;
    if (leaf == true)
    {
        while (i >= 0 && keys[i] > k)
        {
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = k;
        n = n+1;
    }
    else 
    {
        while (i >= 0 && keys[i] > k)
            i--;
        if (C[i+1]->n == 2*d-1)
        {
            splitChild(i+1, C[i+1]);
            if (keys[i+1] < k)
                i++;
        }
        C[i+1]->insertNonFull(k);
    }
}
void BTreeNode::splitChild(int i, BTreeNode *y)
{
    BTreeNode *z = new BTreeNode(y->d, y->leaf);
    z->n = d - 1;
    for (int j = 0; j < d-1; j++)
        z->keys[j] = y->keys[j+d];
    if (y->leaf == false)
    {
        for (int j = 0; j < d; j++)
            z->C[j] = y->C[j+d];
    }
    y->n = d - 1;
    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];
    C[i+1] = z;
    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];
    keys[i] = y->keys[d-1];
    n = n + 1;
}
int main()
{ int n,element[30],k;
cout<<"enter the degree of tree \n";
cin>>n;
    BTree d(n); 
    cout<<"enter the element of the tree else press / \n";
    cin>>element[2*n];
    for(int i=0;i<2*n;i++)
    {
    if(element[0]=='/')
    break;
    else
    d.insert(element[i]);
}
    
 
    cout << "Traversal of the constucted tree is ";
    d.traverse();
 cout<<"enter the element for search \n";
 cin>>k;
    (d.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
    return 0;
}
