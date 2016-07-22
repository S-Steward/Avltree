/**	@file: ut_avltree_size.cpp
@author Garth Santor
@author gsantor@fanshaweonline.ca
@author http://www.gats.ca/
@date 2013-01-16
@version 0.0.0
@note Developed for C++ 11
@brief avltree<T>::size() unit tests.
*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avl_tree.hpp"

/**	size_type max_size() const */
BOOST_AUTO_TEST_CASE( ut_max_size ) {
	// std::cout << "NOT IMPLEMENTED: avltree<T>::max_size() const\n";
	try {
		using namespace avl;
		avltree<char,int> Tree;
		BOOST_CHECK( Tree.max_size() > 10000 );
		BOOST_CHECK( Tree.max_size() > 100000 );
		BOOST_CHECK( Tree.max_size() > 1000000 );
		BOOST_CHECK( Tree.max_size() > 10000000 );
	}
	catch(...) {
		BOOST_FAIL("FAILED: avltree<T>::max_size() const\n");
	}
}

/**	size_type size() const */
BOOST_AUTO_TEST_CASE( ut_size ) {
	// std::cout << "NOT IMPLEMENTED: avltree<T>::size() const\n";
	try {
		using namespace avl;
		avltree<int,int> tree = avltree<int,int>();
		tree.insert(std::pair<int,int>(1,10));
		
		BOOST_CHECK(tree.size() == 1);

		tree.insert(std::pair<int,int>(5,7));

		BOOST_CHECK(tree.size() == 2);
	}
	catch(...) {
		BOOST_FAIL("FAILED: avltree<T>::size() const\n");
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