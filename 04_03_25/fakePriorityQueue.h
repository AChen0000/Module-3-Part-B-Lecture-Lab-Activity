#ifndef PQUEUE_H
#define PQUEUE_H

#include "linkedQueue.h"

template <class T>
class fakePriorityQueue : public linkedQueue<T>
{
public:
    void enqueue(const T &queueElement); // Add a new element to the queue
};

template <class T>
void fakePriorityQueue<T>::enqueue(const T &queueElement)
{
    // create a new node and assign the data to it
    node<T> *newNode = new node<T>;
    newNode->data = queueElement;
    newNode->link = nullptr; // Initially, no next node

    // check if the queue is empty
    if (this->isEmptyQueue())
    {
        // if empty, the new node is both the front and rear of the queue
        this->queueFront = newNode;
        this->queueRear = newNode;
    }
    else
    {
        node<T> *current = this->queueFront;
        node<T> *previous = nullptr;

        // We insert the node where its priority is lower (or equal) than the current node.
        while (current != nullptr && current->data >= queueElement)
        {
            previous = current;
            current = current->link;
        }

        // insert the new node at the correct spot.
        if (previous == nullptr)
        {
            // insert at the front of the queue 
            newNode->link = this->queueFront;
            this->queueFront = newNode;
        }
        else
        {
            // Insert the new node after the previous node
            previous->link = newNode;
            newNode->link = current;
          
            if (current == nullptr)
            {
                this->queueRear = newNode;
            }
        }
    }
}

#endif
