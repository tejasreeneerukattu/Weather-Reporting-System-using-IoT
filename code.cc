
#include <LiquidCrystal.h> // including LiquidCrystal Library 

LiquidCrystal lcd(12,11,5,4,3,2); // Creating LC object where parameters: (RS,E,DB4,DB5,DB6,DB7) 
void setup() 
{ 
  lcd.begin(16,2); // 16 Characters per line and  2 lines
  lcd.setCursor(4,0); // Positioning of the LCD cursor. col=4, row=0
  lcd.print("Monitoring"); // Printing text to the LCD
  lcd.setCursor(7,1); // Positioning of the LCD cursor. col=7, row=1
  lcd.print("System"); // Printing text to the LCD
  delay(2000); // time delay
}
void loop() 
{ 
 lcd.clear(); // Clearing the LCD screen and positioning the cursor in the upper-left corner
 
 float Voltage=analogRead(A0)*0.004882814; // Variable declartion and analog input pin select
 float degrees = ( Voltage - 0.5 ) * 100; // Variable declartion and modification
  
 lcd.setCursor(3,0); // Positioning of the LCD cursor. col=3, row=0
 lcd.print("Temp:"); // Printing text to the LCD
 lcd.setCursor(8,0); // Positioning of the LCD cursor. col=8, row=0
 lcd.print(degrees); // Printing text to the LCD
  if (degrees<10) // Checking variable value using if function
  {
    lcd.setCursor(4,1); // Positioning of the LCD cursor. col=4, row=1
    lcd.print("-TOO COLD"); // Printing text to the LCD
  }
  else if(degrees<18 &&degrees>10 ) // Checking variable value using else if function
  {
    lcd.setCursor(4,1); // Positioning of the LCD cursor. col=4, row=1
    lcd.print("-COLD"); // Printing text to the LCD
  }
  else if(degrees<30 &&degrees>18 ) // Checking variable value using else if function
  {
    lcd.setCursor(4,1); // Positioning of the LCD cursor. col=4, row=1
    lcd.print("-Normal Temp"); // Printing text to the LCD
  }
  else if(degrees<45 &&degrees>30 ) // Checking variable value using else if function
  {
    lcd.setCursor(4,1); // Positioning of the LCD cursor. col=4, row=1
    lcd.print("-Hot"); // Printing text to the LCD
  }
  else if(degrees>45 ) // Checking variable value using else if function
  {
    lcd.setCursor(4,1); // Positioning of the LCD cursor. col=4, row=1
    lcd.print("-TOO HOT"); // Printing text to the LCD
  }
  
  delay(2000); // time delay
  lcd.clear(); // Clearing the LCD screen and positioning the cursor in the upper-left corner
  
  int ldr=analogRead(A1); // Variable declartion and analog input pin select
  
  lcd.setCursor(1,0); // Positioning of the LCD cursor.
  lcd.print("Intensity:"); // Printing text to the LCD
  lcd.setCursor(12,0); // Positioning of the LCD cursor.
  lcd.print(ldr); // Printing text to the LCD
  if (ldr<230) // Checking variable value using if function
  {
     lcd.setCursor(4,1); // Positioning of the LCD cursor.
     lcd.print("-TOO BRIGHT"); // Printing text to the LCD
  }
    else if (ldr<460 && ldr>230 ) // Checking variable value using else if function
  {
     lcd.setCursor(2,1); // Positioning of the LCD cursor.
     lcd.print("-Medium Light"); // Printing text to the LCD
  }
  
  else if (ldr>460) // Checking variable value using else if function
  {
     lcd.setCursor(4,1); // Positioning of the LCD cursor.
     lcd.print("-TOO DARK"); // Printing text to the LCD
  }
  
  delay(2000); // time delay
  lcd.clear(); // Clearing the LCD screen and positioning the cursor in the upper-left corner
}

