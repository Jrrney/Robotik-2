#include "Node.h"
#include <iostream>
#include <sstream>

// #define DEBUG
#ifdef DEBUG
#define DEBUG_MSG(x) cout << x << endl;
#else
#define DEBUG_MSG(x) ;
#endif

int Node::nodeId_ = 0;

Node::Node(const string &name) : name_(name)
{
    nodeId_++;
    if (name_ == "")
    {
        stringstream ss;
        ss << nodeId_;
        string nodeIdStr = ss.str();
        name_ = "node_" + to_string(nodeId_);
    }
    DEBUG_MSG("New Node created: " << name_);
}

Node::~Node()
{
    DEBUG_MSG("Enter ~node() of \"" << name_ << "\"");
    for (int i = 0; i < children_.size(); i++)
    {
        delete children_.at(i);
    }
    DEBUG_MSG("Leave ~node() of \"" << name_ << "\"");
}

Node *Node::createCompleteTree(int nrChildNodes, int treeDepth)
{
    if (treeDepth < 1)
    {
        throw invalid_argument("Tree depth must be at least 1");
    }
    Node *root = new Node();
    if (treeDepth == 1)
    {
        return root;
    }
    if (treeDepth > 1)
    {
        for (int i = 0; i < nrChildNodes; i++)
        {
            root->addChild(createCompleteTree(nrChildNodes, treeDepth - 1));
        }
    }
    return root;
}

void Node::setName(const string &name)
{
    name_ = name;
}

string Node::getName() const
{
    return name_;
}

int Node::getNrOfChildren() const
{
    return children_.size();
}

Node *Node::getChild(int index) const
{
    return children_.at(index);
}

void Node::addChild(Node *child)
{
    children_.push_back(child);
}

void Node::print(ostream &str, int indent) const
{
    for (int i = 0; i < indent; i++)
    {
        str << "    ";
    }
    str << name_ << endl;
    for (unsigned int i = 0; i < children_.size(); i++)
    {
        children_.at(i)->print(str, indent + 1);
    }
}

std::ostream &operator<<(std::ostream &os, Node &node)
{
    node.print(os);
    return os;
}
