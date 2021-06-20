#include <pcmConfig.h>

#include <pcmRF.h>
#include <TMRpcm.h>
#include <SPI.h>
#include <SD.h>
#define SD_ChipSelectPin 4
TMRpcm tmrpcm;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tmrpcm.speakerPin=9;
  if(!SD.begin(SD_ChipSelectPin)){
    Serial.println('SD kart hatasi');
    return;
    }
  tmrpcm.setVolume(5);
}

void play() {
  // put your main code here, to run repeatedly:
  tmrpcm.play("ses.wav");
  delay(240000);
  return;
}

void loop() {
  play();
}
}
