


int seg;
int led = 29;
// Motor A
int ENA = 7;
int IN1 = 6;
int IN2 = 5;

// Motor B
int ENB = 2;
int IN3 = 4;
int IN4 = 3;

int sensor = A1;
float temperatura;
int echo = 23;
int trigger = 22;
void setup() {

  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (led, OUTPUT);
  pinMode (sensor, INPUT);
  Serial.begin(9600);
  pinMode(trigger, OUTPUT); 
  pinMode(echo, INPUT);  
  digitalWrite(trigger, LOW);
}


void Adelante ()
{
  Serial.println("ADELANTE");
  //Direccion motor A
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 255); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 255); //Velocidad motor B
}

void Parar ()
{
  Serial.println("PARAR");
  //Direccion motor A
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, 0); //Velocidad motor A
    //Direccion motor B
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, LOW);
    analogWrite (ENB, 0); //Velocidad motor A
}
void Atras ()
{
  Serial.println("ATRAS");
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, 255); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, 255); //Velocidad motor B
}

void Izquierda ()
{
  Serial.println("IZQ");
  //Direccion motor A
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);
    analogWrite (ENA, 50); //Velocidad motor A
    //Direccion motor B
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, LOW);
    analogWrite (ENB, 255); //Velocidad motor A
}
void Derecha ()
{
  Serial.println("DER");
  //Direccion motor A
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 255); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, 100); //Velocidad motor A
}
// put your main code here, to run repeatedly:
void loop ()
{
analogWrite(ENB,255);
digitalWrite(IN3,HIGH);

  
  
}
