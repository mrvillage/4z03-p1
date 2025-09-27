class Add:
    def __init__(self, left, right):
        self.left = left
        self.right = right
class Mul:
    def __init__(self, left, right):
        self.left = left
        self.right = right
class Num:
    def __init__(self, num):
        self.num = num

def eval(expr):
    if isinstance(expr, Add):
        return eval(expr.left) + eval(expr.right)
    elif isinstance(expr, Mul):
        return eval(expr.left) * eval(expr.right)
    elif isinstance(expr, Num):
        return int(expr.num)

def parse(input):
    pass

expr_str = "2 + 3 * (4 + 5)"
expr = parse(expr_str)
result = eval(expr) # 29
