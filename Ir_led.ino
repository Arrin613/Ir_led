
#include <IRremote.h>

int RECV_PIN = 11;

int codeON = 1236334117;
int codeOFF = 1253111734;

int code;

int LED = 13;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(LED, OUTPUT); digitalWrite(LED, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    code = results.value, DEC;
    irrecv.resume(); // Receive the next value
  }

  if (code == codeON)
    digitalWrite(LED, HIGH);
  else if (code == codeOFF)
    digitalWrite(LED, LOW);

  delay(100);
}
