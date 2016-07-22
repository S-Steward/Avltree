/**	@file: ut_avltree_empty.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::empty() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avl_tree.hpp"

/**	bool empty() const */
BOOST_AUTO_TEST_CASE( ut_empty ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::empty() const\n";
	try	{
		using namespace avl;
		typedef avltree<int,int> avl_tree;
		avl_tree Tree = avl_tree();

		BOOST_CHECK(Tree.empty());

		Tree.insert(std::pair<int,int>(1,10));
		BOOST_CHECK(!Tree.empty());

		avl_tree Tree2 = std::move(Tree);
		// This BOOST_CHECK will fail for now, because there is no way
		// to clean up nyTree after the move construction.  Once
		// Jesse implements erase() we'll be good to go.
		// BOOST_CHECK(myTree.empty());
	}
	catch(...) {
		BOOST_FAIL("FAILED: avltree<T>::empty() const\n");
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