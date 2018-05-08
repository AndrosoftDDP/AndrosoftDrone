/* 
AndrosoftDroneProject - Transmmitter 2
Written by AndrewF.K. in 2018
For more info please visit https://androsoft.yolasite.com/tech.php
*/ 

void setup() {
  DDRD = B11111110; //Legyen Pin 0 bemenet, Pin 1-7 kimenetek
  DDRD = DDRD | B11111100; //Allitsuk be: Pin 2-7 kimenet, TX es RX megvaltoztatasa nelkul
  Serial.begin(9600); //Nyissunk soros kommunikaciot (9600 bps) 
}

void loop() {
  int y = map(analogRead(0), 0, 1023, 1000, 2000); //Yaw ertekenek meghatarozasa (μs)
  int t = map(analogRead(1), 0, 1023, 1000, 2000); //Throttle ertekenek meghatarozasa (μs)
  int p = map(analogRead(2), 0, 1023, 1000, 2000); //Pitch ertekenek meghatarozasa (μs)
  int r = map(analogRead(3), 0, 1023, 1000, 2000); //Roll ertekenek meghatarozasa (μs)

  Serial.print("<"); //KezdoMarker kiirasa
  Serial.print(y); //Yaw kiirasa
  Serial.print("     "); //Szokoz az adatok kozott
  Serial.print(t); //Throttle kiirasa
  Serial.print("     "); //Szokoz az adatok kozott
  Serial.print(p); //Pitch kiirasa
  Serial.print("     "); //Szokoz az adatok kozott
  Serial.print(r); //Roll kiirasa
  Serial.println(">"); //ZaroMarker kiirasa
  delay(1000); //Varjunk 1 s-ot!
}
