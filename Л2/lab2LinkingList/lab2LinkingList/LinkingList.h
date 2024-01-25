#pragma once
#ifndef LINKINGLIST_H
#define LINKINGLIST_H

#include "Node.h"

class LinkingList {

public:

    LinkingList();

    void add(char ch);

    void remove(int index);

    void display();

    Node* get(int index);

    Node* getLast();

    Node* getHead();

    bool containsChar(char ch);

    ~LinkingList();

private:

    Node* head;
    Node* end;

};

#endif