#pragma once
#include <iostream>
#include <queue>

template <typename T> class BSTreeNode {
public:
  T data;
  BSTreeNode<T> *left = nullptr;
  BSTreeNode<T> *right = nullptr;

public:
  // Constructing
  BSTreeNode<T>(){};
  BSTreeNode<T>(T data) { this->data = data; };
};

template <typename T> class BSTree {
private:
  BSTreeNode<T> *root = nullptr;
  
  bool (*func)(T a, T b);

  int lenght = 0;

private:
  void _print_level(BSTreeNode<T>* start_node, int n) {
    if (n < 0) {
      throw "ERROR: Invalid level";
    }

    if (start_node == nullptr) {
      return;
    }

    if (n == 0) {
      std::cout << start_node->data << std::endl;
      return;
    }

    _print_level(start_node->left, n - 1);
    _print_level(start_node->right, n - 1);
  }
  
  void _print_preorder(BSTreeNode<T> *node) {
    if (node == nullptr) {
      return;
    }

    // Preorder traversal
    std::cout << node->data << std::endl;
    _print_preorder(node->left);
    _print_preorder(node->right);
  }

  void _print_inorder(BSTreeNode<T> *node) {
    if (node == nullptr) {
      return;
    }

    // Inorder traversal
    _print_inorder(node->left);
    std::cout << node->data << std::endl;
    _print_inorder(node->right);
  }

  void _print_postorder(BSTreeNode<T> *node) {
    if (node == nullptr) {
      return;
    }

    // Postorder traversal
    _print_postorder(node->left);
    _print_postorder(node->right);
    std::cout << node->data << std::endl;
  }

  void _insert(BSTreeNode<T>*& node, T value) {
    if (node == nullptr) {
      node = new BSTreeNode<T>(value);
      return;
    }

    if (this->func(node->data, value)) {
      _insert(node->left, value);
    } else {
      _insert(node->right, value);
    }
  }

  BSTreeNode<T>* _find_node(BSTreeNode<T>*& node, T value) {
    if (node == nullptr) {
      return nullptr;
    }

    if (node->data == value) {
      return node; 
    }

    if (this->func(node->data, value)) return _find_node(node->left, value);
    else return _find_node(node->right, value);
  }
  
  int _height(BSTreeNode<T>*& node) {
    if (node == nullptr) {
      return 0;
    }

    int height_left = _height(node->left);
    int height_right = _height(node->right);

    return (height_right > height_left) ? 1 + height_right : 1 + height_left;
  }
  
  public:
  // Construction
  BSTree<T>(bool (*func)(T a, T b)){ this->func = func; };
  
  BSTree<T>(bool (*func)(T a, T b), T data){ 
    this->func = func; 
    this->root = new BSTreeNode<T>(data);
    this->lenght++;
  };

  // Destruction
  void delete_subtree(BSTreeNode<T> *node) {
    if (node == nullptr) {
      return;
    }

    delete_subtree(node->left);
    delete_subtree(node->right);

    delete node;
  }
 
  ~BSTree<T>() { this->delete_subtree(this->root); }

  // Printing Tree
  void print_preorder() { this->_print_preorder(this->root); }
  
  void print_inorder() { this->_print_inorder(this->root); }
  
  void print_postorder() { this->_print_postorder(this->root); }

  void print_level(int n) { _print_level(this->root, n); }

  // Inserting
  BSTree& insert(T value) { 
    _insert(this->root, value);
    this->lenght++;
    return *this;
  }

  // Searching
  BSTreeNode<T>* find_node(T value) {
    return _find_node(this->root, value);
  }

  // Utility
  bool contains(T value) {
    if (this->find_node(value) != nullptr) {
      return true;
    }

    return false;
  }

  int height() {
    return _height(this->root);
  }

  int len() {
    return this->lenght;
  }

};