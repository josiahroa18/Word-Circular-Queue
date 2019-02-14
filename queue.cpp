#include <iostream>
#include <sstream>
#include "queue.h"
using namespace std;

Queue::Queue(int sizeArray)
{
    queueSize = sizeArray;
    queue = new string [queueSize];
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
}

Queue::~Queue()
{
    delete [] queue;
    queue = nullptr;
}

void Queue::enqueue(string input)
{
    if(queueIsFull())
    {
        cout << "Queue full" << endl;
    }
    else if(queueIsEmpty())
    {
        queue[queueHead] = input;
        queueTail++;
        cout << "E: " << input << endl;
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
        queueCount++;
    }
    else{
        queue[queueTail] = input;
        cout << "E: " << input << endl;
        cout << "H: " << queueHead << endl;
        queueTail++;
        if(queueTail == queueSize)
        {
            queueTail = 0;
        }
        cout << "T: " << queueTail << endl;
        queueCount++;
    }
}

void Queue::printQueue()
{
    if(queueIsEmpty())
    {
        cout << "Queue empty" << endl;
    }
    for(int i = queueHead; i < queueTail; i++)
    {
        cout << i << ": " << queue[i] << endl;
    }
}

void Queue::dequeue()
{
    if(queueIsEmpty())
    {
        cout << "Queue empty" << endl;
    }
    else
    {
        string word = queue[queueHead];
        queueHead++;
        if(queueHead == queueSize)
        {
            queueHead = 0;
        }
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
        cout << "Word: " << word << endl;
        queueCount --;
    }
}

void Queue::enqueueSentence(string sentence)
{
    istringstream ss(sentence);
    string word;
    while(getline(ss, word, ' '))
    {
        enqueue(word);
    }
}

bool Queue::queueIsFull()
{
    if(queueCount == queueSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Queue::queueIsEmpty()
{
    if(queueCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}