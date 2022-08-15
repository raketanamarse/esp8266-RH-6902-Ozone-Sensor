#include <SoftwareSerial.h>
#define RXD2 D7
#define TXD2 D8
#define DE_RE D6

SoftwareSerial S(RXD2, TXD2); //   (RX , TX)

byte ByteArray[250];
int ByteData[20];

void setup() {
  Serial.begin(9600);
  S.begin(9600, SWSERIAL_8N1);
  pinMode(DE_RE, OUTPUT);
}

void loop() {


  byte msg[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};
  int len = 8;


  digitalWrite(DE_RE, 1); 
  
  Serial.println("SEND DATA");
  for (int i = 0 ; i < len ; i++) {
    S.write(msg[i]);
    Serial.print("[");
    Serial.print(i);
    Serial.print("]");
    Serial.print("=");
    Serial.print(String(msg[i], HEX));
  }
  len = 0;
  Serial.println();
  Serial.println();


  digitalWrite(DE_RE, 0); 

  int a = 0;
  while (S.available())
  {
    ByteArray[a] = S.read();
    a++;
  }

  int b;
  String registros;
  Serial.println("DATA RECEPTION");
  for (b = 0 ; b < a ; b++) {
    Serial.print("[");
    Serial.print(b);
    Serial.print("]");
    Serial.print("=");

    registros = String(ByteArray[b], HEX);
    Serial.print(registros);
    Serial.print(" ");
  }
  Serial.println();
  Serial.println(); 
  
  float O3 = 0;
  O3 = float(ByteArray[3]) * 256;
  O3 += float(ByteArray[4]);
  Serial.println(O3);

  delay(2000);                      


}
