#include "imagem.h"

// ======================================================
// Tarefa 1 - RGB -> Tons de cinza
// IMPLEMENTACAO COMPLETA
//
// Gray = 0.299R + 0.587G + 0.114B
// ======================================================

Imagem Processamento::tonsDeCinza(const Imagem& entrada) {

    Imagem saida(
        entrada.getLargura(),
        entrada.getAltura(),
        entrada.getValorMaximo()
    );

    for (int i = 0; i < entrada.getTamanho(); i++) {

        Pixel pixel = entrada.getPixel(i);

        int cinza = static_cast<int>(
            0.299 * pixel.r +
            0.587 * pixel.g +
            0.114 * pixel.b
        );

        Pixel novoPixel;

        novoPixel.r = cinza;
        novoPixel.g = cinza;
        novoPixel.b = cinza;

        saida.setPixel(i, novoPixel);
    }

    return saida;
}
