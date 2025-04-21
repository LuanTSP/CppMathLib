#pragma once
#include <iostream>

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
  int lenght = 0;

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
      if (idx < 0 || idx >= this->lenght) {
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
    
    List& push_back(T value) {
      if (this->lenght == 0) {
        ListNode<T> *newNode = new ListNode<T>();
        newNode->data = value;
        this->nodes = newNode;
        this->lenght = 1;
      } else {
        ListNode<T> *node = this->nodes;
        while (node->next != nullptr) {
          node = node->next;
        };

        ListNode<T> *newNode = new ListNode<T>();
        newNode->data = value;
        newNode->prev = node;
        node->next = newNode;
        this->lenght += 1;
      }

      return *this;
    }
    
    List& push_begin(T value) {
      ListNode<T> *node = new ListNode<T>(value);

      // handle empty list
      if (this->nodes == nullptr) {
        this->nodes = node;
        this->lenght++;
        return *this;
      }

      node->next = this->nodes;
      this->nodes->prev = node;
      this->nodes = node;
      this->lenght++;

      return *this;
    }
    
    List& push_at(int idx, T value) {
      // Check valid index
      lenght = this->len();

      if (idx < 0) {
        idx += lenght;
      }

      if (idx < 0 || idx > lenght) {
        throw "ERROR: Invalix Index";
      }

      // Handle insert when empty list;
      if (this->nodes == nullptr) {
        if (idx == 0) {
          ListNode<T> *newNode = new ListNode<T>(value);
          this->nodes = newNode;
          this->lenght++;
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
      if (idx == this->lenght) {
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
      this->lenght++;

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
      this->lenght -= 1;

      return *this;
    }

    List& pop_begin() {
      // Handle empty list
      if (this->nodes == nullptr) {
        return *this;
      }
      
      // Handle list with one node
      if (this->lenght == 1) { // lenght == 1
        delete this->nodes;
        this->lenght--;
        this->nodes = nullptr;
        return *this;
      }

      
      // Handle list with more than one node
      ListNode<T>* node = this->nodes;
      this->nodes = this->nodes->next;
      this->nodes->prev = nullptr;
      this->lenght--;
      delete node;
      return *this;
    }
    
    int len() { return this->lenght; }

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

    List& sort(bool (*criterium)(T a, T b), bool reverse = false) {

      if (this->lenght == 1 || this->lenght == 0) {
        return *this;
      }
      
      ListNode<T>* node = this->nodes;

      if (reverse) {
        while (node->next != nullptr) {
          // switch;
          if (!criterium(node->data, node->next->data)) {
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
          if (criterium(node->data, node->next->data)) {
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
  };