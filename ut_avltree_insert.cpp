/**	@file: ut_avltree_insert.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::insert() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avl_tree.hpp"

/**	pair<iterator,bool> insert( value_type const& ) */
BOOST_AUTO_TEST_CASE( ut_insert_value ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::insert(value)\n";
	try {
		using namespace avl;
		typedef avltree<char,int> avl_tree;
		avl_tree Tree;

		std::pair<avl_tree::iterator,bool> it = Tree.insert(std::pair<char,int>('a',1));
		BOOST_CHECK_EQUAL( it.first->second, 1 );
	}
	catch(...) {
		BOOST_FAIL("FAILED: avltree<T>::insert(value)\n");
	}
}



/**	iterator insert( iterator, value_type const& ) */
BOOST_AUTO_TEST_CASE( ut_insert_iterator_value ) {
	// std::cout << "NOT IMPLEMENTED: avltree<T>::insert(iterator,value)\n";
	try {
		using namespace avl;
		typedef avltree<char,int> avl_tree;
		avl_tree Tree;

		Tree.insert(std::pair<char,int>('a',1));
		Tree.insert(Tree.begin(), std::pair<char,int>('b',2));

		avl_tree::iterator it = Tree.begin();
		BOOST_CHECK_EQUAL( it->second, 1 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::insert(iterator,value)\n" );
	}
}



/**	template <class InputIterator> void insert( InputIterator, InputIterator ) */
BOOST_AUTO_TEST_CASE( ut_insert_iterator_iterator ) {
	// std::cout << "NOT IMPLEMENTED: avltree<T>::insert(iterator,iterator)\n";
	try {
		using namespace avl;
		typedef avltree<char,int> avl_tree;
		avl_tree Tree;

		Tree.insert(std::pair<char,int>('a',1));
		Tree.insert(std::pair<char,int>('b',2));
		Tree.insert(std::pair<char,int>('c',3));

		avl_tree Tree2;
		Tree2.insert(Tree.begin(), Tree.end());
		BOOST_CHECK_EQUAL( Tree2.find('a')->second, 1 );
		BOOST_CHECK_EQUAL( Tree2.find('b')->second, 2 );
		BOOST_CHECK_EQUAL( Tree2.find('c')->second, 3 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::insert(iterator,iterator)\n" );
	}
}



/**	template <class ValTy> pair<iterator,bool> insert( ValTy && ) */
BOOST_AUTO_TEST_CASE( ut_insert_T_move ) {
	// std::cout << "NOT IMPLEMENTED: avltree<T>::insert(&&)\n";
	try {
		using namespace avl;
		typedef avltree<char,int> avl_tree;
		avl_tree Tree;

		std::pair<char,int> pair('a',1);
		Tree.insert(std::move(pair));

		BOOST_CHECK_EQUAL( Tree.find('a')->second, 1 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::insert(&&)\n" );
	}
}



/**	template <class ValTy> pair<iterator,bool> insert( const_iterator, ValTy && ) */
BOOST_AUTO_TEST_CASE( ut_insert_iterator_T_move ) {
	// std::cout << "NOT IMPLEMENTED: avltree<T>::insert(iterator,&&)\n";
	try {
		using namespace avl;
		typedef avltree<char,int> avl_tree;
		avl_tree Tree;
		std::pair<char,int> pair('a',1), pair2('b',2);

		Tree.insert(std::move(pair2));
		Tree.insert(Tree.begin(), std::move(pair));
		BOOST_CHECK_EQUAL( Tree.begin()->second, 1 );
	}
	catch( ... ) {
		BOOST_FAIL( "FAILED: avltree<T>::insert(iterator,&&)\n" );
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