#include "unity.h"
#include <string.h>

static char HelperFailMsg[128] = { 0 };

static char* HelperTriggerNames[] = {
    "TRIGGER NOW",
    "TRIGGER BIT CHANGE",
    "TRIGGER BIT STATE",
    "TRIGGER SEQUENCE",
    "TRIGGER TIMESTAMP",
    "TRIGGER NONE",
    "TRIGGER INVALID"
};

static inline void AssertEqualTRIGGER_T(TRIGGER_T exp, TRIGGER_T act, UNITY_LINE_TYPE lineNumber, const char* msg)
{
    if (exp != act)
    {
        if (exp > TRIGGER_MAX)
            exp = TRIGGER_MAX;

        if (act > TRIGGER_MAX)
            act = TRIGGER_MAX;

        HelperFailMsg[0] = 0;
        strcat(HelperFailMsg, "Trigger Mode Incorrect. Expected ");
        strcat(HelperFailMsg, HelperTriggerNames[exp]);
        strcat(HelperFailMsg, " Was ");
        strcat(HelperFailMsg, HelperTriggerNames[act]);
        if (msg)
            strcat(HelperFailMsg, msg);
        UNITY_TEST_FAIL(lineNumber, HelperFailMsg);
    }
}

#define UNITY_TEST_ASSERT_EQUAL_TRIGGER_T(e, a, l, m)   AssertEqualTRIGGER_T(e, a, l, m)
#define TEST_ASSERT_EQUAL_TRIGGER_T(e, a)               AssertEqualTRIGGER_T(e, a, __LINE__, NULL)
#define TEST_ASSERT_EQUAL_TRIGGER_T_MESSAGE(e, a, m)    AssertEqualTRIGGER_T(e, a, __LINE__, m)
