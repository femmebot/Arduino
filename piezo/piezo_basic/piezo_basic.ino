/* piezo sketch
 * lights an LED when the Piezo is tapped
 */

const int sensorPin = A0;  // the analog pin connected to the sensor
const int ledPin  = 13;     // pin connected to LED
const int THRESHOLD = 800;


void setup()
{
   pinMode(ledPin, OUTPUT);
   Serial.begin (9600);
}

void loop()
{
  int val = analogRead(sensorPin);
  if (val >= THRESHOLD)
  {
    digitalWrite(ledPin, HIGH);
    delay(1000);  // to make the LED visible
    Serial.print("true ");
    Serial.print(analogRead(sensorPin));
    Serial.print('\n');
  }
  else
    digitalWrite(ledPin, LOW);
    Serial.print("false ");
    Serial.print(analogRead(sensorPin));
    Serial.print('\n');
}
      
    
