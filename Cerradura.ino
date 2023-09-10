#include <SPI.h>
#include <MFRC522.h>

// Buzzer
#define Buz 2
// Portón
#define Por 4

//Pines RFID
#define RST_PIN 9
#define SS_PIN 10

MFRC522 reader(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

// Asignamos los valores de los llaveros RFID
String CardNumber = "xxxxxxxx - xxxxxxxx";

void setup()
{
  // Definimos la función de los pines
  pinMode(Buz, OUTPUT);  
  pinMode(Por, OUTPUT);

  Serial.begin(9600); // Configuramos el puerto serie

  SPI.begin();

  reader.PCD_Init();

  delay(4);
  
  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF;
  }
  
  // Definimos los estados iniciales de las salidas
  digitalWrite(Buz, LOW); 
  digitalWrite(Por, LOW);

  Serial.println(CardNumber);
  delay(2000);
}

void loop()
{
  // Si no hay tarjeta presente reseteamos el loop
  if (!reader.PICC_IsNewCardPresent())
  {
    return;
  }

  // Si se lee de forma incorrecta se resetea el loop
  if (!reader.PICC_ReadCardSerial())
  {
    return;
  }

  // Transformamos de byte a hex

  String serial = "";
  for (int x = 0; x < reader.uid.size; x++)
  {
    // Si es menor que 10 sumamos 0
    if (reader.uid.uidByte[x] < 0x10)
    {
      serial += "0";
    }
    // Transformamos de byte a hex
    serial += String(reader.uid.uidByte[x], HEX);
    // Añadimos un caracter en blanco
    if (x + 1 != reader.uid.size)
    {
      serial += "";
    }
  }
  // Transformamos a mayúsculas
  serial.toUpperCase();
  //Mostramos por pantalla el resultado
  Serial.println("Read serial is: " + serial);

  // Detenemos PICC
  reader.PICC_HaltA();
  // Detenemos el cifrado en PCD
  reader.PCD_StopCrypto1();

  if (CardNumber.indexOf(serial) >= 0) {
    // Encendemos el buzzer
    emitirPitido(1);

    // Apagamos el electroimán para permitir el ingreso
    digitalWrite(Por, HIGH);
    delay(1500);

  }
  else {    
    //Emitimos 3 pitidos para avisar de un error en la lectura de la tarjeta
    emitirPitido(3);
  }

  // Apagamos el buzzer
  digitalWrite(Buz, LOW);

  // Encendemos el electroimán
  digitalWrite(Por, LOW);
  delay(500);
}

// Función para emitir un pitido en el buzzer
void emitirPitido(int cantidad) {
  if(cantidad == 1)
    digitalWrite(Buz, HIGH);
  else
    for (int i = 0; i < cantidad; i++) {
      digitalWrite(Buz, HIGH);
      delay(100);
      digitalWrite(Buz, LOW);
      delay(100);
    }
}