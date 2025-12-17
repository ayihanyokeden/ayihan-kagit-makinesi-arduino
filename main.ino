//BU KOD YAPAY ZEKADAN ALINMIŞTIR

#include <Servo.h>

Servo servo;

const int servoPin  = 6;
const int buttonPin = 22;
const int ledPin    = 13;
const int buzzerPin = 9;

bool calisti = false;   // tek basışta tek hareket

void setup() {
  servo.attach(servoPin);

  pinMode(buttonPin, INPUT_PULLUP); // buton GND'ye bağlı
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  servo.write(0);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Butona BASILINCA pin LOW olur
  if (digitalRead(buttonPin) == LOW && !calisti) {
    calisti = true;

    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1200, 200); // başlangıç bip

    // yavaş pres hareketi
    for (int pos = 0; pos <= 90; pos++) {
      servo.write(pos);
      delay(15);
    }

    delay(1000);

    for (int pos = 90; pos >= 0; pos--) {
      servo.write(pos);
      delay(15);
    }

    tone(buzzerPin, 800, 300); // bitiş bip
    digitalWrite(ledPin, LOW);
  }

  // Buton bırakılınca tekrar hazır
  if (digitalRead(buttonPin) == HIGH) {
    calisti = false;
  }
}

//BU KOD YAPAY ZEKADAN ALINMIŞTIR
