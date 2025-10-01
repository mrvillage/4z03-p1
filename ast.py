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

expr = Add(
    Num("2"),
    Mul(
	Num("3"),
	Add(
	    Num("4"),
	    Num("5")
	)
    )
)
result = eval(expr) # 29
