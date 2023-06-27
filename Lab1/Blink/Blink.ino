/*


While it is easy to create a blinking LED with the delay() function, 
and many sketches use short delays for such tasks as switch debouncing, 
the use of delay() in a sketch has significant drawbacks. No other reading 
of sensors, mathematical calculations, or pin manipulation can go on 
during the delay function, so in effect, it brings most other activity to a halt. 
For alternative approaches to controlling timing see the Blink Without Delay sketch, 
which loops, polling the millis() function until enough time has elapsed. More 
knowledgeable programmers usually avoid the use of delay() for timing of events longer 
than 10’s of milliseconds unless the Arduino sketch is very simple.


*/

// the setup function runs once when you press reset or power the board
int speaker = 2;
int LED = 10;


const unsigned long event1_speaker = 1;
const unsigned long event2_LED = 200;

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

  } else {

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
  
  

  

  

    speaker_hz();
    LED_blink();
    


  }

  
 
  
 
                      