#include <Servo.h>

// ---------- Servo ----------
Servo steering;
#define servoPin 9

int straight = 90;
int rightTurn = 140;  // اتجاه اليمين
int leftTurn = 50;    // اتجاه اليسار

// ---------- Distances Config ----------
int frontDistanceTrigger = 90;  // مسافة كشف المنعطف
int emergencyDistance = 30;     // مسافة الخطر للرجوع للخلف
int clearDistance = 65;         // المسافة التي يعتبر عندها اللفة انتهت

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

// اعدادات السرعة
int motorSpeed = 160;    // سرعة السير المستقيم
int turnSpeed = 240;     // سرعة عالية جداً عند الالتفاف
int backwardSpeed = 230; // سرعة الرجوع للخلف

// ---------- المتغيرات المساعدة ----------
bool turning = false;
const unsigned long turnTimeout = 2200; // زمن الأمان للفة

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

  // طباعة القيم
  Serial.print("F:");
  Serial.print(front);
  Serial.print(" L:");
  Serial.print(left);
  Serial.print(" R:");
  Serial.println(right);

  // ---------- 1. حركة المكان الضيق (الرجوع مع كسر العجلات مثل السيارة الحقيقية) ----------
  if(front < emergencyDistance && turning == false)
  {
    turning = true;

    // تحديد الاتجاه المفتوح
    bool goRight = (right > left);

    // محاكاة حركة السائق الحقيقي:
    // نكسر العجلات بالاتجاه المعاكس ونرجع للخلف عشان يبعد وجه السيارة عن الحايط
    steering.write(goRight ? leftTurn : rightTurn);
    backward(backwardSpeed);
    delay(600); // يرجع وهو لافف العجلات

    // نكسر العجلات فوراً باتجاه المنعطف المفتوح ونطلع للأمام
    steering.write(goRight ? rightTurn : leftTurn);
    forward(turnSpeed);
    delay(300);

    turning = false;
  }

  // ---------- 2. حالة المنعطف العادي (Adaptive) ----------
  else if(front < frontDistanceTrigger && turning == false)
  {
    turning = true;

    // توجيه السيرفو فوراً للجهة المفتوحة
    bool goRight = (right > left);
    steering.write(goRight ? rightTurn : leftTurn);

    forward(turnSpeed);

    unsigned long startTime = millis();
    int f = front;

    while(f < clearDistance && (millis() - startTime) < turnTimeout)
    {
      f = distance(trigFront, echoFront);

      // إذا قرب كثير وهو يلف: يرجع مع كسر عكسي ويكمل للأمام
      if(f < emergencyDistance)
      {
        steering.write(goRight ? leftTurn : rightTurn);
        backward(backwardSpeed);
        delay(250);
        
        steering.write(goRight ? rightTurn : leftTurn);
        forward(turnSpeed);
      }

      Serial.print("Turning... F:");
      Serial.println(f);
    }

    steering.write(straight);
    turning = false;
  }

  // ---------- 3. حالة السير المستقيم وتصحيح المسار ----------
  else if(!turning)
  {
    if(right < 8)
    {
      steering.write(leftTurn); // الابتعاد عن الجدار الأيمن
    }
    else if(left < 8)
    {
      steering.write(rightTurn); // الابتعاد عن الجدار الأيسر
    }
    else
    {
      steering.write(straight);
    }

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
