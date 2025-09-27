data Node = Node {
  value :: Int,
  left :: Maybe Node,
  right :: Maybe Node
}

sumTree :: Node -> Int
sumTree (Node value Nothing Nothing) = value
sumTree (Node value (Just left) Nothing) = value + sumTree left
sumTree (Node value Nothing (Just right)) = value + sumTree right
sumTree (Node value (Just left) (Just right)) = value + sumTree left + sumTree right

leftNode :: Node -> Maybe Node
leftNode (Node _ l _) = l
main :: IO ()
main = do
  let tree = Node 1 (Just (Node 2 Nothing Nothing)) (Just (Node 3 Nothing Nothing))
  let total = sumTree tree -- 6
  let tree2 = tree { right = Nothing } -- tree2 is now Node 1 (Just (Node 2 Nothing Nothing)) Nothing
  let tree3 = leftNode tree -- tree3 is now Just (Node 2 Nothing Nothing)
  print total
