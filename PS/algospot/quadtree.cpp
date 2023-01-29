#include <iostream>
using namespace std;

typedef struct quadtree
{
    char color;
    quadtree *leftupper;
    quadtree *rightupper;
    quadtree *leftbelow;
    quadtree *rightbelow;
} quadtree;

typedef struct MyTuple
{
    char *first;
    quadtree *second;
} MyTuple;

MyTuple makeTree(quadtree *root, char *data)
{
    if (data[0] == 'x')
    {
        root->color = data[0];
        MyTuple temp = makeTree((quadtree *)malloc(sizeof(quadtree)), data + 1);
        root->leftupper = temp.second;
        data = temp.first;

        temp = makeTree((quadtree *)malloc(sizeof(quadtree)), data);
        root->rightupper = temp.second;
        data = temp.first;

        temp = makeTree((quadtree *)malloc(sizeof(quadtree)), data);
        root->leftbelow = temp.second;
        data = temp.first;

        temp = makeTree((quadtree *)malloc(sizeof(quadtree)), data);
        root->rightbelow = temp.second;
        data = temp.first;

        MyTuple ret;
        ret.first = data;
        ret.second = root;
        return ret;
    }
    else
    {
        root->color = data[0];
        root->leftbelow = root->rightbelow = root->leftupper = root->rightupper = nullptr;
        data = data + 1;
        MyTuple ret;
        ret.first = data;
        ret.second = root;
        return ret;
    }
}

void printTree(quadtree *root)
{
    if (root == nullptr)
        return;
    else
    {
        cout << root->color;
        printTree(root->leftupper);
        printTree(root->rightupper);
        printTree(root->leftbelow);
        printTree(root->rightbelow);
        return;
    }
}

quadtree *reverse(quadtree *root)
{
    if (root->leftupper == nullptr)
        return root;
    else
    {
        root->leftupper = reverse(root->leftupper);
        root->leftbelow = reverse(root->leftbelow);
        quadtree *temp = root->leftupper;
        root->leftupper = root->leftbelow;
        root->leftbelow = temp;

        root->rightupper = reverse(root->rightupper);
        root->rightbelow = reverse(root->rightbelow);
        temp = root->rightupper;
        root->rightupper = root->rightbelow;
        root->rightbelow = temp;
        return root;
    }
}

void freeTree(quadtree *root)
{
    if (root == nullptr)
        free(root);
    else
    {
        freeTree(root->leftbelow);
        freeTree(root->leftupper);
        freeTree(root->rightbelow);
        freeTree(root->rightupper);
        free(root);
        return;
    }
}

int main()
{
    int C;
    cin >> C;
    cin.get();
    char *tree = (char *)malloc(1000 * sizeof(char));
    quadtree *root;

    for (int i = 0; i < C; i++)
    {
        cin.getline(tree, 1000);
        root = makeTree((quadtree *)malloc(sizeof(quadtree)), tree).second;

        printTree(reverse(root));
        cout << '\n';
    }
    freeTree(root);
}
