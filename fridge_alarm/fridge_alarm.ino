const int speakerPin = 8; //output for speaker
const int lightSensorPin = A0; // Input for the photoresistor
const int ledPin = 13;

//Note you dont need to call pinMode for tone() and analog () pins

const int fridgeThreshold = 400; // Photocell value for an open fridge

void setup()
{ 
    pinMode (ledPin, OUTPUT); // Allow us to turn the Arduino's onboard LED on 
    //pinMode (lightSensorPin, INPUT);
    Serial.begin (9600);
    
    while (millis() < 10000) // wait ten seconds so you can set up the device
    
    { 
      digitalWrite (ledPin, HIGH); // Flash the board's LED to provide some feedback that the circuit is working
      delay (100);
      digitalWrite(ledPin, LOW);
      delay (100);
    }
}

void loop()
{
  if (analogRead(lightSensorPin) > fridgeThreshold) // Read the light sensor to see if the fridge is open
    { 
      Serial.print("true ");
      Serial.print(analogRead(lightSensorPin));
      Serial.print('\n');
      for (int i = 500; i < 600; i++) // Change start value and end value to change siren length and pitch
        {
          tone (8, i); // Play the tone to the speaker on pin 8
          delay (10); // change delay to change siren speed. try delayMilliseconds () too
        }
    } else {
  noTone (8);
  Serial.print("false "); // for debugging purposes
  Serial.print(analogRead(lightSensorPin));
  Serial.print('\n');
    }
  
}
            
