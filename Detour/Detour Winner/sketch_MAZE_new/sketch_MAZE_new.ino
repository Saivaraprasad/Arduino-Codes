/*
#define leftExtremeSensor    //left4
#define leftFarSensor      5 //left3 
#define leftNearSensor     4  //left2
#define leftCenterSensor   3  //left1
#define rightCenterSensor  2  //right1
#define rightNearSensor    1  //right2
#define rightFarSensor     0  //right3
#define rightExtremeSensor   //right4
*/
/*int leftCenterReading;
int leftNearReading;
int leftFarReading;
int rightCenterReading;
int rightNearReading;
int rightFarReading;
*/
/*#define left_pwm 10
#define right_pwm 3 
#define left_1 8
#define left_2 9
#define right_1 4
#define right_2 5
*/
int left1;
int left2;
int left3;
int left4;
int right1;
int right2;
int right3;
int right4;

int leftNudge;
int replaystage;
int rightNudge;

#define leapTime 200

#define leftMotor1  7
#define leftMotor2  6

#define rightMotor1 5
#define rightMotor2 8
#define led 13

char path[30] = {};
int pathLength;
int readLength;

void setup()
{
  
 pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  //
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,OUTPUT);
}


void loop()
{
 //less than means ==1, gretaer than means ==0 
 readSensors();                                                                                     
 
 if(left4==1 && right4==1 && (left1==0 || right1==0))
 { 
    straight();                                                                                      
  }
  else
  {                                                                                              
    leftHandWall();                                                                                   
  }

}

void readSensors()
{
   left4 = digitalRead(A0);
   left3 = digitalRead(A1);
   left2 = digitalRead(A2);
   left1 = digitalRead(6);
   right1 = digitalRead(2);
   right2 = digitalRead(A3);
   right3 = digitalRead(A4);  
   right4 = digitalRead(A5);
// serial printing below for debugging purposes

// Serial.print("leftCenterReading: ");
// Serial.println(leftCenterReading);
// Serial.print("leftNearReading: ");
// Serial.println(leftNearReading);
// Serial.print("leftFarReading: ");
// Serial.println(leftFarReading);
  
// Serial.print("rightCenterReading: ");
// Serial.println(rightCenterReading);
// Serial.print("rightNearReading: ");
// Serial.println(rightNearReading);
// Serial.print("rightFarReading: ");
// Serial.println(rightFarReading);
// delay(200);
  

}


void leftHandWall()
{
 if(left4==0 && right4==0)
  {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(leapTime);
    readSensors();
    
    if(left4==0 || right4==0)
    {
      done();
    }
    if(left4==1 && right4==1)
    { 
      turnLeft();
    }
    
  }
  if(left4==0)
  { 
    // if you can turn left then turn left
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(leapTime);
    readSensors();
      
      if(left4==1 && right4==1)
      {
        turnLeft();
      }
      else
      {
        done();
      }
  }
   
  if(right4==0)
  {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(30);
    readSensors();
    
    if(left4==0)
    {
      delay(leapTime-30);
      readSensors();
      
      if(right4==0 && left4==0)
      {
        done();
      }
      else
      {
        turnLeft();
        return;
      }
    }
    delay(leapTime-30);
    readSensors();
    if(left4==1 && left1==1 && right1==1 && right4==1)
    {
      turnRight();
      return;
    }
    path[pathLength]='S';
   // Serial.println("s");
    pathLength++;
    //Serial.print("Path length: ");
    //Serial.println(pathLength);
    if(path[pathLength-2]=='B')
    {
    //Serial.println("shortening path");
    shortPath();
     }
    straight();
  }
  readSensors();
  if(left4==1 && left1==1 && right1==1 && right4==1 && left3==1 && right4==1)
  {
    turnAround();
  }

}
void done()
{
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    replaystage=1;
    path[pathLength]='D';
    pathLength++;
    while(digitalRead(left4)==0)
    {
    digitalWrite(led, LOW);
    delay(150);
    digitalWrite(led, HIGH);
    delay(150);
    }
    delay(500);
    replay();
}

