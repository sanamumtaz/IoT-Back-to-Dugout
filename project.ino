#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//SCL >D1, SDA >D2, 
#define OLED_RESET BUILTIN_LED
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
const int s0 = 2;  //D4
const int s1 = 14;  //D5
const int s2 = 12;  //D6
const int s3 = 13;  //D7
const int out = 15; //D8
const int touchPin = 0;  //D3

// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   
{  
  Serial.begin(9600); 
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  
  display.display();
  delay(300);

  // Clear the buffer.
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  pinMode(touchPin, INPUT);
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
}  
    
void loop() 
{  
  display.setCursor(0,0);
  color();   

  if (red < blue && red < green && red < 20)
  {  
   //Serial.println(" - (Red Color)");
      
  }  

  else if (blue < red && blue < green)   
  {  
   //Serial.println(" - (Blue Color)");  
   Serial.println("BATSMAN CROSSED THE LINE");
   Serial.println("IT IS NOT OUT");
   Serial.println("******************************");
   Serial.println("");  
   display.println("Batsman crossed the  line");
   display.println("IT IS NOT OUT");
   display.println("******************************");
   display.println("");
   display.display();
  }  

  else if (green < red && green < blue)  
  {  
   //Serial.println(" - (Green Color)"); 
    
  }  
  else{
    
  }

  int touchValue = digitalRead(touchPin);
  if (touchValue == HIGH) {
    Serial.println("WICKET TOUCHED");
    Serial.println("IT IS AN OUT");
    Serial.println("******************************");
    Serial.println("");
    display.println("WICKET TOUCHED");
    display.println("IT IS AN OUT");
    display.println("******************************");
    display.println("");
    display.display();
  
  }
  delay(200);
  
  display.clearDisplay();   
 }  
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}

