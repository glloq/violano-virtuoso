#ifndef ViolinString_h
#define ViolinString_h

#include "Arduino.h"
#include "Servo.h"
#include "Wire.h"

#include "settings.h"
/***********************************************************************************************
----------------------------  STRING  ----------------------------------------
l'objectif est d'avoir un objet qui controle la corde, c'est a dire chaque fretes et le "frottage" avec une certaine velocité
controle de 12 a 21 accords sur la corde et 1 servo pour descendre la roue sur la corde.




************************************************************************************************/
class ViolinString {
public:
    ViolinString(int servoPin,  Adafruit_PWMServoDriver pwm[], int baseMidiNote, int numOfNotes);
	
    void playNote(int note, int velocity);
    void stopNote(int note);

    int getCurrentMidiNote();         	// renvoi la note midi en cours
    bool isPlayable(int MidiNote);    	// fct qui dit si la corde peut jouer une note

private:
    Adafruit_PWMServoDriver pwm[];     	// adresse i2c du ou des deux pca pour les doigtsde la corde 
	int angleFingerPlay[];				//angle des servo de la corde pour actionner le doigt contre la corde => recupéré dans settigns

    Servo servoPlay;                  	// servo frottement de la corde


    bool isPlaying;                     // stoque si une note est en cours sur la corde
    int currentMidiNote;               	// note en cours 
    int baseMidiNote;                  	// note corde a vide 
    int numOfNotes;                    	//  nombre de notes/frettes/electroaimants sur la corde

    bool isActive();                   	// renvoi true si il y a une note en cours sur la corde 
    void activateFret(int numServo);     // active la frette
    void desactivateFret(int numServo);  // desactive la frette en cours
    void servoPlay(int velocity);      	// descend le servo en contact avec la corde 
	
};

#endif
