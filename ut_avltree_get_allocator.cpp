/**	@file: ut_avltree_get_allocator.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::get_allocator() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include "avl_tree.hpp"
#include <iostream>

/**	allocator_type get_allocator() const */
BOOST_AUTO_TEST_CASE( ut_get_allocator ) {
	// std::cout << "NOT IMPLEMENTED: avltree<T>::get_allocator()\n";
	try	{
		using namespace avl;
		typedef avltree<char,int> avl_tree;
		avltree<int,int> allTree = avltree<int,int>();
		avltree<int, int>::allocator_type treeAllocator;
		treeAllocator = allTree.get_allocator();
		avltree<int,int> tree2(std::less<int>(), treeAllocator);
	}
	catch(...) {
		BOOST_FAIL( "FAILED: avltree<T>::avltree( traits&, allocator& )\n" );
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