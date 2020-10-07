void handleOther()
{
  String path = server.uri();
  String dataType = "text/plain";
  if (path.endsWith("/")) path = "/index.html";
  if (path.endsWith(".jpg")) dataType = "image/jpeg";
  else if (path.endsWith(".png")) dataType = "image/png";
  else if (path.endsWith(".html")) dataType = "text/html";
  Serial.println(path.c_str());
  File datafile = SPIFFS.open(path.c_str(), "r");
  Serial.println(datafile);
  server.streamFile(datafile, dataType);
  datafile.close();
}
