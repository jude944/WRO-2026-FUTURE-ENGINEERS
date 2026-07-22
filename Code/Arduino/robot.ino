#include <Servo.h>

// ---------- Servo ----------
Servo steering;
#define servoPin 9

int straight = 90;
int rightTurn = 50;
int leftTurn = 130;


// ---------- Ultrasonic ----------
#define trigFront 2
#define echoFront 3

#define trigLeft A0
#define echoLeft A1

#define trigRight 12
#define echoRight 13



// ---------- Motor L298N ----------
#define ENA 5
#define IN1 7
#define IN2 8


int motorSpeed = 200;


// ---------- Laps ----------
int corners = 0;
bool turning = false;


// --------------------------------
void setup() {

  Serial.begin(9600);

  steering.attach(servoPin);
  steering.write(straight);


  pinMode(trigFront, OUTPUT);
  pinMode(echoFront, INPUT);

  pinMode(trigLeft, OUTPUT);
  pinMode(echoLeft, INPUT);

  pinMode(trigRight, OUTPUT);
  pinMode(echoRight, INPUT);


  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);


  stopMotor();
  delay(1000);

}


// --------------------------------
void loop() {


  if(corners >= 12)
  {
    stopMotor();
    steering.write(straight);

    while(true);
  }



  int front = distance(trigFront, echoFront);
  int left = distance(trigLeft, echoLeft);
  int right = distance(trigRight, echoRight);



  Serial.print("F:");
  Serial.print(front);
  Serial.print(" L:");
  Serial.print(left);
  Serial.print(" R:");
  Serial.print(right);
  Serial.print(" Corners:");
  Serial.println(corners);



  // يوجد زاوية
  if(front < 20 && turning == false)
  {

    turning = true;
    corners++;


    // يختار اتجاه اللفة
    if(right > left)
    {
      steering.write(rightTurn);
    }
    else
    {
      steering.write(leftTurn);
    }


    delay(700);

    steering.write(straight);

    delay(300);

    turning = false;

  }



  else
  {

    // تصحيح المسار
    if(right < 15)
    {
      steering.write(leftTurn);
    }

    else if(left < 15)
    {
      steering.write(rightTurn);
    }

    else
    {
      steering.write(straight);
    }


    forward();

  }

}



// ---------- Distance ----------
int distance(int trig, int echo)
{

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);


  long time = pulseIn(echo,HIGH,20000);


  if(time == 0)
    return 200;


  return time * 0.034 / 2;

}



// ---------- Motor Forward ----------
void forward()
{

  analogWrite(ENA,motorSpeed);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

}



// ---------- Motor Stop ----------
void stopMotor()
{

  analogWrite(ENA,0);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);

}
