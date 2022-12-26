{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
module Ficha4 where

  algarismos :: Int -> [Int]                                 -- 4.1
  algarismos 0 = [0]
  algarismos a = reverse (algarismosRev a)

  algarismosRev :: Int -> [Int]
  algarismosRev 0 = []
  algarismosRev a = mod a 10 : algarismosRev (div a 10)


  toBits :: Int -> [Int]                                     -- 4.2
  toBits 0 = [0]
  toBits 1 = [1]
  toBits a = reverse (toBitsRev a)

  toBitsRev :: Int -> [Int]
  toBitsRev 0 = []
  toBitsRev a = mod a 2 : toBitsRev (div a 2)


  fromBits :: [Int] -> Int                                   -- 4.3
  fromBits [0] = 0
  fromBits [1] = 1
  fromBits (x:xs) = x*2^(length xs) + fromBits xs


  mdc :: Integer -> Integer -> Integer                       -- 4.4
  mdc a 0 = a
  mdc a b = mdc b (mod a b)


  myinsert :: Ord a => a -> [a] -> [a]                       -- 4.5(a)
  myinsert a [] = [a]
  myinsert a (x:xs) | a < x      = a : (x:xs)
                    | otherwise  = x : myinsert a xs


  isort :: Ord a => [a] -> [a]                               -- 4.5(b)
  isort [] = []
  isort (x:xs) = myinsert x (isort xs)


  minimus :: Ord a => [a] -> a                               -- 4.6(a)  Podemos chamar os dois primeiros elementos da lista !!
  minimus [x] = x
  minimus (x:y:xs) | x<y       = minimus(x:xs)
                   | otherwise = minimus(y:xs)


  otherminimus :: Ord a => [a] -> a                          -- 4.6(a)
  otherminimus [x] = x
  otherminimus (x:xs) | x < otherminimus xs = x
                 | otherwise      = otherminimus xs


  delete :: Eq a => a -> [a] -> [a]                          -- 4.6(b)
  delete a [] = []
  delete a (x:xs) | a == x =  xs
                  | otherwise = x : delete a xs


  ssort :: Ord a => [a] -> [a]                               -- 4.6(c)
  ssort [] = []
  ssort l = m : ssort (delete m l)
            where m = minimus l


  merge :: Ord a => [a] -> [a] -> [a]                        -- 4.7(a)
  merge [] [] = []
  merge l [] = l
  merge [] l = l
  merge (x:xs) (y:ys) | x <= y = x : merge xs (y:ys)
                      | y < x = y : merge (x:xs) ys


  msort :: Ord a => [a] -> [a]                               -- 4.7(b)
  msort [] = []
  msort [x] = [x]
  msort l = merge lesq ldir
          where
            lesq = msort l1
            ldir = msort l2
            (l1,l2) = metades l



  metades :: [a] -> ([a],[a])         -- 1.4
  metades l = (take x l, drop x l)
        where x = div (length l)2

  addPoly :: [Int] -> [Int] -> [Int]                         -- 4.8(a)
  addPoly [] [] = []
  addPoly (x:xs) (p:ps) = x+p : addPoly xs ps
  addPoly (x:xs) [] = x : addPoly xs []
  addPoly [] (p:ps) = p : addPoly [] ps
