//first of all we will use the  TMP36 which is a temperature sensor that outputs
//a voltage that's proportional to the ambient temperature.

// We'll use analog input 0 to measure the temperature sensor's signal pin.
const int temperaturePin = 0; //the declaration of the variable
const int buzzer = 12; //we will connect the buzzer to D12 on the arduino

void setup()
{
  //pinMode(13, OUTPUT);//for the on-chip LED
  pinMode(buzzer, OUTPUT);//set the pin connected to the buzzer as an output
}

void loop()
{
  //For on-chip LED
  /*digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  */
  	//for buzzer and tmp36 temp sensor
 	float voltage, degreesC;
  	voltage = getVoltage(temperaturePin);
	degreesC = (voltage - 0.5) * 100.0;

  digitalWrite(buzzer,LOW);  
  	delay(500);  //delay half a second       
  	tone(12, 10000, 100);
  	if(degreesC>37)
  	{
  	digitalWrite(buzzer, LOW);    
  	delay(500);  //delay half a second           
  	tone(12, 10000, 100);
  	}
  
}
float getVoltage(int pin)
{
  
  return (analogRead(pin) * 0.004882814);
}
