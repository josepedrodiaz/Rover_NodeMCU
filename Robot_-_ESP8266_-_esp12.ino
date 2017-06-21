#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Servo.h> 
 
const char* ssid = "Cisco68896";
const char* password = "elperrococoliso";
MDNSResponder mdns;

ESP8266WebServer server(444);
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
  WiFi.begin(ssid, password);
  Serial.println("");
  
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

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  Serial.print("Seteando IP estatica: ");
  //set static ip part
  WiFi.config(IPAddress(192,168,2,144),IPAddress(192,168,2,1),IPAddress(255,255,255,0));
  Serial.println(WiFi.localIP());
  
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
  
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
  
  //Interfaz de usuario
    setUX();
  
  //handle 404
  server.onNotFound(handleNotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void){//LOOP@!
  server.handleClient();
} 
