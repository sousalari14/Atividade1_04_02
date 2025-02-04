**Semáforo com Raspberry Pi Pico W**
Este projeto simula o funcionamento de um semáforo utilizando a função *add_repeating_timer_ms()* do Pico SDK. O semáforo alterna entre três sinais: vermelho, amarelo e verde, com temporização de 3 segundos para cada mudança de estado.

**Componentes Necessários**
- Microcontrolador Raspberry Pi Pico W;
- LED vermelho;
- LED amarelo;
- LED verde;
- Resistores de 330 Ω;
- BitDogLab;
- Wokwi.

**Funcionamento**
O programa utiliza a *função add_repeating_timer_ms()* para criar um temporizador que chama a função *repeating_timer_callback* a cada 3 segundos.
O código foi desenvolvido para alternar os LEDs com o seguinte comportamento:
- O LED vermelho é aceso por 3 segundos.
- O LED vermelho apaga e o LED amarelo é aceso por 3 segundos.
- O LED amarelo apaga e o LED verde é aceso por 3 segundos.
- O LED verde apaga.

**Como Usar**
- Compile o código utilizando o VSCode.
- Carregue o código na placa BitDogLab.
- A simulação também pode ser verificada no diagram.json, visto integração com o *Wokwi*.