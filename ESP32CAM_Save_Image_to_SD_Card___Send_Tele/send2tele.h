//
//String sendCapturedImage2Telegram(String BOT_TOKEN, String CHAT_ID) {
//  const char* myDomain = "api.telegram.org";
//  String getAll="", getBody = "";
//
//  camera_fb_t * fb = NULL;
//  fb = esp_camera_fb_get();  
//  if(!fb) {
//    Serial.println("Camera capture failed");
//    delay(1000);
//    ESP.restart();
//    return "Camera capture failed";
//}
//
//Serial.println("Connect to " + String(myDomain));
//
//  WiFiClientSecure client_tcp;
//  client_tcp.setInsecure();
//
//  if (client_tcp.connect(myDomain, 443)) {
//    Serial.println("Connection successful");
//    
//    String head = "--Taiwan\r\nContent-Disposition: form-data; name=\"chat_id\"; \r\n\r\n" + CHAT_ID + "\r\n--Taiwan\r\nContent-Disposition: form-data; name=\"photo\"; filename=\"esp32-cam.jpg\"\r\nContent-Type: image/jpeg\r\n\r\n";
//    String tail = "\r\n--Taiwan--\r\n";
//    uint16_t imageLen = fb->len;
//    uint16_t extraLen = head.length() + tail.length();
//    uint16_t totalLen = imageLen + extraLen;
//  
//    client_tcp.println("POST /bot"+BOT_TOKEN+"/sendPhoto HTTP/1.1");
//    client_tcp.println("Host: " + String(myDomain));
//    client_tcp.println("Content-Length: " + String(totalLen));
//    client_tcp.println("Content-Type: multipart/form-data; boundary=Taiwan");
//    client_tcp.println();
//    client_tcp.print(head);
//  
//    uint8_t *fbBuf = fb->buf;
//    size_t fbLen = fb->len;
//    for (size_t n=0;n<fbLen;n=n+1024) {
//      if (n+1024<fbLen) {
//        client_tcp.write(fbBuf, 1024);
//        fbBuf += 1024;
//      } else if (fbLen%1024>0) {
//        size_t remainder = fbLen%1024;
//        client_tcp.write(fbBuf, remainder);
//      }
//    }  
//
//    client_tcp.print(tail);
//
//    esp_camera_fb_return(fb);
//
//    int waitTime = 10000;   // timeout 10 seconds
//    long startTime = millis();
//    boolean state = false;
//
//    while ((startTime + waitTime) > millis()) {
//      Serial.print(".");
//      delay(100);      
//      while (client_tcp.available()) {
//          char c = client_tcp.read();
//          if (state==true) getBody += String(c);        
//          if (c == '\n') {
//            if (getAll.length()==0) state=true; 
//            getAll = "";
//          } 
//          else if (c != '\r')
//            getAll += String(c);
//          startTime = millis();
//       }
//       if (getBody.length()>0) break;
//    }
//    client_tcp.stop();
//    Serial.println();
//    Serial.println(getBody);
//  } else {
//    getBody="Connected to api.telegram.org failed.";
//    Serial.println("Connected to api.telegram.org failed.");
//  }
//  
//  return getBody;
//}
//
//String sendMessage2Telegram(String token, String chat_id, String text) {
//  const char* myDomain = "api.telegram.org";
//  String getAll="", getBody = "";
//  
//  Serial.println("Connect to " + String(myDomain));
//  
//  WiFiClientSecure client_tcp;
//  client_tcp.setInsecure();   //run version 1.0.5 or above
//  
//  if (client_tcp.connect(myDomain, 443)) {
//    Serial.println("Connection successful");
//
//    String message = "chat_id="+chat_id+"&text="+text;
//    client_tcp.println("POST /bot"+token+"/sendMessage HTTP/1.1");
//    client_tcp.println("Host: " + String(myDomain));
//    client_tcp.println("Content-Length: " + String(message.length()));
//    client_tcp.println("Content-Type: application/x-www-form-urlencoded");
//    client_tcp.println();
//    client_tcp.print(message);
//    
//    int waitTime = 10000;   // timeout 10 seconds
//    long startTime = millis();
//    boolean state = false;
//    
//    while ((startTime + waitTime) > millis()) {
//      Serial.print(".");
//      delay(100);      
//      while (client_tcp.available()) {
//          char c = client_tcp.read();
//          if (state==true) getBody += String(c);        
//          if (c == '\n') {
//            if (getAll.length()==0) state=true; 
//            getAll = "";
//          } 
//          else if (c != '\r')
//            getAll += String(c);
//          startTime = millis();
//       }
//       if (getBody.length()>0) break;
//    }
//    client_tcp.stop();
//    Serial.println();
//    Serial.println(getBody);
//  } else {
//    getBody="Connected to api.telegram.org failed.";
//    Serial.println("Connected to api.telegram.org failed.");
//  }
//  
//  return getBody;
//}
