#include <Arduino.h>
#include <unity.h>

void test_green_state_high(void) {
    digitalWrite(13, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(13));
}

void test_green_state_low(void) {
    digitalWrite(13, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(13));
}

void test_red_state_high(void) {
    digitalWrite(27, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(27));
}

void test_red_state_low(void) {
    digitalWrite(27, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(27));
}

void setup() {
    UNITY_BEGIN(); 
    pinMode(13, OUTPUT);
	pinMode(27, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop() {
    if (i < max_blinks)
    {
        RUN_TEST(test_green_state_high);
        delay(500);
        RUN_TEST(test_green_state_low);
        delay(500);
        RUN_TEST(test_red_state_high);
        delay(500);
        RUN_TEST(test_red_state_low);
        delay(500);
        i++;
    }
    else if (i == max_blinks) {
      UNITY_END(); // stop unit testing
    }
}