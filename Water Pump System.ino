#define BLYNK_TEMPLATE_ID "TMPL6C-cubz2Q"
#define BLYNK_TEMPLATE_NAME "AAAA"
#define BLYNK_AUTH_TOKEN "r7Bh9ae7EYzXl9eh4gv8v1oJ7kAgPHPY"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define LED1 D1
#define LED2 D3

char auth[] = BLYNK_AUTH_TOKEN;   
char ssid[] = "SPT Teacher@wifi"; 
char pass[] = "";     

WidgetLED LED_1(V1);
WidgetLED LED_2(V3);

void setup()
{
  Serial.begin(9600);

  pinMode(LED1,OUTPUT); 
  pinMode(LED2,OUTPUT); 

  digitalWrite(LED1, HIGH); 
  digitalWrite(LED2, LOW); 

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V2){ 
  Serial.println(param.asInt()); 
    if (param.asInt()){ 
        digitalWrite(LED1, LOW); 
        LED_1.on();
    } else {
        digitalWrite(LED1, HIGH); 
        LED_1.off();
    }
}

BLYNK_WRITE(V4){ 
  Serial.println(param.asInt()); 
    if (param.asInt()){ 
        digitalWrite(LED2, HIGH); 
        LED_2.on();
    } else {
        digitalWrite(LED2, LOW); 
        LED_2.off();
    }
}