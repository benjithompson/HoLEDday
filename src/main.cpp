
#include <Arduino.h>

// Define Pins
#define RED 2
#define GREEN 3
#define BLUE 4

#define startDelay 100 // startup sequence delay time
#define delayTime 10 // fading time between colors
#define loopWait 0 // time between loop restart
#define fadeWait 255 // fade loop counter, larger# = faster. 255 = no wait.

int redValue;
int greenValue;
int blueValue;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  startSequence();
}

// main loop
void loop(){
  rayColors(50);
  bethyColors(random(1,2));
  flashingColors(random(10, 50));
  fadeColor(random(2,10));
  randoColor(random(2, 10));
  delay(loopWait);
}

void rayColors(int iters){
  //Start with leds off
  analogWrite(RED, 0);   
  analogWrite(GREEN, 0);   
  analogWrite(BLUE, 0);

  for(int i = 0; i < iters; i++){
    
    analogWrite(GREEN, 255);   
    analogWrite(BLUE, 255);
    delay(100);
    analogWrite(GREEN, 0);   
    analogWrite(BLUE, 0);
    delay(100);
    analogWrite(RED, 255);   
    analogWrite(BLUE, 63);
    delay(100);
    analogWrite(RED, 0);   
    analogWrite(BLUE, 0);
    delay(100);
    
  }
}

void bethyColors(int iters){
  
  //Start with leds off
  analogWrite(RED, 0);   
  analogWrite(GREEN, 0);   
  analogWrite(BLUE, 0);   
  
  for(int i = 0; i< iters; i++){
    onRed(1, 5);
    offRed(1, 50);
    onGreen(1, 5);
    offGreen(1, 50);
    onBlue(1, 5);
    offBlue(1, 50);
    onRed(1, 5);
    onGreen(1, 5);
    offRed(1, 25);
    onBlue(1, 25);
    offGreen(1, 25);
    onRed(1, 25);
    offBlue(1, 25);
    onGreen(1, 25);
    offRed(1, 25);
    offGreen(1, 25);  
  }
}

void onRed(int incr, int wait){
  while(redValue < 255){
    redValue += incr;
    if(redValue > 255){
      redValue = 255;
    }
    analogWrite(RED, redValue);
    delay(wait);
  }
}

void offRed(int incr, int wait){
  while(redValue > 0){
    redValue -= incr;
    if(redValue < 0){
      redValue = 0;
    }
    analogWrite(RED, redValue);
    delay(wait);
  }
}

void onGreen(int incr, int wait){
  while(greenValue < 255){
    greenValue += incr;
    if(greenValue > 255){
      greenValue = 255;
    }
    analogWrite(GREEN, greenValue);
    delay(wait);
  }
}

void offGreen(int incr, int wait){
  while(greenValue > 0){
    greenValue -= incr;
    if(greenValue < 0){
      greenValue = 0;
    }
    analogWrite(GREEN, greenValue);
    delay(wait);
  }
}

void onBlue(int incr, int wait){
  while(blueValue < 255){
    blueValue += incr;
    if(blueValue > 255){
      blueValue = 255;
    }
    analogWrite(BLUE, blueValue);
    delay(wait);
  }
}

void offBlue(int incr, int wait){
  while(blueValue > 0){
    blueValue -= incr;
    if(blueValue < 0){
      blueValue = 0;
    }
    analogWrite(BLUE, blueValue);
    delay(wait);
  }
}

void fadeColor(int iters){
  for(int i = 0; i < iters; i++){
    onRed   (1, random(1, 10));
    onGreen (1, random(1, 10));
    onBlue  (1, random(1, 10));
    offRed  (1, random(1, 10));
    offGreen(1, random(1, 10));
    offBlue (1, random(1, 10));
    onGreen (1, random(1, 10));
    onRed   (1, random(1, 10));
    offRed  (1, random(1, 10));
    onBlue  (1, random(1, 10));
    offGreen(1, random(1, 10));
    onRed   (1, random(1, 10));
    onGreen (1, random(1, 10));
    offRed  (1, random(1, 10));
    onBlue  (1, random(1, 10));
    offGreen(1, random(1, 10));
    offBlue (1, random(1, 10)); 
  }
}

void flashingColors(int iters){
   for(int i = 0 ; i < iters; i++){
      redValue = random(0,255);
      greenValue = random(0, 255);
      blueValue = random(0, 255);
      
      analogWrite(RED, redValue);     
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
      delay(random(10, 1000));
      analogWrite(RED, 0);     
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
      delay(random(10, 1000));
   }
}

void randoColor(int iters){
  int i, j, high, low, wait;
  
  for(int i = 0; i< iters; i++){
    high = random(0,255);
    low = random(0,255);
    
    for(int j = 0; j < high; j++){
      wait = random(10, 1000);
      redValue = random(0,j);
      greenValue = random(0,j);
      blueValue = random(0,j);
    
      analogWrite(RED, redValue);     
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
      delay(wait);
    }
    
    for(; j>0; j--){
      wait = random(50, 5000);
      redValue = random(0,j);
      greenValue = random(0,j);
      blueValue = random(0,j);
    
      analogWrite(RED, redValue);     
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
      delay(wait);
    }
  }
}
  
  
void startSequence(){
  analogWrite(RED, 10);
  delay(startDelay);
  analogWrite(RED, 0);
  analogWrite(GREEN, 10);
  delay(startDelay);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 10);
  delay(startDelay);
  analogWrite(BLUE, 0);
  analogWrite(GREEN, 10);
  delay(startDelay);
  analogWrite(GREEN, 0);
  analogWrite(RED, 10);
  delay(startDelay);
  analogWrite(RED, 0);
  delay(1000);
}
