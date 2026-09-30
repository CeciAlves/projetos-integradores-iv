#include "imagem.h"

// ======================================================
// Tarefa 10 - Recorte
// ======================================================

Imagem Processamento::recortar(const Imagem& entrada, int x0, int y0, int largura, int altura) {

    Imagem saida(
        largura,
        altura,
        entrada.getValorMaximo()
    );

    for (int y = 0; y < altura; y++) {
        for (int x = 0; x < largura; x++) {
            Pixel p = entrada.getPixel(x0 + x, y0 + y);
            saida.setPixel(x, y, p);
        }
    }

    return saida;
}