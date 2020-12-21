/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCKDIGITAL_H
#define _MOCKDIGITAL_H

#include "unity.h"
#include "stdint.h"
#include "Defs.h"
#include "LPC1768.h"
#include "Digital.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void MockDigital_Init(void);
void MockDigital_Destroy(void);
void MockDigital_Verify(void);




#define Digital_Init_Ignore() Digital_Init_CMockIgnore()
void Digital_Init_CMockIgnore(void);
#define Digital_Init_StopIgnore() Digital_Init_CMockStopIgnore()
void Digital_Init_CMockStopIgnore(void);
#define Digital_Init_Expect() Digital_Init_CMockExpect(__LINE__)
void Digital_Init_CMockExpect(UNITY_LINE_TYPE cmock_line);
#define Digital_GetBits_IgnoreAndReturn(cmock_retval) Digital_GetBits_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void Digital_GetBits_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return);
#define Digital_GetBits_StopIgnore() Digital_GetBits_CMockStopIgnore()
void Digital_GetBits_CMockStopIgnore(void);
#define Digital_GetBits_ExpectAndReturn(cmock_retval) Digital_GetBits_CMockExpectAndReturn(__LINE__, cmock_retval)
void Digital_GetBits_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif