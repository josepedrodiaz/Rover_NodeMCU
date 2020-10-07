void urlsServos() {
  //
  //Mueve un paso hacia la izquierda
  //
  server.on("/servoHorizontal/l", []() {
    if (servoHorizontalPos < 160) {
      servoHorizontalPos += 10;
      servoHorizontal.write(servoHorizontalPos);
    }
    server.send(200, "text/html", "Servo Horizontal Left");
  });

  //
  //Mueve un paso hacia la derecha
  //
  server.on("/servoHorizontal/r", []() {
    if (servoHorizontalPos > 20) {
      servoHorizontalPos -= 10;
      servoHorizontal.write(servoHorizontalPos);
    }
    server.send(200, "text/html", "Servo Horizontal Right");
  });

  //
  //Mueve un paso hacia Arriba
  //
  server.on("/servoVertical/up", []() {
    if (servoVerticalPos > 20) {
      servoVerticalPos -= 10;
      servoVertical.write(servoVerticalPos);
    }
    server.send(200, "text/html", "Servo Vertical Up");
  });

  //
  //Mueve un paso hacia abajo
  //
  server.on("/servoVertical/down", []() {
    if (servoVerticalPos < 160) {
      servoVerticalPos += 10;
      servoVertical.write(servoVerticalPos);
    }
    server.send(200, "text/html", "Servo Vertical Down");
  });
}
