#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>

String name = "kevin";
int age = 12;
bool authorisation = true;
const char* Wifi_name = "iPhone";
const char* Wifi_password = "christdaniel";
HTTPClient http1;
String url1 = "http://localhost:5000/api/measurement";

void setup(){
    Serial.begin(115200);
    WiFi.begin(Wifi_name,Wifi_password);
    while (WiFi.status() != WL_CONNECTED)
    {
         delay(100);
    }
}

void loop(){
    http1.begin(url1);
    http1.addHeader("Content-Type", "application/json");
    String json = "{";
    json += "\"name\" : \"+ name +\""; 
    json += "\"age\" : \"+ age +\"";
    json += "\"authorisation\" :";
    json +=(authorisation ? "true" : "false");
    json += "}";
    int reponse = http1.POST(json); 
    http1.end();
    if (reponse != 200){
        Serial.println("Echec");
    }else{
        Serial.println("Succes");
    }
}

