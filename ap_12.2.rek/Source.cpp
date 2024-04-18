#include <iostream>

using namespace std;

struct Elem
{
    Elem* link;
    int info;
};

typedef int Info;

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;

    if (last != NULL)
        last->link = tmp;

    last = tmp;

    if (first == NULL)
        first = tmp;
}

Info dequeue(Elem*& first, Elem*& last)
{
    if (first == NULL) { 
        return 0;
    }
    else if (first == last) { 
        Info value = first->info;
        delete first;
        first = last = NULL;
        return value;
    }
    else { 
        Elem* tmp = first->link;
        Info value = first->info;
        delete first;
        first = tmp;
        return value;
    }
}

int count(Elem* L, int x)
{
    if (L == NULL) {
        return 0;
    }
    if (L->info == x) {
        return 1 + count(L->link, x);
    }
    else {
        return count(L->link, x);
    }
}

void removeValue(Elem*& first, Elem*& last, int value)
{
    Elem* current = first;
    Elem* previous = NULL;

    while (current != NULL)
    {
        if (current->info == value)
        {
            if (previous == NULL) 
            {
                first = current->link;
                delete current;
                current = first;
                if (first == NULL) 
                    last = NULL;
            }
            else
            {
                previous->link = current->link;
                if (current == last) 
                    last = previous;
                delete current;
                current = previous->link;
            }
        }
        else
        {
            previous = current;
            current = current->link;
        }
    }
}

void printList(Elem* L)
{
    while (L != NULL)
    {
        cout << L->info << " ";
        L = L->link;
    }
    cout << endl;
}

int main()
{
    Elem* first = NULL;
    Elem* last = NULL;

    for (int i = 1; i <= 10; i++)
        enqueue(first, last, i);
   
    cout << "List: ";
    printList(first);

    int x;
    cout << "Element to delete: ";
    cin >> x;

    removeValue(first, last, x);

    cout << "List: ";
    printList(first);

    return 0;
}
