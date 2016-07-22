/**	@file: ut_avltree_operator_array.cpp
	@author Garth Santor
	@author gsantor@fanshaweonline.ca
	@author http://www.gats.ca/
	@date 2013-01-16
	@version 0.0.0
	@note Developed for C++ 11
	@brief avltree<T>::operator[] unit tests.
	*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avl_tree.hpp" 
using namespace avl;


/**	Type& operator[]( Key const& ) */
BOOST_AUTO_TEST_CASE( ut_operator_array_key_ref ) {
	avltree<std::string,int> Tree;
	Tree["a"] = 1; 
	Tree["b"] = 3;
	Tree["c"] = 2;
	Tree["d"] = 4;


	BOOST_CHECK(Tree.at("a") == 1);
	BOOST_CHECK(Tree.at("b") == 3);
	BOOST_CHECK(Tree.at("c") == 2);
	BOOST_CHECK(Tree.at("d") == 4);
	//std::cout << "NOT IMPLEMENTED: operator [&]\n";
}



/**	Type& operator[]( Key && ) */
BOOST_AUTO_TEST_CASE( ut_operator_array_key_move ) {
	// c2[move(str)] 
	//std::cout << "NOT IMPLEMENTED: operator [&&]\n";
	avltree<std::string,int> Tree;
	std::string a = "a";
	std::string b = "b";
	std::string c = "c";
	std::string d = "d";
	Tree[std::move(a)] = 1; 
	Tree[std::move(b)] = 3;
	Tree[std::move(c)] = 2;
	Tree[std::move(d)] = 4;


	BOOST_CHECK(Tree["a"] == 1);
	BOOST_CHECK(Tree["b"] == 3);
	BOOST_CHECK(Tree["c"] == 2);
	BOOST_CHECK(Tree["d"] == 4);
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