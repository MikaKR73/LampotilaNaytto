// Kirjastot.
// <> kirjastot ovat arduinon. Ne pitää latailla ja asentaa sieltä.
// "" kirjastot ovat *.ino tiedoston kansiossa.
#include <OneWire.h>
#include <DallasTemperature.h>
#include "ajastin.h"

//Lämpötilan anturin portti.
#define ONE_WIRE_BUS 12

//Näytön portit ja arvot.
#define LedE 11
#define LedD 10
#define LedC 9
#define LedDP 8
#define LedG 7
#define LedF 6
#define LedA 5
#define LedB 4
#define nayttoA 3
#define nayttoB 2
#define LedOFF LOW
#define LedON HIGH

//Ajastimen asetukset.
ajastin T1(1);
ajastin T2(2500);

// Lämpötila anturin määritystä.
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celcius=0;
float Fahrenheit=0;

//Muuttujien arvon määritys.
int LedEState = LedOFF;
int LedDState = LedOFF;
int LedCState = LedOFF;
int LedDPState = LedOFF;
int LedGState = LedOFF;
int LedFState = LedOFF;
int LedAState = LedOFF;
int LedBState = LedOFF;
int nayttoAtila = LedOFF;
int nayttoBtila = LedOFF;

// Otetaan käyttöön.
void setup(){
  pinMode(LedE, OUTPUT);
  pinMode(LedD, OUTPUT);
  pinMode(LedC, OUTPUT);
  pinMode(LedDP, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(LedF, OUTPUT);
  pinMode(LedA, OUTPUT);
  pinMode(LedB, OUTPUT);
  pinMode(nayttoA, OUTPUT);
  pinMode(nayttoB, OUTPUT);
  digitalWrite(LedE, LedEState);
  digitalWrite(LedD, LedDState);
  digitalWrite(LedC, LedCState);
  digitalWrite(LedDP, LedDPState);
  digitalWrite(LedG, LedGState);
  digitalWrite(LedF, LedFState);
  digitalWrite(LedA, LedAState);
  digitalWrite(LedB, LedBState);
  digitalWrite(nayttoA, nayttoAtila);
  digitalWrite(nayttoB, nayttoBtila);
  Serial.begin(9600);
}

//Muuttujien arvon määritystä ja alustusta.
int count = 0; // Laskuri numeron näyttöä varten.
int naytto = 0; // Vaihtaa näyttöä.
int laskuri = 0; // Määrittää mikä numeroa yritetään näyttää

void LediTila(){ // Määritetään ledien päälle.
  switch( count ){
    case 1:
      // Määritetään ledin tila numerolle 1.
        LedEState = LedOFF;
        LedDState = LedOFF;
      LedCState = LedON;
      LedDPState = LedOFF;
      LedGState = LedOFF;
      LedFState = LedOFF;
      LedAState = LedOFF;
      LedBState = LedON;
      break;
    case 2: 
      // Määritetään ledin tila numerolle 2.
        LedEState = LedON;
        LedDState = LedON;
      LedCState = LedOFF;
      LedDPState = LedOFF;
      LedGState = LedON;
      LedFState = LedOFF;
      LedAState = LedON;
      LedBState = LedON;
      break;
    case 3: 
      // Määritetään ledin tila numerolle 3.
        LedEState = LedOFF;
        LedDState = LedON;
      LedCState = LedON;
      LedDPState = LedOFF;
      LedGState = LedON;
      LedFState = LedOFF;
      LedAState = LedON;
      LedBState = LedON;
      break;
    case 4: 
      // Määritetään ledin tila numerolle 4.
        LedEState = LedOFF;
        LedDState = LedOFF;
      LedCState = LedON;
      LedDPState = LedOFF;
      LedGState = LedON;
      LedFState = LedON;
      LedAState = LedOFF;
      LedBState = LedON;
      break;
    case 5: 
      // Määritetään ledin tila numerolle 5.
        LedEState = LedOFF;
        LedDState = LedON;
      LedCState = LedON;
      LedDPState = LedOFF;
      LedGState = LedON;
      LedFState = LedON;
      LedAState = LedON;
      LedBState = LedOFF;
      break;
    case 6: 
      // Määritetään ledin tila numerolle 6.
        LedEState = LedON;
        LedDState = LedON;
      LedCState = LedON;
      LedDPState = LedOFF;
      LedGState = LedON;
      LedFState = LedON;
      LedAState = LedON;
      LedBState = LedOFF;
      break;
    case 7: 
      // Määritetään ledin tila numerolle 7.
        LedEState = LedOFF;
        LedDState = LedOFF;
      LedCState = LedON;
      LedDPState = LedOFF;
      LedGState = LedOFF;
      LedFState = LedOFF;
      LedAState = LedON;
      LedBState = LedON;
      break;
    case 8: 
      // Määritetään ledin tila numerolle 8.
        LedEState = LedON;
        LedDState = LedON;
      LedCState = LedON;
      LedDPState = LedOFF;
      LedGState = LedON;
      LedFState = LedON;
      LedAState = LedON;
      LedBState = LedON;
      break;
     case 9: 
      // Määritetään ledin tila numerolle 9.
        LedEState = LedOFF;
        LedDState = LedON;
      LedCState = LedON;
      LedDPState = LedOFF;
      LedGState = LedON;
      LedFState = LedON;
      LedAState = LedON;
      LedBState = LedON;
      break;
     case 0: 
      // Määritetään ledin tila numerolle 0.
        LedEState = LedON;
        LedDState = LedON;
      LedCState = LedON;
      LedDPState = LedOFF;
      LedGState = LedOFF;
      LedFState = LedON;
      LedAState = LedON;
      LedBState = LedON;
      break;
    case 10: // Sammutetaan ledit.
        LedEState = LedOFF;
        LedDState = LedOFF;
      LedCState = LedOFF;
      LedDPState = LedON;
      LedGState = LedOFF;
      LedFState = LedOFF;
      LedAState = LedOFF;
      LedBState = LedOFF;
      break;
    }
  }

void Naytto(){ // Tulostetaan arvot näytölle.
  digitalWrite(nayttoA, nayttoAtila);// Onko näyttö päällä.
  digitalWrite(nayttoB, nayttoBtila);// Onko näyttö päällä.
  digitalWrite(LedE, LedEState); //Kirjoittaa ledin tilan.
  digitalWrite(LedD, LedDState); //Kirjoittaa ledin tilan.
  digitalWrite(LedC, LedCState); //Kirjoittaa ledin tilan.
  digitalWrite(LedDP, LedDPState); //Kirjoittaa ledin tilan.
  digitalWrite(LedG, LedGState); //Kirjoittaa ledin tilan.
  digitalWrite(LedF, LedFState); //Kirjoittaa ledin tilan.
  digitalWrite(LedA, LedAState); //Kirjoittaa ledin tilan.
  digitalWrite(LedB, LedBState); //Kirjoittaa ledin tilan.
}

void Numero(){ // Vaihdetaan näyttöjä ja lasketaan näytön arvo. 0-99.
  if(T1.timeIsUp()){ // Jos ajastin täyttyy aktivoidaan toiminto.
    if(naytto == 0){
      nayttoAtila = LedON;
      nayttoBtila = LedOFF;
      naytto = 1;
      count = laskuri % 10;
    }else{ // Jos ajatin ei täyty tehdään toiminnot.
      nayttoAtila = LedOFF;
      nayttoBtila = LedON;
      naytto = 0;
      count = laskuri / 10;
    }
  }
}

void Lampotila(){// Lukee anturin lämpötilan.
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  laskuri = Celcius;

  // Tulostetaan serial porttiin tiedot.
  Serial.print("  C: ");
  Serial.print(Celcius);
  Serial.print("  F: ");
  Serial.println(Fahrenheit);
}

void loop(){
  Numero(); // Määritellään näyttö ja arvo.
  LediTila(); // Määritellään numero näytölle.
  Naytto(); // Tulostetaan näytölle arvot.
  if(T2.timeIsUp()){ // Jos ajatin täyttyy menään lukemaan arvo.
    Lampotila(); // Luetaan lämpöanturia.
  }
}
