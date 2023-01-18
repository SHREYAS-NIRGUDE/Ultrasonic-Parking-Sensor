// C++ code by SHREYAS 
// defines pins numbers
const int trigPin = 10;
const int echoPin = 11;
const int buzzer = 3;
const int redledPin = 9;
const int blueledPin = 6;
const int greenledPin = 5;



// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(redledPin, OUTPUT);
pinMode(blueledPin, OUTPUT);
pinMode(greenledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {

// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
  
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 50&& safetyDistance>=2){
    digitalWrite(blueledPin, LOW);
    digitalWrite(greenledPin, LOW);
    digitalWrite(redledPin, HIGH);
    digitalWrite(buzzer,HIGH);
    
}
else if (safetyDistance <= 150 && safetyDistance>50){
  digitalWrite(blueledPin, LOW);
  digitalWrite(greenledPin, HIGH);
    digitalWrite(redledPin, LOW);
    digitalWrite(buzzer,LOW);
}
else if (safetyDistance <=322 && safetyDistance>155){
  digitalWrite(blueledPin, HIGH);
    digitalWrite(greenledPin, LOW);
    digitalWrite(redledPin, LOW);
    digitalWrite(buzzer,LOW);
}
else{
    digitalWrite(redledPin, LOW);
    digitalWrite(blueledPin, LOW);
    digitalWrite(greenledPin, LOW);
    digitalWrite(buzzer,LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
