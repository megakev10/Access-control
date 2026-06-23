#include <Arduino.h>

class identification{
    public:
    String take_name();
    private:
     String name;
};

String identification::take_name(){
    Serial.println("Veuillez entrer votre nom");
    if(Serial.available()){
        name = Serial.readString();
        return name;
    }   
}

void setup(){
    identification identity;
    Serial.println("lancons le test d'identification");
    String n = identity.take_name();
    Serial.println(n);
}

void loop(){}