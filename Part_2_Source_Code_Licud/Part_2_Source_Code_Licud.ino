int ledArray[5] = {4, 6, 8, 10, 12};	
int analogPin = 3;	                	//Set the analog pin number as an integer
int analogPinValue;	                	//Variable to hold the analog pin value

void setup(){
  for(int i = 0; i < 5; i++){	        
    pinMode(ledArray[i], OUTPUT);		//Set all the digital pins used as output
  }
  pinMode(analogPin, INPUT);	                //Set the analog pin as input
  Serial.begin(9600);	        	        //Statement to be able to use the serial monitor (baud)
}

/*Method that lights up the LED. The parameter light count is used to determine how many LEDs will be lit up.*/

void LEDLightSequence(int lightCount){		        
    for(int i = 0; i < lightCount; i++){		                        	
      digitalWrite(ledArray[i], HIGH);	        
    }	                                        	                                
  }	
  
/*Method that will switch off every LEDs*/

void LEDOff(){
  for(int i = 0; i < 5; i++){	
    digitalWrite(ledArray[i], LOW);	
  }
}

/* Determine the value of analog pin in digital format (0 – 1023) and determine, by using current value, how many LED’s to light up. 
The LEDlightSequence() is then called and given the number of LED’s to light up as the parameter. LEDOff() is called to make 
sure all the LED’s are switched off when value of analogPinValue is decreasing. Then switch it on with the correct (lower) amount of LED’s*/

void loop(){
  analogPinValue = analogRead(analogPin);	
  
  if(analogPinValue > 0 && analogPinValue <= 204){	
    LEDOff();
    LEDLightSequence(1);
  }
  else if(analogPinValue > 204 && analogPinValue <= 409){
    LEDOff();
    LEDLightSequence(2);
  }
  else if(analogPinValue > 409 && analogPinValue <= 613){
    LEDOff();
    LEDLightSequence(3);
  }
  else if(analogPinValue > 613 && analogPinValue <= 818){
    LEDOff();
    LEDLightSequence(4);
  }
  else if(analogPinValue > 818 && analogPinValue <= 1023){
    LEDLightSequence(5);
  }
  else{
    LEDOff();
  }
  Serial.println(analogPinValue);         //Print analogPinValue to monitor (for monitoring digital values)  
}

