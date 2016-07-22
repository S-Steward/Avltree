/**	@file: ut_avltree_ctor.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::ctor() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include "avl_tree.hpp"
#include <iostream>

/**	avltree() */
BOOST_AUTO_TEST_CASE( ut_ctor_default )
{
	//std::cout << "NOT IMPLEMENTED: avltree<T>::avltree()\n";
	try {
		using namespace avl;
		typedef avltree<char,int> avl_tree;
		avl_tree avlTreedef;
		BOOST_CHECK( avlTreedef.empty() );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::avltree()\n" );
	}
}



/**	explicit avltree( Traits const& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_traits_ref )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::avltree( Traits& )\n";
	try {
		using namespace avl;
		avltree<char,int,std::greater<char>> myTree;
		myTree.insert(std::pair<char,int>('b',20));
		myTree.insert(std::pair<char,int>('a',10));
		myTree.insert(std::pair<char,int>('c',30));
		auto it = myTree.begin();
		BOOST_CHECK_EQUAL( it->second, 30 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED:  avltree<T>::avltree( Traits& )\n" );
	}
}



/**	avltree( Traits const&, Allocator const& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_traits_ref_allocator_ref )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::avltree( traits&, allocator& )\n";
	try	{
		using namespace avl;
		typedef avltree<char,int> avl_tree;
		avltree<int,int> allocTree = avltree<int,int>();
		avltree<int, int>::allocator_type treeAllocator;
		treeAllocator = allocTree.get_allocator();
		avltree<int,int> tree2(std::less<int>(), treeAllocator);
	}
	catch(...) {
		BOOST_FAIL( "FAILED: avltree<T>::avltree( traits&, allocator& )\n" );
	}
}



/**	avltree( avltree& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_avltree_ref )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::avltree(avltree&)\n";
	try {
		using namespace avl;
		typedef avltree<char,int> avl_tree;
		avl_tree myTree;
		myTree.insert(std::pair<char,int>('a',1));

		avl_tree copyTree(myTree);
		BOOST_CHECK_EQUAL( copyTree['a'], myTree['a'] );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::avltree(avltree&)\n" );
	}
}



/**	avltree( InputIterator, InputIterator ) */
BOOST_AUTO_TEST_CASE( ut_ctor_iterator_iterator )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::avltree(iterator,iterator)\n";
	try {
		using namespace avl;
		typedef avltree<char,int> avl_tree;
		avl_tree myTree;

		myTree.insert(std::pair<char,int>('a',100));
		myTree.insert(std::pair<char,int>('b',200));
		myTree.insert(std::pair<char,int>('c',300));
		myTree.insert(std::pair<char,int>('d',400));
		myTree.insert(std::pair<char,int>('e',500));

		avl_tree::iterator it = myTree.find('b');
		avl_tree::iterator it2 = myTree.find('e');

		avltree<char,int> rangeTree (it, it2);
		avl_tree::iterator it3 = rangeTree.begin();
		BOOST_CHECK( it3->second == 200 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::avltree(iterator,iterator)\n" );
	}
}



/**	avltree( InputIterator, InputIterator, Traits const& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_iterator_iterator_traits )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::avltree(iterator,iterator,traits)\n";
	try {
		using namespace avl;
		typedef avltree<char,int,std::greater<char>> avl_tree;
		avl_tree myTree;

		myTree.insert(std::pair<char,int>('a',100));
		myTree.insert(std::pair<char,int>('b',200));
		myTree.insert(std::pair<char,int>('c',300));
		myTree.insert(std::pair<char,int>('d',400));
		myTree.insert(std::pair<char,int>('e',500));

		avl_tree::iterator it = myTree.find('b');
		avl_tree::iterator it2 = myTree.find('e');

		avl_tree rangeTree (it2, it);
		avl_tree::iterator it3 = rangeTree.begin();
		BOOST_CHECK_EQUAL( it3->second, 500 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::avltree(iterator,iterator)\n" );
	}
}



/**	avltree( InputIterator, InputIterator, Traits const&, allocator& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_iterator_iterator_traits_allocator )
{
	//std::cout << "NOT IMPLEMENTED: avltree<T>::avltree(iterator,iterator,traits,allocator)\n";
	try {
		using namespace avl;
		avltree<char,int,std::less<char>,std::allocator<std::pair<const char,int>>> myTree;

		myTree.insert(std::pair<char,int>('a',100));
		myTree.insert(std::pair<char,int>('b',200));
		myTree.insert(std::pair<char,int>('c',300));
		myTree.insert(std::pair<char,int>('d',400));
		myTree.insert(std::pair<char,int>('e',500));

		avltree<char,int,std::less<char>,std::allocator<std::pair<const char,int>>>::iterator it = myTree.find('b');
		avltree<char,int,std::less<char>,std::allocator<std::pair<const char,int>>>::iterator it2 = myTree.find('e');

		avltree<char,int,std::greater<char>> rangeTree (it, it2);
		avltree<char,int,std::greater<char>>::iterator it3 = rangeTree.begin();
		BOOST_CHECK_EQUAL( it3->second, 500 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::avltree(iterator,iterator)\n" );
	}
}



/**	avltree( avltree&& ) */
BOOST_AUTO_TEST_CASE( ut_ctor_avltree_move )
{
	// std::cout << "NOT IMPLEMENTED: avltree<T>::avltree(avltree&&)\n";
	try {
		using namespace avl;
		typedef avltree<char,int> avl_tree;
		avltree<char,int> myTree;
		myTree.insert(std::pair<char,int>('a',100));
		avltree<char,int> moveTree (std::move(myTree));

		BOOST_CHECK( moveTree.find('a')->second == 100 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::avltree(avltree&&)\n" );
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