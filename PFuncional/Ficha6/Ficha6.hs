module Ficha6 where
  import Data.Char (chr, ord)

  elefantes :: Integer -> IO()
  elefantes n = contas 2 n

  frases :: Integer -> IO ()
  frases x = do
    putStrLn ("Se "++ show (x) ++" elefantes incomodam muita gente,")
    putStrLn (show(x+1)++ " elefantes incomodam muito mais!")

  contas :: Integer -> Integer -> IO()
  contas x n |x<n = do
                    frases x
                    contas (x+1) n
             |otherwise = return()


  mywc :: String -> IO()                                     -- 6.2
  mywc l = do
            putStrLn ("número de linhas = "++show(length (lines l)))
            putStrLn ("número de palavras = "++show(length (words l)))
            putStrLn ("número de caracteres = "++show(length l))


  textreverse :: String -> IO()
  textreverse l = do
                    putStrLn (reverse l)


  rot13 :: String -> IO()
  rot13 l = do
              putStrLn (cifrar 13 l)

  cifrar :: Int -> String -> String
  cifrar k xs = [desloca k x | x<-xs  ]

  desloca :: Int -> Char -> Char
  desloca k x | maiúscula x = intLetra ((letraInt x + k)`mod`26)
              | minuscula x = intletra ((letraint x + k)`mod`26)
              | otherwise   = x

  letraInt :: Char -> Int
  letraInt c = ord c - ord 'A'

  intLetra :: Int -> Char
  intLetra n = chr (n + ord 'A')

  maiúscula :: Char -> Bool
  maiúscula x = x>='A' && x<='Z'

  minuscula :: Char -> Bool
  minuscula x = x>='a' && x<='z'

  intletra :: Int -> Char
  intletra n = chr (n + ord 'a')

  letraint :: Char -> Int
  letraint c = ord c - ord 'a'


  readDict :: IO [String]
  readDict = do txt <- readFile "/usr/share/dict/words"
                return (lines txt)

  checkWord :: String -> IO()
  checkWord l = do
                  d <- readDict   --como esta em IO o readDict primeiro tenho que atribui-lo a outra variavel
                  if elem l d then putStrLn ("\ESC[32m" ++ l ++ "\ESC[0m") else putStrLn("\ESC[31m" ++ l ++ "\ESC[0m")

  aux :: [IO()] -> IO() --checkStrings não tem show por isso usamos aux pois checkStrings ao criar um [IO] não vai imprimir
  aux [] = return()
  aux (x :xs)  = do
                  x
                  aux xs

  checkStrings :: String -> IO()
  checkStrings l = do
                    aux (map checkWord (words l))
