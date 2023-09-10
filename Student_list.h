#pragma once
#include "Student.h"
class Student_list {
private:
    struct Node {
        Node* next;
        Student Student_data;
    };
    Node* head;
    int size;

public:
    Student_list() {
        head = nullptr;
        size = 0;
    }
    ~Student_list() { clear_list(); }

    void push_back(Student Student_data) {
        Node* node = new Node;
        node->Student_data = Student_data;
        node->next = nullptr;
        if (head == nullptr) {
            head = node;
        }
        else {
            Node* current = head;
            for (current = head; current->next != nullptr; current = current->next);
            current->next = node;
        }
        size++;
    }
    void clear_list() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
            size--;
        }
    }
    Student& operator[](int index) {
        Node* current = head;
        for (int i = 0; i < index; i++) { current = current->next; }
        return current->Student_data;
    }
    int get_size() { return size; }
};