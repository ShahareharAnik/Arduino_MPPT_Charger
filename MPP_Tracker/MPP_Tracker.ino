 
 int i = 0 ; // microseconds
 
void setup() {
   
  pinMode(13, OUTPUT) ;
  
  
}

void loop() {                        
    /*
     digitalWrite(13, HIGH);
     delay( 100 ) ;
     digitalWrite(13, LOW);
     delay( 100 ) ;
      */

      /*
      analogWrite(13, 255) ;
      delay( 1000 ) ;
      analogWrite(13, 0) ;
      delay( 1000 ) ;
      */
      digitalWrite(13, HIGH) ;
      delayMicroseconds( 100 ) ;
      digitalWrite(13, LOW) ;
      delayMicroseconds( 1 ) ;

      
       
     
}

                    