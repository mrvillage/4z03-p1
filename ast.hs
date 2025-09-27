data Ast = Add Ast Ast | Mul Ast Ast | Num String
eval :: Ast -> Int
eval (Add left right) = eval left + eval right
eval (Mul left right) = eval left * eval right
eval (Num num) = read num :: Int
parse :: String -> Ast
parse input = undefined
main :: IO ()
main = do
    let expr_str = "2 + 3 * (4 + 5)"
    let expr = parse expr_str
    let result = eval expr -- 29
    print result

