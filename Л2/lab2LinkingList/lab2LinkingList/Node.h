#pragma once
#ifndef NODE_H
#define NODE_H

class Node {
public:

    Node(char ch);

    char ch;

    Node* next;
    Node* prev;

};

#endif //NODE_H
