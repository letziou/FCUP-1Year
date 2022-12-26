module Ficha1 where

  testaTriangulo :: Float -> Float -> Float -> Bool    -- 1.2
  testaTriangulo a b c = (a < b+c) && (b < a+c) && (c < a+b)


  areatriangulo :: Float -> Float -> Float -> Float    -- 1.3
  areatriangulo a b c = sqrt(s*(s-a)*(s-b)*(s-c))
                  where s =(a+b+c)/2

  metade :: [Integer] -> ([Integer],[Integer])         -- 1.4
  metade lista = (take x lista, drop x lista)
        where x = div (length lista)2


  last1 :: [a] -> a                                    -- 1.5(a)
  last1 lista = head (drop ((length lista)-1) lista)

  last2 :: [a] -> [a]                                  -- 1.5(b)
  last2 lista = reverse(drop 1(reverse lista))

  binom :: Integer -> Integer -> Integer               -- 1.6(a)
  binom n k = div (product[1..n]) ((product[1..k])*product[1..(n-k)])

  binom2 :: Integer -> Integer -> Integer              -- 1.6(b)
  binom2 n k = product [n-k+1]
