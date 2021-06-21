/* Sparkfun - Infrared Proximity Sensor Short Range - Sharp GP2Y0A41SK0F
 * on Arduino pin A0 (1v - 3v) floating point value, led on pin 13
 * min distance: 4 cm (0 volts)
 * max distance 30 cm (3 volts)
 * wire diagram: red = 5v, blk = gnd, ylw = output
 */ 

int prox_sensor = A0;
                                   
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);                  
}

void loop() {
  float value = analogRead(prox_sensor);
  Serial.println(value);
  if (value > 140) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(100);
}
