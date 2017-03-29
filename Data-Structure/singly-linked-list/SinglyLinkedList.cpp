#include "SinglyLinkedList.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

SinglyLinkedList::SinglyLinkedList() {
    __head = NULL;
    __size = 0;
}

SinglyLinkedList::~SinglyLinkedList() {
    __destroy(__head);
}

void SinglyLinkedList::insert(int value) {
    pushBack( value );    // Push back, when no position is specified.
}

void SinglyLinkedList::insertAt(int pos, int value) {
    if (pos < 0 || pos > __size) {
        cout << "Insertion error: index(" << pos << ") must be within [0," << __size << "], currently" << endl;
        return;
    }

    Node** indir = &__head;
    int i = 0;
    while ( *indir && i < pos ) {
        indir = &( (*indir)->next );
        ++i;
    }
    *indir = new Node( value, *indir );

    ++__size;
}

void SinglyLinkedList::pushBack(int value) {
    Node** indir = &__head;
    while ( *indir ) {
        indir = &( (*indir)->next );
    }
    *indir = new Node( value );

    ++__size;
}

void SinglyLinkedList::pushFront(int value) {
    Node** indir = &__head;
    *indir = new Node( value, *indir );

    ++__size;
}

void SinglyLinkedList::removeAt(int pos) {
    if ( pos < 0 || pos >= __size ) {
        cout << "Removal error: index(" << pos << ") must be within [0," << __size - 1 << "], currently." << endl;
        return;
    }

    Node** indir = &__head;
    for (int i = 0; i < pos; ++i) {
        indir = &( (*indir)->next );
    }
    Node* entry = *indir;
    *indir = entry->next;
    if (entry) {    // Caution, when the list is empty.(Don't delete a NULL head.)
        delete entry;
        --__size;
    }
}

void SinglyLinkedList::removeValue(int valueToRemove) {
    Node** indir = &__head;
    Node* entry;
    while ( *indir ) {
        if ( (*indir)->value == valueToRemove ) {
            entry = *indir;
            *indir = entry->next;
            delete entry;
            --__size;
        } else {
            indir = &( (*indir)->next );
        }
    }
}

void SinglyLinkedList::removeIf(UNARY_PREDICATE predicate) {
    Node** indir = &__head;
    Node* entry;
    while ( *indir ) {
        entry = *indir;
        if ( predicate( entry ) ) {
            *indir = entry->next;
            delete entry;
            --__size;
        } else {
            indir = &( entry->next );
        }
    }
}

void SinglyLinkedList::popBack() {
    Node** indir = &__head;
    while ( *indir && (*indir)->next ) {
        indir = &( (*indir)->next );
    }
    Node* entry = *indir;
    *indir = NULL;
    if ( entry ) {  // Caution, when the list is empty.(Don't delete a NULL head.)
        delete entry;
        --__size;
    }
}

void SinglyLinkedList::popFront() {
    Node** indir = &__head;
    Node* entry = *indir;
    *indir = (*indir)->next;
    if ( entry ) {  // Caution, when the list is empty.(Don't delete a NULL head.)
        delete entry;
        --__size;
    }
}

vector<int> SinglyLinkedList::getAll() const {
    vector<int> ret;
    Node* p = __head;
    while ( p ) {
        ret.push_back( p->value );
        p = p->next;
    }
    return ret;
}

void SinglyLinkedList::print(const string &delim) const {
    cout << "List(" << __size << " nodes): ";

    Node* p = __head;
    bool isFirst = true;
    while ( p ) {
        if (isFirst) {
            isFirst = false;
            cout << p->value;
        } else {
            cout << delim << p->value;
        }
        p = p->next;
    }
    cout << endl;
}

int SinglyLinkedList::get(int pos) const {
    if (pos < 0 || pos >= __size) {
        cout << "Retrieve error: index must be within [0," << __size - 1 << "]" << endl;
        return ERROR_VALUE;
    }

    Node* p = __head;
    for (int i = 0; i < pos; ++i) {
        p = p->next;
    }
    return p->value;
}

void SinglyLinkedList::set(int pos, int newValue) {
    if (pos < 0 || pos >= __size) {
        cout << "Update error: index(" << pos << ") must be within [0," << __size - 1 << "]" << endl;
        return;
    }

    Node* p = __head;
    int i = 0;
    while ( i < pos ) {
        p = p->next;
        ++i;
    }
    p->value = newValue;
}

int SinglyLinkedList::count(int value) const {
    Node* p = __head;
    int ret = 0;
    while ( p ) {
        if ( p->value == value ) {
            ++ret;
        }
        p = p->next;
    }
    return ret;
}

int SinglyLinkedList::size() const {
    return __size;
}



void SinglyLinkedList::__destroy(Node* &head) {
    Node* entry = head;
    while ( entry ) {
        head = head->next;
        delete entry;
        entry = head;
    }
    head = NULL;
}