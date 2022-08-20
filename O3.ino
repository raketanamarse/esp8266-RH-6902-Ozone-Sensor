#include <SoftwareSerial.h>
#define RXD2 D1
#define TXD2 D2
#define DE_RE D3

SoftwareSerial S(RXD2, TXD2); //   (RX , TX)

byte ByteArray[250];
int ByteData[20];

void setup() {
  Serial.begin(74880);
  while (!Serial) { }// ожидаем подключения к последовательному порту.
  pinMode(DE_RE, OUTPUT);
  S.begin(9600, SWSERIAL_8N1);

}

void loop() {
    delay(2000); 
  byte msg[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};
  int len = 8;


  digitalWrite(DE_RE, 1); 
  
  Serial.println("SEND DATA:");
  for (int i = 0 ; i < len ; i++) {
    S.write(msg[i]);
    Serial.print("[");
    Serial.print(i);
    Serial.print("]");
    Serial.print("=");
    Serial.print(String(msg[i], HEX));
    Serial.print(" ");
  }
  Serial.println();
  Serial.println();


  digitalWrite(DE_RE, 0); 

  int a = 0;
  while (S.available())
  {
    ByteArray[a] = S.read();
    a++;
  }

  String registros;
  Serial.println("DATA RECEPTION");
  for (int b = 0 ; b < a ; b++) {
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

                     
}
