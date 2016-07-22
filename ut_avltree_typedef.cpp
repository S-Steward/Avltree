/**	@file: ut_avltree_typedef.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::types() unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include "avl_tree.hpp"
using namespace avl;

/**	Display typedefs. */
BOOST_AUTO_TEST_CASE( ut_typedef ) {
	//std::cout << "NOT IMPLEMENTED: typedefs\n";
	BOOST_CHECK( typeid( avltree<int,int>::value_type ).name() == typeid( std::pair<const int, int> ).name() );
	BOOST_CHECK( typeid( avltree<int,int>::value_type ).name() != typeid( std::pair<int, int> ).name() );

	BOOST_CHECK( typeid( avltree<std::string, int>::key_type ).name() == typeid( std::string ).name() );
	BOOST_CHECK( typeid( avltree<std::string, int>::key_type ).name() != typeid( char ).name() );
	// ---------- AVLTREE INCEPTION -------------------
	BOOST_CHECK( typeid( avltree<avltree<avltree<std::vector<bool>, int>, int>, int, std::greater<int>, std::allocator<std::vector<bool>>>::key_type ).name() == typeid( avltree<avltree<std::vector<bool>, int>, int> ).name() );

	BOOST_CHECK( typeid( avltree<int, std::vector<char>>::mapped_type ).name() == typeid( std::vector<char> ).name() );
	BOOST_CHECK( typeid( avltree<int, std::vector<char>>::mapped_type ).name() != typeid( const std::vector<int> ).name() );

	BOOST_CHECK( typeid( avltree<std::vector<float>, std::string>::key_compare ).name() == typeid( std::less<std::vector<float>> ).name() );
	BOOST_CHECK( typeid( avltree<std::vector<float>, std::string, std::greater<std::vector<float>>>::key_compare ).name() == typeid( std::greater<std::vector<float>> ).name() );

	BOOST_CHECK( typeid( avltree<std::string, std::vector<int>>::allocator_type ).name() == typeid( std::allocator<std::pair<const std::string, std::vector<int>>> ).name() );
	BOOST_CHECK( typeid( avltree<avltree<avltree<std::vector<bool>, int>, int>, int, std::greater<int>, std::allocator<std::vector<bool>>>::allocator_type ).name() == typeid( std::allocator<std::vector<bool>> ).name() );

	BOOST_CHECK( typeid( avltree<int, int>::size_type ).name() == typeid( std::allocator<std::pair<int, int>>::size_type ).name() );
	BOOST_CHECK( typeid( avltree<int, int, std::greater<int>, std::allocator<int>>::size_type ).name() == typeid( std::allocator<int>::size_type ).name() );

	BOOST_CHECK( typeid( avltree<int,int>::pointer ).name() == typeid( std::pair<const int, int>* ).name() );
	BOOST_CHECK( typeid( avltree<int,int>::pointer ).name() != typeid( std::pair<int, int>* ).name() );
	
	BOOST_CHECK( typeid( avltree<int,int>::reference ).name() == typeid( std::allocator<std::pair<const int, int>>::reference ).name() );
	BOOST_CHECK( typeid( avltree<std::string,double, std::greater<int>, std::allocator<int>>::reference ).name() == typeid( std::allocator<int>::reference ).name() );

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