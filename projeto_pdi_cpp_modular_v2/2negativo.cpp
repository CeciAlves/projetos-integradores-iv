#include "imagem.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

// ====================================================== 
// Tarefa 2 - Negativo                                    
// ====================================================== 

Imagem Processamento::negativo(const Imagem& entrada) {

    Imagem saida(
        entrada.getLargura(), 
        entrada.getAltura(), 
        entrada.getValorMaximo()
    );

    int tamanho = entrada.getTamanho();

    
    // =================================================== 
    // Alocar memória & Informações                        
    // =================================================== 

    std::cout << "\n===== MEMORIA =====\n";
    std::cout << "sizeof(Pixel): " 
              << sizeof(Pixel) 
              << " bytes\n";
    
    double memoria = 
        tamanho * sizeof(Pixel) 
        / (1024.0 * 1024.0);

    std::cout << "Memoria por imagem: " 
              << memoria 
              << " MB\n";


    // =================================================== 
    // Iniciar medição do tempo                            
    // =================================================== 
    auto inicio = std::chrono::high_resolution_clock::now();


    // =================================================== 
    // Calcular negativo da imagem                         
    // =================================================== 

    for (int i = 0; i < tamanho; i++) {
        Pixel pixel = entrada.getPixel(i);
        Pixel pixelNegativo;

        // Inverte a intensidade de cada canal da cor
        pixelNegativo.r = entrada.getValorMaximo() - pixel.r;
        pixelNegativo.g = entrada.getValorMaximo() - pixel.g;
        pixelNegativo.b = entrada.getValorMaximo() - pixel.b;

        saida.setPixel(i, pixelNegativo);
    }


    // =================================================== 
    // Finalizar medição                                   
    // =================================================== 

    auto fim = std::chrono::high_resolution_clock::now();


    // =================================================== 
    // Calcular tempo                                      
    // =================================================== 
    
    auto tempoMicro = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);
    double microsegundos = tempoMicro.count();
    double milissegundos = microsegundos / 1000.0;
    double segundos = microsegundos / 1000000.0;


    // =================================================== 
    // Calcular desempenho                                 
    // =================================================== 

    double megapixels = tamanho / 1000000.0;
    double taxa = 0.0;
    if (segundos > 0) {
        taxa = megapixels / segundos;
    }

    std::cout << "\n===== PROCESSAMENTO =====\n";
    std::cout << "Algoritmo: Negativo\n";
    std::cout << "Pixels processados: " << tamanho << "\n";
    std::cout << "Tempo: " << microsegundos << " us\n";
    std::cout << "Tempo: " << milissegundos << " ms\n";
    std::cout << "Taxa: " << taxa << " MPixels/s\n";

    return saida;
}
