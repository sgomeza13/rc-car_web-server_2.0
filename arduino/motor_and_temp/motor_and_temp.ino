 int var;
int analog = A0;
int temp = 0;
String inputString = "";
boolean stringComplete = false;
// Motor A
int ENA = 7;
int IN1 = 6;
int IN2 = 5;

// Motor B
int ENB = 2;
int IN3 = 4;
int IN4 = 3;
void setup() {
  pinMode(analog, INPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  Serial.begin(9600);
  while(!Serial){
    ;
    }
    while(Serial.available()<=0){
      sendTemp();
      delay(500);
      }
}

void loop() {
  
  if(stringComplete){
    if(inputString.startsWith("status")){
      sendTemp();
    }
    else if(inputString.startsWith("set")){
      if (inputString.indexOf("on") > -1){
      digitalWrite(23,HIGH);
        digitalWrite (IN1, HIGH);
        digitalWrite (IN2, LOW);
        analogWrite (ENA, 255); //Velocidad motor A
        //Direccion motor B
        digitalWrite (IN3, HIGH);
        digitalWrite (IN4, LOW);
        analogWrite (ENB, 255);
      Serial.println("encendio el led");
      }
      else if(inputString.indexOf("off") > -1) {
            digitalWrite(23,LOW);
            digitalWrite(24,LOW);
            digitalWrite(25,LOW);
            digitalWrite(26,LOW);
            digitalWrite (IN1, LOW);
            digitalWrite (IN2, LOW);
            analogWrite (ENA, 0); //Velocidad motor A
            //Direccion motor B
            digitalWrite (IN3, LOW);
            digitalWrite (IN4, LOW);
            analogWrite (ENB, 0); 
      Serial.println("apago el led");
      }
      else if(inputString.indexOf("back") > -1) {
           digitalWrite(24,HIGH);
           digitalWrite (IN1, LOW);
            digitalWrite (IN2, HIGH);
            analogWrite (ENA, 255); //Velocidad motor A
            //Direccion motor B
            digitalWrite (IN3, LOW);
            digitalWrite (IN4, HIGH);
            analogWrite (ENB, 255);
            Serial.println("motor en reversa");
      }
      else if(inputString.indexOf("left") > -1){
          digitalWrite(25,HIGH);
            digitalWrite (IN1, LOW);
            digitalWrite (IN2, HIGH);
            analogWrite (ENA, 50); //Velocidad motor A
            //Direccion motor B
            digitalWrite (IN3, HIGH);
            digitalWrite (IN4, LOW);
            analogWrite (ENB, 255);
            Serial.println("motor hacia la izquierda");
      }
      else if(inputString.indexOf("rigth") > -1){
          digitalWrite(26,HIGH);
              digitalWrite (IN1, HIGH);
              digitalWrite (IN2, LOW);
              analogWrite (ENA, 255); //Velocidad motor A
              //Direccion motor B
              digitalWrite (IN3, LOW);
              digitalWrite (IN4, HIGH);
              analogWrite (ENB, 50); //Velocidad motor A
            Serial.println("motor hacia la derecha");
      }
      else {
        Serial.println("comando set invalido");
      }
    }
    else{
       Serial.println("comando invalido");
    }
    stringComplete = false;
    inputString = "";
  }
delay(10);
}

void sendTemp(){
  char buffer[50];
  temp = analogRead(analog);
  temp = (temp*500)/1023;
  sprintf (buffer, "%d", temp);
  Serial.println(buffer);
}

void serialEvent() {
  while (Serial.available()){
    char inChar = (char)Serial.read();
    inputString += inChar;
    if(inChar == '\n') {
      stringComplete = true;
      }
  }
}
