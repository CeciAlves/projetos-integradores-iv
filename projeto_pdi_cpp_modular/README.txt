PROJETO - PROCESSAMENTO DE IMAGENS EM C++
========================================

Projeto PDI com C++.

OBJETIVO
--------
Implementar as 9 tarefas de processamento de imagens discutidas em aula, utilizando imagens PPM no formato P3 (RGB) e orientacao a objetos.

A Tarefa 1 (RGB -> tons de cinza) esta completamente implementada como exemplo. As demais tarefas possuem trechos TODO que devem ser preenchidos.

ESTRUTURA
---------
imagem.h
    Definicao de Pixel, classe Imagem e classe Processamento.

imagem.cpp
    Implementacao da classe Imagem e das funcoes de leitura/escrita PPM P3.

tons_cinza.cpp
    Tarefa 1 - RGB -> tons de cinza (COMPLETA).

negativo.cpp
    Tarefa 2 - Negativo.

brilho.cpp
    Tarefa 3 - Ajuste de brilho.

contraste.cpp
    Tarefa 4 - Ajuste de contraste.

threshold.cpp
    Tarefa 5 - Limiarizacao.

espelhamento.cpp
    Tarefa 6 - Espelhamento horizontal e vertical.

histograma.cpp
    Tarefa 7 - Histograma.

media3x3.cpp
    Tarefa 8 - Filtro de media 3x3.

sobel.cpp
    Tarefa 9 - Deteccao de bordas Sobel.

main.cpp
    Programa principal.

COMPILACAO MANUAL - GERACAO DOS OBJETOS
----------------------------------------

IMPORTANTE:
Como os arquivos sao C++, utilize g++ para compilar.

1) Gerar os arquivos objeto (.o):

g++ -std=c++17 -c imagem.cpp -o imagem.o
g++ -std=c++17 -c tons_cinza.cpp -o tons_cinza.o
g++ -std=c++17 -c negativo.cpp -o negativo.o
g++ -std=c++17 -c brilho.cpp -o brilho.o
g++ -std=c++17 -c contraste.cpp -o contraste.o
g++ -std=c++17 -c threshold.cpp -o threshold.o
g++ -std=c++17 -c espelhamento.cpp -o espelhamento.o
g++ -std=c++17 -c histograma.cpp -o histograma.o
g++ -std=c++17 -c media3x3.cpp -o media3x3.o
g++ -std=c++17 -c sobel.cpp -o sobel.o

2) Criar a biblioteca estatica libimagem.a:

ar rcs libimagem.a \
    imagem.o \
    tons_cinza.o \
    negativo.o \
    brilho.o \
    contraste.o \
    threshold.o \
    espelhamento.o \
    histograma.o \
    media3x3.o \
    sobel.o

3) Compilar o programa principal e LINKAR com libimagem.a:

g++ -std=c++17 main.cpp -L. -limagem -o programa

A opcao:
    -L.
informa que a biblioteca deve ser procurada no diretorio atual.

A opcao:
    -limagem
faz o linker procurar pelo arquivo:
    libimagem.a

EXECUCAO
--------
./programa entrada.ppm

Se nenhum arquivo for informado:

./programa

o programa tentara abrir:
entrada.ppm
