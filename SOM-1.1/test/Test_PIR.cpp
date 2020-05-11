#include <Arduino.h>
#include <unity.h>

// The PIR test will allow 5 seconds for someone to be detected before failing

void test_pir_state(void) {
    TEST_ASSERT_EQUAL(HIGH, digitalRead(34));
}
void setup() {
    UNITY_BEGIN(); 
    pinMode(34, INPUT);
}

void loop() {
    while(millis() < 5000){
        if(digitalRead(34) == HIGH){
            RUN_TEST(test_pir_state);
            break;
        }
    }
    RUN_TEST(test_pir_state);
    UNITY_END();
}