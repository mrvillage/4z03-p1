#include <stdlib.h>

struct Node {
  int value;
  struct Node *left;
  struct Node *right;
};

int sum(struct Node *node) {
  int acc = node->value;
  if (node->left != NULL) {
    acc += sum(node->left);
  }
  if (node->right != NULL) {
    acc += sum(node->right);
  }
  return acc;
}

int main() {
  struct Node *tree = malloc(sizeof(struct Node));
  *tree = (struct Node){.value = 1,
                        .left = malloc(sizeof(struct Node)),
                        .right = malloc(sizeof(struct Node))};
  *tree->left = (struct Node){.value = 2, .left = NULL, .right = NULL};
  *tree->right = (struct Node){.value = 3, .left = NULL, .right = NULL};
  int total = sum(tree); // 6
  free(tree->right);
  tree->right = NULL; // tree is now Node { value: 1, left: ..., right: NULL }
  struct Node *tmp = tree->left;
  free(tree);
  tree = tmp; // tree is now Node { value: 2, left: NULL, right: NULL }
}
