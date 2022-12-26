module Ficha2 where

  classifica :: Integer -> String                            -- 2.1
  classifica a |a<=9           = "reprovado"
               |a>=10 && a<=12 = "suficiente"
               |a>=13 && a<=15 = "bom"
               |a>=16 && a<=18 = "muito bom"
               |a>=19 && a<=20 = "muito bom com distinção"


  classifica2 :: Float -> Float -> String                    -- 2.2
  classifica2 a b |i<18.5             = "baixo peso"
                  |i>=18.5 && i<=25   = "peso normal"
                  |i>=25 && i<=30     = "excesso de peso"
                  |i>=30              = "obesidade"
        where i = a / (b*b)


  max3, min3 :: Integer -> Integer -> Integer -> Integer     -- 2.3(a)
  max3 a b c  |a>b && a>c  = a
              |b>c && b>a  = b
              |c>a && c>b  = c
              |otherwise = 42
  min3 a b c  |a<b && a<c  = a
              |b<a && b<c  = b
              |c<a && c<b  = c
              |otherwise = 42


  max4, min4 :: Integer -> Integer -> Integer -> Integer     -- 2.3(b)
  max4 a b c  |s>c  = s
              |otherwise = c
            where s = if a>b then a else b
  min4 a b c  |s<c  = s
              |otherwise = c
            where s = if a<b then a else b


  xor :: Bool -> Bool -> Bool                                -- 2.4
  xor x y  |x && not y = True
           |not x && y = True
           |otherwise = False


  safetail1 :: [a] -> [a]                                    -- 2.5
  safetail1 [] = []
  safetail (x:xs) = xs
  -- safetail1 l = tail l //outra forma em que l corresponde a uma lista da forma (x:xs)



  curta1 :: [a] -> Bool                                    -- 2.6(a)
  curta1 [] = True
  curta1 l |length l >2 = False
           |otherwise   = True


  curta2 :: [a] -> Bool                                    -- 2.6(b)
  curta2 []    = True
  curta2 [_]   = True        -- em vez de _ pode ser x
  curta2 [_,_] = True        -- em vez de _,_ pode ser x.y
  curta2 l     = False

  mediana1 :: Integer -> Integer -> Integer -> Integer       -- 2.7(a)
  mediana1 a b c |a>b && a<c ||a>c && a<b  = a
                 |b>a && b<c ||b>c && b<a  = b
                 |c>a && c<b ||c>b && c<a  = c


  mediana2 :: Integer -> Integer -> Integer -> Integer       -- 2.7(b)
  mediana2 a b c = a+b+c-(max4 a b c + min4 a b c)
