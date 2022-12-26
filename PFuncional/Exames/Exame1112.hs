module Exame1112 where

  -- Exame Normal

  duplicar :: String -> String
  duplicar [] = []
  duplicar (x:xs) | x=='a' || x=='A' || x=='e'|| x=='E'|| x=='i'|| x=='I' || x=='o' || x=='O' || x=='u' || x=='U' = x:x:duplicar xs
                  | otherwise = x:duplicar xs

  type Ponto = (Float, Float)

  dist :: Ponto -> Ponto -> Float
  dist (x1,y1) (x2,y2) = sqrt ((x1-x2)^2 + (y1-y2)^2)

  comprimento :: [Ponto] -> Float
  comprimento [] = 0
  comprimento [x] = 0
  comprimento (x:y:xs) = dist x y + comprimento(y:xs)

  data Arv a = Vazia
              | No a (Arv a) (Arv a)
              deriving Show

  insert :: Ord a => a -> Arv a -> Arv a
  insert x Vazia = No x Vazia Vazia
  insert x (No a esq dir) | x<a = insert x esq
                          | x>a = insert x dir
                          | otherwise = No a esq dir

  -- Exame Recurso

  prefixo :: String -> String -> Bool
  prefixo a b = myaux a (take (length a) b)

  myaux :: String -> String -> Bool
  myaux [] [] = True
  myaux (x:xs) (y:ys) |x/=y = False
                    |otherwise = True && myaux xs ys

  type Mat = [Vec]
  type Vec = [Int]

  somaV :: Vec -> Vec -> Vec
  somaV [] [] = []
  somaV (x:xs) (y:ys) = x+y : somaV xs ys
  somaV l t = error "imcompatible vector size"

  somaM :: Mat -> Mat -> Mat
  somaM [] [] = []
  somaM (x:xs) (y:ys) = somaV x y : somaM xs ys
  somaM l t = error "imcompatible matrix size"


  rld :: [(Integer,Char)] -> String
  rld [] = []
  rld ((x,y):xs) = aux x y ++ rld xs

  aux :: Integer -> Char -> String
  aux 0 a = []
  aux n a = a : aux (n-1) a

  data Prop = Const Bool
            | Var Char
            | Neg Prop
            | Conj Prop Prop
            | Disj Prop Prop
             deriving Show

  dual :: Prop -> Prop
  dual (Conj l a) = Disj l a
  dual (Disj l a) = Conj l a

  perfeito :: Integer -> Bool
  perfeito 0 = False
  perfeito 1 = True
  perfeito n | n== (sum [x | x<-[1..n],(mod x n)==0]) = True
             | otherwise = False
