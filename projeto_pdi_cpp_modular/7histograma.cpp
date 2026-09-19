#include "imagem.h"

#include <vector>

// ======================================================
// Tarefa 7 - Histograma
// ======================================================

std::vector<int> Processamento::histograma(const Imagem& entrada) {

    // 1. Converte a imagem de entrada para tons de cinza
    Imagem imagemCinza = Processamento::tonsDeCinza(entrada);

    // Inicializa uma posição para cada intensidade de 0 a 255 (sabendo que são os valores min e max!)
    std::vector<int> histograma(256, 0);

    for (int i = 0; i < imagemCinza.getTamanho(); i++) {

        Pixel pixel = imagemCinza.getPixel(i);

        // 2. Conta a ocorrência da intensidade do pixel
        int intensidade = pixel.r;
        histograma[intensidade]++;
    }

    return histograma;
}
