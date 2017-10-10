//
// Created by IanLachance on 7/26/2017.
//

#include <afxres.h>
#include "CuTest.h"
#include "../lib/crypto/crypto.h"

void TestCryptoLength(CuTest *tc)
{
    char* test = "hello";
    char* test_empty = "";
    CuAssertIntEquals(tc, 5, length(test));
    CuAssertIntEquals(tc, 0, length(test_empty));
}

void TestCryptoRot13(CuTest *tc)
{
    char* test = "hello";
    char* test2 = "world";
    char* test_empty = "";
    CuAssertStrEquals(tc, "uryyc", ceasar_cipher(test, ROT13));
    CuAssertStrEquals(tc, "kcfyq", ceasar_cipher(test2, ROT13));
    CuAssertStrEquals(tc, "", ceasar_cipher(test_empty, ROT13));
}

CuSuite* StrUtilGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCryptoLength);
    SUITE_ADD_TEST(suite, TestCryptoRot13);
    return suite;
}