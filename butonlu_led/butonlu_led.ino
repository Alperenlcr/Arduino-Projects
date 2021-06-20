#define buton 8
#define led 10
int butondurumu = 0;

void setup() {
  pinMode(buton, INPUT);
  pinMode(led, OUTPUT);  
  // put your setup code here, to run once:

}

void loop() {
  butondurumu = digitalRead(buton);
  if (butondurumu == 1)
  digitalWrite(led,HIGH);
  else digitalWrite(led,LOW);
  // put your main code here, to run repeatedly:

}
