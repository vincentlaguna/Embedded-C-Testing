
#include "unity.h"
#include "Core.h"
#include "Buffer.h"

#define BUFFER_SIZE (1000)

static uint8_t test_data[BUFFER_SIZE + 1];
static BUFFER_T test_buffer;

void setUp(void)
{
    TEST_ASSERT_EQUAL(STATUS_OK, Buffer_Init(&test_buffer, test_data, BUFFER_SIZE + 1));
}

void test_Buffer_Put_and_Get_should_WorkTogetherToInsertAndExtractAValue(void)
{
    const uint8_t data[ ] = { 0, 1, 0x5A, 0x7F, 0xFF };
    uint8_t fetched;
    int i;

    for (i = 0; i < DIMENSION_OF(data); i++)  {
        TEST_ASSERT_EQUAL(STATUS_OK, Buffer_Put( &test_buffer, data[i] ));
        TEST_ASSERT_EQUAL(STATUS_OK, Buffer_Get( &test_buffer, &fetched ));
        TEST_ASSERT_EQUAL_HEX8(data[i], fetched);
    }
}

void test_Buffer_Get_should_ReturnErrorIfCalledWhenEmpty(void)
{
    uint8_t fetched;

    TEST_ASSERT_NOT_EQUAL(STATUS_OK, Buffer_Get( &test_buffer, &fetched ));
}

void test_Buffer_Put_should_ReturnErrorIfCalledWhenFull(void)
{
    int i;

    for (i = 0; i < BUFFER_SIZE; i++) {
        TEST_ASSERT_EQUAL(STATUS_OK, Buffer_Put( &test_buffer, i));
    }

    TEST_ASSERT_NOT_EQUAL(STATUS_OK, Buffer_Put( &test_buffer, 1));
}

void test_Buffer_Get_should_ProperlyGrabEveryItemFromFullToEmpty(void)
{
    int i;
    uint8_t fetched;

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        TEST_ASSERT_EQUAL(STATUS_OK, Buffer_Put( &test_buffer, i ));
    }

    TEST_ASSERT_NOT_EQUAL(STATUS_OK, Buffer_Put( &test_buffer, 1 ));

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        TEST_ASSERT_EQUAL(STATUS_OK, Buffer_Get( &test_buffer, &fetched ));
        TEST_ASSERT_EQUAL_HEX8(i, fetched);
    }

    TEST_ASSERT_NOT_EQUAL(STATUS_OK, Buffer_Get( &test_buffer, &fetched ));
}

void test_Buffer_IsFull_should_ReturnTrueWhenFullOtherwiseFalse(void)
{
    int i;

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        TEST_ASSERT_FALSE(Buffer_IsFull(&test_buffer));
        TEST_ASSERT_EQUAL(STATUS_OK, Buffer_Put( &test_buffer, i ));
    }

    TEST_ASSERT_TRUE(Buffer_IsFull(&test_buffer));
    TEST_ASSERT_NOT_EQUAL(STATUS_OK, Buffer_Put( &test_buffer, 1 ));
}

void test_Buffer_IsEmpty_should_ReturnTrueWhenEmptyOtherwiseFalse(void)
{
    int i;
    uint8_t fetched;

    TEST_ASSERT_TRUE(Buffer_IsEmpty(&test_buffer));

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        TEST_ASSERT_EQUAL(STATUS_OK, Buffer_Put( &test_buffer, i ));
        TEST_ASSERT_FALSE(Buffer_IsEmpty(&test_buffer));
    }

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        TEST_ASSERT_FALSE(Buffer_IsEmpty(&test_buffer));
        TEST_ASSERT_EQUAL(STATUS_OK, Buffer_Get( &test_buffer, &fetched ));
    }

    TEST_ASSERT_TRUE(Buffer_IsEmpty(&test_buffer));
}

void test_Buffer_Clear_should_ClearItIfCleared(void)
{
    TEST_ASSERT_TRUE(Buffer_IsEmpty( &test_buffer ));
    Buffer_Clear( &test_buffer );
    TEST_ASSERT_TRUE(Buffer_IsEmpty( &test_buffer ));
}

void test_Buffer_Clear_should_ClearItIfSomeElementsInIt(void)
{
    int i;

    TEST_ASSERT_TRUE(Buffer_IsEmpty( &test_buffer ));
    Buffer_Clear( &test_buffer );
    TEST_ASSERT_TRUE(Buffer_IsEmpty( &test_buffer ));

    for (i = 0; i < 3; i++)
        TEST_ASSERT_EQUAL(STATUS_OK, Buffer_Put( &test_buffer, i ));
    TEST_ASSERT_FALSE(Buffer_IsEmpty( &test_buffer ));

    Buffer_Clear( &test_buffer );
    TEST_ASSERT_TRUE(Buffer_IsEmpty( &test_buffer ));
}

void test_Buffer_Clear_should_ClearItIfFull(void)
{
    int i;

    TEST_ASSERT_TRUE(Buffer_IsEmpty( &test_buffer ));
    Buffer_Clear( &test_buffer );
    TEST_ASSERT_TRUE(Buffer_IsEmpty( &test_buffer ));

    for (i = 0; i < BUFFER_SIZE; i++)
        TEST_ASSERT_EQUAL(STATUS_OK, Buffer_Put( &test_buffer, i ));
    TEST_ASSERT_FALSE(Buffer_IsEmpty( &test_buffer ));

    Buffer_Clear( &test_buffer );
    TEST_ASSERT_TRUE(Buffer_IsEmpty( &test_buffer ));
}

