#include "imagem.h"

// ======================================================
// Tarefa 6 - Espelhamento da imagem
// ======================================================

Imagem Processamento::espelhamentoHorizontal(const Imagem& entrada) {

    Imagem saida(
        entrada.getLargura(),
        entrada.getAltura(),
        entrada.getValorMaximo()
    );

    for (int x = 0; x < entrada.getLargura(); x++) {
        for (int y = 0; y < entrada.getAltura(); y++) {
            Pixel pixel = entrada.getPixel(x, y);

            // Inverte a posição horizontal do pixel
            int xEspelhado = entrada.getLargura() - 1 - x;

            saida.setPixel(xEspelhado, y, pixel);
        }
    }

    return saida;
}

Imagem Processamento::espelhamentoVertical(const Imagem& entrada) {

    Imagem saida(
        entrada.getLargura(),
        entrada.getAltura(),
        entrada.getValorMaximo()
    );

    for (int x = 0; x < entrada.getLargura(); x++) {
        for (int y = 0; y < entrada.getAltura(); y++) {

            Pixel pixel = entrada.getPixel(x, y);

            // Inverte a posição vertical do pixel
            int yEspelhado = entrada.getAltura() - 1 - y;

            saida.setPixel(x, yEspelhado, pixel);
        }
    }

    return saida;
}