#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>
#include <pcmConfig.h>
#include <pcmRF.h>
#define SD_ChipSelectPin 4
TMRpcm tmrpcm;

int buttonValue = 0;
//Dosya isimlerini sırasıyla tutan değişken
//Başlangıç değeri "0"
String filename[] = {"oksijen", "hidrojen", "oksijen"};
int w_time[] = {1, 3, 5};

void setup() {
  Serial.begin(9600);
  tmrpcm.speakerPin = 9;
  tmrpcm.setVolume(100);
  if(!SD.begin(SD_ChipSelectPin)){
    Serial.println("Sd kart hatası");
    return;
  }
}

void loop() {
  //Button değerini ölçen değişken buttonValue
  buttonValue = analogRead(A0);
  
  //button değerini görmek için aşağıdaki yorum satırını kaldırın
  //Serial.println(buttonValue);

  //Button değerine göre seçim yapmak için gereken koşullar
  if(buttonValue > 500 && buttonValue < 521){
    //Fonksiyona çalması istenilen dosya ismini tutan değer ile çağrılır.
    playWav(0);
  } else if(buttonValue > 680 && buttonValue < 700){
    playWav(1);
  }else if(buttonValue > 760 && buttonValue < 780){
    playWav(2);
  }else{
    Serial.println("Buttona basılmadı");
  }
}

void playWav(int code){
    tmrpcm.stopPlayback();
    String fname = filename[code] + ".wav";
    tmrpcm.play("oksijen.wav");
    Serial.println(fname);
    delay(1000 * w_time[code]);
}
