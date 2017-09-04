#include <LiquidCrystal.h>
#include <LedControl.h>
 
LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );

//  pin 12 is connected to the DataIn 
//  pin 11 is connected to the CLK 
//  pin 10 is connected to LOAD 
//  1 = We have only a single MAX72XX
LedControl lc_timer = LedControl(12,11,10,1);

// Define delay between updates of 7-digit display 
unsigned long delay_7digit = 250;

// inputs: DIN pin, CLK pin, LOAD pin. number of chips
LedControl lc_target = LedControl(3, 1, 2, 1);



// PIN USAGE
// 1
// 2
// 3
// 4  LCD Command Display
// 5  LCD Command Display
// 6  LCD Command Display
// 7  LCD Command Display
// 8  LCD Command Display
// 9  LCD Command Display
// 10 Timer load
// 11 Timer clk
// 12 Timer data in
// 13
// A0
// A1
// A2



int button_1_inputPin = 8;         // the number of the input pin for button #1

int button_2_inputPin = 9;         // the number of the input pin for button #2
int button_2_outputPin = 3;       // the number of the output pin LED for button #2

int state_1 = HIGH;      // the current state of the output pin for button #1
int state_2 = HIGH;      // the current state of the output pin for button #1
int reading_1;           // the current reading from the input pin for button #1
int previous_1 = LOW;    // the previous reading from the input pin for button #1
int reading_2;           // the current reading from the input pin for button #2
int previous_2 = LOW;    // the previous reading from the input pin for button #2

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers


 
void setup()
{
  // Reet timer display
  lc_timer.shutdown(0,false); // turn on the timer display
  lc_timer.setIntensity(0,8); // medium brightness
  lc_timer.clearDisplay(0);   // clear display
  
  lc_timer.setChar(0,0,9,false);
  lc_timer.setChar(0,1,9,false);










  
  // Set up buttons #1 and #2
  pinMode(button_1_inputPin, INPUT);
  pinMode(button_2_inputPin, INPUT);
  pinMode(button_1_outputPin, OUTPUT);
  pinMode(button_2_outputPin, OUTPUT);
  
  // Write title screen
  lcd.begin(16, 2);
  lcd.setCursor(4,0);   
  lcd.print("BABBAGE.");

  lc_target.shutdown(0, false);  // turns on display
  lc_target.setIntensity(0, 15); // 15 = brightest
  lc_target.setDigit(0, 0, 9, false);
  lc_target.setDigit(0, 1, 8, false);
  lc_target.setDigit(0, 2, 7, false);
  lc_target.setDigit(0, 3, 6, false);
  lc_target.setDigit(0, 4, 5, false);
  lc_target.setDigit(0, 5, 4, false);
  lc_target.setDigit(0, 6, 3, false);
  lc_target.setDigit(0, 7, 2, false);

  
  
  // lcd.write(byte(0)); // when calling lcd.write() '0' must be cast as a byte
  
  // lcd.setCursor(0, 1);
  // lcd.print("");

  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(9, OUTPUT);

  
}
 
void loop()
{
  //digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
 //delay(1000);                       // wait for a second
  //digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);                       // wait for a second


    reading_1 = digitalRead(button_1_inputPin);

    // if the input just went from LOW and HIGH and we've waited long enough
    // to ignore any noise on the circuit, toggle the output pin and remember
    // the time
    if (reading_1 == HIGH && previous_1 == LOW && millis() - time > debounce)
    {
      if (state_1 == HIGH)
        state_1 = LOW;
      else
        state_1 = HIGH;
  
      time = millis();    
    }
  
    digitalWrite(button_1_outputPin, state_1);  
    previous_1 = reading_1;

    

    reading_2 = digitalRead(button_2_inputPin);

    // if the input just went from LOW and HIGH and we've waited long enough
    // to ignore any noise on the circuit, toggle the output pin and remember
    // the time
    if (reading_2 == HIGH && previous_2 == LOW && millis() - time > debounce)
    {
      if (state_2 == HIGH)
        state_2 = LOW;
      else
        state_2 = HIGH;
  
      time = millis();    
    }
  
    digitalWrite(button_2_outputPin, state_2);  
    previous_2 = reading_2;

    // Turn off the blinking cursor:
    //lcd.noBlink();
    //delay(3000);
    // Turn on the blinking cursor:
    //lcd.blink();
    //delay(3000);

    value=digitalRead(pin);
    digitalWrite(led,value);  
}
