#pragma once
#include <iostream>
#include <queue>

template <typename T> class TreeNode {
public:
  T data;
  TreeNode<T> *left = nullptr;
  TreeNode<T> *right = nullptr;

public:
  TreeNode<T>(T data) { this->data = data; };
};

template <typename T> class Tree {
public:
  TreeNode<T> *root = nullptr;

private:
  void _print(TreeNode<T> *root) {
    if (root == nullptr) {
      return;
    }

    // Preorder traversal
    std::cout << root->data << std::endl;
    _print(root->left);
    _print(root->right);
  }

public:
  Tree<T>(){};
  Tree<T>(T data) { this->root = new TreeNode<T>(data); }

  void print() { _print(this->root); }

  void insert(T data) { // Inserts beadth first
    TreeNode<T> *newNode = new TreeNode<T>(data);

    if (!this->root) {
      this->root == newNode;
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
};