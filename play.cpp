#include <Arduino.h>
#include "pitches.h"

const int speakerPin  = PA8;
int defaultDuration   = 500;
int defaultOctave     = 4;

static int getNoteFrequency(char note, int octave) {
    char notes[] = "cdefgabC";
    int frequencies[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
    int noteIndex = strchr(notes, tolower(note)) - notes;

    if (noteIndex >= 0 && octave >= 4 && octave <= 5) {
      return frequencies[noteIndex] * pow(2, octave - 4);
    }

  return -1; // 無効な音符またはオクターブ
}

void play(const char *mml) {
    int duration = defaultDuration;
    int octave = defaultOctave;
  
    for (int i = 0; mml[i] != '\0'; i++) {
        char note = mml[i];
        int noteDuration = duration;
      
        // オクターブの変更
        if (note == 'o') {
            octave = mml[++i] - '0';
            continue;
        }
      
        // 音符の持続時間の変更
        if (note == 'l') {
            noteDuration = 1000 / (mml[++i] - '0');
            continue;
        }
      
        // 休符
        if (note == 'r') {
            delay(noteDuration);
            continue;
        }

        // 音符の再生
        int frequency = getNoteFrequency(note, octave);
        if (frequency != -1) {
            tone(speakerPin, frequency, noteDuration);
            delay(noteDuration); 
        }
    }
}


