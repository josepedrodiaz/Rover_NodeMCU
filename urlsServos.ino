void urlsServos(){
  //
  //Mueve un paso hacia la izquierda
  //
  server.on("/servoHorizontal/l", [](){
      if(servoHorizontalPos < 180){
        servoHorizontalPos += 18;
        servoHorizontal.write(servoHorizontalPos); 
      }else{
        servoHorizontalPos = 0;
        servoHorizontal.write(servoHorizontalPos); 
      }
      server.send(200, "text/html", "Servo Horizontal Left");
    });
  
  //
  //Mueve un paso hacia la derecha
  //  
  server.on("/servoHorizontal/r", [](){
      if(servoHorizontalPos > 0){
        servoHorizontalPos -= 18;
        servoHorizontal.write(servoHorizontalPos); 
      }else{
        servoHorizontalPos = 180;
        servoHorizontal.write(servoHorizontalPos); 
      }
      server.send(200, "text/html", "Servo Horizontal Right");
    });
  
  //
  //Mueve un paso hacia Arriba
  //  
  server.on("/servoVertical/up", [](){
      if(servoVerticalPos < 180){
        servoVerticalPos += 18;
        servoVertical.write(servoVerticalPos); 
      }else{
        servoVerticalPos = 180;
        servoVertical.write(servoVerticalPos); 
      }
      server.send(200, "text/html", "Servo Vertical Up");
    });
  
  //
  //Mueve un paso hacia abajo
  //  
  server.on("/servoVertical/down", [](){
    if(servoVerticalPos > 0){
        servoVerticalPos -= 18;
        servoVertical.write(servoVerticalPos); 
      }else{
        servoVerticalPos = 0;
        servoVertical.write(servoVerticalPos); 
      }
      server.send(200, "text/html", "Servo Vertical Down");    
    });
}
