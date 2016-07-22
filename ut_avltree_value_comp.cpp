/**	@file: ut_avltree_value_comp.cpp
@author Garth Santor
@author gsantor@fanshaweonline.ca
@author http://www.gats.ca/
@date 2013-01-16
@version 0.0.0
@note Developed for C++ 11
@brief avltree<T>::value_comp() unit tests.
*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avl_tree.hpp"
using namespace avl;

/**	value_compare value_comp() const */
BOOST_AUTO_TEST_CASE( ut_value_comp ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::value_comp() const\n";
	try
	{
		avltree<int,int> tree;
		avltree<int,int>::value_compare vc = tree.value_comp();

		std::pair<avltree<int,int>::iterator, bool> hr1,hr2;

		hr1 = tree.insert(std::pair<int,int>(1,10));
		hr2 = tree.insert(std::pair<int,int>(3,5));

		BOOST_CHECK( vc( *hr1.first, *hr2.first ) );

	}
	catch(...)
	{
		BOOST_FAIL("FAILED: avltree<T>::value_comp() const\n");
	}
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