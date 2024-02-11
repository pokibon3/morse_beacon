#include "morse.h"
#include "play.h"


Morse m1;

void setup()
{
    delay(1000);
    m1.begin();
    m1.morse_str("HI");
    delay(2000);
}

void loop()
{
    m1.morse_str("VVV DE JA9OIR");
    delay(2000);
    play("o5l4cdercdergedcdedr");
    delay(2000);
}

