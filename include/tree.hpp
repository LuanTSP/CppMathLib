#pragma once
#include <iostream>
#include <queue>

template <typename T> class TreeNode {
public:
  T data;
  TreeNode<T> *left = nullptr;
  TreeNode<T> *right = nullptr;

public:
  // Constructing
  TreeNode<T>(){};
  TreeNode<T>(T data) { this->data = data; };
};

template <typename T> class Tree {
public:
  TreeNode<T> *root = nullptr;

private:
  void _deleteSubtree(TreeNode<T> *root) {
    if (root == nullptr) {
      return;
    }

    _deleteSubtree(root->left);
    _deleteSubtree(root->right);

    delete root;
  }

  void _printPreorder(TreeNode<T> *root) {
    if (root == nullptr) {
      return;
    }

    // Preorder traversal
    std::cout << root->data << std::endl;
    _printPreorder(root->left);
    _printPreorder(root->right);
  }

  void _printInorder(TreeNode<T> *root) {
    if (root == nullptr) {
      return;
    }

    // Inorder traversal
    _printInorder(root->left);
    std::cout << root->data << std::endl;
    _printInorder(root->right);
  }

  void _printPostorder(TreeNode<T> *root) {
    if (root == nullptr) {
      return;
    }

    // Postorder traversal
    _printPostorder(root->left);
    _printPostorder(root->right);
    std::cout << root->data << std::endl;
  }

  void _printLevel(TreeNode<T> *root, int n) {
    if (n < 0) {
      throw "ERROR: Invalid level";
    }

    if (root == nullptr) {
      return;
    }

    if (n == 0) {
      std::cout << root->data << std::endl;
      return;
    }

    _printLevel(root->left, n - 1);
    _printLevel(root->right, n - 1);
  }

public:
  // Construction
  Tree<T>(){};
  Tree<T>(T data) { this->root = new TreeNode<T>(data); }

  // Destruction
  ~Tree<T>() { _deleteSubtree(this->root); }

  // Printing Tree
  void printTreePreorder() { _printPreorder(this->root); }
  void printTreeInorder() { _printInorder(this->root); }
  void printTreePostorder() { _printPostorder(this->root); }

  // Inserting
  void insert(T data) { // Inserts beadth first
    TreeNode<T> *newNode = new TreeNode<T>(data);

    if (this->root == nullptr) {
      root = newNode;
      return;
    }

    std::queue<TreeNode<T> *> queue;
    queue.push(this->root);

    while (!queue.empty()) {
      TreeNode<T> *curr = queue.front();
      queue.pop();

      if (curr->left == nullptr) {
        curr->left = newNode;
        break;
      } else if (curr->right == nullptr) {
        curr->right = newNode;
        break;
      } else {
        queue.push(curr->left);
        queue.push(curr->right);
      }
    }
  }

  // Print Level
  void printLevel(int n) { _printLevel(this->root, n); }
};