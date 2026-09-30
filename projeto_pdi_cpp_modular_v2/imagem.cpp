#include "imagem.h"

#include <fstream>
#include <iostream>
#include <limits>

Imagem::Imagem()
    : largura(0), altura(0), valorMaximo(255) {
}

Imagem::Imagem(int largura, int altura, int valorMaximo)
    : largura(largura),
      altura(altura),
      valorMaximo(valorMaximo),
      pixels(largura * altura) {
}

bool Imagem::carregar(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        return false;
    }

    std::string formato;
    arquivo >> formato;

    if (formato != "P3") {
        std::cerr << "Formato invalido. Utilize PPM P3.\n";
        return false;
    }

    arquivo >> std::ws;

    // Ignora linhas de comentario no cabecalho.
    while (arquivo.peek() == '#') {
        arquivo.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        arquivo >> std::ws;
    }

    arquivo >> largura >> altura >> valorMaximo;

    if (!arquivo || largura <= 0 || altura <= 0 || valorMaximo <= 0) {
        return false;
    }

    pixels.resize(largura * altura);

    for (int i = 0; i < largura * altura; i++) {
        arquivo >> pixels[i].r
                >> pixels[i].g
                >> pixels[i].b;

        if (!arquivo) {
            std::cerr << "Erro durante a leitura dos pixels.\n";
            return false;
        }
    }

    return true;
}

bool Imagem::salvar(const std::string& nomeArquivo) const {
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        return false;
    }

    arquivo << "P3\n";
    arquivo << largura << " " << altura << "\n";
    arquivo << valorMaximo << "\n";

    for (int i = 0; i < largura * altura; i++) {
        arquivo << pixels[i].r << " "
                << pixels[i].g << " "
                << pixels[i].b << "\n";
    }

    return true;
}

int Imagem::getLargura() const {
    return largura;
}

int Imagem::getAltura() const {
    return altura;
}

int Imagem::getTamanho() const {
    return largura * altura;
}

int Imagem::getValorMaximo() const {
    return valorMaximo;
}

Pixel Imagem::getPixel(int i) const {
    return pixels[i];
}

Pixel Imagem::getPixel(int x, int y) const {
    return pixels[y * largura + x];
}

void Imagem::setPixel(int i, const Pixel& p) {
    pixels[i] = p;
}

void Imagem::setPixel(int x, int y, const Pixel& p) {
    pixels[y * largura + x] = p;
}
