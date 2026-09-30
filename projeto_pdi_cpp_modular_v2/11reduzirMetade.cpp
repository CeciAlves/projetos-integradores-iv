#include "imagem.h"

// ======================================================
// Tarefa 1 - Redução (Metade)
// ======================================================

Imagem Processamento::reduzirMetade(const Imagem& entrada) {

    // 1. Calcular novo tamanho
    int novaLargura = entrada.getLargura() / 2;
    int novaAltura = entrada.getAltura() / 2;

    Imagem saida(
        novaLargura,
        novaAltura, 
        entrada.getValorMaximo()
    );

    // 3. Reduzir pela metade
    for (int y = 0; y < novaAltura; y++) {
        for (int x = 0; x < novaLargura; x++) {
            // Copiar o pixel correspondente
            Pixel p = entrada.getPixel(x * 2, y * 2);
            saida.setPixel(x, y, p);
        }
    }

    return saida;
}