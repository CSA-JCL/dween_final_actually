const int motionPin = 2;
const int swap1 = 8;
const int swap2 = 9;
const int power = A1;
const int enable = 10;

// when 8 is high and 9 is low or vise versa it swaps.
// if both are the same, stop.
int duration = 0;

int state = LOW;


// Called when the simulation starts
void setup() 
{
  // Initiallize the LED and alarm to be off by default.
  // Also activate the serial console.
  Serial.begin(9600);
  
  
  
  pinMode(swap1, OUTPUT);
  pinMode(enable, OUTPUT);
  pinMode(swap2, OUTPUT);
  
  // Wait one second before proceeding
  delay(1000);
}

// Called repeatedly during the simulation run
void loop()
{
  // Set the sensor up to make sure it gives a 
  // reliable result by setting it LOW - HIGH - LOW with
  // a short delay between each.
 
  pinMode(motionPin, OUTPUT);
  digitalWrite(motionPin, LOW);
  delayMicroseconds(2);
  digitalWrite(motionPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(motionPin, LOW);
  pinMode(motionPin, INPUT);

  duration = 0;
  duration = pulseIn(motionPin, HIGH);
  
 
  // Send some debug info to the serial console
  Serial.println(duration);
  Serial.print("  ");
  
  
  int speed = analogRead(power);
  Serial.print(speed);
  Serial.print(" ");
  boolean reverse = digitalRead(motionPin); 
  setMotor(speed, reverse, duration); 
  
  

}
  // Check the sesnor for activity. By default this will timeout
  // after one second if there is no activity.
void setMotor(int speed, boolean reverse, int duration)
  
{
    delay(2000);
    if (duration < 1200 && duration > 5 ){
    analogWrite(enable, speed);
    digitalWrite(swap1, ! reverse);
    digitalWrite(swap2, reverse);
   
  } 
    if (duration > 1350){
    analogWrite(enable, speed);
    digitalWrite(swap1, reverse);
    digitalWrite(swap2, ! reverse); 
    
   
  
  }
  
    if (duration > 1900){
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


                                                                                                                                                                                                                                
