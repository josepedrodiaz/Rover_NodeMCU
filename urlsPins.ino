void urlsPins(){
  server.on("/inline", [](){
    server.send(200, "text/html", "this works as well");
  });
  
  server.on("/gpio/1A/0", [](){
    digitalWrite(pin1A, LOW);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
  
  server.on("/gpio/1A/1", [](){
    digitalWrite(pin1A, HIGH);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
  
  server.on("/gpio/1B/0", [](){
    digitalWrite(pin1B, LOW);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
  
  server.on("/gpio/1B/1", [](){
    digitalWrite(pin1B, HIGH);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
  
  
  server.on("/gpio/2A/0", [](){
    digitalWrite(pin2A, LOW);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
  
  server.on("/gpio/2A/1", [](){
    digitalWrite(pin2A, HIGH);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
  
  server.on("/gpio/2B/0", [](){
    digitalWrite(pin2B, LOW);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
  
  server.on("/gpio/2B/1", [](){
    digitalWrite(pin2B, HIGH);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
  
  server.on("/gpio/12/0", [](){
    digitalWrite(12, LOW);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
   server.on("/gpio/12/1", [](){
    digitalWrite(12, HIGH);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
  
  server.on("/gpio/13/0", [](){
    digitalWrite(13, LOW);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
   server.on("/gpio/13/1", [](){
    digitalWrite(13, HIGH);
    server.send(200, "text/html", "this works as well<script>history.back();</script>");
  });
}
