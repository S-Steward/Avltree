/**	@file: ut_avltree_at.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::at() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avl_tree.hpp"

/**	at( Key const& ) */
BOOST_AUTO_TEST_CASE( ut_at_key )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::at( Key const& )\n";
	try {
		using namespace avl;
		avltree<char,int> Tree;

		Tree.insert(std::pair<char,int>('a',1));
		BOOST_CHECK_EQUAL( Tree.at('a'), 1 );

		Tree.at('a') = 10;
		BOOST_CHECK_EQUAL( Tree.at('a'), 10 );

		BOOST_REQUIRE_THROW( Tree.at('c'), std::out_of_range );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::at( Key const& )\n" );
	}
}



/**	at( Key const& ) const */
BOOST_AUTO_TEST_CASE( ut_at_key_const )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::at( Key const& ) const\n";
	try {
		using namespace avl;
		avltree<char,int> myTree;
		myTree.insert(std::pair<char,int>('a',1));
		const avltree<char,int> myTree2 = myTree;
		BOOST_CHECK_EQUAL( myTree2.at('a'), 1 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::at( Key const& )\n" );
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