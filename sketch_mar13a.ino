
int trigPin = 4;
int echoPin = 3;

int led = 2;
int buzzer = 5;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  
  distance = ((duration/2) / 29.1);     
  digitalWrite(led, LOW);
  if(distance < 50){
    delay(1);
    digitalWrite(led, HIGH);        
    tone(buzzer, 1000);    
    delay(1000);    
    noTone(buzzer);            
  }       
  delay(500); 
}



