#include <Arduino.h>
#include <unity.h>
#include <DHT.h>
DHT dht(33, DHT22);
void setup() {
    UNITY_BEGIN();
    dht.begin(55);
}
void test_DHT(void){
    TEST_ASSERT_NOT_EQUAL(0,dht.readHumidity())
}
void loop() {
    RUN_TEST(test_DHT);
    UNITY_END();
}