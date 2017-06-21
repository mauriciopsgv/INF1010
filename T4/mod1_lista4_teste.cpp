#include "mod1_lista4.h"

#include <iostream>
using namespace std;

int main()
{
    Avl a;
    a.insert(5);
    a.insert(8);
    a.insert(10);
    a.insert(4);
    a.insert(3);
    a.insert(6);
    a.insert(12);
    a.insert(11);
    a.show("1) Original Tree");

    std::cout << "\n2) Height: " << a.height() << std::endl;

    std::cout << "\n3) Traversal:\n";

    a.first();
    std::cout << a.value();
    while (a.next())
    {
        std::cout << " " << a.value();
    }
    std::cout << std::endl;

    a.last();
    std::cout << a.value();
    while (a.prev())
    {
        std::cout << " " << a.value();
    }
    std::cout << std::endl;

    a.remove(7);  //tries to remove a non-existent key
    a.show("\n4) After non-existent key (7) removing attempt:");
    a.remove(5);  //causes left-rotation
    a.show("\n4) Removing 5 causes left rotation:");
    a.remove(12); //causes left-right rotation
    a.show("\n4) Removing 12 causes left-right rotation:");
    a.insert(7);
    a.insert(9);
    a.show("\n4) After insertion of keys 7 and 9:");
    a.remove(11); //causes right-rotation
    a.show("\n4) Removing 11 causes right rotation:");
    a.remove(6);  //causes right-left rotation
    a.show("\n4) Removing 6 causes right-left rotation:");
    a.remove(4);  //one child node remove
    a.show("\n4) After one child node (4) remove:");

    Avl b(a);
    b.show("\n5) Copy");

    std::cout << "\n6) Delete to be assessed." << std::endl;

    return 0;
}

