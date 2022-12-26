module Exame1314 where

  transforma :: String -> String
  transforma [] = []
  transforma (x:xs) | x=='a' || x=='e' || x=='i' || x=='o' || x=='u' = x:'p':x:transforma xs
                    | otherwise = x : transforma xs

  subidas :: [Float] -> Int
  subidas [] = 0
  subidas [x] = 0
  subidas (x:y:xs) | x<y       = 1 + subidas (y:xs)
                   | otherwise = subidas (y:xs)

  insert :: Ord a => a -> [a] -> [a]
  insert a [] = [a]
  insert a (x:xs) | a>x = x : insert a xs
                  | otherwise = a:x:xs

  intersperse :: a -> [a] -> [a]
  intersperse a l | length l < 3 = l
                  | otherwise = auxintersperse a l

  auxintersperse :: a -> [a] -> [a]
  auxintersperse a [x] = [x]
  auxintersperse a (x:xs) = x:a:auxintersperse a xs

  
