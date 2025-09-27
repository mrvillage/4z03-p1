enum Ast<'a> {
    Add(Box<Ast<'a>>, Box<Ast<'a>>),
    Mul(Box<Ast<'a>>, Box<Ast<'a>>),
    Num(&'a str),
}

fn eval(expr: &Ast) -> i32 {
    match expr {
        Ast::Add(left, right) => eval(left) + eval(right),
        Ast::Mul(left, right) => eval(left) * eval(right),
        Ast::Num(num) => num.parse::<i32>().unwrap(),
    }
}

fn parse<'a>(input: &'a str) -> Ast<'a> {
    unimplemented!()
}

fn main() {
    let expr_str = String::from("2 + 3 * (4 + 5)");
    let expr = parse(&expr_str);
    let result = eval(&expr); // 29

    let mut expr = Ast::Add(Box::new(Ast::Num("2")), Box::new(Ast::Num("3")));
    if let Ast::Add(left, right) = &mut expr {
        *left = Box::new(Ast::Num("4"));
    }
}

fn will_error() {
    let expr;
    // we can use {...} to define a new scope
    {
        let expr_str = String::from("2 + 3 * (4 + 5)");
        expr = parse(&expr_str); // error: expr_str does not live long enough
    }
}
