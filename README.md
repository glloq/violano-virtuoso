# violano-virtuoso

projet pour faire un systeme inspiré du systeme de violano virtuoso avec un arduino de type leonardo.

Nous utiliserons le meme type de systeme pour controller l'instrument : 
- les doigts pour les cordes (actioné par servomoteur)
- le moteur pour actionner les archet a roue (nous commencerons avec un moteur pas a pas mais il faut aussi etudier l'utilisation d'un moteur cc avec variation de vitesse)
- les servomoteur pour actionner les archets a roue
- optionel : ajout d'un servomoteur pour le vibrato (=> utiliser le moteur ?) 

# schema de principe :
![schemas project](https://raw.githubusercontent.com/glloq/violano-virtuoso/main/img/violano%20virtuoso%20midi%20-%20Copie.png)

# messages midi reconnu :

Nous commencerons par les messages midi classique tel que :
- noteOn : 0x90
- noteOff : 0x80

Puis nous ajouterons petit a petit la gestion d'autres messages adapté au violon :
- Pitch Bend :0xE0
- Channel Pressure (Aftertouch) :0xA0
- Polyphonic Key Pressure :0xD0
- Control Change :0xB0
  - 1| Modulation Wheel: Gère le contrôle de la modulation, par exemple, le vibrato.
  - 7| Volume: Contrôle le niveau de volume du son.
  - 11| Expression Controller: Contrôle général de l'expression musicale.
  - 75| Sound Controller 6 (default: Decay Time).
  - 76| Sound Controller 7 (default: Vibrato Rate).
  - 77| Sound Controller 8 (default: Vibrato Depth).
  - 78| Sound Controller 9 (default: Vibrato Delay).
  - 120| All Sound Off: Désactive tous les sons.
  - 121| Reset All Controllers: Réinitialise tous les contrôleurs.
  - 123| All Notes Off: Désactive toutes les notes.
