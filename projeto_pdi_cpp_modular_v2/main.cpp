#include <iostream>
#include <string>
#include <vector>

#include "imagem.h"

using namespace std;

int main(int argc, char* argv[]) {

    string nomeArquivo = "entrada.ppm";

    if (argc > 1) {
        nomeArquivo = argv[1];
    }

    Imagem imagem;

    if (!imagem.carregar(nomeArquivo)) {
        cout << "Erro ao carregar a imagem: "
             << nomeArquivo << endl;
        return 1;
    }

    cout << "Imagem carregada com sucesso.\n";
    cout << "Largura: " << imagem.getLargura() << endl;
    cout << "Altura: " << imagem.getAltura() << endl;
    cout << "Pixels: " << imagem.getTamanho() << endl;

    cout << "\n=== MENU ===\n";
    cout << "1  - Tons de cinza\n";
    cout << "2  - Negativo\n";
    cout << "3  - Ajuste de brilho\n";
    cout << "4  - Ajuste de contraste\n";
    cout << "5  - Threshold\n";
    cout << "6  - Espelhamento horizontal\n";
    cout << "7  - Espelhamento vertical\n";
    cout << "8  - Histograma\n";
    cout << "9  - Filtro de media 3x3\n";
    cout << "10 - Sobel\n";
    cout << "11 - Recorte\n";
    cout << "12 - Reduzir pela metade\n";
    cout << "13 - Rotação de 90°\n";
    cout << "Opcao: "; 

    int opcao;
    cin >> opcao;

    Imagem resultado;

    switch (opcao) {

        case 1:
            resultado = Processamento::tonsDeCinza(imagem);
            break;

        case 2:
            resultado = Processamento::negativo(imagem);
            break;

        case 3: {
            int valor;
            cout << "Valor do brilho: ";
            cin >> valor;
            resultado = Processamento::brilho(imagem, valor);
            break;
        }

        case 4: {
            float alpha;
            cout << "Valor de alpha: ";
            cin >> alpha;
            resultado = Processamento::contraste(imagem, alpha);
            break;
        }

        case 5: {
            int limiar;
            cout << "Valor do limiar: ";
            cin >> limiar;
            resultado = Processamento::threshold(imagem, limiar);
            break;
        }

        case 6:
            resultado = Processamento::espelhamentoHorizontal(imagem);
            break;

        case 7:
            resultado = Processamento::espelhamentoVertical(imagem);
            break;

        case 8: {
            vector<int> h = Processamento::histograma(imagem);

            for (int i = 0; i < 256; i++) {
                cout << i << " " << h[i] << endl;
            }

            return 0;
        }

        case 9:
            resultado = Processamento::filtroMedia(imagem);
            break;

        case 10:
            resultado = Processamento::sobel(imagem);
            break;
   
        case 11:
            int x0, y0, largura, altura;
            cout << "Valor de inicio do recorte vertical (x0): ";
            cin >> x0;
            cout << "Valor de inicio do recorte horizontal (y0): ";
            cin >> y0;
            cout << "Valor da largura final: ";
            cin >> largura;
            cout << "Valor da altura final: ";
            cin >> altura;
            resultado = Processamento::recortar(imagem, x0, y0, largura, altura);
            break;

        case 12:
            resultado = Processamento::reduzirMetade(imagem);
            break;

        case 13:
            resultado = Processamento::rotacao90(imagem);
            break;


        default:
            cout << "Opcao invalida.\n";
            return 1;
    }

    if (!resultado.salvar("saida.ppm")) {
        cout << "Erro ao salvar saida.ppm\n";
        return 1;
    }

    cout << "Resultado salvo em saida.ppm\n";

    return 0;
}
