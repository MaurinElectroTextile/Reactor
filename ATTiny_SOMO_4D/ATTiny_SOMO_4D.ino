// This project is combining ATTiny85 and SOMO-4D module
// the electronic board is made for stand alone audio player controlled by a knitted fabric sensor
// this sketch implement sleep mode to reduce power consumption
////////////////////
#include <avr/sleep.h>
#include <avr/wdt.h>         // Watchdog timer handling

unsigned int sound[] = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
  10, 11, 12, 13, 14, 15,
  16, 17, 18, 

};

unsigned int volume[] = {
  0xfff0, 0xfff1, 0xfff2, 0xfff3, 0xfff4, 0xfff5, 0xfff6, 0xfff7
};

const int clockPin = 0;           // SOMO-4D clock pin
const int dataPin = 1;            // SOMO-4D data pin
const int resetPin = 2;           // ATTiny analog 1 to SOMO-4D reset pin
const int volumePin = 4;          // ATTiny analog 2 as input to trigger SOMO-4D volume
const int sensorPin = 3;          // ATTiny analog 3 to sens potentiometer scarf
const int DEBOUNCETIME = 16;      // debounce to avoid double playing instructions
const int THRESHOLD_SENS = 35;    // threshold for analog input sensing
const int INACTIVETIME = 500;     // time before sleeping mode
const int THRESHOLD_SWITCH = 100; //

unsigned long curentMillis = 0;
unsigned long lastMillis = 0;
unsigned long lastPlayingTime = 0;
unsigned long curentInactiveTime = 0;

unsigned int rowSensorVal = 0;
unsigned int lastRowSensorVal = 0;
int derivee = 0;
boolean toggle = false;

boolean volumeSwitch = 0;
boolean toggelSwitch = true;
unsigned int curentVolume = 7;

unsigned int pos = 0;

/////////////////////// initialisation
void setup(){

  pinMode(clockPin, OUTPUT);  // set pin to output for clock
  pinMode(dataPin, OUTPUT);   // set pin to output for data
  pinMode(resetPin, OUTPUT);  // set pin to output for reset

  // ajouter une resistance pullUp sur la carte pour l'interrupteur de vollume
  pinMode(volumePin, INPUT);      // set pin to input for volume control
  digitalWrite(volumePin, HIGH);  // enable internal pull-up resistor

  digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin, LOW);

  //////////////////////////////////////// initialize watchdog timer
  sendData(volume[curentVolume]);          // set SOMO-4D volume
  WDT_Init();
  somoReset();  
}

/////////////////////// boucle principale
void loop(){

  curentMillis = millis();

  //if((curentMillis - lastMillis) >= DEBOUNCETIME){  // slow down analog readings

    lastMillis = curentMillis;
    curentInactiveTime = (curentMillis - lastPlayingTime);

    rowSensorVal = analogRead(sensorPin);
    derivee = rowSensorVal - lastRowSensorVal;
    lastRowSensorVal = rowSensorVal;

    if(derivee < THRESHOLD_SENS && curentInactiveTime >= INACTIVETIME){
      somoLowPower();
      enable_wdt();
      sleepNow();
      disable_wdt();
      lastMillis = millis();
      lastPlayingTime = millis();
    }

    if(toggle == true && derivee >= THRESHOLD_SENS){
      lastPlayingTime = curentMillis;
      toggle = false;                  // play only one sound
      // sendData( sound[random(7)] );
      sendData(int(pos++ % 36));
    }
    if(toggle == false && derivee < THRESHOLD_SENS){
      toggle = true;
    }
  //}
}

///////////////////////////////////////// fonctions

/////////////////////// Watchdog Interrupt Service Routine
// EMPTY_INTERRUPT(WDT_vect);
ISR(WDT_vect){  // go back to the main loop when we get an interrupt from the watchdog timer
}

/////////////////////// Init ATTiny WDT
void WDT_Init(void){
  WDTCR = 0x00;                   // clear WDTCR register
}

///////////////////////  Put ATTiny to sleep
void sleepNow(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  // Enter power down mode
  sleep_mode();                         // put to sleep
}

/////////////////////// Set ATTiny WDT ON
void enable_wdt(void){
  cli();
  wdt_reset();
  WDTCR |= (1 << WDCE) | (1 << WDE);                                 // enable WDT 4 cycle timer operation bit 
  // WDTCR |= (1 << WDE) | (1 << WDIE) | (1 << WDP2);                // 0.25s timeout, interrupt mode
  WDTCR |= (1 << WDE) | (1 << WDIE) | (1 << WDP2) | (1 << WDP1);     // 1.0s timeout, interrupt mode
  // WDTCR |= (1 << WDE) | (1 << WDIE) | (1 << WDP3);                // 4.0s timeout, interrupt mode
  sei();
}

/////////////////////// Set ATTiny WDT OFF
void disable_wdt(void){
  cli();
  // wdt_reset();
  // WDTCR |= (1 << WDIE);                  // WDIE must be set after each interrupt to avoid the watchdog reset
  // MCUCR &= ~(1 << WDRF);                 // WDRF must be cleared before WDE can be cleared 
  MCUSR = 0;                                // Clear WDRF in MCUSR
  WDTCR |= (1 << WDCE) | (1 << WDE);        // enable WDT 4 cycle timer operation bit 
  // WDTCR &= ~(1 << WDIE);                 // disable WDT interrupt
  WDTCR = 0x00; // Turn off WDT 
  sei();
}

/////////////////////////////// send data to SOMO module
void sendData(int thisSong){
  int theSong = thisSong;
  int clockCounter = 0;
  int clockCycle = 15;

  // digitalWrite(clockPin, HIGH); // Hold (idle) for 300msec to prepare data start
  digitalWrite(clockPin, LOW);  // Hold for 2msec to signal data start
  //delay(2);                   // 2msec delay
  delayMicroseconds(260);       //

  while(clockCounter <= clockCycle){
    digitalWrite(clockPin, LOW);
    if(theSong & 0x8000){
      digitalWrite(dataPin, HIGH);
    } 
    else {
      digitalWrite(dataPin, LOW);
    }
    theSong = theSong << 1;
    delayMicroseconds(25); // Clock cycle period is 200 uSec - LOW
    digitalWrite(clockPin, HIGH);
    clockCounter++;
    delayMicroseconds(25); // Clock cycle period is 200 uSec - HIGH
  }
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, HIGH); // Place clock high to signal end of data
}

/////////////////////// Reset SOMO-4D
void somoReset(){
  digitalWrite(resetPin, LOW);
  delay(10);
  digitalWrite(resetPin, HIGH);
}

/////////////////////// Reset SOMO-4D
void somoLowPower(){
  digitalWrite(resetPin, LOW);
  delay(130);
  digitalWrite(resetPin, HIGH);
}


