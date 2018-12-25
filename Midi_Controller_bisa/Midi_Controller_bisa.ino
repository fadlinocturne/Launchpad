  #include <MIDI.h>
#include <Keypad.h>
#include <math.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <pt.h> 

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

static struct pt pt1, pt2;
int a=0;
const byte ROWS = 5; //four rows
const byte COLS = 5; //three columns
char keys[ROWS][COLS] = {
{'a','b','c','d'},
{'e','f','g','h'},
{'i','j','k','l'},
{'m','n','o','p'}
};

MIDI_CREATE_DEFAULT_INSTANCE();
byte rowPins[ROWS] = {10, 11, 12, 13}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {8, 7, 6, 5}; //connect to the column pinouts of the kpd
byte rowLeds[ROWS] = {3, 2, 1, 0, 14}; //connect to the row pinouts of the kpd
byte colLeds[COLS] = {15, 16, 17, 18, 19}; //connect to the column pinouts of the kpd

byte kpdNote[16]= {48,49,50,51,44,45,46,47,40,41,42,43,36,37,38,39};
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;
String msg;

void ledon(int c,int r){
  pinMode(c+15,OUTPUT);
  digitalWrite(c+15,HIGH);
  if(r==4){
  pinMode(r+10,OUTPUT);
  digitalWrite(r+10,LOW);
  }else{
  pinMode(r,OUTPUT);
  digitalWrite(r,LOW);
  }
}

void ledoff(int c,int r){
  pinMode(c+15,INPUT);
  digitalWrite(c+15,LOW);
  if(r==4){
  pinMode(r+10,INPUT);
  digitalWrite(r+10,LOW);
  }else{
  pinMode(r,INPUT);
  digitalWrite(r,LOW);
  }
}

void setup() {
   MIDI.begin(MIDI_CHANNEL_OMNI);
     matrix.begin(0x70);  // pass in the address
   
    //Serial.begin(9600);
    loopCount = 0;
    startTime = millis();
    msg = "";
  
  PT_INIT(&pt1);
  PT_INIT(&pt2);
}


static const uint8_t PROGMEM
  minum1[]={
  B00000000,
  B10000111,
  B01011110,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B01111110
},
minum2[]={
  B00000000,
  B10000001,
  B01111110,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B01111110
},
minum3[]={
  B00000000,
  B11100001,
  B01111010,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B01111110
},
minum4[]={
  B00000000,
  B10000001,
  B01111110,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B01111110
},
minum5[]={
  B00000000,
  B10000001,
  B01000010,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B01111110
},
minum6[]={
  B00000000,
  B10000001,
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00011000,
  B01111110
},
  pedang[]=
  {  B00000011,
  B00000101,
  B01001010,
  B01110100,
  B00111000,
  B01111000,
  B11101100,
  B11000000},
  
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 };

static int protothread1(struct pt *pt) {
  static unsigned long timestamp = 0;
  PT_BEGIN(pt);
  while(1) {
    matrix.clear();
  matrix.drawBitmap(0, 0, pedang, 8, 8, LED_YELLOW);
  matrix.writeDisplay();
  delay(500);
  matrix.clear();
  matrix.drawBitmap(0, 0, pedang, 8, 8, LED_GREEN);
  matrix.writeDisplay();
  delay(500);
  matrix.clear();
  matrix.drawBitmap(0, 0, pedang, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_GREEN);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_YELLOW);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();      // clear display
  matrix.drawPixel(0, 0, LED_GREEN);  
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawLine(0,0, 7,7, LED_YELLOW);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawRect(0,0, 8,8, LED_RED);
  matrix.fillRect(2,2, 4,4, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawCircle(3,3, 3, LED_YELLOW);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextSize(1);
  matrix.setTextColor(LED_GREEN);
  for (int8_t x=7; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Mantul");
    matrix.writeDisplay();
    delay(100);
  }
  matrix.setRotation(0);
  matrix.setTextColor(LED_RED);
  for (int8_t x=7; x>=-40; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Pencetin");
    matrix.writeDisplay();
    delay(100);
  }
  matrix.setRotation(0);
  }
  PT_END(pt);
}

static int protothread2(struct pt *pt) {
  static unsigned long timestamp = 0;
  PT_BEGIN(pt);
  while(1) {

    loopCount++;
    if ( (millis()-startTime)>5000 ) {
      //  Serial.print("Average loops per second = ");
      //  Serial.println(loopCount/5);
        startTime = millis();
        loopCount = 0;
    }

    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    MIDI.sendNoteOn(kpdNote[kpd.key[i].kchar-97], 127, 1); 
                    
                    msg = " PRESSED.";
                break;
                    case HOLD:
                    msg = " HOLD.";
                break;
                    case RELEASED:
                    MIDI.sendNoteOff(kpdNote[kpd.key[i].kchar-97], 127, 1);
                    msg = " RELEASED.";
                break;
                    case IDLE:
                    msg = " IDLE.";
                }
            }
        }
    }
  }
  PT_END(pt);
}

void loop() {
ledon(0,0);
 // protothread2(&pt2);
//protothread1(&pt1); 
}  // End loop
