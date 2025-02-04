#include <stdio.h>
#include "pico/stdlib.h" 
#include "hardware/timer.h"

#define LED_PIN_RED    11  // Pino do LED vermelho
#define LED_PIN_YELLOW 12  // Pino do LED amarelo
#define LED_PIN_GREEN  13  // Pino do LED verde

// Variável para armazenar o estado do semáforo (0: Vermelho, 1: Amarelo, 2: Verde)
int semaforo_estado = 0;

// Função de callback chamada pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
 
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_YELLOW, 0);
    gpio_put(LED_PIN_GREEN, 0);

    // Altera o estado do semáforo
    switch (semaforo_estado) {
        case 0: // Vermelho
            gpio_put(LED_PIN_RED, 1); // Acende o LED vermelho
            semaforo_estado = 1; // Vai para o amarelo
            break;
        case 1: // Amarelo
            gpio_put(LED_PIN_YELLOW, 1); // Acende o LED amarelo
            semaforo_estado = 2; // Vai para o verde
            break;
        case 2: // Verde
            gpio_put(LED_PIN_GREEN, 1); // Acende o LED verde
            semaforo_estado = 0; // Vai para o vermelho
            break;
    }

    return true;
}

int main() {
    stdio_init_all();

    // Inicializa os pinos dos LEDs e define os LEDs como saída
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, true);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, true);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, true);

     // Configura o temporizador para chamar a callback a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
   
    while (true) {

        sleep_ms(10000); // Pausa de 1 segundo
    }

    return 0;
}
