#pragma once
#include <iostream>


namespace cppmath {
  template <typename T>
  class ListNode {
    public:
      ListNode *next = nullptr;
      ListNode *prev = nullptr;
      T data;

    public:
      // Initialization
      ListNode<T>(){};
      ListNode<T>(T data) { this->data = data; }
  };

  template <typename T> 
  class List {
    ListNode<T> *nodes = nullptr;
    int length = 0;

    public:
      // Initialization
      List<T>(){};

      // Destruction
    ~List<T>() {
        ListNode<T> *node = this->nodes;
        if (node != nullptr) {
          while (node->next != nullptr) {
            node = node->next;
            delete node->prev;
          }

          delete node;
        }
      }
      
      // Overloads
      T& operator[](const int idx) {
        if (idx < 0 || idx >= this->length) {
          throw "ERROR: Invalid Index";
        }

        ListNode<T> *node = this->nodes;
        for (int i = 0; i < idx; i++) {
          node = node->next;
        }

        return node->data;
      }

      // Utilities
      void print() {
        std::cout << "[";

        ListNode<T> *node = this->nodes;

        if (node != nullptr) {
          while (node != nullptr) {
            std::cout << node->data;

            if (node->next != nullptr) {
              std::cout << ", ";
            }
            node = node->next;
          }
        }

        std::cout << "]\n";
      }
      
      List filter(bool (*func)(T value)) {
        ListNode<T>* node = this->nodes;
        List found = List<T>();
        while(node != nullptr) {
          T data = node->data;
          if (func(node->data)) found.push_back(data);
          
          node = node->next;
        }

        return found;
      }

      List reverse() {
        List reversed = List<T>();
        ListNode<T>* node = this->nodes;

        while (node != nullptr) {
          reversed.push_begin(node->data);
          node = node->next;
        }

        return reversed;
      }

      List copy() {
        List copy_list = List<T>();
        ListNode<T>* node = this->nodes;
        while (node != nullptr) {
          copy_list.push_back(node->data);
          node = node->next;
        }

        return copy_list;
      }
      
      List& push_back(T value) {
        if (this->length == 0) {
          ListNode<T> *newNode = new ListNode<T>();
          newNode->data = value;
          this->nodes = newNode;
          this->length = 1;
        } else {
          ListNode<T> *node = this->nodes;
          while (node->next != nullptr) {
            node = node->next;
          };

          ListNode<T> *newNode = new ListNode<T>();
          newNode->data = value;
          newNode->prev = node;
          node->next = newNode;
          this->length += 1;
        }

        return *this;
      }
      
      List& push_begin(T value) {
        ListNode<T> *node = new ListNode<T>(value);

        // handle empty list
        if (this->nodes == nullptr) {
          this->nodes = node;
          this->length++;
          return *this;
        }

        node->next = this->nodes;
        this->nodes->prev = node;
        this->nodes = node;
        this->length++;

        return *this;
      }
      
      List& insert(int idx, T value) {
        // Check valid index
        length = this->len();

        if (idx < 0) {
          idx += length;
        }

        // Add to list if insert(-1, "value") when empty list
        if (idx == -1 && length == 0) {
          this->push_begin(value);

          return *this;
        }

        if (idx < 0 || idx > length) {
          throw "ERROR: Invalix Index";
        }

        // Handle insert when empty list;
        if (this->nodes == nullptr) {
          if (idx == 0) {
            ListNode<T> *newNode = new ListNode<T>(value);
            this->nodes = newNode;
            this->length++;
          } else {
            throw "ERROR: Invalid Index";
          }
          return *this;
        }

        // Handle insert at beginning
        if (idx == 0) {
          this->push_begin(value);
          return *this;
        }

        // handle insert at end;
        if (idx == this->length) {
          this->push_back(value);
          return *this;
        }

        // Handle insert at middle;
        ListNode<T> *node = this->nodes;
        for (int i = 0; i < idx; i++) {
          node = node->next;
        }

        ListNode<T> *newNode = new ListNode<T>(value);
        newNode->prev = node->prev;
        newNode->next = node;
        node->prev->next = newNode;
        node->prev = newNode;
        this->length++;

        return *this;
      }

