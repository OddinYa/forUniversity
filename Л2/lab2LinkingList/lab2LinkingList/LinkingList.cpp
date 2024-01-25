
#include <iostream>
#include "LinkingList.h"

LinkingList::LinkingList() {
    head = nullptr;
}

void LinkingList::add(char ch) {

    Node* node = new Node(ch);

    if (head == nullptr) {
        head = node;
        end = node;
    }
    else {
        node->prev = end;
        end->next = node;
        end = node;
    }
}

Node* LinkingList::get(int index) {

    Node* current = head;

    int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    return current;

}

Node* LinkingList::getLast() {
    return end;
}
Node* LinkingList::getHead() {
    return head;
}

void LinkingList::remove(int index) {

    Node* nodeToRemove = get(index);

    if (nodeToRemove != nullptr) {
        if (nodeToRemove->prev != nullptr) {
            nodeToRemove->prev->next = nodeToRemove->next;
        }
        else {
            head = nodeToRemove->next;
        }

        if (nodeToRemove->next != nullptr) {
            nodeToRemove->next->prev = nodeToRemove->prev;
        }

        if (nodeToRemove == end) {
            end = nodeToRemove->prev;
        }

        delete nodeToRemove;
    }
}


bool LinkingList::containsChar(char ch) {
    Node* current = head;

    while (current != nullptr) {
        if (current->ch == ch) {
            return true;
        }
        else {
            current = current->next;
        }
    }
    return false;
}

LinkingList::~LinkingList(){

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkingList::display() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->ch << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

