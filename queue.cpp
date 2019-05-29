// .author: Roland Nyamoga
// .date: May 16th, 2019
// .description: implementation file that defines a list  queue.

#include "queue.hpp"
#include <iostream>
#include <string>
#include <cstring>

// .description: default contructor, initializes head to null.
Queue::Queue()
{
    head = NULL;
}
// .description: checks if the queue is empty, if so returns true, otherwise return false.
bool Queue::isEmpty()
{
    if (!head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// .description: adds an int to the back of the queue
void Queue::addBack(int v)
{
    QueueNode *t = new QueueNode(v);//temp node for swapping

    if (isEmpty())//if it's an empty queue
    {
        head = t;
        head->next = head;
        head->prev = head;
    }
    else if (head == head->prev)//if there's only one item in the queue
    {
        head->prev = t;
        t->next = head;
        t->prev = head;
        head->next = t;
    }
    else//there's more than one item in the queue
    {
        head->prev->next = t;
        t->prev = head->prev;
        head->prev = t;
        t->next = head;//transfer whatever was head to t->next
    }
}

// .description: Prints the front queue value.
int Queue::getFront()
{
    std::cout << "\n";
    if (isEmpty())
    {
        std::cout << "This list seems to be empty!\n";
        return 0;
    }

    std::cout << head->value << std::endl;

    return head->value;
}
// .description: deletes the item at the front of the queue.
void Queue::removeFront()
{
    if (!isEmpty())
    {
        if (head == head->prev)//if there's only 1 item in the queue
        {
            delete head;
            head = NULL;
        }
        else
        {
            QueueNode *t = head->next;
            head->prev->next = t; //point t to next position of the last node to keep it circular
            t->prev = head->prev;
            delete head;
            head = NULL;
            head = t; //make t the head
        }
    }
    else
    {
        std::cout << "\nThis queue seems to be empty!\n";
    }
}

// .description: prints a queue from first to last item.
void Queue::printQueue()
{
    QueueNode *temp;
    if (!isEmpty())
    {
        temp = head;//start from the first queue item.
        std::cout << "\nYour queue is: " << temp->value << " ";

        while (temp != head->prev)
        {
            temp = temp->next;
            std::cout << temp->value << " ";  
        }
        std::cout << "\n";                
    }
    else
    {
        std::cout << "\nThis list seems to be empty!\n";
    }
}

//.destructor
Queue::~Queue()
{
    if (head)//only if there's something in the list
    {
        QueueNode *temp;
        head->prev->next = NULL;//cut the circle so you know when you're at the end
        while (head)
        {
            temp = head->next;
            delete head;
            head = NULL;
            head = temp;
        }
        temp = NULL;
    }
}