void turnLeft()
{
    while(digitalRead(right1)==0 || digitalRead(left1)==0)
    {
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(2);
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
    }
    
   while(digitalRead(right1)==1)
   {
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
 
  if(replaystage==0)
  {
    path[pathLength]='L';
    //Serial.println("l");
    pathLength++;
    //Serial.print("Path length: ");
    //Serial.println(pathLength);
      if(path[pathLength-2]=='B')
      {
        //Serial.println("shortening path");
        shortPath();
      }
  }
}

void turnRight()
{

    
  while(digitalRead(right1)==0)
  {
     digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, HIGH);
    delay(2);
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
   while(digitalRead(right1)==1)
   {
     digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, HIGH);
    delay(2);
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
   while(digitalRead(left1)==1)
   {
     digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, HIGH);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
  
  if(replaystage==0)
  {
  path[pathLength]='R';
  Serial.println("r");
  pathLength++;
  Serial.print("Path length: ");
  Serial.println(pathLength);
    if(path[pathLength-2]=='B')
    {
      Serial.println("shortening path");
      shortPath();
    }
  }
 
}

void straight()
{
  if(digitalRead(left1)==1)
  {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(1);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(5);
    return;
  }
  if(digitalRead(right1)==1)
  {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(1);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(5);
    return;
  }
  
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(4);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  
}

void turnAround()
{
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(150);
   while(digitalRead(left1)==1)
   {
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(2);
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  }
  path[pathLength]='B';
  pathLength++;
  straight();
  //Serial.println("b");
  //Serial.print("Path length: ");
  //Serial.println(pathLength);
}

void shortPath()
{
 int shortDone=0;
  if(path[pathLength-3]=='L' && path[pathLength-1]=='R')
  {
    pathLength-=3;
    path[pathLength]='B';
    //Serial.println("test1");
    shortDone=1;
  }
   
  if(path[pathLength-3]=='L' && path[pathLength-1]=='S' && shortDone==0)
  {
    pathLength-=3;
    path[pathLength]='R';
    //Serial.println("test2");
    shortDone=1;
  }
   
  if(path[pathLength-3]=='R' && path[pathLength-1]=='L' && shortDone==0)
  {
    pathLength-=3;
    path[pathLength]='B';
    //Serial.println("test3");
    shortDone=1;
  }
  
   
  if(path[pathLength-3]=='S' && path[pathLength-1]=='L' && shortDone==0)
  {
    pathLength-=3;
    path[pathLength]='R';
    //Serial.println("test4");
    shortDone=1;
  }
     
  if(path[pathLength-3]=='S' && path[pathLength-1]=='S' && shortDone==0)
  {
    pathLength-=3;
    path[pathLength]='B';
    //Serial.println("test5");
    shortDone=1;
  }
   if(path[pathLength-3]=='L' && path[pathLength-1]=='L' && shortDone==0)
   {
    pathLength-=3;
    path[pathLength]='S';
    //Serial.println("test6");
    shortDone=1;
   }
  
  path[pathLength+1]='D';
  path[pathLength+2]='D';
  pathLength++;
  //Serial.print("Path length: ");
  //Serial.println(pathLength);
  //printPath();
}




void printPath()
{
  Serial.println("+++++++++++++++++");
  int x;
  while(x<=pathLength)
  {
  Serial.println(path[x]);
  x++;
  }
  Serial.println("+++++++++++++++++");
}


void replay()
{
  readSensors();
  if(left4==1 && right4==1)
  {
    straight();
  }
  else
  {
    if(path[readLength]=='D')
    {
       digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(100);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
      endMotion();
    }
    if(path[readLength]=='L')
    {
     digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(leapTime);
      turnLeft();
    }
    if(path[readLength]=='R')
    {
       digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(leapTime);
    turnRight();
    }
    if(path[readLength]=='S')
    {
       digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(leapTime);
    straight();
    }
    
    readLength++;
  }
    
  replay();
  
}

void endMotion()
{
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(200);
      digitalWrite(led, LOW);
    delay(200);
    digitalWrite(led, HIGH);
    delay(500);
  endMotion();
}
