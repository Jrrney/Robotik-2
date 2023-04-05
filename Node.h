/// @file Node.h
/// @brief contains the declaration of the Node class
/// @author Jenny Dietrich
/// @date 2023-04-05
/// @version 1.0

#ifndef NODE_H
#define NODE_H

// #define DEBUG

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Node
{

private:
    static int nodeId_;
    string name_;
    vector<Node *> children_;

public:
    ///
    /// @brief creates a new node with the given name as a const reference to a string.
    /// If no name is given, the node is named "node_<id>", where <id> is a unique id
    /// This is a pass-by-reference parameter, so the string is not copied, which is more efficient.
    /// @param name the name of the node (default: "")
    ///
    Node(const string &name = "");

    ///
    /// @brief destroys the node and all its children
    /// virtual because we want to be able to delete a Node pointer to a derived class
    ///
    virtual ~Node();

    ///
    /// @brief creates a complete tree with the given number of children per node and the given depth
    /// @param nrChildNodes the number of children per node
    /// @param treeDepth the depth of the tree
    /// @return the root of the tree
    /// @throws invalid_argument if treeDepth < 1
    ///
    static Node *createCompleteTree(int nrChildNodes, int treeDepth);

    ///
    /// @brief sets the name of the node to a new name
    /// @param name the new name
    ///
    void setName(const string &name);

    ///
    /// @brief returns the name of the node
    /// @return the name of the node
    /// const const because it does not copy the string
    /// this is more efficient
    ///
    string getName() const;

    ///
    /// @brief returns the number of the direct children of the node
    /// @return the number of the direct children of the node
    ///
    int getNrOfChildren() const;

    ///
    /// @brief returns the child at the given index
    /// @param index the index of the child
    /// @return the child at the given index
    /// @throws out_of_range if index < 0 or index >= getNrOfChildren()
    ///
    Node *getChild(int index) const;

    ///
    /// @brief adds a child to the node
    /// @param child the child to add
    ///
    void addChild(Node *child);

    ///
    /// @brief prints the node and its children to the given stream
    /// @param str the stream to print to
    /// @param indent the number of spaces to indent the node
    ///
    void print(ostream &str, int indent = 0) const;

    ///
    /// @brief overload of the << operator to print the node and its children to the given stream
    /// @param str the stream to print to
    /// @param node the node to print
    /// @return the stream
    ///
    friend ostream &operator<<(ostream &os, Node &node);
};

#endif
