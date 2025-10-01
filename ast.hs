data Ast = Add Ast Ast | Mul Ast Ast | Num String
eval :: Ast -> Int
eval (Add left right) = eval left + eval right
eval (Mul left right) = eval left * eval right
eval (Num num) = read num :: Int
parse :: String -> Ast
parse input = undefined
main :: IO ()
main = do
    let expr = Add (Num "2") (Mul (Num "3") (Add (Num "4") (Num "5")))
    let result = eval expr -- 29
    print result

