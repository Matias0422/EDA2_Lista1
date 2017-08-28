# EDA2_Lista1

- Bruno Matias Casas - 150051212

- Carlos Enrique Rodrigues Aragon - 150121148


# EXPLICAÇÃO INSERIR EXER 4: 
Basicamente apos escolher a opção 1 na interface, o usuario digita 
um numero a ser inserido. No metodo ele irá realocar +1 espaço no vetor
principal e adicionar esse numero inserido no novo espaço criado na ultima posição.
Depois disso é feito um "insertionSort" partindo ja da ultima posição, ou seja
o numero ira comparar com o de tras e fazer o swap enquanto ele for maior.

# EXPLICAÇÃO REMOVER EXER 4: 
Apos o usuario escolher a opção 2, ele digita o numero a ser removido. 
No metodo irá acontecer uma busca utilizando indice, para achar
a posição do numero escolhido ou se ele existe no vetor. Após encontrado ele é feito
um swap com os numeros da frente até o numero escolhido chegar na
ultima posição. Depois o vetor é realocado -1 espaço.

# RESPOSTA EXER 6: A taxa de crescimento é menor que a ordem de log(n).

# TEMPO EXER 6:


10

real    0m0.005s    -    0m0.005s     =   0m0.000s

-----------------------

25

real    0m0.004s    -    0m0.003s     =   0m0.001s

---------------------

50

real    0m0.005s    -    0m0.005s    =    0m0.000s

-----------------------

100

real    0m0.005s    -    0m0.005s    =    0m0.000s

-----------------------

500

real    0m0.005s   -     0m0.005s    =    0m0.000s

-----------------------

1000

real    0m0.006s   -    0m0.004s    =     0m0.002s

-----------------------

10000

real    0m0.014s   -    0m0.012s    =      0m0.002s

-----------------------

100000

real    0m0.063s   -    0m0.057s    =       0m0.006s

-----------------------

1000000

real    0m0.723s  -    0m0.656s    =        0m0.067s

