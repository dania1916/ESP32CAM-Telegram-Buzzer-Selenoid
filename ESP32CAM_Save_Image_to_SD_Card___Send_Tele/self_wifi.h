#include <WiFi.h>
#define WIFI_SSID_STR   "Rainy"
#define WIFI_PWD_STR    ""

#define GET_MS_TICK(x)  (millis() - elapsed_time) > x

static uint32_t elapsed_time = 0;

void wifi_init_system(){
    WiFi.begin((const char*)WIFI_SSID_STR, (const char*)WIFI_PWD_STR);

    uint8_t flag_connected = 0;

    Serial.print("[WIFI] Connecting ");
    elapsed_time = millis();
    while(WiFi.status() != WL_CONNECTED){
        if(GET_MS_TICK(1000)){
            if(flag_connected >= 8){
                Serial.println("\n[WIFI] WiFi connect timeout!");
                break;
            }

            Serial.print("*");
            flag_connected++;

            elapsed_time = millis();
        }
    }

    if(flag_connected < 8){
        Serial.println("\n[WIFI] WiFi connected");
        Serial.println("[WIFI] IP Address : " + WiFi.localIP().toString());
        //local_IP = WiFi.localIP().toString();
    }else{
        Serial.println("[WIFI] WiFi not connected!");
    }
}
