#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
  float MPP, offsetVoltage = 0.5047, temp;
  int i ;
  
void setup() {
      
   // set up the LCD's number of columns and rows:

      lcd.begin(20, 4);
      lcd.setCursor(0,1);
      lcd.print("PV_volt= ");
      lcd.setCursor(15,1);
      lcd.print("V");

      lcd.setCursor(0,2);
      lcd.print("PV_crnt= ");
       lcd.setCursor(15,2);
      lcd.print("A");

      lcd.setCursor(0,3);
      lcd.print("power  = ");
      lcd.setCursor(15,3);
      lcd.print("W");

      lcd.setCursor(0,0);
      lcd.print("Loop N0: ");
      

    // Set pins A0, A1, and A2 as inputs
      pinMode(A0, INPUT);
      pinMode(A1, INPUT);
      pinMode(A2, INPUT);
      pinMode(A3, INPUT);

  // Set pins 0 to 7 as outputs
      for (int i = 0; i <= 7; i++) { pinMode(i, OUTPUT); }
       delay(2000); 
}

  void loop() {    
                
                float power [255] ;  
              //  float a0Val [255] ;
              //  float current [255] ;
          // Loop through the binary values 0 to 255 
                for ( i = 35; i <= 255; i++) {   

          // Write the binary value to pins 0 to 7
                  for (int j = 0; j <= 7; j++) {        
                    digitalWrite(j, bitRead(i, j));     // comment here
                  }
          // read analog input values of A0, A1, and A2               
                  float a0Val   = ( analogRead(A0) * 5.0 ) / 1023.0;     // Reads voltage output of PV System
                  float a1Val   = ( analogRead(A1) * 5.0 ) / 1023.0;     // offsetVoltage Reads Voltage output from Current Sensor (PV End)
                  float a2Val   = analogRead(A2) ;                       // Reads Voltage output from Current Sensor (Load End)
                  float current = a1Val * 10.0 ;
                  float voltage = a0Val * 10.0 ;
                    power [i]   = voltage * current ;
                                     
          // display the input values on the LCD display
              
              lcd.setCursor(9,0);
              lcd.print(i);

              lcd.setCursor(9,1);
          //  lcd.print("PV V=");
              lcd.print(voltage);
              lcd.setCursor(9,2);
              lcd.print(current );

              lcd.setCursor(9,3);
              lcd.print(power [i]);
              delay(100); // Adjust the delay time as needed
        }  

          
          // Finds largest Value in the array power[i] 
          for ( i=1; i<=255 ; i++ ) {
           if ( power [0] < power [i] ) power [0] = power [i] ;
          }
          MPP = power [0] ;
            // Finds the value of i for which power[i] is largest 
            for ( i=1; i<=255 ; i++ ) {
              if ( power [i] = MPP ) {
                for (int j = 0; j <= 7; j++) {
                  digitalWrite(j, bitRead(i, j));  // comment here
                  lcd.setCursor(9,3);
                  lcd.print(power[i]);
                  delay (5000) ;
                }    
              }
            }
        
  } 
                  
  
 /* 
  for (i=0 ; i<=255 ; i++) {
    for (int j=i+1 ; j<= 255 ; j++) {
      if power [i] > power [j] {
        temp = power [i] ;
        power [i] = power [j] ;
        power [j] = temp ;
      }

    }

  }
 */
