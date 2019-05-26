#include <SoftwareSerial.h>
#include "WiFiEsp.h"
SoftwareSerial SerialWifi(6, 7);
char ssid[] = "wifi skrivs här";
char pass[] = "WIFI LÖSEN SKRIVS HÄR";
int status = WL_IDLE_STATUS;
WiFiEspServer server(80);
RingBuffer buf(8);

void setup() {

  Serial.begin(115200);
  SerialWifi.begin(9600);
  WiFi.init(&SerialWifi);
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);
  }
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    server.begin();
  }
    printWifiStatus();
    //delay(5000);
}

void loop() {
  WiFiEspClient client = server.available();
  if (client) {
    buf.init(); 
    Serial.println("New client");
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        buf.push(c);

        
        if (c == '\n' && currentLineIsBlank) 
        {
          Serial.println("Sending response");

          // Send a standard HTTP response header
          client.print(
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n"
            "\r\n");
          client.print("<!DOCTYPE HTML>\r\n");
          client.print("<html>\r\n");
          client.print("<head>\r\n");
          
          
          client.print("<link rel=\"stylesheet\" href=\"https://lindaljub.github.io/Css/arduino.css\">");
            
          //client.print("<link rel=\"stylesheet\" href=\"http://primat.se/services/css/arduino.css\">");
          client.print("<link rel=\"shortcut icon\" href=\"about:blank\">");
          client.print("<title>AServer</title>\r\n");
          client.print("</head>\r\n");
          client.print("<body>");
         
          // div container börjar
          client.print("<div class=\"grid-container\">");

          client.print("<div class=\"header\">");
          client.print("<h1>Lindas Arduino</h1>");
          client.print("</div>");
          
          client.print("<div class=\"sida1\">");
          client.print("<h3>box1</h3>");
          client.print("</div>");
          
          client.print("<div class=\"sida2\">");
          client.print("<h3>box2</h3>");
          client.print("</div>");

          // här slutar div container
          client.print("</div>");
     
          client.print("</body>");
          client.print("</html>");
          break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }

    delay(3000);

    client.stop();
    Serial.println("Client disconnected");
  }
}


void printWifiStatus()
{
    // print the SSID of the network you're attached to
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print your WiFi shield's IP address
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print the received signal strength
    long rssi = WiFi.RSSI();
    Serial.print("Signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");

}
