module Excs where
  import Log

  parseMessage :: String -> LogEntry                         -- exc1
  parseMessage (x:y:xs) | x=='E' && y == ' '  = aux (words(x:y:xs))
                        | x=='I' && y == ' ' = aux1 (words(x:y:xs))
                        | x=='W' && y == ' ' = aux1 (words(x:y:xs))
                        | otherwise = Unknown (x:y:xs)

  aux :: [String] -> LogEntry
  aux (x:y:z:xs) = LogMessage (Error a) b speach
                 where
                   a = read y :: Int
                   b = read z :: Int
                   speach = unwords xs

  aux1 :: [String] -> LogEntry
  aux1 (x:y:xs) | x=="W"  = LogMessage Warning a speach
                | x=="I"  = LogMessage Info a speach
                  where
                    a = read y :: Int
                    speach = unwords xs



  insert :: LogEntry -> MessageTree -> MessageTree           -- exc2
  insert (Unknown l) t = t
  insert (LogMessage x y l) Empty = Node (LogMessage x y l) Empty Empty
  insert (LogMessage x y l) (Node (LogMessage a b c) esq dir) | y==b = Node (LogMessage a b c) esq (insert (LogMessage x y l) dir)
                                                              | y<b  = Node (LogMessage a b c) (insert (LogMessage x y l) esq) dir
                                                              | y>b  = Node (LogMessage a b c) esq (insert (LogMessage x y l) dir)


  build :: [LogEntry] -> MessageTree                         -- exc3
  build [] = Empty
  build (x:xs) = insert x (build xs)

  inOrder :: MessageTree -> [LogEntry]
  inOrder Empty = []
  inOrder (Node (LogMessage a b c) esq dir) = inOrder esq ++ [LogMessage a b c] ++ inOrder dir

  sortMessages :: [LogEntry] -> [LogEntry]
  sortMessages msgs = inOrder (build msgs)
