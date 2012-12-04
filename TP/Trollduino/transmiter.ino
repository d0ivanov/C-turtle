int input;
void setup()
{
 Serial.begin(9600);
}

void loop()
{
  if (Serial.available()) {
       input = Serial.read();
       Serial.write(input); 
  }
}
