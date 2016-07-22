/**	@file: ut_avltree_emplace.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::emplace() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include "avl_tree.hpp" 
#include <iostream>
using namespace avl;

/**	template <class ValTy> pair<iterator,bool> emplace( ValTy&& ) */
BOOST_AUTO_TEST_CASE( ut_emplace )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::emplace(&&)\n";

	try {
		avltree<char,int> Tree;
		std::pair<char,int> pair('a',1);
		Tree.emplace(move(pair));
		BOOST_CHECK_EQUAL( Tree['a'], 1 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::emplace(&&)\n" );
	}
}


/**	template <class ValTy> pair<iterator,bool> emplace_hint( const_iterator, ValTy&& ) */
BOOST_AUTO_TEST_CASE( ut_emplace_hint )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::emplace(iterator,&&)\n";
	try {
		avltree<char,int> myTree;
		std::pair<char,int> pair('a',1);
		myTree.emplace_hint(myTree.begin(), std::move(pair));
		BOOST_CHECK_EQUAL( myTree['a'], 1 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::emplace(iterator,&&)\n" );
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