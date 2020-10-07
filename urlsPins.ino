void urlsPins() {
  server.on("/inline", []() {
    server.send(200, "text/html", "this works as well");
  });
}
