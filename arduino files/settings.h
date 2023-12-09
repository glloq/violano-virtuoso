#ifndef SETTINGS_H
#define SETTINGS_H
#include "stdint.h"

#define DEBUG 1

//*********************arduino micro pro
//i2c SDA: pin 2 SDl: pin 3

constexpr int SERVO_PLAY_OPEN_ANGLE=10;
constexpr int SERVO_PLAY_MIN_ANGLE={20,20,20,20};        // angle servo pour avoir la roue d'arc contre la corde
constexpr int SERVO_PLAY_MAX_ANGLE=5;                   // angle max servo contre la corde


constexpr int OPEN_STRING_NOTE[4]= {55, 62, 69, 76}; //base accordage ukulele (numero midi a vide pour les 4 cordes)
constexpr int FINGERS_PER-STRING={12,12,14,22};

constexpr int SERVO_ANGLE_FINGERS_STRINGS={
	{90,90,90,90,90,90,90,90,90,90,90,90},
	{90,90,90,90,90,90,90,90,90,90,90,90},
	{90,90,90,90,90,90,90,90,90,90,90,90,90,90},
	{90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90}
};

#endif
