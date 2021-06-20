int deger = 0;

void setup() {
Serial.begin(9600);
Serial.println("pot değer okuma");
}

void loop() {
deger = analogRead(A0);
Serial.println(deger);

}
