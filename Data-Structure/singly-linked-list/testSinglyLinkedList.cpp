#include "SinglyLinkedList.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <time.h>   // srand
#include <cstdlib>    // rand
using namespace std;

bool isOdd(const Node* node) {
    int tmp = node->value;
    if ( tmp < 0 ) {
        tmp *= -1;
    }
    return tmp % 2 == 1;
}

int main() {
    srand((unsigned int)time(0));

    SinglyLinkedList list;

    list.insert(7);
    list.insertAt(10, 1000);
    list.insert(3);
    list.insert(2);
    list.insert(4);
    list.insert(6);
    list.insert(3);
    list.print();

    list.insertAt(1, 9);
    list.set(5, 5);
    list.insert(6);
    list.insertAt(8, 4);
    list.print();   // 793245364

    list.pushBack(99);
    list.pushFront(-1);
    list.pushFront(-2);
    list.pushBack(100);
    list.print();


    list.removeAt(-1);
    list.removeAt(0);
    list.removeAt(3);
    list.removeAt(list.size() - 1);
    list.print();

    list.removeValue(4);
    list.print();

    list.removeIf( isOdd );
    list.print();

    for (int i = 0; i < 5; ++i) {
        list.insert(100 + i);
    }
    list.print();

    list.popBack();
    list.popBack();
    list.popFront();
    list.print();

    for (int i = 0; i < 5; ++i) {
        list.insertAt(0, 5 - i);
    }
    list.print();

    list.set(9,100);
    list.set(8,999);
    list.print();

    cout << "Size: " << list.size() << endl;
    for (int i = 0; i < 5; ++i) {
        int index = rand() % list.size();
        list.insertAt( index, 555 );
    }
    list.print("->");
    cout << "Count 7: " << list.count( 7 ) << endl;
    cout << "Count 555: " << list.count( 555 ) << endl;
    cout << "Count 0: " << list.count( 0 ) << endl;

    for (int i = 0; i < list.size(); ++i) {
        cout << i << "th element: " << list.get( i ) << endl;
    }

    vector<int> elements = list.getAll();
    for (int i = 0; i < elements.size(); ++i) {
        cout << "--" << elements.at( i );
    }
    cout << endl;

    return 0;
}
