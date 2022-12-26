module Ficha3 where
  import Data.Char

  divprop :: Integer -> [Integer]                            -- 3.1
  divprop n = [ x | x<-[1..n-1],n`mod`x==0 ]


  perfeitos :: Integer -> [Integer]                          -- 3.2
  perfeitos n = [ x | x<-[1..n],sum (divprop x) == x]


  pitagoricos :: Integer -> [(Integer,Integer,Integer)]      -- 3.3
  pitagoricos n = [ (x,y,z) | x<-[1..n],y<-[1..n],z<-[1..n], (x*x) + (y*y) == (z*z)]


  primo :: Integer -> Bool                                   -- 3.4
  primo n = length(divprop n) == 1


  pascal :: Integer -> [[Integer]]                           -- 3.5    
  pascal n = [ [ binom l k | k <- [0..l] ] | l <- [0..n] ]

  binom :: Integer -> Integer -> Integer
  binom n k = div (product[1..n]) ((product[1..k])*product[1..(n-k)])


  myand :: [Bool] -> Bool                                    -- 3.7(a)
  myand [] = True
  myand (False:xs) = False
  myand (True:xs) = myand xs


  myor :: [Bool] -> Bool                                     -- 3.7(b)
  myor [] = False
  myor (True:xs) = True
  myor (False:xs) = myor xs


  myconcat :: [[a]] -> [a]                                   -- 3.7(c)
  myconcat[] = []
  myconcat (x:xs) = x ++ myconcat(xs)


  myreplicate :: Int -> a-> [a]                              -- 3.7(d)
  myreplicate 0 a = []
  myreplicate n a = a : myreplicate (n-1) a


  mySelect :: [a] -> Int -> a                                -- 3.7(e)
  mySelect (x:_) 0 = x
  mySelect (x:xs) n = mySelect xs (n-1)


  myelem :: Eq a => a -> [a] -> Bool                         -- 3.7(f)
  myelem a [] = False
  myelem a (x:xs) = x == a || myelem a xs


  forte :: String -> Bool                                    -- 3.9
  forte a = length(a)>8 && (maiuscula a) && (minuscula a) && (numeros a)

  maiuscula :: String -> Bool
  maiuscula [] = False
  maiuscula (x:xs) = isUpper x || maiuscula xs

  minuscula :: String -> Bool
  minuscula [] = False
  minuscula (x:xs) = isLower x || minuscula xs

  numeros :: String -> Bool
  numeros [] = False
  numeros (x:xs) = isDigit x || numeros xs


  mynub :: Eq a => [a] -> [a]                                -- 3.11
  mynub [] = []
  mynub (x:xs) = x : mynub (apaga x xs)
      where apaga c l = [y | y <- l, y /= c]


  myintersperse :: a -> [a] -> [a]                           -- 3.12
  myintersperse a [] = []
  myintersperse a (x:[]) = x : []
  myintersperse a (x:xs) = x : a : myintersperse a xs



  apaga :: Eq a => a -> [a] -> [a]                           -- pedido do stor
  apaga a [] = []
  apaga a (x:xs) | a == x = apaga a xs
                 | otherwise = x : apaga a xs

  apaga1 :: Eq a => a -> [a] -> [a]                          -- pedido do stor
  apaga1 a [] = []
  apaga1 a (x:xs) | a == x =  xs
                 | otherwise = x : apaga1 a xs
