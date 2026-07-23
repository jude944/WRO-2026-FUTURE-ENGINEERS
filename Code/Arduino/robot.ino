#include <Servo.h>

// ---------- Servo ----------
Servo steering;
#define servoPin 9

int straight = 90;
int rightTurn = 180;  // اتجاه اليمين
int leftTurn = 0;     // اتجاه اليسار

// ---------- Distances Config ----------
int frontDistanceTrigger = 40; // مسافة كشف المنعطف
int emergencyDistance = 15;    // مسافة الخطر للرجوع للخلف


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

// اعدادات السرعة الموزونة
int motorSpeed = 140;    // سرعة السير المستقيم (هادئة للتحكم)
int turnSpeed = 240;     // سرعة عالية جداً عند الالتفاف (تزيد السرعة فوراً)
int backwardSpeed = 220; // سرعة قوية للرجوع للخلف

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

}


// --------------------------------
void loop() {

  // قراءة المسافات من الحساسات
  int front = distance(trigFront, echoFront);
  int left = distance(trigLeft, echoLeft);
  int right = distance(trigRight, echoRight);


  // طباعة القيم لمتابعة الأداء
  Serial.print("F:");
  Serial.print(front);
  Serial.print(" L:");
  Serial.print(left);
  Serial.print(" R:");
  Serial.println(right);


  // ---------- 1. حالة الطوارئ: اقتراب شديد جداً (رجوع مسافة منيحة وبدون توقف) ----------
  if(front < emergencyDistance && turning == false)
  {
    turning = true;

    // عكس الاتجاه فوراً للخلف وبسرعة عالية ولمدة 700ms ليرجع مسافة منيحة
    steering.write(straight);
    backward(backwardSpeed);
    delay(700); 

    turning = false;
  }

  // ---------- 2. حالة وجود منعطف (كسر سريع وزيادة السرعة فوراً) ----------
  else if(front < frontDistanceTrigger && turning == false)
  {
    turning = true;

    // توجيه السيرفو فوراً للجهة المفتوحة
    if(right > left)
    {
      steering.write(rightTurn); 
    }
    else
    {
      steering.write(leftTurn);  
    }

    // زيادة سرعة الـ DC فوراً لـ 240 أثناء اللف
    forward(turnSpeed);
    delay(220); // زمن خاطف وسريع جداً ليعبر الممر بدون اندفاع زاد

    steering.write(straight);

    turning = false;
  }

  // ---------- 3. حالة السير المستقيم وتصحيح المسار ----------
  else if(!turning)
  {
    if(right < 14)
    {
      steering.write(leftTurn); // الابتعاد عن الجدار الأيمن
    }
    else if(left < 14)
    {
      steering.write(rightTurn); // الابتعاد عن الجدار الأيسر
    }
    else
    {
      steering.write(straight);
    }

    // السير بالأمام بالسرعة العادية للمستقيم
    forward(motorSpeed);
  }

}


// ---------- Distance Calculation ----------
int distance(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  long time = pulseIn(echo, HIGH, 12000);

  if(time == 0)
    return 200;

  return time * 0.034 / 2;
}


// ---------- Motor Forward ----------
void forward(int speedValue)
{
  analogWrite(ENA, speedValue);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void forward()
{
  forward(motorSpeed);
}


// ---------- Motor Backward ----------
void backward(int speedValue)
{
  analogWrite(ENA, speedValue);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void backward()
{
  backward(motorSpeed);
}
