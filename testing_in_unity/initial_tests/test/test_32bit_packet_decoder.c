
#include "unity.h"
#include "32bit_packet_decoder.h"

void test_CRC_should_ReturnValidOutput(void) 
{
    char input[] = {"1234abcd"};
    TEST_ASSERT_EQUAL_HEX32(0x3, _32bit_packet_decoder(input));
} // Let's work on changing this to more applicable input please...

int main(void) 
{
    UNITY_BEGIN();
    RUN_TEST(test_CRC_should_ReturnValidOutput);
    return UNITY_END();
}