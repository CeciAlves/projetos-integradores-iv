#include "imagem.h"

// ======================================================
// Tarefa 5 - Limiarizacao (Threshold)
// ======================================================

Imagem Processamento::threshold(const Imagem& entrada, int limiar) {

    // 1. Converte a imagem de entrada para tons de cinza!
    Imagem imagemCinza = Processamento::tonsDeCinza(entrada);

    Imagem saida(
        entrada.getLargura(),
        entrada.getAltura(),
        entrada.getValorMaximo()
    );

    for (int i = 0; i < imagemCinza.getTamanho(); i++) {

        Pixel pixel = imagemCinza.getPixel(i);
        Pixel pixelLimiar;

        // 2. Classifica o pixel como preto ou branco conforme o limiar
        int valor = (pixel.r >= limiar) ? entrada.getValorMaximo() : 0;

        pixelLimiar.r = valor;
        pixelLimiar.g = valor;
        pixelLimiar.b = valor;

        saida.setPixel(i, pixelLimiar);
    }

    return saida;
}
