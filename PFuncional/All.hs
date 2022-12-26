{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
module Teste where
  import Data.Char

  transforma :: String -> String                             -- exc2 exame2014
  transforma [] = []
  transforma (x:xs) | x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' = x:'p':x:transforma(xs)
                    | otherwise = x:transforma(xs)

  subidas :: [Float] -> Int                                  -- exc3 exame2014
  subidas [] = 0
  subidas [x] = 0
  subidas (x:y:xs) | x<y = 1 + subidas(y:xs)
                   | otherwise = subidas (y:xs)

-----------------------------------------------------------------------------
--                              Folha 1                                    --
-----------------------------------------------------------------------------

  testaTriangulo :: Float -> Float -> Float -> Bool          -- 1.2
  testaTriangulo a b c = (a<b+c) && (b<a+c) && (c<a+b)

  areaTriangulo :: Float -> Float -> Float -> Float          -- 1.3
  areaTriangulo a b c = sqrt(s*(s-a)*(s-b)*(s-c))
                          where
                            s = (a+b+c)/2

  metades :: [a] -> ([a],[a])                                -- 1.4
  metades l = (take x l,drop x l)
              where x = div(length l) 2

  mylast :: [Int] -> Int                                     -- 1.5(a)
  mylast l = head(reverse l)

  myotherlast :: [Int] -> Int
  myotherlast l = head(drop x l)
                  where x = (length l)-1

  myinit :: [Int] -> [Int]                                   -- 1.5(b)
  myinit l = reverse (tail (reverse l))

  myotherinit :: [Int] -> [Int]
  myotherinit l = take x l
                  where x = (length l)-1

  binom :: Integer -> Integer -> Integer                     -- 1.6(a)
  binom n k = div (product[1..n]) (product[1..k]*product[1..(n-k)])

  otherbinom :: Integer -> Integer -> Integer
  otherbinom n k | k < n-k  = div (product[(n-k+1)..n]) (product[1..k])
                 | k >= n-k = div (product[(k+1)..n]) (product[1..(n-k)])

-----------------------------------------------------------------------------
--                              Folha 2                                    --
-----------------------------------------------------------------------------

  classifica :: Int -> String                                -- 2.1
  classifica a | a < 10 = "reprovado"
               | a < 12 = "suficiente"
               | a < 16 = "bom"
               | a < 19 = "muito bom"
               | a < 21 = "muito bom com distincao"

  classificaII :: Float -> Float -> String                   -- 2.2
  classificaII a b | a / (b*b) < 18.6 = "baixo peso"
                   | a / (b*b) < 25.1 = "peso normal"
                   | a / (b*b) < 30.1 = "excesso de peso"
                   | otherwise = "obesidade"

  max3, min3 :: Ord a => a -> a -> a -> a                    -- 2.3(a)
  max3 a b c = mymax (mymax a b) c
  min3 a b c = mymin (mymin a b) c

  mymax, mymin :: Ord a => a -> a -> a
  mymax x y = if x>=y then x else y
  mymin x y = if x<=y then x else y

  myothermax, myothermin :: Ord a => a -> a -> a -> a        -- 2.3(b)
  myothermax a b c = if x>=c then x else c
                    where
                      x = if a>=b then a else b
  myothermin a b c = if y<=c then y else c
                    where
                      y = if a<=b then a else b

  myxor :: Bool -> Bool -> Bool                              -- 2.4
  myxor a b |a==True && b==False = True
            |a==False && b==True = True
            |otherwise = False

  safetail :: [a] -> [a]                                     -- 2.5 v1
  safetail [] = []
  safetail l = tail l

  mysafetail :: [a] -> [a]                                   -- 2.5 v2
  mysafetail [] = []
  mysafetail (x:xs) = xs

  curta :: [a] -> Bool                                       -- 2.6(a)
  curta l |(length l) < 3 = True
          | otherwise     = False

  othercurta :: [a] -> Bool                                  -- 2.6(b)
  othercurta []    = True
  othercurta [x]   = True
  othercurta [x,y] = True
  othercurta l     = False

  mediana :: Ord a => a -> a -> a -> a                       -- 2.7(a)
  mediana x y z | (x >= y && x<= z) || (x >= z && x<= y) = x
                | (y >= x && y<= z) || (y >= z && y<= x) = y
                | (z >= y && z<= x) || (z >= x && z<= y) = z

  othermediana :: Integer -> Integer -> Integer -> Integer   -- 2.7(b)
  othermediana a b c = (a+b+c) - (max3 a b c  + min3 a b c)

-----------------------------------------------------------------------------
--                              Folha 3                                    --
-----------------------------------------------------------------------------

  divdrop :: Integer -> [Integer]                            -- 3.1
  divdrop n = [x | x<-[1..n-1] , mod n x == 0]

  perfeitos :: Integer -> [Integer]                          -- 3.2
  perfeitos n = [x | x<-[1..n-1] , sum (divdrop x) == x]

  pitagoricos :: Integer -> [(Integer,Integer,Integer)]      -- 3.3
  pitagoricos n = [(x,y,z) | x<-[1..n],y<-[1..n],z<-[1..n], (x*x) + (y*y) == (z*z)]

  primo :: Integer -> Bool                                   -- 3.4
  primo 0 = False
  primo l | (length (divdrop l)) < 2 = True
          | otherwise                = False

  pascal :: Integer -> [[Integer]]                           -- 3.5
  pascal n = [ [ binom l k | k <- [0..l] ] | l <- [0..n] ]

  myand :: [Bool] -> Bool                                    -- 3.7(a)
  myand [] = True
  myand (x:xs) | not x = False
               | otherwise = myand xs

  myor :: [Bool] -> Bool                                     -- 3.7(b)
  myor [] = False
  myor (x:xs) | x == True = True
              | otherwise = myor(xs)

  myconcat :: [[a]] -> [a]                                   -- 3.7(c)
  myconcat [] = []
  myconcat (x:xs) = x ++ myconcat xs

  myreplicate :: Int -> a -> [a]                             -- 3.7(d)
  myreplicate 0 x = []
  myreplicate n x = x : myreplicate (n-1) x

  myshock :: [a] -> Int -> a                                 -- 3.7(e)
  myshock l a = myshockaux l a 1

  myshockaux :: [a] -> Int -> Int -> a
  myshockaux (x:xs) a b | b==a      = x
                        | otherwise = myshockaux xs a (b+1)

  myelem :: Eq a => a -> [a] -> Bool                         -- 3.7(f)
  myelem a [] = False
  myelem a (x:xs) | a==x      = True
                  | otherwise = myelem a xs

  forte :: String -> Bool                                    -- 3.9
  forte l = (length l) > 7 && maiuscula l && minuscula l && numeros l

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

  apaga :: Eq a => a -> [a] -> [a]
  apaga a [] = []
  apaga a (x:xs) | a==x = apaga a xs
                 | otherwise = x : apaga a xs

  myintersperse :: a -> [a] -> [a]                           -- 3.12
  myintersperse a [x] = x : []
  myintersperse a (x:xs) = x : a : myintersperse a xs

-----------------------------------------------------------------------------
--                              Folha 4                                    --
-----------------------------------------------------------------------------

  algarismos :: Int -> [Int]                                 -- 4.1
  algarismos a = reverse (algarismosRev a)

  algarismosRev :: Int -> [Int]
  algarismosRev 0 = []
  algarismosRev a = mod a 10 : algarismosRev (div a 10)

  toBits :: Int -> [Int]                                     -- 4.2
  toBits 0 = [0]
  toBits a = reverse (toBitsRev a)

  toBitsRev :: Int -> [Int]
  toBitsRev 0 = []
  toBitsRev a = mod a 2 : toBitsRev (div a 2)

  fromBits :: [Int] -> Int                                   -- 4.3
  fromBits [] = 0
  fromBits (x:xs) | x==1      = x*2^length xs + fromBits xs
                  | otherwise = fromBits xs

  mdc :: Integer -> Integer -> Integer                       -- 4.4
  mdc a b | b==0      = a
          | otherwise = mdc b (mod a b)

  myinsert :: Ord a => a -> [a] -> [a]                       -- 4.5(a)
  myinsert a [] = [a]
  myinsert a (x:xs) | a<x = a : (x:xs)
                    | otherwise = x : myinsert a xs

  myisort :: Ord a => [a] -> [a]                             -- 4.5(b)
  myisort [] = []
  myisort (x:xs) = myinsert x (myisort xs)

  myminimum :: Ord a => [a] -> a                             -- 4.6(a)
  myminimum [x] = x
  myminimum (x:xs) = myminimumaux (x:xs) x

  myminimumaux :: Ord a => [a] -> a -> a
  myminimumaux [] a = a
  myminimumaux (x:xs) a | x<a       = myminimumaux xs x
                        | otherwise = myminimumaux xs a

  mydelete :: Eq a => a -> [a] -> [a]                        -- 4.6(b)
  mydelete a [] = []
  mydelete a (x:xs) | a==x = xs
                    | otherwise = x : mydelete a xs

  myssort :: Ord a => [a] -> [a]                             -- 4.6(c)
  myssort [] = []
  myssort l = m : myssort (mydelete m l)
              where m = myminimum l

  mymerge :: Ord a => [a] -> [a] -> [a]                      -- 4.7(a)
  mymerge [] [] = []
  mymerge l [] = l
  mymerge [] l = l
  mymerge (x:xs) (y:ys) = if x<=y then (x:xs)++(y:ys) else (y:ys)++(x:xs)

  msort :: Ord a => [a] -> [a]                               -- 4.7(b)
  msort [] = []
  msort [x] = [x]
  msort l = mymerge le ld
              where
                le = msort l1
                ld = msort l2
                (l1,l2) = metades l

-----------------------------------------------------------------------------
--                              Folha 5                                    --
-----------------------------------------------------------------------------

  divisores :: Integer -> [Integer]                          -- 5.1
  divisores 0 = []
  divisores a = 1 : filter (\x -> mod a x == 0) [1..a]


  otherprimo :: Integer -> Bool                              -- 5.2
  otherprimo 1 = False
  otherprimo a = all (\x -> mod a x /= 0) [2..floor (sqrt (fromIntegral a))]


  myglue :: [a] -> [a] -> [a]                                -- 5.3(a)
  myglue [] [] = []
  myglue [] l2 = l2
  myglue l1 l2 = foldr (:) l2 l1

  myotherconcat :: [[a]] -> [a]                              -- 5.3(b)
  myotherconcat [] = []
  myotherconcat l = foldr (++) [] l

  myreverse :: [a] -> [a]                                    -- 5.3(c)
  myreverse [] = []
  myreverse l = foldr aux [] l          -- [] é o caso final, ou seja é preservada até ao final
              where aux x xs = xs ++ [x]

  myotherreverse :: [a] -> [a]                               -- 5.3(d)
  myotherreverse [] = []
  myotherreverse l = foldl aux [] l
        where aux xs x = x : xs

  myotherelem :: Eq a => a -> [a] -> Bool                    -- 5.3(e)
  myotherelem a [] = False
  myotherelem a l = any (a==) l


  myfromBits :: [Integer] -> Integer                         -- 5.4
  myfromBits (x:xs) = foldl aux x xs
            where aux n x = 2*n + x


  myzipWith :: (a -> b -> c) -> [a] -> [b] -> [c]            -- 5.5
  myzipWith f (x:xs) (y:ys) = f x y : myzipWith f xs ys
    -- f combina x com y


  isort :: Ord a => [a] -> [a]                               -- 5.6
  isort l = foldr myinsert [] l

  myotherinsert :: Ord a => a -> [a] -> [a]
  myotherinsert a [] = [a]
  myotherinsert a (x:xs) | a < x      = a : (x:xs)
                      | otherwise  = x : myinsert a xs


  palavras :: String -> [String]                             -- 5.7
  palavras "" = []
  palavras s = palavra1 : outraspalavras
    where
      (palavra1,resto) = takeWord s
      outraspalavras = palavras (dropSpace resto)

  dropSpace :: String -> String
  dropSpace = dropWhile eSp
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
  myscanl f ac (x:xs) = f ac x : myscanl f (f ac x) xs

-----------------------------------------------------------------------------
--                              Folha 6                                    --
-----------------------------------------------------------------------------

  elefantes :: Int -> IO()                                   -- 6.1
  elefantes n = elefantesaux n 2

  frase :: Int -> IO()
  frase n = do
             putStrLn ("Se "++show(n)++" elefantes incomodam muita gente,")
             putStrLn (show(n+1)++" elefantes incomodam muito mais!")

  elefantesaux :: Int -> Int -> IO()
  elefantesaux a b | b<a = do
                            frase b
                            elefantesaux a (b+1)
                   | otherwise = return()

  mywc :: String -> IO()                                     -- 6.2
  mywc l = do
            putStrLn (show(length (lines l))++"    "++show(length(words l))++"    "++show(length l))

  reverseline :: String -> IO()                              -- 6.3
  reverseline l = do
                    putStrLn (reverse l)

  rot13 :: String -> IO()                                    -- 6.4
  rot13 l = do
             putStrLn(cifrar 13 l)

  cifrar :: Int -> String -> String
  cifrar k xs = [desloca k x | x<-xs  ]

  desloca :: Int -> Char -> Char
  desloca k x | maiúscula x = intLetra ((letraInt x + k)`mod`26)
              | cifrarminuscula x = intletra ((letraint x + k)`mod`26)
              | otherwise   = x

  letraInt :: Char -> Int
  letraInt c = ord c - ord 'A'

  intLetra :: Int -> Char
  intLetra n = chr (n + ord 'A')

  maiúscula :: Char -> Bool
  maiúscula = isUpper

  cifrarminuscula :: Char -> Bool
  cifrarminuscula = isLower

  intletra :: Int -> Char
  intletra n = chr (n + ord 'a')

  letraint :: Char -> Int
  letraint c = ord c - ord 'a'

  readDict :: IO[String]                                     -- 6.7(a)
  readDict = do txt <- readFile "/usr/share/dict/words"
                return (lines txt)

  checkStrings :: String -> IO()                             -- 6.7(b)
  checkStrings l = do
                    auxcheckStrings (map checkWord (words l))

  checkWord :: String -> IO()
  checkWord l = do
                 d <- readDict
                 if l `elem` d then putStrLn ("\ESC[32m"++l++"\ESC[0m") else putStrLn("\ESC[31m"++l++"\ESC[0m")

  auxcheckStrings :: [IO()] -> IO()
  auxcheckStrings [] = return()
  auxcheckStrings (x:xs) = do
                            x
                            auxcheckStrings xs

-----------------------------------------------------------------------------
--                              Folha 7                                    --
-----------------------------------------------------------------------------

  data Arv a = Vazia
              | No a (Arv a) (Arv a)
              deriving Show

  -- listar os elementos da esquerda para a direita
  listar :: Arv a -> [a]
  listar Vazia = []
  listar (No x esq dir) = listar esq ++ [x] ++ listar dir

  -- verificar se uma árvore é *ordenada*, isto é:
  -- o valor em cada nó é:
  -- 1) maior que os valores na sub-árvore esquerda
  -- 2) menor que os valores na sub-árvore direita
  ordenada :: Ord a => Arv a -> Bool
  ordenada arv = crescente (listar arv)
    where   -- verificar se uma lista está por ordem crescente
      crescente [] = True
      crescente [_] = True
      crescente (x:y:xs) = x<y && crescente (y:xs)

  -- procurar um valor numa árvore de pesquisa
  procura :: Ord a => a -> Arv a -> Bool
  procura x Vazia = False
  procura x (No y esq dir)
    | x==y  = True
    | x<y   = procura x esq
    | x>y   = procura x dir

  -- inserir um elemento numa árvore de pesquisa
  -- mantem a ordenação
  inserir :: Ord  a => a -> Arv a -> Arv a
  inserir x Vazia = No x Vazia Vazia
  inserir x (No y esq dir)
    | x==y = No y esq dir
    | x<y  = No y (inserir x esq) dir
    | x>y  = No y esq (inserir x dir)

  -- construir uma árvore equilibrada usando partição binária
  -- pré-condição: a lista deve estar por ordem crescente
  construir :: [a] -> Arv a
  construir [] = Vazia
  construir xs = No x (construir xs') (construir xs'')
      where xs'    = take n xs
            x:xs'' = drop n xs
            n      = length xs`div`2

  -- remover um elemento duma árvore de pesquisa
  remover :: Ord a => a -> Arv a -> Arv a
  -- não encontrou
  remover x Vazia  = Vazia
  -- um descendente
  remover x (No y Vazia dir)
    | x==y = dir
  remover x (No y esq Vazia)
    | x==y = esq
  -- dois descendentes
  remover x (No y esq dir)
    | x<y  = No y (remover x esq) dir
    | x>y  = No y esq (remover x dir)
    | x==y = let z = maisEsq dir
             in No z esq (remover z dir)

  -- valor mais à esquerda
  -- (menor valor numa árvore ordenada)
  maisEsq :: Arv a -> a
  maisEsq (No x Vazia _) = x
  maisEsq (No _ esq _)   = maisEsq esq

  -- contar o número de nós
  tamanho :: Arv a -> Int
  tamanho Vazia          = 0
  tamanho (No _ esq dir) = 1 + tamanho esq + tamanho dir

  -- calcular a altura de uma árvore
  -- maior comprimento da raiz até a uma folha
  altura :: Arv a -> Int
  altura Vazia          = 0
  altura (No _ esq dir) = 1 + max (altura esq) (altura dir)

  -- verificar se uma árvore é *equilibrada*, isto é:
  -- em cada nó, a altura das sub-árvores direita
  -- e esquerda difere no máximo de 1 unidade
  equilibrada :: Arv a -> Bool
  equilibrada Vazia = True
  equilibrada (No _ esq dir) = abs (altura esq - altura dir)<=1 && equilibrada esq && equilibrada dir

  sumArv :: Num a => Arv a -> a                              -- 7.6
  sumArv Vazia = 0
  sumArv l = sum (listar l)

  listarup :: Arv a -> [a]                                   -- 7.7
  listarup Vazia = []
  listarup (No x esq dir) = listarup dir ++ [x] ++ listarup esq

  nivel :: Integer -> Arv a -> [a]                           -- 7.8
  nivel a Vazia = []
  nivel 0 (No x esq dir) = [x]
  nivel n (No x esq dir) = nivel (n-1) esq ++ nivel (n-1) dir
