#include "imagem.h"

#include <algorithm>
#include <cmath>

// ======================================================
// Tarefa 9 - Deteccao de bordas - Sobel
// ======================================================

Imagem Processamento::sobel(const Imagem& entrada) {

    // 1. Converte a imagem para tons de cinza antes de detectar as bordas
    Imagem imagemCinza = Processamento::tonsDeCinza(entrada);

    Imagem saida(
        entrada.getLargura(),
        entrada.getAltura(),
        entrada.getValorMaximo()
    );

    // 2. Aplicar Sobel
    for (int y = 0; y < entrada.getAltura(); y++) {
        for (int x = 0; x < entrada.getLargura(); x++) {

            // Seta os pixels da borda para branco,
            // pois eles não possuem vizinhança 3x3 completa!
            if (x == 0 || x == entrada.getLargura() - 1 ||
                y == 0 || y == entrada.getAltura() - 1) {

                Pixel pixelBorda;
                pixelBorda.r = 0;
                pixelBorda.g = 0;
                pixelBorda.b = 0;

                saida.setPixel(x, y, pixelBorda);
                continue;
            }

            int gx = 0;
            int gy = 0;

            // Percorre a vizinhança 3x3 e aplica as máscaras de Sobel
            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {

                    Pixel pixel = imagemCinza.getPixel(x + i, y + j);

                    // Máscara Gx: detecta variações horizontais
                    int pesoGx = i;

                    if (j == 0) {
                        pesoGx *= 2;
                    }

                    gx += pixel.r * pesoGx;

                    // Máscara Gy: detecta variações verticais
                    int pesoGy = j;

                    if (i == 0) {
                        pesoGy *= 2;
                    }

                    gy += pixel.r * pesoGy;
                }
            }

            // Combina as duas variações para obter a intensidade da borda
            int magnitude = static_cast<int>(
                std::sqrt(gx * gx + gy * gy)
            );

            // Limita o resultado ao intervalo válido da imagem
            magnitude = std::min(
                magnitude,
                entrada.getValorMaximo()
            );

            Pixel pixelSobel;
            pixelSobel.r = magnitude;
            pixelSobel.g = magnitude;
            pixelSobel.b = magnitude;

            saida.setPixel(x, y, pixelSobel);
        }
    }

    return saida;
}