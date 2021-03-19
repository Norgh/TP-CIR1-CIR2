#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "seatest.h"
#include "mystring.h"



void test_myStrTrimStart(void) {
	char chaine[128] = "";
	strcpy_s(chaine, _countof(chaine), " XX X ");
	assert_string_equal("XX X ", myStrTrimStart(chaine));
	strcpy_s(chaine, _countof(chaine), "   XX X   ");
	assert_string_equal("XX X   ", myStrTrimStart(chaine));
	strcpy_s(chaine, _countof(chaine), " XX X");
	assert_string_equal("XX X", myStrTrimStart(chaine));
	strcpy_s(chaine, _countof(chaine), "XX X ");
	assert_string_equal("XX X ", myStrTrimStart(chaine));
	strcpy_s(chaine, _countof(chaine), "XX X");
	assert_string_equal("XX X", myStrTrimStart(chaine));
	strcpy_s(chaine, _countof(chaine), "");
	assert_string_equal("", myStrTrimStart(chaine));
}
void test_myStrTrimEnd(void) {
	char chaine[128] = "";
	strcpy_s(chaine, _countof(chaine), " XX X ");
	assert_string_equal(" XX X", myStrTrimEnd(chaine));
	strcpy_s(chaine, _countof(chaine), "   XX X   ");
	assert_string_equal("   XX X", myStrTrimEnd(chaine));
	strcpy_s(chaine, _countof(chaine), " XX X");
	assert_string_equal(" XX X", myStrTrimEnd(chaine));
	strcpy_s(chaine, _countof(chaine), "XX X ");
	assert_string_equal("XX X", myStrTrimEnd(chaine));
	strcpy_s(chaine, _countof(chaine), "XX X");
	assert_string_equal("XX X", myStrTrimEnd(chaine));
	strcpy_s(chaine, _countof(chaine), "");
	assert_string_equal("", myStrTrimEnd(chaine));
}

void test_myStrTrim(void) {
	char chaine[128] = "";
	strcpy_s(chaine, _countof(chaine), " XX X ");
	assert_string_equal("XX X", myStrTrim(chaine));
	strcpy_s(chaine, _countof(chaine), "   XX X   ");
	assert_string_equal("XX X", myStrTrim(chaine));
	strcpy_s(chaine, _countof(chaine), " XX X");
	assert_string_equal("XX X", myStrTrim(chaine));
	strcpy_s(chaine, _countof(chaine), "XX X ");
	assert_string_equal("XX X", myStrTrim(chaine));
	strcpy_s(chaine, _countof(chaine), "XX X");
	assert_string_equal("XX X", myStrTrim(chaine));
	strcpy_s(chaine, _countof(chaine), "");
	assert_string_equal("", myStrTrim(chaine));
}


void test_fixture_string(void) {

	test_fixture_start();

	
	run_test(test_myStrTrimStart);
	run_test(test_myStrTrimEnd);
	run_test(test_myStrTrim);


	test_fixture_end();

}
