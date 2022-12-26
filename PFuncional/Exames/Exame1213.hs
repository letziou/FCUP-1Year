module Exame1213 where
  import Data.Char

  data MConj a = Vazio
                | No a Int (MConj a) (MConj a)
                  deriving Show

  maxpos :: [Int] -> Int
  maxpos [] = 0
  maxpos [x] | x>0 = x
             | otherwise = 0
  maxpos (x:y:xs) | x>y = maxpos (x:xs)
                  | otherwise = maxpos (y:xs)

  dups :: [a] -> [a]
  dups [] = []
  dups [x] = [x,x]
  dups (x:y:xs) = x:x:y:dups xs

  ocorre :: Ord a => a -> MConj a -> Int
  ocorre x Vazio = 0
  ocorre x (No a b esq dir) | x==a = b
                            | otherwise = (ocorre x esq) + (ocorre x dir)

  inserir :: Ord a => a -> MConj a -> MConj a
  inserir x Vazio = No x 1 Vazio Vazio
  inserir x (No a b esq dir) | x<a  = inserir x esq
                             | x>a  = inserir x dir
                             | x==a = No x (b+1) esq dir

  count :: (a-> Bool) -> [a] -> Int
  count l [] = 0
  count x l = auxcount (map x l)

  auxcount :: [Bool] -> Int
  auxcount [] = 0
  auxcount (x:xs) | x==True = 1 + auxcount xs
                  | otherwise = auxcount xs

  mycount :: (a-> Bool) -> [a] -> Int
  mycount x [] = 0
  mycount x l = length (filter x l)

  extras :: String -> Int
  extras [] = 0
  extras l = count isLetter l

  nodups :: Eq a => [a] -> [a]
  nodups [] = []
  nodups [x,y] | x==y = [x]
               | otherwise = [x,y]
  nodups (x:y:xs) | x == y = nodups (y:xs)
                  | otherwise = x : nodups (y:xs)

  data Box = Text String -- texto simples
            | Horiz Box Box -- justaposição horizontal
            | Vert Box Box -- justaposição vertical
              deriving Show
