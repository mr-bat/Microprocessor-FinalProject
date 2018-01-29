char Location[100];
int begin, end;

void getLoc() {
  begin = 0;
  end = 0;

  while(true) {
    ++end;
    while(PORTD.4 == 0) ;
    while(PORTD.4 == 1) ;
    Location[end - 1] = PORTB;
    PORTD.5 = 1;
    delay_ms(1);
    PORTD.5 = 0;
    if(PORTB == 0)
      break;
  }
}

void requestLoc() {
  PORTD.3 = 1;
  delay_ms(1);
  PORTD.3 = 0;
  getLoc();
}
