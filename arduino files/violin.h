#ifndef VIOLIN_H
#define VIOLIN_H

#include "settings.h"
#include "violinString.h"
#include "Servo.h"
/***********************************************************************************************
----------------------------      violin system       ----------------------------------------
************************************************************************************************/
class Violin {
public:
  Violin();
  void playMidiNote(int midiNote, int velocity); // note On
  void stopMidiNote(int midiNote);// note off

private:
  int findString(int midiNote);// demande a chaque string si c'est jouable et assigne la note a la premiere corde dipo
  violinString* _strings[4];// tableaux des cordes 
};

#endif
