#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti wifiMulti;

const char* host = "server";
const int httpPort = 3000;
const int SerialPort = 115200;

void setup(void)
{
Serial.begin(SerialPort);
Serial.print("setup begin\r\n");
WiFi.begin("SSID", "PASSWORD"); 
Serial.print("Wi-Fi connecting");
while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
}
Serial.print("Wi-Fi connected!!!\r\n");  
Serial.print("setup finished\r\n");
}

void loop() {
  WiFiClient client;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
   String data = "DateTime=002&content=aiueo"; //センサーからデータを取得する（ここではダミー）
   Serial.print("Requesting POST: ");
   client.println("POST / HTTP/1.1");
   client.println("Host: server");
   client.println("Accept: */*");
   client.println("Content-Type: application/x-www-form-urlencoded");
   client.print("Content-Length: ");
   client.println(data.length());
   client.println();
   client.print(data);

   delay(1000);
  if (client.connected()) { 
    client.stop();  
  }
  Serial.println();
  Serial.println("connection closed");
  delay(5000);
  
}