      List& pop_back() {
        if (this->nodes == nullptr) {
          return *this;
        }

        ListNode<T> *node = this->nodes;
        // Get last node
        while (node->next != nullptr) {
          node = node->next;
        }

        if (node->prev != nullptr) {
          node->prev->next = nullptr;
        } else {
          this->nodes = nullptr;
        }
        delete node;
        this->length -= 1;

        return *this;
      }

      List& pop_front() {
        // Handle empty list
        if (this->nodes == nullptr) {
          return *this;
        }
        
        // Handle list with one node
        if (this->length == 1) { // length == 1
          delete this->nodes;
          this->length--;
          this->nodes = nullptr;
          return *this;
        }

        
        // Handle list with more than one node
        ListNode<T>* node = this->nodes;
        this->nodes = this->nodes->next;
        this->nodes->prev = nullptr;
        this->length--;
        delete node;
        return *this;
      }
      
      List& remove(int idx) {
        // Check valid index
        length = this->len();

        if (idx < 0) {
          idx += length;
        }

        if (idx < 0 || idx > length) {
          throw "ERROR: Invalix Index";
        }

        if (idx == 0) {this->pop_begin(); 
          return *this;
        }
        
        if (idx == length - 1) {
          this->pop_back();
          return *this;
        }
        
        ListNode<T>* curr = this->nodes;
        for (int i=0; i < idx; i++) {
          curr = curr->next;
        }

        if (curr->prev != nullptr) curr->prev->next = curr->next;
        if (curr->next != nullptr) curr->next->prev = curr->prev;
        delete curr;

        this->length--;
        return *this;
      }
      
      List& sort_inplace(bool (*func)(T a, T b), bool reverse = false) {

        if (this->length == 1 || this->length == 0) {
          return *this;
        }
        
        ListNode<T>* node = this->nodes;

        if (reverse) {
          while (node->next != nullptr) {
            // switch;
            if (!func(node->data, node->next->data)) {
              int c = node->data;
              node->data = node->next->data; 
              node->next->data = c;
              node = this->nodes;
            }
        
            node = node->next;
          }
        } else {
          while (node->next != nullptr) {
            // switch;
            if (func(node->data, node->next->data)) {
              int c = node->data;
              node->data = node->next->data; 
              node->next->data = c;
              node = this->nodes;
            }
        
            node = node->next;
          }
        }
        
      
        return *this;
      }

      List& reverse_inplace() {
        ListNode<T>* curr = this->nodes;
        
        while (curr != nullptr) {
          ListNode<T>* next = curr->next;
          ListNode<T>* prev = curr->prev;
          
          ListNode<T>* tmp = next;
          next = prev;
          prev = tmp;
          
          curr->next = next;
          curr->prev = prev;

          this->nodes = curr;
          curr = curr->prev;
        }
        
        return *this;
      }

      List& clear() {
        ListNode<T>* node = this->nodes;
        if (node != nullptr) {
          while (node->next != nullptr) {
            node = node->next;
            delete node->prev;
          }

          delete node;
        }

        this->nodes = nullptr;

        return *this;
      }
      
      List& for_each(T (*func)(T value)) {
        ListNode<T>* node = this->nodes;
        while(node != nullptr) {
          T data = node->data;
          node->data = func(data);
          node = node->next;
        }

        return *this;
      }

      int len() { return this->length; }

      int find(int value) {
        if (this->nodes == nullptr) {
          return false;
        }
        ListNode<T> *node = this->nodes;
        int idx = 0;
        while (true) {
          if (node->data == value) {
            return idx;
          }

          if (node->next == nullptr) {
            return -1;
          }
          node = node->next;
          idx++;
        }
      }

      bool contains(T value) {

        if (this->nodes == nullptr) {
          return false;
        }
        ListNode<T> *node = this->nodes;
        while (true) {
          if (node->data == value) {
            return true;
          }

          if (node->next == nullptr) {
            return false;
          }
          node = node->next;
        }
      }

      bool empty() {
        if (this->nodes == nullptr) return true;
        return false;
      }
    };
}