#include "menu.hpp"
#include "queue.hpp"

int main()
{
    int choice = -1;

    Queue *queue1 = new Queue;//create a new queue

    std::cout << "\nWelcome to my queue!\n";
    
    Menu menu1("\n***\nChoose from following options\n***\n", 5);
    menu1.setOptions(1, "Add a value to the back of queue");
    menu1.setOptions(2, "Display the front value");
    menu1.setOptions(3, "Remove the front node");
    menu1.setOptions(4, "Display the queue content");
    menu1.setOptions(5, "Exit");

    choice = menu1.displayOptions();

    while (choice != 5)
    {
        if (choice == 1)
        {
            std::cout << "Enter a positive integer to add to the front of the queue: ";
            int head = Menu::getInt();

            queue1->addBack(head);

            choice = menu1.displayOptions();
        }
        else if (choice == 2)
        {
            queue1->getFront();
            choice = menu1.displayOptions();
        }
        else if (choice == 3)
        {
            queue1->removeFront();
            choice = menu1.displayOptions();
        }
        else if (choice == 4)
        {
            queue1->printQueue();
            choice = menu1.displayOptions();
        }        
    }
    std::cout <<"\n\nGoodbye!\n\n";
    delete queue1;
	queue1 = NULL;
}