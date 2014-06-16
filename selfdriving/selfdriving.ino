#include <NewPing.h>
#include <AFMotor.h>

AF_DCMotor motor(4, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor2(1, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
NewPing sonar(26, 24, 300);

void setup() {
  Serial.begin(115200);     
  Serial.println("Motor test!");

  motor.setSpeed(150);     // set the speed to 200/255
  motor2.setSpeed(255);     // set the speed to 200/255
  pinMode(28, OUTPUT);
}

void loop() {
  digitalWrite(28, HIGH);
  motor.run(FORWARD);      // turn it on going forward
  
  int uS = sonar.ping();
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
  if((uS / US_ROUNDTRIP_CM)<=60 && (uS / US_ROUNDTRIP_CM)!=0){
    motor2.run(BACKWARD);
    motor.run(BACKWARD);
    delay(1500); 
    motor2.run(FORWARD);
    motor.run(FORWARD);
    delay(800);
    motor2.run(RELEASE);
  }
 
}
