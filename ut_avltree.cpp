/**	@file: ut_avltree.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T> unit test.
	*/


#define BOOST_TEST_MODULE avltree_unit_test
#include <boost/test/unit_test.hpp>
#include <iostream>


/**	Build model. */
BOOST_AUTO_TEST_CASE( ut_build_type )
{
	using namespace std;
	//cout << "ut-avltree<T> version 0.0.0: " __GATS_BUILD_TYPE__ << endl; 
	cout << "Last build: " __TIMESTAMP__ "\n" << endl;
}


/*=============================================================

Revision History

Version 0.0.0: 2013-01-16
Alpha release.

=============================================================

Copyright Garth Santor

The copyright to the computer program(s) herein
is the property of Garth Santor of Canada.
The program(s) may be used and/or copied only with
the written permission of Garth Santor
or in accordance with the terms and conditions
stipulated in the agreement/contract under which
the program(s) have been supplied.
=============================================================*/