#include <ESP8266WiFi.h>

//Esp File system
#include <FS.h>


//Init Web Server
#include <ESP8266WebServer.h>
ESP8266WebServer server(444);

//Save IP Adress value
IPAddress ip;

#include <Servo.h>
#include <DNSServer.h>
#include <WiFiManager.h>


//Motores
int PWMA = 5; //Right side
int PWMB = 4; //Left side
int DA = 0; //Right reverse
int DB = 2; //Left reverse

//Servos
Servo servoHorizontal, servoVertical;
int servoHorizontalPos = 90;//servo init postion
int servoVerticalPos = 90;//servo init postion


void setup(void) {

  Serial.begin(115200);

  //Servos Setup
  servoHorizontal.attach(16);  // attaches the servo on pin 9 to the servo object
  servoVertical.attach(5);  // attaches the servo on pin 9 to the servo object


  // prepare Pins
  //Motors init
  pinMode(PWMA, OUTPUT);
  digitalWrite(PWMA, LOW);
  pinMode(PWMB, OUTPUT);
  digitalWrite(PWMB, LOW);
  pinMode(DA, OUTPUT);
  digitalWrite(DA, LOW);
  pinMode(DB, OUTPUT);
  digitalWrite(DB, LOW);

  //Extra PIns 2 y 13 (lights - camera switchs - to do -)
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
  //server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");

  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;
  //reset settings - for testing
  //wifiManager.resetSettings();

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
  //print the local IP address
  ip = WiFi.localIP();
  Serial.println(ip);
  //keep LED on
  digitalWrite(2, LOW);

  //FIle system init
  if (!SPIFFS.begin())
  {
    // Serious problem
    Serial.println("ERROR! SPIFFS Mount failed");
  } else {
    Serial.println("OK! SPIFFS Mount succesfull");
  }

  server.onNotFound(handleOther);
}

void loop(void) { //LOOP@!
  server.handleClient();
}
