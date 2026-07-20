# TimerEvents

A task scheduler library for Arduino (ATmega328P/Arduino Uno), 100% based on **hardware interrupts (Timer1)**.
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/cannedsans/library/TimerEvents.svg)](https://registry.platformio.org/libraries/cannedsans/TimerEvents)
---

## Installation

Add the library to your `platformio.ini` file:

```ini
lib_deps =
    https://github.com/Cannedsans/TimerEvents
```
## Important Notices

* Keep tasks lightweight: Do not use this library for large code blocks or within functions that utilize delay().

* Interrupt conflicts: Communication buses like UART or others may cause issues due to competing hardware interrupts.

* Loop safety: The main void loop() can still use delay() without affecting the scheduled background events.

# Em PT-BR

Uma biblioteca de agendamento de tarefas (task scheduler) para Arduino (ATmega328P/Arduino Uno), baseada 100% em **interrupção por hardware (Timer1)**.
## Instalação

Adicione a biblioteca ao seu arquivo `platformio.ini`:
```Ini
lib_deps =
    [https://github.com/seu-usuario/TimerEvents.git](https://github.com/seu-usuario/TimerEvents.git)
```
## Avisos Importantes

* Mantenha o código leve: Não utilize para blocos de códigos grandes ou que usem a função `delay()`.

* Conflitos de interrupção: Barramentos de comunicação (como UART) ou periféricos semelhantes podem causar erros devido à concorrência com outras interrupções.

* Segurança no Loop: O void loop() principal pode usar delay() livremente sem afetar a execução dos eventos agendados.
