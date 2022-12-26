module Ficha5 where

  divisores :: Integer -> [Integer]                          -- 5.1
  divisores 0 = []
  divisores a = 1 : filter (\x -> mod a x == 0) [1..a]


  primo :: Integer -> Bool                                   -- 5.2
  primo 1 = False
  primo a = all (\x -> mod a x /= 0) [2..floor (sqrt (fromIntegral a))]


  myglue :: [a] -> [a] -> [a]                                -- 5.3(a)
  myglue [] [] = []
  myglue [] l2 = l2
  myglue l1 l2 = foldr (:) l2 l1

  myconcat :: [[a]] -> [a]                                   -- 5.3(b)
  myconcat [] = []
  myconcat l = foldr (++) [] l

  myreverse :: [a] -> [a]                                    -- 5.3(c)
  myreverse [] = []
  myreverse l = foldr aux [] l          -- [] é o caso final, ou seja é preservada até ao final
              where aux x xs = xs ++ [x]

  myotherreverse :: [a] -> [a]                               -- 5.3(d)
  myotherreverse [] = []
  myotherreverse l = foldl aux [] l
        where aux xs x = x : xs

  myelem :: Eq a => a -> [a] -> Bool                         -- 5.3(e)
  myelem a [] = False
  myelem a l = any (a==) l


  fromBits :: [Integer] -> Integer                           -- 5.4
  fromBits (x:xs) = foldl aux x xs
            where aux n x = 2*n + x


  myzipWith :: (a -> b -> c) -> [a] -> [b] -> [c]            -- 5.5
  myzipWith f (x:xs) (y:ys) = f x y : myzipWith f xs ys
    -- f combina x com y


  isort :: Ord a => [a] -> [a]                               -- 5.6
  isort l = foldr myinsert [] l

  myinsert :: Ord a => a -> [a] -> [a]
  myinsert a [] = [a]
  myinsert a (x:xs) | a < x      = a : (x:xs)
                      | otherwise  = x : myinsert a xs


  palavras :: String -> [String]                             -- 5.7
  palavras "" = []
  palavras s = palavra1 : outraspalavras
    where
      (palavra1,resto) = takeWord s
      outraspalavras = palavras (dropSpace resto)

  dropSpace :: String -> String
  dropSpace s = dropWhile eSp s
    where
      eSp c = c == ' '

  takeWord :: String -> (String,String)
  takeWord s = (palavra,resto)
    where
        nSp c = c /= ' '
        palavra = takeWhile nSp (dropSpace s)
        resto = dropWhile nSp (dropSpace s)


  myscanl :: (b -> a -> b) -> b -> [a] -> [b]                -- 5.8
  myscanl _ ac  [] = []
  myscanl f ac (x:xs) = (f ac x) : myscanl f (f ac x) xs


  aproxPi1 :: Int -> Double
  aproxPi1
