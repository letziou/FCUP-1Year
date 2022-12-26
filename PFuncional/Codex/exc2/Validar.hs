module Validar where

  validar :: Integer -> Bool
  validar a | mod (somaDigitos(multSegundo(algarismosRev a))) 10 == 0 = True
            | otherwise = False

  multSegundo :: [Integer] -> [Integer]
  multSegundo [] = []
  multSegundo a = map myDobro (zip [1..] a)

  myDobro :: (Integer,Integer) -> Integer
  myDobro (primeiro,segundo) | mod primeiro 2 == 0 = segundo*2
                             | otherwise = segundo

  somaDigitos :: [Integer] -> Integer
  somaDigitos [] = 0
  somaDigitos (x:xs) = sum (algarismosRev x) + somaDigitos xs

  algarismosRev :: Integer -> [Integer]
  algarismosRev 0 = []
  algarismosRev a = mod a 10 : algarismosRev (div a 10)
