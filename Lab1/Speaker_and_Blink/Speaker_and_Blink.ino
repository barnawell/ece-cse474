/*

*/

int speaker = 2;
int LED = 10;


const unsigned long event1_speaker = 4;
const unsigned long event2_LED = 400;

unsigned long prev_time1 = 0;
unsigned long prev_time2 = 0;



void setup() {
  

  pinMode(LED, OUTPUT);
  pinMode(speaker, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  

  
}

void speaker_hz(){

  unsigned long currentTime = millis();

    
  if (currentTime - prev_time1 >= event1_speaker){

    digitalWrite(speaker, HIGH);

    prev_time1 = currentTime;

  } else if(currentTime == prev_time1 + event1_speaker / 2) {

    digitalWrite(speaker, LOW);
    
  } 


}


void LED_blink() {

  unsigned long currentTime = millis();
  
  if (currentTime - prev_time2 >= event2_LED) {
    digitalWrite(LED, HIGH);  // Turn on the LED
    digitalWrite(LED_BUILTIN, LOW);  // Turn off the built-in LED
    prev_time2 = currentTime;
  }
  else if (currentTime == prev_time2 + event2_LED / 2) {
    digitalWrite(LED, LOW);  // Turn off the LED
    digitalWrite(LED_BUILTIN, HIGH);  // Turn on the built-in LED
  }
}

// the loop function runs over and over again forever
void loop() {
  
  
    if(millis() >= 5000){ //once you get to five seconds, the void loop holds here
     
     //do nothing

    }else{ 
      
      speaker_hz();
    }

    LED_blink();
    // speaker_hz();
    // if(millis() >= 1000){ //once you get to five seconds, the void loop holds here
     
    //  //do nothing

    // }else{ 
      
    //   LED_blink();
    // }

    

}

  
 
  
 
                      