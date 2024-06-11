#include <Servo.h>
float FX = -5;   // Horizontal distance from upper servo which is on (0,0) position ie FG
float FY = 10;   // vertical distance from upper servo which is on (0,0) position ie AG
float AB = 3.2;  // Distance from first servo to second
float CB = 6.2;  // Distance from second servo to second joint
float AC = 9.4;  // Distance from 1st servo to second joint ie thigh length
float CF = 10;   // leg length

float AF, HAB, FAB, FAG, GAB, A, FCB;  // unknown variables to be calculated

Servo servo1, servo2;  // servo objects

typedef struct {
  //calculating semi circle points
  double x;
  double y;
} Point;

void setup() {
  Serial.begin(9600);
  servo1.attach(5);  // upper servo
  servo2.attach(9);  //lower servo
}
void loop() {

  int num_points = 20;              // no of points
  coordinaate(-2,7);
  delay(500);
  coordinaate(-2,17);
  backline(-2, 17, 7, num_points);  //straight horizontal line
}

double coordinaate(float FX, float FY) {
  //inverse kinematics

  AF = sqrt(FX * FX + FY * FY);

  FAB = acos((AC * AC + AF * AF - CF * CF) / (2 * AC * AF)) * (180 / 3.14);

  FAG = acos((FY * FY + AF * AF - FX * FX) / (2 * FY * AF)) * (180 / 3.14);

  if (FX >= 0) {
    GAB = FAB - FAG;
  } else if (FX < 0) {
    GAB = FAB + FAG;
  }
  A = 90 - GAB;
  servo1.write(A);  // upper servo position for FX and FY coordinates

  FCB = acos((AC * AC + CF * CF - AF * AF) / (2 * AC * AF)) * (180 / 3.14);
  servo2.write(FCB);  // lower servo position for FX and FY coordinates
}



double backline(int x, float y1, float y2, int numpoints) {
  //calculating upward path

  float add = (y1 - y2) / numpoints;
  float a;
  for (int i = 0; i < numpoints - 1; i++) {
    a = y1 - add;
    coordinaate(x, a);
    Serial.print(x);
    Serial.println("  ");
    Serial.println(a);
    Serial.println("  ");
    y1 = y1 - add;
    delay(70);
  }
}