/**	@file: ut_avltree_operator_relational.cpp
@author Garth Santor
@author gsantor@fanshaweonline.ca
@author http://www.gats.ca/
@date 2013-01-16
@version 0.0.0
@note Developed for C++ 11
@brief avltree<T> relational operator unit tests.
*/

#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include "avl_tree.hpp"
using namespace avl;

typedef std::pair<int,int> intPair;
/**	operator != */
BOOST_AUTO_TEST_CASE( ut_inequality ) {
	//std::cout << "NOT IMPLEMENTED: operator !=\n";
	avltree<int,int> tree = avltree<int,int>();

	avltree<int,int> m1, m2, m3;
	int i;
	typedef std::pair < int, int > Int_Pair;

	for ( i = 0 ; i < 3 ; i++ )
	{
		m1.insert ( Int_Pair ( i, i ) );
		m2.insert ( Int_Pair ( i, i * i ) );
		m3.insert ( Int_Pair ( i, i ) );
	}

   BOOST_CHECK( m1 != m2 );    
   BOOST_CHECK(!( m1 != m3) );
}

/**	operator == */
BOOST_AUTO_TEST_CASE( ut_equality ) {
	//std::cout << "NOT IMPLEMENTED: operator ==\n";
	avltree<int,int> tree = avltree<int,int>();

	avltree<int,int> m1, m2, m3;
	int i;
	typedef std::pair < int, int > Int_Pair;

	for ( i = 0 ; i < 3 ; i++ )
	{
		m1.insert ( Int_Pair ( i, i ) );
		m2.insert ( Int_Pair ( i, i * i ) );
		m3.insert ( Int_Pair ( i, i ) );
	}

   BOOST_CHECK( !(m1 == m2) );    
   BOOST_CHECK( m1 == m3 );
	
}

/**	operator < */
BOOST_AUTO_TEST_CASE( ut_less ) {
	//std::cout << "NOT IMPLEMENTED: operator <\n";
	

	avltree<int,int> m1, m2, m3;
	int i;
	typedef std::pair < int, int > Int_Pair;

	for ( i = 0 ; i < 3 ; i++ )
	{
		m1.insert ( Int_Pair ( i, i ) );
		m2.insert ( Int_Pair ( i, i * i ) );
		m3.insert ( Int_Pair ( i, i-1 ) );
	}

   BOOST_CHECK( m1 < m2 );    
   BOOST_CHECK( !(m1 < m3) );
}

/**	operator <= */
BOOST_AUTO_TEST_CASE( ut_less_equal ) {
	//std::cout << "NOT IMPLEMENTED: operator <=\n";
   avltree<int,int> m1, m2, m3, m4;
   int i;
   typedef std::pair <int, int> Int_Pair;

   for ( i = 1 ; i < 3 ; i++ )
   {
      m1.insert ( Int_Pair ( i, i ) );
      m2.insert ( Int_Pair ( i, i * i ) );
      m3.insert ( Int_Pair ( i, i - 1 ) );
      m4.insert ( Int_Pair ( i, i ) );
   }

   BOOST_CHECK ( m1 <= m2 );
   
   BOOST_CHECK ( !(m1 <= m3) );
    
   BOOST_CHECK ( m1 <= m4 );
   
}

/**	operator > */
BOOST_AUTO_TEST_CASE( ut_greater ) {
	//std::cout << "NOT IMPLEMENTED: operator >\n";
	avltree<int,int>  m1, m2, m3;
	int i;
	typedef std::pair < int, int > Int_Pair;

	for ( i = 0 ; i < 3 ; i++ )
	{
		m1.insert ( Int_Pair ( i, i ) );
		m2.insert ( Int_Pair ( i, i * i ) );
		m3.insert ( Int_Pair ( i, i - 1 ) );
	}

   BOOST_CHECK ( !(m1 > m2) );      
   BOOST_CHECK ( m1 > m3 );
}

/**	operator >= */
BOOST_AUTO_TEST_CASE( ut_greater_equal ) {
	//std::cout << "NOT IMPLEMENTED: operator >=\n";
	avltree<int,int> m1, m2, m3, m4;
	int i;
	typedef std::pair < int, int > Int_Pair;

	for ( i = 1 ; i < 3 ; i++ )
	{
		m1.insert ( Int_Pair ( i, i ) );
		m2.insert ( Int_Pair ( i, i * i ) );
		m3.insert ( Int_Pair ( i, i - 1 ) );
		m4.insert ( Int_Pair ( i, i ) );
	}

   BOOST_CHECK ( !(m1 >= m2) );
     
   BOOST_CHECK ( m1 >= m3 );
      
   BOOST_CHECK ( m1 >= m4 );
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