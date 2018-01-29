void sendLoc() {
  for (int i = 0; i < end; i++) {
    PORTB = Loc[i];
    PORTD.4 = 1;
    delay_ms(1);
    PORTD.4 = 0;
    while(PORTD.5 == 0) ;
    while(PORTD.5 == 1) ;
  }
  PORTB = 0;
  PORTD.4 = 1;
  delay_ms(1);
  PORTD.4 = 0;
}

void ISR() {
  while(PORTD.3 == 1) ;
  sendLoc();
}
