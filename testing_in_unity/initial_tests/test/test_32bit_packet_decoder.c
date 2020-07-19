
#include "unity.h"
#include "32bit_packet_decoder.h"

void test_CRC_should_ReturnValidOutput(void) 
{
    uint32_t input = abcd;
    TEST_ASSERT_EQUAL_HEX32(0x1, _32bit_packet_decoder(input));
}

int main(void) 
{
    UNITY_BEGIN();
    RUN_TEST(test_CRC_should_ReturnValidOutput);
    return UNITY_END();
}