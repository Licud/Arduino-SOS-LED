int ledArray[5] = {4, 6, 8, 10, 12};	//Array declaration of pins to be used
int switchPin = 2;	                //Declaration of pin to be used with the switch
int switchPinValue;	                //Variable to hold the value of pin 2

void setup(){
  for(int i = 0; i < 5; i++){	        //For loop that cycles through the ledArray
    pinMode(ledArray[i], OUTPUT);	//and sets them all as OUTPUT pins*/
  }
  pinMode(switchPin, INPUT);	        //Sets the switch pin as input
}
/*below is the method that runs the sequence.  
Parameters are time that will be used for the delay, steps that indicate 
the number of times a certain sequence should loop, i.e. an 800 millisecond
delay needs to loop 3 times, and the light count that specifies how many of the 
5 LED’s are to be lit up. */

void LEDLightSequence(int time, int steps, int lightCount){	
  for(int i = 0; i < steps; i++){	        //For loop for number of steps
    for(int i = 0; i < lightCount; i++){	//For loop for number of lights
      delay(time);	                        //Delay based on the time given
      digitalWrite(ledArray[i], HIGH);	        //Send a high (5v) signal to the element of array in question
    }	                                        //End for loop for light count 
   LEDOff();	                                //Call the LEDOff function
  }	
}

/*below is the method that “switches off” all the LED’s by going 
through the led array and giving each one a 0v signal. */

void LEDOff(){
  for(int i = 0; i < 5; i++){	
    digitalWrite(ledArray[i], LOW);	
  }
}

void loop(){
  switchPinValue = digitalRead(switchPin);	//Set the switchPinValue with switchPin’s input

  if(switchPinValue == HIGH){	                //Test if switchPin’s value is high
    LEDLightSequence(800, 3, 6);	        //LEDLightSequence function: 800 milliseconds, 3 steps, 5 LEDs
    delay(1000);	                        //Delay for 1 s econd
    LEDLightSequence(400, 3, 6);	        //LEDLightSequence function: 400 milliseconds, 3 steps, 5 LEDs
    delay(1000);	                        //Delay for 1 second
  }
  else{
    LEDOff();	                                //LEDOff function if switchPinValue is anything other than HIGH
  }
}

