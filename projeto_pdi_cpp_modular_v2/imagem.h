#ifndef IMAGEM_H
#define IMAGEM_H

#include <string>
#include <vector>

struct Pixel {
    int r;
    int g;
    int b;
};

class Imagem {
private:
    int largura;
    int altura;
    int valorMaximo;
    std::vector<Pixel> pixels;

public:
    Imagem();
    Imagem(int largura, int altura, int valorMaximo = 255);

    bool carregar(const std::string& nomeArquivo);
    bool salvar(const std::string& nomeArquivo) const;

    int getLargura() const;
    int getAltura() const;
    int getTamanho() const;
    int getValorMaximo() const;

    Pixel getPixel(int i) const;
    Pixel getPixel(int x, int y) const;

    void setPixel(int i, const Pixel& p);
    void setPixel(int x, int y, const Pixel& p);
};

class Processamento {
public:
    // 1
    static Imagem tonsDeCinza(const Imagem& entrada);

    // 2
    static Imagem negativo(const Imagem& entrada);

    // 3
    static Imagem brilho(const Imagem& entrada, int valor);

    // 4
    static Imagem contraste(const Imagem& entrada, float alpha);

    // 5
    static Imagem threshold(const Imagem& entrada, int limiar);

    // 6
    static Imagem espelhamentoHorizontal(const Imagem& entrada);
    static Imagem espelhamentoVertical(const Imagem& entrada);

    // 7
    static std::vector<int> histograma(const Imagem& entrada);

    // 8
    static Imagem filtroMedia(const Imagem& entrada);

    // 9
    static Imagem sobel(const Imagem& entrada);

    // 10
    static Imagem recortar(const Imagem& entrada, int x0, int y0, int largura, int altura);

    // 11
    static Imagem reduzirMetade(const Imagem& entrada);

    // 12
    static Imagem rotacao90(const Imagem& entrada);
};

#endif
