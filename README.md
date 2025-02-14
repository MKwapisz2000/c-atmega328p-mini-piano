# c-atmega328p-mini-piano

**Project Description - English**

This project is a mini piano running on ATmega328P, using PWM to generate sounds and external interrupts (PCINT) to handle key presses. Pressing a button produces a specific sound frequency on the buzzer.

Features:

- Sound generation via PWM (Fast PWM, Timer1)

- Key press detection using PCINT (Pin Change Interrupts)

- Low latency thanks to hardware mechanisms of the microcontroller

- Using ATmega328P microcontroller in pure C

Hardware Requirements:

- ATmega328P microcontroller (e.g., Arduino Nano or standalone AVR)

- Buzzer connected to PB1 (OC1A)

- Buttons connected to PB0, PB2, PB3, PB4, PD2, PD3, PD4

- Connecting wires

- 5V power supply

Usage Instructions:

- Compile the code in an AVR C-compatible environment (e.g., Atmel Studio, PlatformIO, AVR-GCC).

- Connect the buzzer to PB1 and buttons to PB0, PB2, PB3, PB4, PD2, PD3, PD4.

- Upload the program to the microcontroller using an ISP programmer.

- Press the buttons to play sounds (C to A scale).

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Opis projektu - Polski**

Ten projekt to mini pianinko działające na ATmega328P, wykorzystujące PWM do generowania dźwięków oraz przerwania zewnętrzne (PCINT) do obsługi klawiszy. Naciśnięcie klawisza powoduje generowanie dźwięku o określonej częstotliwości na buzzerze.

Funkcjonalność:

- Generowanie dźwięków poprzez PWM (Fast PWM, Timer1)

- Obsługa klawiatury poprzez przerwania PCINT (Pin Change Interrupts)

- Niskie opóźnienia dzięki wykorzystaniu hardware'owych mechanizmów mikrokontrolera

- Obsługa mikrokontrolera ATmega328P w czystym C

Wymagania sprzętowe:

- Mikrokontroler ATmega328P (np. Arduino Nano lub standalone AVR)

- Buzzer podłączony do PB1 (OC1A)

- Przyciski podłączone do PB0, PB2, PB3, PB4, PD2, PD3, PD4

- Przewody połączeniowe

- Zasilanie 5V

Instrukcja użytkowania:

- Skompiluj kod w środowisku obsługującym AVR C (np. Atmel Studio, PlatformIO, AVR-GCC).

- Podłącz buzzer do PB1 oraz przyciski do PB0, PB2, PB3, PB4, PD2, PD3, PD4.

- Wgraj program do mikrokontrolera za pomocą programatora ISP.

- Naciskaj przyciski, aby generować dźwięki (skala od C do A).

