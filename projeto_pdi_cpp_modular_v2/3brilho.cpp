#include "imagem.h"
#include <algorithm>

using namespace std;

// ======================================================
// Tarefa 3 - Ajuste de brilho
// ======================================================

Imagem Processamento::brilho(const Imagem& entrada, int valor) {

    Imagem saida(
        entrada.getLargura(),
        entrada.getAltura(),
        entrada.getValorMaximo()
    );

    for (int i = 0; i < entrada.getTamanho(); i++) {

        Pixel pixel = entrada.getPixel(i);
        Pixel pixelBrilho;

        // Soma o valor de brilho (e limita cada canal ao intervalo válido)
        pixelBrilho.r = clamp(pixel.r + valor, 0, entrada.getValorMaximo());
        pixelBrilho.g = clamp(pixel.g + valor, 0, entrada.getValorMaximo());
        pixelBrilho.b = clamp(pixel.b + valor, 0, entrada.getValorMaximo());

        saida.setPixel(i, pixelBrilho);
    }

    return saida;
}