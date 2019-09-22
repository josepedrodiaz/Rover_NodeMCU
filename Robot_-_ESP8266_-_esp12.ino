#include <ESP8266WiFi.h>

//Init Web Server
#include <ESP8266WebServer.h>
ESP8266WebServer server(444);

#include <Servo.h> 
#include <DNSServer.h>
#include <WiFiManager.h>  

//for LED status WiFi
#include <Ticker.h>
Ticker ticker;
void tick()
{
  //toggle state
  int state = digitalRead(2);  // get the current state of GPIO1 pin
  digitalWrite(2, !state);     // set pin to the opposite state
}


//Motores
//Motor1
int pin1A = 12;
int pin1B = 13;

//Motor2
int pin2A = 4;
int pin2B = 5;

//Servos
Servo servoHorizontal,servoVertical;
int servoHorizontalPos = 0;//servo init postion
int servoVerticalPos = 0;//servo init postion

 
void setup(void){

  Serial.begin(115200);
  
  //Servos Setup
  servoHorizontal.attach(14);  // attaches the servo on pin 9 to the servo object 
  servoVertical.attach(16);  // attaches the servo on pin 9 to the servo object 
  
  
  // prepare Pins
  //Motors
  pinMode(pin1A, OUTPUT);
  digitalWrite(pin1A, 0);
  pinMode(pin1B, OUTPUT);
  digitalWrite(pin1B, 0);
  pinMode(pin2A, OUTPUT);
  digitalWrite(pin2A, 0);
  pinMode(pin2B, OUTPUT);
  digitalWrite(pin2B, 0);
  
  //Extra PIns 2 y 13 (lights - camera switchs - to do -)
  pinMode(12, OUTPUT);
  digitalWrite(12, 0);
  pinMode(13, OUTPUT);
  digitalWrite(13, 0);
  
  //show default index page
  server.on("/", handleRoot);
  
  //set Urls de acceso directo a cada pin de los motores: 
  //ej: /gpio/1A/0 = pin1A LOW
  urlsPins();
  
  //set Urls de acceso a pins de servos
  //a desarrolar 
  urlsServos();
  
  //Setea alguna Urls semanticas para mover el robot
  //ej.: /frena all 4 motor pins (2,0,4,5) seted to LOW
  setUrls();
  
  //Crea lnterfaz de usuario
  setUX();
  
  //handle 404
  server.onNotFound(handleNotFound);
  
  server.begin();
  Serial.println("HTTP server started");
  
  //set led pin as output
  pinMode(2, OUTPUT);
  // start ticker with 0.5 because we start in AP mode and try to connect
  ticker.attach(0.6, tick);

  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;
  //reset settings - for testing
  wifiManager.resetSettings();

  //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wifiManager.setAPCallback(configModeCallback);

  //fetches ssid and pass and tries to connect
  //if it does not connect it starts an access point with the specified name
  //here  "AutoConnectAP"
  //and goes into a blocking loop awaiting configuration
  if (!wifiManager.autoConnect()) {
    Serial.println("failed to connect and hit timeout");
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(1000);
  }

  //if you get here you have connected to the WiFi
  Serial.println("connected...yeey :)");
  ticker.detach();
  //keep LED on
  digitalWrite(2, LOW);
}
 
void loop(void){//LOOP@!
  server.handleClient();
} 
