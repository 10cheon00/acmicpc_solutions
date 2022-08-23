/*
 * 1406 에디터
 * 실버IV
 */
#include <iostream>
struct Node {
  char ch;
  Node *next, *prev;
};
int main() {
  char str[100001];
  int M, len = 0;
  scanf("%s", str);
  Node *cursor = new Node();
  cursor->ch = '*';
  Node *head = cursor;
  while (str[len]) {
    cursor->ch = str[len++];
    cursor->next = new Node();
    cursor->next->prev = cursor;
    cursor = cursor->next;
  }
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    char cmd;
    scanf(" %c", &cmd);
    switch (cmd) {
    case 'L':
      if (cursor->prev != nullptr) {
        cursor = cursor->prev;
      }
      break;
    case 'D':
      if (cursor->next != nullptr) {
        cursor = cursor->next;
      }
      break;
    case 'B':
      if (cursor->prev != nullptr) {
        Node *prev = cursor->prev->prev;
        if (prev != nullptr) {
          prev->next = cursor;
        }
        delete cursor->prev;
        cursor->prev = prev;
      }
      break;
    case 'P':
      Node *newNode = new Node();
      scanf(" %c", &newNode->ch);
      newNode->prev = cursor->prev;
      newNode->next = cursor;
      if (cursor->prev != nullptr) {
        cursor->prev->next = newNode;
      }
      cursor->prev = newNode;
      break;
    }
  }
  while (cursor->prev != nullptr) {
    cursor = cursor->prev;
  }
  while (cursor->next != nullptr) {
    if (cursor->ch == '*')
      break;
    printf("%c", cursor->ch);
    Node *t = cursor;
    cursor = cursor->next;
    delete t;
  }
}