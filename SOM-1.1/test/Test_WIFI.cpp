#include <Arduino.h>
#include <unity.h>
#include "WiFi.h"

void setup() {
    UNITY_BEGIN();
    WiFi.begin("VM-guest4587444", "s$h9SyHRaa5m9b");
}
void test_Wifi_Connection(void) {
    TEST_ASSERT_EQUAL(WL_CONNECTED, WiFi.status());
}


void loop() {
    delay(5000);
    RUN_TEST(test_Wifi_Connection);
    UNITY_END();
}