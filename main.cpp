#include <iostream>
#include "queue.h"
using namespace std;

void menu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Enqueue word" << endl;
    cout << "2. Dequeue word" << endl;
    cout << "3. Print queue" << endl;
    cout << "4. Enqueue sentence" << endl;
    cout << "5. Quit" << endl;
}

int main()
{
    Queue wordQueue(3);
    int userInput;
    bool run = true;
    string newWord;
    string sentence;
    while(run)
    {
        menu();
        cin >> userInput;
        switch(userInput)
        {
            case 1:
                cout << "What word would you like to add?" << endl;
                cin >> newWord;
                wordQueue.enqueue(newWord);
                break;
            case 2:
                wordQueue.dequeue();
                break;
            case 3:
                wordQueue.printQueue();
                break;
            case 4:
                cout << "sentence: ";
                cin.ignore();
                getline(cin, sentence);
                wordQueue.enqueueSentence(sentence);
                break;
            case 5:
                run = false;
                break;
        }
    }
}
