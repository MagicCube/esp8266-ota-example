#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>

const char *WIFI_SSID = "OTA-Example";
const char *WIFI_PWD = "";
const WiFiMode_t WIFI_MODE = WIFI_AP;

void setup()
{
    Serial.begin(115200);
    WiFi.mode(WIFI_MODE);
    if (WIFI_MODE == WIFI_AP)
    {
        WiFi.softAP(WIFI_SSID, WIFI_PWD);
        IPAddress myIP = WiFi.softAPIP();
        Serial.println("AP is now started as " + String(WIFI_SSID));
        Serial.print("AP IP address: ");
        Serial.println(myIP);
    }
    else if (WIFI_MODE == WIFI_STA)
    {
        WiFi.begin(WIFI_SSID, WIFI_PWD);
        while (WiFi.waitForConnectResult() != WL_CONNECTED)
        {
            Serial.println("Fail to connect to " + String(WIFI_SSID));
            delay(1000);
        }
        Serial.println("Connected to " + String(WIFI_SSID));
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }

    ArduinoOTA.begin();
    pinMode(BUILTIN_LED, OUTPUT);
}

void loop()
{
    ArduinoOTA.handle();
    digitalWrite(BUILTIN_LED, HIGH);
    delay(1000);
    digitalWrite(BUILTIN_LED, LOW);
    delay(1000);
}
