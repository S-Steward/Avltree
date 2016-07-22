/**	@file: ut_avltree_iterator_operators.cpp
@author Garth Santor
@author gsantor@fanshaweonline.ca
@author http://www.gats.ca/
@date 2013-01-16
@version 0.0.0
@note Developed for C++ 11
@brief avltree<T>::iterator::operator unit tests.
*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avl_tree.hpp"
using namespace avl;
/**	iterator operator pre++ */
BOOST_AUTO_TEST_CASE( ut_iterator_pre_inc ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::iterator::operator++(int)\n";
	try
	{
		avltree<std::string,int> tree;
		tree.insert(std::pair<std::string,int>("a",1));
		tree.insert(std::pair<std::string,int>("b",2));
		tree.insert(std::pair<std::string,int>("c",3));
		tree.insert(std::pair<std::string,int>("d",4));

		avltree<std::string,int>::iterator it = tree.begin();
		BOOST_CHECK( 2 == (++it)->second );
		BOOST_CHECK( 3 == (++it)->second);
	}
	catch(...)
	{
		BOOST_FAIL("FAILED: avltree<T>::iterator::operator++(int)\n");
	}
}

/**	iterator operator post++ */
BOOST_AUTO_TEST_CASE( ut_iterator_post_inc ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::iterator::operator++()\n";
	try
	{
		avltree<std::string,int> tree;
		tree.insert(std::pair<std::string,int>("a",1));
		tree.insert(std::pair<std::string,int>("b",2));
		tree.insert(std::pair<std::string,int>("c",3));
		tree.insert(std::pair<std::string,int>("d",4));

		avltree<std::string,int>::iterator it = tree.begin();
		BOOST_CHECK( 1 == (it++)->second);
		BOOST_CHECK( 2 == (it++)->second);
		BOOST_CHECK( 3 == it->second );
	}
	catch(...)
	{
		BOOST_FAIL("FAILED: avltree<T>::iterator::operator++()\n");
	}
}

/**	iterator operator pre-- */
BOOST_AUTO_TEST_CASE( ut_iterator_pre_dec ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::iterator::operator--(int)\n";
	try
	{
		avltree<std::string,int> tree;
		tree.insert(std::pair<std::string,int>("a",1));
		tree.insert(std::pair<std::string,int>("b",2));
		tree.insert(std::pair<std::string,int>("c",3));
		tree.insert(std::pair<std::string,int>("d",4));

		avltree<std::string,int>::iterator it = tree.end();
		BOOST_CHECK((--it)->second == 4);
		BOOST_CHECK((--it)->second == 3);
	}
	catch(...)
	{
		BOOST_FAIL("FAILED: avltree<T>::iterator::operator--(int)\n");
	}
}

/**	iterator operator post-- */
BOOST_AUTO_TEST_CASE( ut_iterator_post_dec ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::iterator::operator--()\n";
	try
	{
		avltree<std::string,int> tree;
		tree.insert(std::pair<std::string,int>("a",1));
		tree.insert(std::pair<std::string,int>("b",2));
		tree.insert(std::pair<std::string,int>("c",3));
		tree.insert(std::pair<std::string,int>("d",4));

		avltree<std::string,int>::iterator it = tree.end();
		it--;
		BOOST_CHECK(it--->second == 4);
		BOOST_CHECK(it->second == 3);
		//	BOOST_CHECK((it--)->second == 1);
	}
	catch(...)
	{
		BOOST_FAIL("FAILED: avltree<T>::iterator::operator--()\n");
	}
}

/**	iterator operator rev pre++ */
BOOST_AUTO_TEST_CASE( ut_iterator_rev_pre_inc ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::reverse_iterator::operator++(int)\n";

	try
	{
		avltree<std::string,int> tree;
		tree.insert(std::pair<std::string,int>("a",1));
		tree.insert(std::pair<std::string,int>("b",2));
		tree.insert(std::pair<std::string,int>("c",3));
		tree.insert(std::pair<std::string,int>("d",4));

		avltree<std::string,int>::reverse_iterator it = tree.rbegin();

		BOOST_CHECK((++it)->second == 3);
		BOOST_CHECK((++it)->second == 2);
	}
	catch(...)
	{
		BOOST_FAIL("FAILED: avltree<T>::reverse_iterator::operator++(int)\n");
	}
}

/**	iterator operator rev post++ */
BOOST_AUTO_TEST_CASE( ut_iterator_rev_post_inc ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::reverse_iterator::operator++()\n";

	try
	{
		avltree<std::string,int> tree;
		tree.insert(std::pair<std::string,int>("a",1));
		tree.insert(std::pair<std::string,int>("b",2));
		tree.insert(std::pair<std::string,int>("c",3));
		tree.insert(std::pair<std::string,int>("d",4));

		avltree<std::string,int>::reverse_iterator it = tree.rbegin();

		BOOST_CHECK((it++)->second == 4);
		BOOST_CHECK((it++)->second == 3);
		BOOST_CHECK(it->second == 2);
	}
	catch(...)
	{
		BOOST_FAIL("FAILED: avltree<T>::reverse_iterator::operator++()\n");
	}
}

/**	iterator operator rev pre-- */
BOOST_AUTO_TEST_CASE( ut_iterator_rev_pre_dec ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::reverse_iterator::operator--(int)\n";

	try
	{
		avltree<std::string,int> tree;
		tree.insert(std::pair<std::string,int>("a",1));
		tree.insert(std::pair<std::string,int>("b",2));
		tree.insert(std::pair<std::string,int>("c",3));
		tree.insert(std::pair<std::string,int>("d",4));

		avltree<std::string,int>::reverse_iterator it = tree.rend();
		--it;
		BOOST_CHECK((--it)->second == 2);
		BOOST_CHECK((--it)->second == 3);
	}
	catch(...)
	{
		BOOST_FAIL("FAILED: avltree<T>::reverse_iterator::operator--(int)\n");
	}
}

/**	iterator operator rev post-- */
BOOST_AUTO_TEST_CASE( ut_iterator_rev_post_dec ) {
	//std::cout << "NOT IMPLEMENTED: avltree<T>::reverse_iterator::operator--()\n";
	try
	{
		avltree<std::string,int> tree;
		tree.insert(std::pair<std::string,int>("a",1));
		tree.insert(std::pair<std::string,int>("b",2));
		tree.insert(std::pair<std::string,int>("c",3));
		tree.insert(std::pair<std::string,int>("d",4));

		avltree<std::string,int>::reverse_iterator it = tree.rend();
		it--;
		BOOST_CHECK((it--)->second == 1);
		BOOST_CHECK(it->second == 2);
		//BOOST_CHECK((it--)->second == 1);
	}
	catch(...)
	{
		BOOST_FAIL("FAILED: avltree<T>::reverse_iterator::operator--()\n");
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