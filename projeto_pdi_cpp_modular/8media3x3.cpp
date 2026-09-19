#include "imagem.h"

// ======================================================
// Tarefa 8 - Filtro de média 3x3
// ======================================================

Imagem Processamento::filtroMedia(const Imagem& entrada) {

    Imagem saida(
        entrada.getLargura(),
        entrada.getAltura(),
        entrada.getValorMaximo()
    );

    // For aninhado :. Percorre cada pixel para aplicar o kernel 3x3
    for (int y = 0; y < entrada.getAltura(); y++) {
        for (int x = 0; x < entrada.getLargura(); x++) {

            // Mantém os pixels da borda sem alteração,
            // pois eles não possuem vizinhança 3x3 completa!
            if (x == 0 || x == entrada.getLargura() - 1 ||
                y == 0 || y == entrada.getAltura() - 1) {

                saida.setPixel(x, y, entrada.getPixel(x, y));
                continue;
            }

            int somaR = 0;
            int somaG = 0;
            int somaB = 0;

            // Percorre os 9 pixels da vizinhança 3x3
            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {

                    Pixel pixel = entrada.getPixel(x + i, y + j);

                    somaR += pixel.r;
                    somaG += pixel.g;
                    somaB += pixel.b;
                }
            }

            Pixel pixelMedia;

            // Divide a soma dos 9 pixels para obter a média de cada canal
            pixelMedia.r = somaR / 9;
            pixelMedia.g = somaG / 9;
            pixelMedia.b = somaB / 9;

            saida.setPixel(x, y, pixelMedia);
        }
    }

    return saida;
}