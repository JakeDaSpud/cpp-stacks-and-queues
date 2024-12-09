#pragma once
#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include <iostream>

template <typename T>
class SLinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr) {}
    };

    Node* m_head;
    int m_size;

public:
    SLinkedList() : m_head(nullptr), m_size(0) {}
    ~SLinkedList() { clear(); }

    // Add an element to the front
    void push_front(const T &value) {
        Node* new_node = new Node(value);
        new_node->next = this->m_head;
        this->m_head = new_node;
        this->m_size++;
    }

    // Add an element to the back
    void push_back(const T &value) {
        Node* new_node = new Node(value);
        
        if (!this->m_head) {
            this->m_head = new_node;
        } 
        
        else {
            Node* temp = this->m_head;
            
            while (temp->next) {
                temp = temp->next;
            }

            temp->next = new_node;
        }

        this->m_size++;
    }

    // Remove an element from the front
    void pop_front() {
        if (!m_head) return;
        Node* temp = this->m_head;
        this->m_head = m_head->next;
        delete temp;
        this->m_size--;
    }

    // Get the size of the list
    int size() const {
        return this->m_size;
    }

    // Check if the list is empty
    bool empty() const {
        return this->m_size == 0;
    }

    // Clear the entire list
    void clear() {
        while (this->m_head) {
            pop_front();
        }
    }

    void print() {
        Node* temp = this->m_head;
        if (temp != nullptr)
            std::cout << "Node: " << temp->data;
            
        temp = temp->next;
        
        while (temp != nullptr) {
            std::cout << " | Node: " << temp->data; 
            temp = temp->next;
        }

        std::cout << '\n';
    }
};

#endif // SLINKEDLIST_H
