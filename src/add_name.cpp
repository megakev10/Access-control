#include <Arduino.h>
#include <Preferences.h>

Preferences pref;
int d;

class identification{
    public:
    String take_name();
    void Saving();
    private:
     String name;
};

String identification::take_name(){
    while (!Serial.available()){}
    name = Serial.readString();
    return name;     
}

void identification::Saving(){
    pref.begin("users_infos", false);
        pref.putString("names", take_name());
        Serial.printf("salut %s", pref.getString("name"));
    pref.end();
}

int decision(){
    Serial.println("Entrez 1 pour lire le nom enregistre, 2 pour mettre votre nom");
    while (!Serial.available()){ }
    d = Serial.parseInt();
    return d;
}

void setup(){
    Serial.begin(115200);
    identification identity;
    d = decision();
    if(d == 1){
        identity.Saving();
    }else{
    Serial.println("lancons le test d'identification");
    Serial.println("Veuillez entrer votre nom");
    delay(4000);
    String n = identity.take_name();
    Serial.println(n);
    identity.Saving();
}}

void loop(){}