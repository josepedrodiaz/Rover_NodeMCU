void handleRoot() {
  //Responde al llamado a la raiz ("/") del sitio
   // Prepare the response for index page
  String html = "<script>"
                "function mobileCheck() {"
                "  var check = false;"
                "  if(typeof window.orientation !== 'undefined'){"
                "  	check = true;"
                "  }"
                "  return check;"
                "}"
                "if( mobileCheck() == true){"
                "	location.href = '/mobile';"
                "}else{"
                "	location.href = '/desktop';"
                "}"
                "</script>";
  server.send(200, "text/html", html);
}


//404 server page
void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}



//Setup all urls associated with actions
void setUrls(){


  server.on("/adelante", [](){
    digitalWrite(pin1A, HIGH);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2A, HIGH);
    digitalWrite(pin2B, LOW);
    
    server.send(200, "text/html", "{\"mensaje\": \"El robot está moviéndose hacia adelante\"}");
  });
  
  server.on("/atras", [](){
    digitalWrite(pin1A, LOW);
    digitalWrite(pin1B, HIGH);
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, HIGH);    

    server.send(200, "text/html", "{\"mensaje\": \"El robot está moviéndose hacia atrás\"}");
  });
  
  server.on("/izquierda", [](){
    digitalWrite(pin1A, HIGH);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, LOW);  
    
    server.send(200, "text/html", "{\"mensaje\": \"El robot está moviéndose hacia la izquierda\"}");
  });
  
  server.on("/derecha", [](){
    digitalWrite(pin1A, LOW);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2A, HIGH);
    digitalWrite(pin2B, LOW);  
    
    server.send(200, "text/html",  "{\"mensaje\": \"El robot está moviéndose hacia la derecha\"}");
  });
  
server.on("/frena", [](){
    digitalWrite(pin1A, LOW);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, LOW);    
    
    server.send(200, "text/html", "{\"mensaje\": \"El robot ha frenado\"}");
  });
  
server.on("/loco-derecha", [](){
    digitalWrite(pin1A, LOW);
    digitalWrite(pin1B, HIGH);
    digitalWrite(pin2A, HIGH);
    digitalWrite(pin2B, LOW); 
    
    server.send(200, "text/html",  "{\"mensaje\": \"El robot gira sobre su eje hacia la derecha\"}");
  });
  
server.on("/loco-izquierda", [](){
    digitalWrite(pin1A, HIGH);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, HIGH); 
    
    server.send(200, "text/html",  "{\"mensaje\": \"El robot gira sobre su eje hacia la izquierda\"");
  });
//Battery measurement
server.on("/battCheck", [](){
    String volts = String(analogRead(A0));
    server.send(200, "text/html", volts);
  });
}

// frena el robot
void frena(){
    digitalWrite(pin1A, LOW);
    digitalWrite(pin1B, LOW);
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, LOW);
}
