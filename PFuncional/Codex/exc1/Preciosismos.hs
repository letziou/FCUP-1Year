module Preciosismos where

  horas :: Int -> Int -> Int -> Int -> (String,String)
  horas a b c d |diff==1   = (("Passou apenas 1 minuto!"),("De facto!"))
                |hora==0 && minu<60 = (("Passaram apenas "++ show(diff)++" minutos!"),("De facto!"))
                |hora==1 && minu==0 = (("Passaram apenas 60 minutos!"),("Queres dizer, 1 hora?!"))
                |hora>=2 && minu==0 = (("Passaram apenas "++ show(diff)++" minutos!"),("Queres dizer, "++show(hora)++" horas?!"))
                |hora==1 && minu==1 = (("Passaram apenas 61 minutos!"),("Queres dizer, 1 hora e 1 minuto?!"))
                |hora>=2 && minu==1 = (("Passaram apenas "++show(diff)++" minutos!"),("Queres dizer, "++show(hora)++" e 1 minuto?!"))
                |hora==1 && minu>=2 = (("Passaram apenas "++show(diff)++" minutos!"),("Queres dizer, "++show(hora)++" hora e "++show(minu)++" minutos?!"))
                |hora>=2 && minu>=2 = (("Passaram apenas "++show(diff)++" minutos!"),("Queres dizer, "++show(hora)++" horas e "++show(minu)++" minutos?!"))


                where t1 = a*60 + b
                      t2 = c*60 + d
                      diff = t2 - t1
                      minu = rem diff 60
                      hora = div (diff-minu) 60
  
