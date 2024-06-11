#include <Servo.h>
float fx = 10;  // AG
float fy = -5;  //FG
float ab = 3.2;
float cb = 6.2;
float ac = 9.4;
float cf = 10;

float AF, fsr, hab, bh, ah, bj, fj, bf, fab, fag, gab, A, fcb;
Servo servo1, servo2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(5);
  servo2.attach(9);
}


void loop() {
  fx = 10;              // AG
  fy = -5;              //FG
  fsr = servo1.read();  //reading first servo for finding second servo position
  hab = 90 - fsr;
  bh = sin(hab * 3.14 / 180) * ab;
  Serial.println(bh);
  ah = cos(hab * 3.14 / 180) * ab;
  Serial.println(ah);
  AF = sqrt(fx * fx + fy * fy);
  Serial.println(AF);
  bj = fx - ah;
  Serial.println(bj);
  fj = fy + bh;
  Serial.println(fj);
  bf = sqrt(bj * bj + fj * fj);
  Serial.println(bf);
  fab = acos((ac * ac + AF * AF - cf * cf) / (2 * ac * AF)) * (180 / 3.14);
  Serial.println(fab);
  fag = acos((fx * fx + AF * AF - fy * fy) / (2 * fx * AF)) * (180 / 3.14);
  Serial.println(fag);
  if (fy >= 0) {
    gab = fab - fag;
  } else if (fy < 0) {
    gab = fab + fag;
  }
  A = 90 - gab;
  servo1.write(A);
  Serial.println(A);
  fcb = acos((ac * ac + cf * cf - AF * AF) / (2 * ac * AF)) * (180 / 3.14);
  servo2.write(fcb);
  Serial.println(fcb);

  delay(1000);



  fx = 10;  // AG
  fy = 5;   //FG

  fsr = servo1.read();  //reading first servo for finding second servo position
  hab = 90 - fsr;
  bh = sin(hab * 3.14 / 180) * ab;
  Serial.println(bh);
  ah = cos(hab * 3.14 / 180) * ab;
  Serial.println(ah);
  AF = sqrt(fx * fx + fy * fy);
  Serial.println(AF);
  bj = fx - ah;
  Serial.println(bj);
  fj = fy + bh;
  Serial.println(fj);
  bf = sqrt(bj * bj + fj * fj);
  Serial.println(bf);
  fab = acos((ac * ac + AF * AF - cf * cf) / (2 * ac * AF)) * (180 / 3.14);
  Serial.println(fab);
  fag = acos((fx * fx + AF * AF - fy * fy) / (2 * fx * AF)) * (180 / 3.14);
  Serial.println(fag);
  if (fy >= 0) {
    gab = fab - fag;
  } else if (fy < 0) {
    gab = fab + fag;
  }
  A = 90 - gab;
  servo1.write(A);
  Serial.println(A);
  fcb = acos((ac * ac + cf * cf - AF * AF) / (2 * ac * AF)) * (180 / 3.14);
  servo2.write(fcb);
  Serial.println(fcb);
  delay(1000);


  fx = 15;  // AG
  fy = 0;   //FG

  fsr = servo1.read();  //reading first servo for finding second servo position
  hab = 90 - fsr;
  bh = sin(hab * 3.14 / 180) * ab;
  Serial.println(bh);
  ah = cos(hab * 3.14 / 180) * ab;
  Serial.println(ah);
  AF = sqrt(fx * fx + fy * fy);
  Serial.println(AF);
  bj = fx - ah;
  Serial.println(bj);
  fj = fy + bh;
  Serial.println(fj);
  bf = sqrt(bj * bj + fj * fj);
  Serial.println(bf);
  fab = acos((ac * ac + AF * AF - cf * cf) / (2 * ac * AF)) * (180 / 3.14);
  Serial.println(fab);
  fag = acos((fx * fx + AF * AF - fy * fy) / (2 * fx * AF)) * (180 / 3.14);
  Serial.println(fag);
  if (fy >= 0) {
    gab = fab - fag;
  } else if (fy < 0) {
    gab = fab + fag;
  }
  A = 90 - gab;
  servo1.write(A);
  Serial.println(A);
  fcb = acos((ac * ac + cf * cf - AF * AF) / (2 * ac * AF)) * (180 / 3.14);
  servo2.write(fcb);
  Serial.println(fcb);
  delay(1000);
}