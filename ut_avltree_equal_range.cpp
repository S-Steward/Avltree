/**	@file: ut_avltree_equal_range.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::equal_range() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include "avl_tree.hpp"
#include <iostream>

/**	pair <iterator, iterator> equal_range ( Key const& ) */
BOOST_AUTO_TEST_CASE( ut_equal_range )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::equal_range()\n";
	try {
		using namespace avl;
		avltree<char,int> Tree;
		Tree.insert(std::pair<char,int>('a',1));
		Tree.insert(std::pair<char,int>('b',2));
		Tree.insert(std::pair<char,int>('c',3));
		BOOST_CHECK_EQUAL( Tree.equal_range('a').first->second, Tree.lower_bound('a')->second );
		BOOST_CHECK_EQUAL( Tree.equal_range('a').second->second, Tree.upper_bound('a')->second );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::equal_range()\n" );
	}
}


/**	pair <const_iterator, const_iterator> equal_range ( Key const& ) const */
BOOST_AUTO_TEST_CASE( ut_equal_range_const )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::equal_range() const\n";
	try {
		using namespace avl;
		avltree<char,int> myTree;
		myTree.insert(std::pair<char,int>('a',1));
		myTree.insert(std::pair<char,int>('b',2));
		myTree.insert(std::pair<char,int>('c',3));
		const avltree<char,int> myTree2(myTree);
		BOOST_CHECK_EQUAL( myTree2.equal_range('a').first->second, myTree2.lower_bound('a')->second );
		BOOST_CHECK_EQUAL( myTree2.equal_range('a').second->second, myTree2.upper_bound('a')->second );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::equal_range() const\n" );
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