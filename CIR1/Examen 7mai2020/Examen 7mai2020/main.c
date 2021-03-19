#include "seatest.h"
#include <locale.h>

void test_fixture_one( void );
void test_fixture_two( void );
void test_fixture_string(void);

void all_tests( void )
{
	
	// test_suite_stringfct.c
	test_fixture_string();

	// add new test fixtures here.
}

void my_suite_setup( void )
{
	//printf("I'm done before every single test in the suite\r\n");
}

void my_suite_teardown( void )
{
	//printf("I'm done after every single test in the suite\r\n");
}

int main( int argc, char** argv )
{
	setlocale(LC_ALL, "fr-FR"); // gestion des accents dans la console
	
	suite_setup(my_suite_setup);
	run_tests(all_tests);	
	suite_teardown(my_suite_teardown);

	

	


	return 0;
}

