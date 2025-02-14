#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>

//......................................................... PWM .................................................................
void PWM_init()
{
  //Tryp pracy - Fast PWM (TOP=ICR1)
  TCCR1A |= (1<<WGM11);
  TCCR1B |= (1<<WGM12); 
  TCCR1B |= (1<<WGM13);
  
  //Prescaler 1
  TCCR1B |= (1<<CS10);

  // Ustawienie wartości ICR1 dla pełnego zakresu
  ICR1 = 0xFFFF;
}

void play(uint16_t frequency)
{
  //TOP
  ICR1 = 16000000/(1*frequency) - 1;
  
  //Compare output mode - włączenie sygnału PWM
  TCCR1A |= (1<<COM1A1);
  
  //wypełnienie 50%
  OCR1A = ICR1/2;
}


//..................................................... INTERRUPTS ..............................................................
void ExternalInterupts_init()
{
  //
  PCICR |= (1<<PCIE0);
  PCICR |= (1<<PCIE2);
  PCMSK0 |= (1<< PCINT0);
  PCMSK0 |= (1<< PCINT2);
  PCMSK0 |= (1<< PCINT3);
  PCMSK0 |= (1<< PCINT4);
  PCMSK2 |= (1<< PCINT20);
  PCMSK2 |= (1<< PCINT18);
  PCMSK2 |= (1<< PCINT19);

  //wlaczenie przerwań 
  sei();
}

ISR(PCINT0_vect)
{
  if (!(PINB & (1<<PB0)))
  {
    // dzwięk E
    play(2637);
  }
  else if (!(PINB & (1<<PB2)))
  {
    // dzwięk F
    play(2793);
  }
  else if (!(PINB & (1<<PB3)))
  {
    // dzwięk G
    play(3135);
  }
  else if (!(PINB & (1<<PB4)))
  {
    // dzwięk A
    play(3520);
  }
  else
  {
    // Compare output mode - wyłączenie sygnału PWM
    TCCR1A &= ~(1<<COM1A1);
  }
}

ISR(PCINT2_vect)
{
  _delay_ms(50);
  if (!(PIND & (1<<PD4)))
  {
    // dzwięk H
    play(3951);
  }
  else if (!(PIND & (1<<PD2)))
  {
    // dzwięk C
    play(2093);
  }
  else if (!(PIND & (1<<PD3)))
  {
    // dzwięk D
    play(2349);
  }
  else
  {
    // Compare output mode - wyłączenie sygnału PWM
    TCCR1A &= ~(1<<COM1A1);
  }
}

//......................................................... MAIN ................................................................
int main()
{
  //Buzzer
  DDRB |= (1<<PB1);
  
  //Pull-up:                                                                                                                                                                      
  //PCINT0
  DDRB &= ~(1<<PB0);
  PORTB |= (1<<PB0);

  //PCINT2
  DDRB &= ~(1<<PB2);
  PORTB |= (1<<PB2);

  //PCINT3
  DDRB &= ~(1<<PB3);
  PORTB |= (1<<PB3);

  //PCINT4
  DDRB &= ~(1<<PB4);
  PORTB |= (1<<PB4);

  //PCINT20
  DDRD &= ~(1<<PD4);
  PORTD |= (1<<PD4);

  //PCINT18
  DDRD &= ~(1<<PD2);
  PORTD |= (1<<PD2);

  //PCINT19
  DDRD &= ~(1<<PD3);
  PORTD |= (1<<PD3);
  
  PWM_init();
  ExternalInterupts_init();

  while(1)
  {}

  return 0;
}
