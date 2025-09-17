#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Mapeia as teclas conforme a disposição física do teclado
const char keys[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

// Define os pinos GPIO conectados às linhas (entradas)
// Conforme o conector do Kit Básico do Embarcatech
const int row_pins[4] = {4, 8, 9, 16};

// Define os pinos GPIO conectados às colunas (saídas)
// Conforme o conector do Kit Básico do Embarcatech
const int col_pins[4] = {17, 18, 19, 20};

int main() {
    // Inicializa o stdio para que possamos usar printf
    stdio_init_all();

    // Configura os pinos das linhas como entrada com pull-up
    for (int i = 0; i < 4; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_IN);
        gpio_pull_up(row_pins[i]);
    }

    // Configura os pinos das colunas como saída
    for (int i = 0; i < 4; i++) {
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_OUT);
    }

    printf("Plataforma BitDogLab - Teste do Teclado Matricial\n");
    printf("Pressione uma tecla...\n");

    // Loop infinito para varredura contínua
    while (1) {
        // Itera sobre cada coluna
        for (int c = 0; c < 4; c++) {
            // Coloca todas as colunas em nível alto
            for (int i = 0; i < 4; i++) {
                gpio_put(col_pins[i], 1);
            }

            // Coloca a coluna atual em nível baixo
            gpio_put(col_pins[c], 0);
            sleep_us(100); // Pequeno delay para estabilizar o sinal

            // Itera sobre cada linha para ler o estado
            for (int r = 0; r < 4; r++) {
                // Se a linha está em nível baixo, a tecla foi pressionada
                if (!gpio_get(row_pins[r])) {
                    printf("Tecla pressionada: %c\n", keys[r][c]);
                    // Espera um pouco para evitar leituras repetidas (debounce)
                    while(!gpio_get(row_pins[r])); // Aguarda a tecla ser solta
                    sleep_ms(50); // Debounce para o próximo pressionamento
                }
            }
        }
    }

    return 0;
}