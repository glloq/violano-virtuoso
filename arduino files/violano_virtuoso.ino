#include "settings.h"
#include "violin.h"
#include "midiHandler.h"
#include "Arduino.h"

Violin* violin = nullptr;
MidiHandler* midiHandler = nullptr;

void setup() {
    Serial.begin(115200);
  
  while (!Serial) {
   delay(10); // Attendre que la connexion série soit établie
  }
    Serial.println("setup main VIOLIN MIDI USB");
    //initialise les objets pour avoir les info de debuggage
    violin = new Violin();
    midiHandler = new MidiHandler(*violin);
    // test cordes => servo plus frette
    violin->initMusic();
}

void loop() {
  midiHandler->readMidi(); // gestion des messages midi
  violin->update(); // gestion extinction electroaiamants / temps maximum actif
}
d
