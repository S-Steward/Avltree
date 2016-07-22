/**	@file: ut_avltree_swap.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::swap() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include "avl_tree.hpp"
#include <iostream>

/** void swap( avltree<Key, Type, Traits, Allocator>& ) */
BOOST_AUTO_TEST_CASE( ut_swap_method )
{
	//std::cout << "NOT IMPLEMENTED: avltree<T>::swap( avltree<T>& )\n";
	try {
		using namespace avl;
		avltree<int,int> tree;
		tree.insert(std::pair<int,int>(1,10));

		avltree<int,int> tree2;
		tree2.insert(std::pair<int,int>(5,7));
		
		tree.swap(tree2);
		
		BOOST_CHECK(tree[5] == 7);
		BOOST_CHECK(tree2[1] == 10);
		
		tree.swap(tree2);
		
		BOOST_CHECK(tree[1] == 10);
		BOOST_CHECK(tree2[5] == 7);
	}
	catch(...) {
		BOOST_FAIL("FAILED: avltree<T>::swap( avltree<T>& )\n");
	}
}

/** void swap( avltree<Key, Type, Traits, Allocator>& ) */
BOOST_AUTO_TEST_CASE( ut_swap_function ) {
	//std::cout << "NOT IMPLEMENTED: swap( avltree<T>&, avltree<T>& )\n";
	try {
		using namespace avl;
		avltree<int,int> tree;
		tree.insert(std::pair<int,int>(1,10));

		avltree<int,int> tree2;
		tree2.insert(std::pair<int,int>(5,7));

		swap(tree,tree2);

		BOOST_CHECK(tree[5] == 7);
		BOOST_CHECK(tree2[1] == 10);

		swap(tree,tree2);

		BOOST_CHECK(tree[1] == 10);
		BOOST_CHECK(tree2[5] == 7);
	}
	catch(...) {
		BOOST_FAIL("FAILED: swap( avltree<T>&, avltree<T>& )\n");
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