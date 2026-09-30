#include "imagem.h"

// ======================================================
// Tarefa 1 - Rotação 90° 
// ======================================================

Imagem Processamento::rotacao90(const Imagem& entrada) {

    int largura = entrada.getLargura();
    int altura = entrada.getAltura();

    Imagem saida(
        altura,        // Largura = Altura
        largura,       // Altura = Largura
        entrada.getValorMaximo()
    );

    for (int y = 0; y < altura; y++) {
        for (int x = 0; x < largura; x++) {
            Pixel p = entrada.getPixel(x, y);
            
            // Descobrindo o novo par de coordenadas para rotacao horaria
            int novoX = altura - 1 - y;
            int novoY = x;

            saida.setPixel(novoX, novoY, p);
        }
    }

    return saida;
}