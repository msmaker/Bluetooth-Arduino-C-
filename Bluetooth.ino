#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11);//TX, RX (Bluetooth)

#define led1 3
#define led2 4
#define led3 5

String comando;
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

}

void loop() {
  comando = "";

  if (bluetooth.available()) {
    while (bluetooth.available()) {
      char caracter = bluetooth.read();

      comando += caracter;
      delay(3);
    }
    //bluetooth.print("Comando: ");
    //bluetooth.println(comando);
    if (comando.indexOf("led1") >= 0) {
      Serial.println("Ligar/Desligar led1");
      digitalWrite(led1, !digitalRead(led1));
    }

     bluetooth.print("{");

    if (comando.indexOf("led2") >= 0) {
      Serial.println("Ligar/Desligar led2");
      digitalWrite(led2, !digitalRead(led2));
    }

    if (comando.indexOf("led3") >= 0) {
      Serial.println("Ligar/Desligar led3");
      digitalWrite(led3, !digitalRead(led3));
    }

    if (digitalRead(led1)) {
      bluetooth.println("l1on");
    } else {
      bluetooth.println("l1of");
    }

    if (digitalRead(led2)) {
      bluetooth.println("l2on");
    } else {
      bluetooth.println("l2of");
    }

    if (digitalRead(led3)) {
      bluetooth.println("l3on");
    } else {
      bluetooth.println("l3of");
    }
    bluetooth.print("}");

  }
}
