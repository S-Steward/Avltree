/**	@file: ut_avltree_key_comp.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::key_comp() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include "avl_tree.hpp"
#include <iostream>
using namespace avl;



/**	key_compare key_comp() const */
BOOST_AUTO_TEST_CASE( ut_key_comp ) {
	// std::cout << "NOT IMPLEMENTED: avltree<T>::key_comp() const\n";
	try {
		avltree<int,int,std::less<int>> Tree;
		avltree<int,int,std::less<int>>::key_compare keyComp = Tree.key_comp();
		BOOST_CHECK( keyComp(2,3) == true );
	}
	catch(...) {
		BOOST_FAIL( "FAILED: avltree<T>::key_comp() const\n" );
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