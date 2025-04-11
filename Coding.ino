#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>

RTC_DS3231 rtc;
Servo feedServo;

const int servoPin = 9;
const int relayPin = 8;

int feedHour = 7;
int feedMinute = 0;

bool Fed = false;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  if (rtc.lostPower()) 
  {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  feedServo.attach(servoPin);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
}

void loop() 
{
  DateTime now = rtc.now();

  Serial.print("Current Time: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.println(now.minute());

  if (now.hour() == feedHour && now.minute() == feedMinute && !Fed) 
  {
    dispenseFeed();
    pumpWater();
    Fed = true;
  }

  if (now.hour() == ((feedHour + 1) % 24) && Fed)
  {
    Fed = false;
  }

  delay(30000);
}

void dispenseFeed() 
{
  feedServo.write(0);
  delay(1000);
  feedServo.write(90);
  delay(2000);
  feedServo.write(0);
  delay(1000);
}

void pumpWater() 
{
  digitalWrite(relayPin, HIGH);
  delay(5000);
  digitalWrite(relayPin, LOW);
}
