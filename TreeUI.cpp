/// @file TreeUI.cpp
/// @brief tests the Node class
/// @author Jenny Dietrich
/// @date 2023-04-05
/// @version 1.0

#include "Node.h"

int main()
{
    Node *root = new Node();
    root->addChild(new Node());
    root->addChild(new Node());
    /// in the first place, the children are deleted, then the parent
    /// because the destructor of the parent calls the destructor of the children
    /// and the parents cannot be deleted before the children
    delete root;

    try
    {
        Node *tree = Node::createCompleteTree(2, -1);
        delete tree;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    Node *tree2 = Node::createCompleteTree(2, 4);
    cout << (&tree2) << endl;
    delete tree2;

    return 0;
}
