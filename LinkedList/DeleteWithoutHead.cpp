
/*
Given only a pointer/reference to a node to be deleted in a singly linked list, how do you delete it?
*/
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <vector>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{
    Node *newcurr = node->next;
    node->data = newcurr->data;
    node->next = newcurr->next;
    delete (newcurr);
}

/*
This solution doesn’t work if the node to be deleted is the last node of the list. To make this solution work we can mark the end node as a dummy node. But the programs/functions that are using this function should also be modified.
*/