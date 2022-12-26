module Parent where
  import Stack

  parent :: String -> Bool
  parent str = parentAux str empty

  parentAux :: String -> Stack Char -> Bool
  parentAux [] stk = isEmpty stk
  parentAux (x:xs) stk | x == '(' = parentAux xs (push '(' stk)
                       | x == ')' = not (isEmpty stk) && top stk == '(' && parentAux xs (pop stk)
                       | otherwise = parentAux xs stk
                       | x == '[' = parentAux xs (push '[' stk)
                       | x == ']' = not (isEmpty stk) && top stk == ']' && parentAux xs (pop stk)

  calculo :: String -> Float
  calculo l = aux (words l) empty

  aux :: [String] -> Stack Float -> Float
  aux [] stk = (top stk)
  aux (x:y:xs) stk | x>="1" && x<="9" = aux (y:xs) (push (pau x) stk)
                   | x == "+" = aux (y:xs) (push (pop stk + pop stk) stk)
                   | x == "-" = aux (y:xs) (push (pop stk - pop stk) stk)
                   | x == "*" = aux (y:xs) (push (pop stk * pop stk) stk)
                   | x == "/" = aux (y:xs) (push (pop stk / pop stk) stk)
                    where
                      pau x = read x :: Float

  union :: Ord a => Set a -> Set a -> Set a
  union empty b =
  union (Node x left right) b =
