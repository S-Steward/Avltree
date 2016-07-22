/**	@file: ut_avltree_find.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::find() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avl_tree.hpp"


/**	iterator find( Key const& ) */
BOOST_AUTO_TEST_CASE( ut_find ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::find()\n";
	try	{
		using namespace avl;
		typedef avltree<int,int> avl_tree;
		avl_tree tree;
		tree.insert(std::pair<int,int>(1,10));
		tree.insert(std::pair<int,int>(2,20));
		tree.insert(std::pair<int,int>(3,30));

		avl_tree::iterator treeIterator;

		treeIterator = tree.find(2);
		BOOST_CHECK(treeIterator->second == 20);

		treeIterator = tree.find(4);
		BOOST_CHECK(treeIterator == tree.end());
	}
	catch(...) {
		BOOST_FAIL("FAILED: avltree<T>::find()\n");
	}
}



/**	const_iterator find( Key const& ) const */
BOOST_AUTO_TEST_CASE( ut_find_const )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::find() const\n";
	try {
		using namespace avl;
		typedef avltree<int,int> avl_tree;
		avl_tree myTree;
		myTree.insert(std::pair<char,int>('a',1));
		const avl_tree myTree2(myTree);
		BOOST_CHECK_EQUAL( myTree2.find('a')->second, 1 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::find() const\n" );
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