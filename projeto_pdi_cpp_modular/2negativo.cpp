#include "imagem.h"

// ======================================================
// Tarefa 2 - Negativo
// ======================================================

Imagem Processamento::negativo(const Imagem& entrada) {

    Imagem saida(
        entrada.getLargura(),
        entrada.getAltura(),
        entrada.getValorMaximo()
    );

    for (int i = 0; i < entrada.getTamanho(); i++) {

        Pixel pixel = entrada.getPixel(i);
        Pixel pixelNegativo;

        // Inverte a intensidade de cada canal da cor
        pixelNegativo.r = entrada.getValorMaximo() - pixel.r;
        pixelNegativo.g = entrada.getValorMaximo() - pixel.g;
        pixelNegativo.b = entrada.getValorMaximo() - pixel.b;

        saida.setPixel(i, pixelNegativo);
    }

    return saida;
}