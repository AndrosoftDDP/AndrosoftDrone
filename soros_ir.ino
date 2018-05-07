void setup() {
  DDRD = B11111110; //Legyen Pin 0 bemenet, Pin 1-7 kimenetek
  DDRD = DDRD | B11111100; //Allitsuk be: Pin 2-7 kimenet, TX es RX megvaltoztatasa nelkul
}

void loop() {
  int p = map(analogRead(0), 0, 1023, 1000, 2000); //Pitch ertekenek meghatarozasa (μs)
  int r = map(analogRead(1), 0, 1023, 1000, 2000); //Roll ertekenek meghatarozasa (μs)
  int y = map(analogRead(2), 0, 1023, 1000, 2000); //Yaw ertekenek meghatarozasa (μs)
  int t = map(analogRead(3), 0, 1023, 1000, 2000); //Throttle ertekenek meghatarozasa (μs)

  PORTD = B00010000;  //Pin 4 jelszintje legyen magas
  delayMicroseconds(p); //p μs-ig
  PORTD = B00100000; //Pin 5 jelszintje legyen magas
  delayMicroseconds(r); //p μs-ig
  PORTD = B01000000; //Pin 6 jelszintje legyen magas
  delayMicroseconds(y); //p μs-ig
  PORTD = B10000000; //Pin 7 jelszintje legyen magas
  delayMicroseconds(t); //p μs-ig
  PORTD = B00000000; //Az osszes kimenet legyen alacsony jelszinten
  delayMicroseconds(16000 - (p + r + y + t)); //A kod 16 ms-onkent ismetlodik, igy lesz a jel frekvenciaja f = 62,5 1/s; 
}
