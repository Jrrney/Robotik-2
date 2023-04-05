#include "Node.h"
#include <iostream>

using namespace std;

int main()
{
    // Node *root = new Node();
    // root->addChild(new Node());
    // root->addChild(new Node());
    // delete root;

    // try
    // {
    //     Node *root2 = Node::createCompleteTree(2, -1);
    //     delete root2;
    // }
    // catch (const exception &e)
    // {
    //     cerr << e.what() << endl;
    // }

    Node *root2 = Node::createCompleteTree(2, 4);
    // root2->print(cout);
    cout << root2;
    delete root2;
    return 0;
}
