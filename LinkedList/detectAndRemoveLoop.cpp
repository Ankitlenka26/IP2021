
//Detect and Remove Loop in a Linked List
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <vector>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    Node *fastptr = head;                       // it will jump twice
    Node *slowptr = head;                       // it will jump a single jump
    int loopexists = 0;                         // 0 indicates the loop does not exists till now
    while (slowptr && fastptr && fastptr->next) // the condition that will insure that even if linked list is not circular the program does not run into infinite loop
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (slowptr == fastptr) // the first time slowptr and fastptr matches
        {
            loopexists = 1;  
            break;   // break out of the loop as we know that the loop exists now we just have to 
        }
    }

    if (loopexists)
    {
        fastptr = head;
        while (temp->next != slowptr)
        {
            temp = temp->next;
        }
        while (fastptr != slowptr)
        {
            temp = slowptr;
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }

        temp->next = NULL;
    }
    return;
}

/*
We do not need to count number of nodes in Loop. After detecting the loop, if we start slow pointer from head 
and move both slow and fast pointers at same speed until fast don’t meet, they would meet at the beginning of the loop.


Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time
           m + k = (x-2y)*n

Which means m+k is a multiple of n. 
Thus we can write, m + k = i*n or m = i*n - k.
Hence, distance moved by slow pointer: m, is equal to distance moved by fast pointer:
i*n - k or (i-1)*n + n - k (cover the loop completely i-1 times and start from n-k).
*/

/*
Method 4 Hashing: Hash the address of the linked list nodes 
We can hash the addresses of the linked list nodes in an unordered map and just check if the element already exists in the map. 
If it exists, we have reached a node which already exists by a cycle, hence we need to make the last node’s next pointer NULL.
*/