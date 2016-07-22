/**	@file: ut_avltree_count.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::count() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include "avl_tree.hpp" 
using namespace avl;

/**	size_type count( Key const& ) const */
BOOST_AUTO_TEST_CASE( ut_count )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::count()\n";
	try {
		avltree<char,int> Tree;
		Tree.insert(std::pair<char,int>('a',100));
		
		int i = Tree.count('a');
		BOOST_CHECK_EQUAL( i, 1 );
		i = Tree.count('b');
		BOOST_CHECK_EQUAL( i, 0 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::count()\n" );
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