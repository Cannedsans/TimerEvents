#include "events.h"
#include <avr/io.h>
#include <avr/interrupt.h>

struct Task {
  void (*function)();
  int interval;
  int tickCount;
};

const int max = 10;
volatile int total = 0;
volatile Task taskList[max];

void attachEvent(void (*userFunc)(void), int interval) {
    if (total < max) {
      taskList[total].function = userFunc;
      taskList[total].interval = interval;
      taskList[total].tickCount = 0;
      total++;
    }
}

void startEvents() {
    TCCR1A = 0; 
    TCCR1B = 0; 

    // Configura Prescaler de 256 (Modo Normal)
    TCCR1B |= (1 << CS12); 
    TIMSK1 |= (1 << TOIE1); // Habilita interrupção por overflow
    TCNT1 = 65536 - 62;     // Recarrega para aproximadamente 1ms
}

ISR(TIMER1_OVF_vect) {
    // Recarrega o timer imediatamente para manter a precisão do relógio
    TCNT1 = 65536 - 62; 

    // Percorre as tarefas
    for (int i = 0; i < total; i++) {
        taskList[i].tickCount++;

        // Se a tarefa atingiu o seu próprio intervalo
        if (taskList[i].tickCount >= taskList[i].interval) {
            taskList[i].tickCount = 0; // Reseta o contador dela
            
            // Chama a função correta usando o índice [i]
            taskList[i].function(); 
        }
    }
}