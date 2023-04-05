#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using namespace std;

class Node
{

private:
    static int nodeId_;
    string name_;
    vector<Node *> children_;

public:
    Node(const string &name = "");

    virtual ~Node();

    static Node *createCompleteTree(int nrChildNodes, int treeDepth);

    void setName(const std::string &name);

    std::string getName() const;

    int getNrOfChildren() const;

    Node *getChild(int index) const;

    void addChild(Node *child);

    void print(ostream &str, int indent = 0) const;

    friend ostream &operator<<(ostream &os, Node &node);
};

#endif
