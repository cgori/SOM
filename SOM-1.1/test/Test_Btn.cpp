#include <Arduino.h>
#include <unity.h>
bool snooze = false;
bool serial = false;
void setup() {
    UNITY_BEGIN();
    pinMode(25, INPUT);
	pinMode(14, INPUT);
    
}
void serial_Test_Btn(void){
    TEST_ASSERT_EQUAL(true, serial);
}
void snooze_Test_Btn(void){
    TEST_ASSERT_EQUAL(true, snooze);
}

void loop() {
    while (millis() < 5000)
    {
       if(digitalRead(25)){
           snooze = true;
       }
       if(digitalRead(14)){
           serial = true;
       }
    }
    RUN_TEST(snooze_Test_Btn);
    RUN_TEST(serial_Test_Btn);
    
    UNITY_END();
}