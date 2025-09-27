#include <stdlib.h>

enum AstKind { ADD, MUL, NUM };
union AstData {
  struct {
    struct Ast *left;
    struct Ast *right;
  } add;
  struct {
    struct Ast *left;
    struct Ast *right;
  } mul;
  char *num;
};
struct Ast {
  enum AstKind kind;
  union AstData data;
};

int eval(struct Ast *expr) {
  switch (expr->kind) {
  case ADD:
    return eval(expr->data.add.left) + eval(expr->data.add.right);
  case MUL:
    return eval(expr->data.mul.left) * eval(expr->data.mul.right);
  case NUM:
    return atoi(expr->data.num);
  default:
    return exit(1), 0; // unreachable)
  }
}

struct Ast *parse(char **input);

int main() {
  char *expr_str = "2 + 3 * (4 + 5)";
  struct Ast *expr = parse(&expr_str);
  int result = eval(expr); // 29

  // ensure we have an ADD node, otherwise we could be writing to an incorrect
  // field
  if (expr->kind == ADD) {
    free(
        expr->data.add.left); // free the old left node to prevent a memory leak
    expr->data.add.left = malloc(sizeof(struct Ast));
    *expr->data.add.left = (struct Ast){.kind = NUM, .data.num = "4"};
  }
}
