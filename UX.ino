void setUX(){
  /*
  /DESKTOP UI 23/01/2016  - P. Diaz
  */
  server.on("/desktop", [](){
  
    // Prepare the UI response for desktop client
  String html = "<!doctype html>\r\n"
"<html lang=\"es\">\r\n"
"<head>\r\n"
"   <meta charset=\"utf-8\">\r\n"
"   <title>Descangallado - Live</title>\r\n"
"   <link rel=\"stylesheet\" href=\"//code.jquery.com/ui/1.11.4/themes/smoothness/jquery-ui.css\">\r\n"
"   <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/2.1.4/jquery.min.js\"></script>\r\n"
"   <script src=\"//code.jquery.com/ui/1.11.4/jquery-ui.js\"></script>\r\n"
"   <script src=\"https://combinatronics.com/dmauro/Keypress/development/keypress-2.1.5.min.js\"></script>\r\n"
"   <script src=\"https://combinatronics.com/josepedrodiaz/Rover_NodeMCU/master/js/ux.js\"></script>\r\n"
"   <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css\" integrity=\"sha512-dTfge/zgoMYpP7QbHy4gWMEGsbsdZeCXz7irItjcC3sPUFtf0kuFbDz/ixG7ArTxmDjLXDmezHubeNikyKGVyQ==\" crossorigin=\"anonymous\">\r\n"
"   <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap-theme.min.css\" integrity=\"sha384-aUGj/X2zp5rLCbBxumKTCw2Z50WgIr1vs/PFN4praOTvYXWlVyh2UtNUU0KAUhAX\" crossorigin=\"anonymous\">\r\n"
"   <script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js\" integrity=\"sha512-K1qjQ+NcF2TYO/eI3M6v8EiNYZfA95pQumfvcVrTHtwQVDG+aHRqLi/ETn2uB+1JqwYqVG3LIvdm9lj6imS/pQ==\" crossorigin=\"anonymous\"></script>\r\n"
"   <link rel=\"stylesheet\" href=\"https://combinatronics.com/josepedrodiaz/Rover_NodeMCU/master/css/style.css\">\r\n"
"</head>\r\n"
"<body>\r\n"
"<h1>Dale que so' vo!!</h1>"
"<!-- <iframe width=\"100%\" src=\"http://pedrodiaz.no-ip.org:8081\" id=\"ifm\"  frameBorder=\"0\"></iframe> -->\r\n"
"<div id=\"statusDiv\" style=\"color: rgb(255, 235, 59);margin-left: 45%;margin-top: 50px;\">Enviando...</div>\r\n"
"<!-- <button type=\"button\" id=\"checkBatt\"> Nivel de bater&iacute;a</button> -->\r\n"
"<!-- <div id=\"battLevelInfo\"></div> -->\r\n"
"</body>\r\n"
"</html>\r\n";
//END UI RESPONSE

  server.send(200, "text/html", html);
  });
}
