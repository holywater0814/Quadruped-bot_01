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
  double radius = 5.0;              // Radius of the semi-circle
  int num_points = 20;              // no of points
  circle(radius, num_points);       //calculating coordinates of semi circle
  backline(15, 4, -6, num_points);  //straight horizontal line
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

void semi_circle_trajectory(double radius, int num_points, Point *coordinates) {
  // calculating semi circle for walking
  double theta;
  for (int i = 0; i < num_points; i++) {
    theta = (double)i / (num_points - 1) * PI;       // Angle range from 0 to pi (semi-circle)
    coordinates[i].x = -(radius * cos(theta) + 3);   // X-coordinate
    coordinates[i].y = -(radius * sin(theta) - 15);  // Y-coordinate
  }
}
void circle(double radius, int num_points) {
  // Number of points along the semi-circle

  // Allocate memory for coordinates array
  Point *trajectory = malloc(num_points * sizeof(Point));
  if (trajectory == NULL) {
    Serial.print("memory allocation failed");
    return 1;
  }

  // Generate coordinates for semi-circle trajectory
  semi_circle_trajectory(radius, num_points, trajectory);

  // Print coordinates
  for (int i = 0; i < num_points; i++) {
    Serial.print(trajectory[i].x);
    Serial.println("  ");
    Serial.println(trajectory[i].y);
    Serial.println("  ");
    coordinaate(trajectory[i].x, trajectory[i].y);
    delay(50);
  }

  // Free allocated memory
  free(trajectory);

  return 0;
}

double backline(int y, float x1, float x2, int numpoints) {
  //calculating straight backward path

  float add = (x1 - x2) / numpoints;
  float a;
  for (int i = 0; i < numpoints - 1; i++) {
    a = x1 - add;
    coordinaate(a, y);
    Serial.print(a);
    Serial.println("  ");
    Serial.println(y);
    Serial.println("  ");
    x1 = x1 - add;
    delay(50);
  }
}