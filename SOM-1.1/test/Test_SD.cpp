#include <Arduino.h>
#include <unity.h>
#include "SD.h"

void setup() {
    UNITY_BEGIN();
}
void test_sd(void){
    TEST_ASSERT_EQUAL(true, SD.begin());
}
void loop() {
    RUN_TEST(test_sd);
    UNITY_END();
}