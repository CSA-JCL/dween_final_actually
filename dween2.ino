const int motionPin = 2; //sets values of pins 
const int swap1 = 8;
const int swap2 = 9;
const int power = A1;
const int enable = 10;

// when 8 is high and 9 is low or vise versa it swaps.
// if both are the same, stop.
int duration = 0; //sets duration as an integer so that it may be changed later

void setup() 
{
  // Initiallize the LED and alarm to be off by default.
  // Also activate the serial console.
  Serial.begin(9600); //starts the serial tab so that we can see the value of duration 
  
  
  
  pinMode(swap1, OUTPUT); //sets important pins to output mode 
  pinMode(enable, OUTPUT);
  pinMode(swap2, OUTPUT);
  
  // Wait one second before proceeding
  delay(1000);
}

// Called repeatedly during the simulation run
void loop()
{
  
 
  pinMode(motionPin, OUTPUT); //changes more pins mode to output 
  digitalWrite(motionPin, LOW); //runs a check where it flickers the power on and off to make sure it works 
  delayMicroseconds(2);
  digitalWrite(motionPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(motionPin, LOW);
  pinMode(motionPin, INPUT);

  duration = 0; //sets up duration within the function 
  duration = pulseIn(motionPin, HIGH); //tells us that duration is equal to the value that the pin is getting
  
 
  // Send some debug info to the serial console
  Serial.println(duration); //shows said value on the console 
  Serial.print("  ");
  
  
  int speed = analogRead(power); //sets up the value for speed which is one of the values needed to get the door to open or shut 
  Serial.print(speed); // prints it in the console to debug 
  Serial.print(" ");
  boolean reverse = digitalRead(motionPin); // sets up reverse which allows us to switch the mode 
  setMotor(speed, reverse, duration); //passes those values to a function 
  
  

}
  // Check the sesnor for activity. By default this will timeout
  // after one second if there is no activity.
void setMotor(int speed, boolean reverse, int duration)
  
{
    delay(2000);
    if (duration < 1200 && duration > 5 ){ //if the sensor senses stuff close enough, it opens 
    analogWrite(enable, speed);
    digitalWrite(swap1, ! reverse);
    digitalWrite(swap2, reverse);
   
  } 
    if (duration > 1350){ //if not it shuts 
    analogWrite(enable, speed);
    digitalWrite(swap1, reverse);
    digitalWrite(swap2, ! reverse); 
    
   
  
  }
  
    if (duration > 1900){ //if stuff is very far away, it turns off 
    analogWrite(enable, 0);
    digitalWrite(swap1, reverse);
    digitalWrite(swap2, reverse);
    
  }

}


  
 /* // If motion was detected sound the alarm!
  state1 = LOW;
  state2 = LOW;
  if (duration < 3000) //greater duration = greater distance, too much and it will always be on. To little and it'll never turn on.
  {
    state = HIGH;
    state = LOW;
  }?????????????????..
 
  digitalWrite(openPin, state);
}              










 */


                                                                                                                                                                                                                                
