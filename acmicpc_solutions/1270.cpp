/*
 * 1270 전쟁- 땅따먹기
 * 실버III
 */
#include <iostream>
#define NOT_FOUND 2147483649
struct Node {
  long long id;
  int count;
  Node *left, *right;
  Node(long long id, int count)
      : id(id), count(count), left(nullptr), right(nullptr) {}
};

Node *search(long long id, Node *node) {
  if (node == nullptr) {
    return node;
  }

  if (id == node->id) {
    return node;
  } else if (id < node->id) {
    return search(id, node->left);
  } else {
    return search(id, node->right);
  }
}

void insert(long long id, Node *node) {
  Node *res = search(id, node);
  if (res != nullptr) {
    res->count++;
    return;
  }
  while (1) {
    if (id < node->id) {
      if (node->left == nullptr) {
        node->left = new Node(id, 1);
        return;
      }
      node = node->left;
    } else {
      if (node->right == nullptr) {
        node->right = new Node(id, 1);
        return;
      }
      node = node->right;
    }
  }
}
long long findWinner(int size, Node *node) {
  if (node == nullptr) {
    return NOT_FOUND;
  }

  if (node->count * 2 > size) {
    return node->id;
  }
  long long id = findWinner(size, node->left);
  id = id != NOT_FOUND ? id : findWinner(size, node->right);
  return id;
}
void deleteTree(Node *node) {
  if (node == nullptr) {
    return;
  }
  deleteTree(node->left);
  deleteTree(node->right);
  delete node;
}
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int K;
    Node *tree = nullptr;
    scanf("%d", &K);
    for (int j = 0; j < K; j++) {
      long long id;
      scanf("%lld", &id);
      if (tree == nullptr) {
        tree = new Node(id, 1);
      } else {
        insert(id, tree);
      }
    }
    long long winner = findWinner(K, tree);
    if (winner != NOT_FOUND) {
      printf("%lld\n", winner);
    } else {
      printf("SYJKGW\n");
    }
    deleteTree(tree);
  }
}