/**	@file: ut_avltree_clear.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::clear() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include "avl_tree.hpp" 
using namespace avl;

/**	void clear() */
BOOST_AUTO_TEST_CASE( ut_clear )
{
	//std::cout << "NOT IMPLEMENTED: avltree<T>::clear()\n";
	try {
		avltree<char,int> Tree;
		Tree.insert(std::pair<char,int>('a',100));
		Tree.clear();

		BOOST_CHECK( Tree.size() == 0 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::clear()\n" );
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