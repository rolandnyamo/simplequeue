// .author: Roland Nyamoga 
// .date: May 16th, 2019
// .description: header file that defines a node linked list.

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>

//. description: this defines a node of int type value.
struct QueueNode 
{
    int value;
    QueueNode  *prev;
    QueueNode  *next;
    QueueNode  (int val, QueueNode  *p = NULL, QueueNode  *n = NULL)
    {
        value = val;
        prev = p;
        next = n;
    }
};

class Queue
{
private:
    QueueNode *head;//head node

public:
    Queue();
    bool isEmpty();
    void addBack(int);//addBack
    int getFront();
    void removeFront();
    void printQueue();
    ~Queue();
};

#endif