#include "imagem.h"
#include <algorithm>

using namespace std;
// ======================================================
// Tarefa 4 - Ajuste de contraste
// ======================================================

Imagem Processamento::contraste(const Imagem& entrada, float alpha) {

    Imagem saida(
        entrada.getLargura(),
        entrada.getAltura(),
        entrada.getValorMaximo()
    );

    for (int i = 0; i < entrada.getTamanho(); i++) {

        Pixel pixel = entrada.getPixel(i);
        Pixel pixelContraste;

        // Ajusta o contraste em torno do valor central
        pixelContraste.r =
            static_cast<int>(alpha * (pixel.r - 128) + 128);
        pixelContraste.r =
            max(0, min(entrada.getValorMaximo(), pixelContraste.r));

        pixelContraste.g =
            static_cast<int>(alpha * (pixel.g - 128) + 128);
        pixelContraste.g =
            max(0, min(entrada.getValorMaximo(), pixelContraste.g));

        pixelContraste.b =
            static_cast<int>(alpha * (pixel.b - 128) + 128);
        pixelContraste.b =
            max(0, min(entrada.getValorMaximo(), pixelContraste.b));

        saida.setPixel(i, pixelContraste);
    }

    return saida;
}
