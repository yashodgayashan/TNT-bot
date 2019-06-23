#ifndef colorsensor_h
  #define colorsensor_h
#define s0 49
#define s1 47
#define s2 31
#define s3 39
#define outPin 51

#define redNumber 1
#define blueNumber 2
#define greenNumber 3
#define otherColor 0

// Variables
int red;
int green;
int blue;
String color ="";

void colorInit(){
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT); //out from sensor becomes input to arduino

  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
}

void readRGB() 
{
  red = 0;
  green = 0;
  blue = 0;
  int n = 10;
  for (int i = 0; i < n; ++i)
  {
    //read red component
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    red = red + pulseIn(outPin, LOW);
  
   //read green component
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    green = green + pulseIn(outPin, LOW);
    
   //let's read blue component
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    blue = blue + pulseIn(outPin, LOW);
  }
  red = red/n;
  green = green/n;
  blue = blue/n;
}

void getColor()
{  
  readRGB();
  
        if (red > 8 && red < 18 && green > 9 && green < 19 && blue > 8 && blue < 16) color = "WHITE";
  else if (red > 80 && red < 125 && green > 90 && green < 125 && blue > 80 && blue < 125) color = "BLACK";
  else if (red > 12 && red < 30 && green > 40 && green < 70 && blue > 33 && blue < 70) color = "RED";
  else if (red > 50 && red < 95 && green > 35 && green < 70 && blue > 45 && blue < 85) color = "GREEN";
  else if (red > 10 && red < 20 && green > 10 && green < 25 && blue > 20 && blue < 38) color = "YELLOW";
  else if (red > 60 && red < 68 && green > 10 && green < 20 && blue > 55 && blue < 65) color = "BLUE";
  else  color = "NO_COLOR";
}

int colourNumber()
{
  getColor();
  if (color=="RED")
    return redNumber;
  else if (color=="GREEN")
    return greenNumber;
  else if (color=="BLUE")
    return blueNumber;
  else
    return otherColor;
}

void printData(void)
{
  Serial.print("red= ");
  Serial.print(red);
  Serial.print("   green= ");
  Serial.print(green);
  Serial.print("   blue= ");
  Serial.print(blue);
  Serial.print (" - ");
  Serial.print (color);
  Serial.println (" detected!");
}
#endif 
