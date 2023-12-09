 #include "midiHandler.h"

MidiHandler::MidiHandler(Instrument &instrument) : _instrument(instrument) {
   if (DEBUG) {
        Serial.println("DEBUG : midiHandler--creation");
    } 
}

void MidiHandler::readMidi() {
  midiEventPacket_t midiEvent;
  do {
    midiEvent = MidiUSB.read();
    if (midiEvent.header != 0) {
      processMidiEvent(midiEvent);
    }
  } while (midiEvent.header != 0);
}

void MidiHandler::processMidiEvent(midiEventPacket_t midiEvent) {
  byte messageType = midiEvent.byte1 & 0xF0;
  byte channel = midiEvent.byte1 & 0x0F;
  byte note = midiEvent.byte2;
  byte velocity = midiEvent.byte3;
  int pitchBendValue = (midiEvent.byte3 << 7) | midiEvent.byte2;
  int channelPressureValue = midiEvent.byte2;
  int polyKeyPressureValue = midiEvent.byte3;

  switch (messageType) {
    case 0x90: // Note On
      if (velocity > 0) {
        _instrument.noteOn(note, velocity);
      } else {
        // Note Off
        _instrument.noteOff(note);
      }
      break;
    case 0x80: // Note Off
      _instrument.noteOff(note);
      break;
    case 0xE0: // Pitch Bend
      //_instrument.pitchBend(channel, pitchBendValue);
      break;
    case 0xA0: // Channel Pressure (Aftertouch)
      //_instrument.channelPressure(channel, channelPressureValue);
      break;
    case 0xD0: // Polyphonic Key Pressure
      //_instrument.polyKeyPressure(note, polyKeyPressureValue);
      break;
    case 0xB0: // Control Change
      processControlChange(channel, note, velocity);
    case 0xF0: // System Common or System Real-Time
      // Add logic for handling System Common and System Real-Time messages
      break;
    case 0xF7: // End of System Exclusive
      // Add logic for handling the end of System Exclusive message
      break;
    // Add more cases as needed for other message types
  }
}
/*------------------------------------------------------------------
--------------        process Control Change             ----------
------------------------------------------------------------------
 Tableau des Control Change (CC)
 Chaque ligne représente un CC avec son numéro et sa description
CC | Description
---|---------------------------------------------------
  1| Modulation Wheel: Gère le contrôle de la modulation, par exemple, le vibrato.
  2| Breath Controller: Contrôle la pression du souffle sur un contrôleur MIDI.
  3| Undefined.
  4| Foot Controller: Contrôle associé au pied, comme une pédale d'expression.
  5| Portamento Time: Contrôle la vitesse du portamento entre les notes.
  6| Data Entry MSB: MSB pour la valeur de données entrantes (utilisé avec CC 38).
  7| Volume: Contrôle le niveau de volume du son.
  8| Balance: Contrôle la balance entre les canaux gauche et droit.
  9| Undefined.
 10| Pan: Contrôle la position panoramique du son dans l'espace stéréo.
 11| Expression Controller: Contrôle général de l'expression musicale.
 12| Effect Control 1: Contrôle d'effet configurable par l'utilisateur.
 13| Effect Control 2: Contrôle d'effet configurable par l'utilisateur.
 14-31| Réservé pour une utilisation future.
 32| Bank Select MSB: MSB pour la sélection de la banque d'instruments (utilisé avec CC 0).
 33| Modulation Wheel MSB: MSB pour le contrôle de la modulation.
 34| Breath Controller MSB: MSB pour le contrôle de la pression du souffle.
 35| Undefined.
 36| Foot Controller MSB: MSB pour le contrôle associé au pied.
 37| Portamento Time MSB: MSB pour la vitesse du portamento.
 38| Data Entry LSB: LSB pour la valeur de données entrantes (utilisé avec CC 6).
 39| Volume MSB: MSB pour le contrôle du volume.
 40| Balance MSB: MSB pour le contrôle de la balance.
 41| Undefined.
 42| Pan MSB: MSB pour le contrôle de la position panoramique.
 43| Expression Controller MSB: MSB pour le contrôle de l'expression.
 44| Effect Control 1 MSB: MSB pour le contrôle d'effet configurable par l'utilisateur.
 45| Effect Control 2 MSB: MSB pour le contrôle d'effet configurable par l'utilisateur.
 46-63| Réservé pour une utilisation future.
 64| Hold Pedal (Sustain): Active ou désactive la pédale de maintien (pédale de sustain).
 65| Portamento On/Off: Active ou désactive la fonction de portamento entre les notes.
 66| Sustenuto Pedal: Active ou désactive la pédale de soutien (sustenuto).
 67| Soft Pedal: Active ou désactive la pédale douce (soft pedal).
 68| Legato Footswitch: Active ou désactive le mode legato.
 69| Hold 2 Pedal: Deuxième fonction de la pédale de maintien.
 70| Sound Controller 1 (default: Sound Variation).
 71| Sound Controller 2 (default: Timbre/Harmonic Content).
 72| Sound Controller 3 (default: Release Time).
 73| Sound Controller 4 (default: Attack Time).
 74| Sound Controller 5 (default: Brightness).
 75| Sound Controller 6 (default: Decay Time).
 76| Sound Controller 7 (default: Vibrato Rate).
 77| Sound Controller 8 (default: Vibrato Depth).
 78| Sound Controller 9 (default: Vibrato Delay).
 79-95| Réservé pour une utilisation future.
 96| Data Increment: Augmente la valeur de données.
 97| Data Decrement: Diminue la valeur de données.
 98| Non-Registered Parameter Number LSB.
 99| Non-Registered Parameter Number MSB.
100| Registered Parameter Number LSB.
101| Registered Parameter Number MSB.
102-119| Réservé pour une utilisation future.
120| All Sound Off: Désactive tous les sons.
121| Reset All Controllers: Réinitialise tous les contrôleurs.
122| Local Control On/Off: Active ou désactive le contrôle local du clavier.
123| All Notes Off: Désactive toutes les notes.
124| Omni Mode Off: Désactive le mode Omni (réception sur un seul canal MIDI).
125| Omni Mode On: Active le mode Omni (réception sur tous les canaux MIDI).
126| Mono Mode On: Active le mode Mono (réception monophonique).
127| Poly Mode On: Active le mode Poly (réception polyphonique).
128| Réservé pour une utilisation future.
---|---------------------------------------------------
*/

void MidiHandler::processControlChange(byte channel, byte controller, byte value) {
  // Add logic for handling Control Change messages
  // You can switch on the controller value to handle specific control changes
  switch (controller) {
     case 1:
    case 91:
    case 92:
    case 94: // Gestion du vibrato
      //_instrument.modulationWheel(channel, value);
      break;
    case 0x07: // Volume
      //_instrument.volumeControl(channel, value);
      break;
    case 121: // Réinitialisation de tous les contrôleurs
      //_instrument.reset();
      break;
    case 123: // Désactiver toutes les notes
      //_instrument.mute();
      break;
    // Add more cases as needed for other control changes
  }
}
