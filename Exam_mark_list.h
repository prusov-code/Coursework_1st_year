#pragma once
#include "Exam_mark.h"
class Exam_mark_list {
private:
    struct Node {
        Node* next;
        Exam_mark exam_mark_data;
    };
    Node* head;
    int size;

public:
    Exam_mark_list() {
        head = nullptr;
        size = 0;
    }
    ~Exam_mark_list() { 
        clear_list(); 
    }
    void push_back(Exam_mark exam_mark_data) {
        Node* node = new Node;
        node->exam_mark_data = exam_mark_data;
        node->next = nullptr;
        if (head == nullptr) {
            head = node;
        }  
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
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
    Exam_mark& operator[](int index) {
        Node* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        } 
        return current->exam_mark_data;
    }
};