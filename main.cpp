#include <iostream>
#include "avl_tree.hpp"
#include <map>

int main ( int argc, const char* argv[] )
{
	typedef std::pair<int,int> intPair;
	try {
		std::cout << "The Map\n";
		std::map<int, int> myMap;
		myMap.insert(intPair(1, 1));
		myMap.insert(intPair(2, 2));
		myMap.insert(intPair(3, 3));
		myMap.insert(intPair(4, 4));
		myMap.insert(intPair(5, 5));

		for( auto it = myMap.begin(); it != myMap.end(); ++it ) {
			std::cout << it->first << ":" << it->second;
			std::cout << "\t\t" << (*it).first << ":" << (*it).second << std::endl;
		}
		
		std::cout << "\nThe Tree\n";
		using namespace avl;
		avltree<int, int> myTree;
		myTree.insert(intPair(1, 1));
		myTree.insert(intPair(2, 2));
		myTree.insert(intPair(3, 3));
		myTree.insert(intPair(4, 4));
		myTree.insert(intPair(5, 5));

		int erased = myTree.erase( 2 );
		if ( myTree.find( 2 ) == myTree.end() ) {
			std::cout << "yayyyyyyy!";
		}

		avltree<int, int> myTreeConst;
		myTreeConst.insert(myTree.begin(), --myTree.end());

		std::cout << "The Tree (at)" << std::endl;
		std::cout << myTree.at(2) << std::endl;
		myTree.at(2) = 5;
		std::cout << myTree.at(2) << std::endl;

		std::cout << "The Tree (at) const" << std::endl;
		std::cout << myTreeConst.at(2) << std::endl;

		//for( auto it = myTree.begin(); it != myTree.end(); ++it ) {
		//	std::cout << it->first << ":" << it->second << std::endl;
		//	/*std::cout << "\t\t" << (*it).first << ":" << (*it).second << std::endl;*/
		//}

		//*******************************************************
		//Jovan Test Area
		//*******************************************************
		std::cout << "JOVAN TEST AREA" << std::endl;
		typedef avltree<int, int> avltree_type;
		avltree_type jovanTree;
		//std::map<int, int> jovanTree;
		std::cout << "Round one" << std::endl;
		jovanTree[1] = 1;
		jovanTree[2] = 1;
		jovanTree[3] = 1;
		jovanTree[4] = 1;
		jovanTree[5] = 1;
		for( auto it = jovanTree.begin(); it != jovanTree.end(); ++it ) {
			std::cout << it->first << ":" << it->second;
			std::cout << "\t\t" << (*it).first << ":" << (*it).second << std::endl;
		}
		std::cout << "Round Two" << std::endl;
		jovanTree[1] = 1;
		jovanTree[2] = 2;
		jovanTree[3] = 3;
		jovanTree[4] = 4;
		jovanTree[5] = 5;
		for( auto it = jovanTree.begin(); it != jovanTree.end(); ++it ) {
			std::cout << it->first << ":" << it->second;
			std::cout << "\t\t" << (*it).first << ":" << (*it).second << std::endl;
		}
		std::cout << "Round Three" << std::endl;
		for(size_t i = 0; i < jovanTree.size(); ++i)
		{
			std::cout << i << ":" << jovanTree[i] << std::endl;
		}

		std::cout << "Round Four -- move insert" << std::endl;
		jovanTree.insert(std::move(std::pair<int,int>(6,6) ) );

		for( auto it = jovanTree.begin(); it != jovanTree.end(); ++it ) {
			std::cout << it->first << ":" << it->second;
			std::cout << "\t\t" << (*it).first << ":" << (*it).second << std::endl;
		}

		std::cout << "Round Five -- move array" << std::endl;
		jovanTree[std::move(7)] = 7;
		for( auto it = jovanTree.begin(); it != jovanTree.end(); ++it ) {
			std::cout << it->first << ":" << it->second;
			std::cout << "\t\t" << (*it).first << ":" << (*it).second << std::endl;
		}
		//*******************************************************
		//Swap
		//*******************************************************
		std::cout << "Round Six -- Swap test" << std::endl;
		avltree_type jovanTreeSwap;
		//std::map<int, int> jovanTreeSwap;
		jovanTreeSwap[100] = 1;
		jovanTreeSwap[101] = 2;
		jovanTreeSwap[102] = 3;
		jovanTreeSwap[103] = 4;
		jovanTreeSwap[104] = 5;

		{
			avltree_type::iterator swapIt = jovanTreeSwap.cbegin();
			avltree_type::iterator it = jovanTree.cbegin();
			std::cout << "tree" << "\t\t" << "tree swap"<< std::endl;
			while(swapIt != jovanTreeSwap.end() && it != jovanTree.end()){
				std::cout << it->first << ":" << it->second;
				std::cout << "\t\t" << (*swapIt).first << ":" << (*swapIt).second << std::endl;
				++it;
				++swapIt;
			}
		}
		jovanTree.swap(jovanTreeSwap);
		{
			avltree_type::iterator swapIt = jovanTreeSwap.cbegin();
			avltree_type::iterator it = jovanTree.cbegin();
			std::cout << "tree" << "\t\t" << "tree swap"<< std::endl;
			while(swapIt != jovanTreeSwap.end() && it != jovanTree.end()){
				std::cout << it->first << ":" << it->second;
				std::cout << "\t\t" << (*swapIt).first << ":" << (*swapIt).second << std::endl;
				++it;
				++swapIt;
			}
		}
		swap(jovanTreeSwap,jovanTree);
		{
			avltree_type::iterator swapIt = jovanTreeSwap.cbegin();
			avltree_type::iterator it = jovanTree.cbegin();
			std::cout << "tree" << "\t\t" << "tree swap"<< std::endl;
			while(swapIt != jovanTreeSwap.end() && it != jovanTree.end()){
				std::cout << it->first << ":" << it->second;
				std::cout << "\t\t" << (*swapIt).first << ":" << (*swapIt).second << std::endl;
				++it;
				++swapIt;
			}
		}
		std::cout << "Round Six -- Empty test" << std::endl;
		avltree_type emptyTree;
		std::cout << "emptyTree is empty: "<< emptyTree.empty() << std::endl;
		emptyTree[5] = 5;
		std::cout << "emptyTree is empty: "<< emptyTree.empty() << std::endl;

		//*******************************************************
		//Lower Bound
		//*******************************************************
		std::cout << "Lower Bound" << std::endl;

		if(jovanTree.lower_bound(2)->second == 2)
		{
			std::cout << "Every Thing Good" << std::endl;
		}
		else
		{
			std::cout << "Every Thing BAD" << std::endl;
		}
		if(jovanTree.lower_bound(3)->second == 3)
		{
			std::cout << "Every Thing Good" << std::endl;
		}
		else
		{
			std::cout << "Every Thing BAD" << std::endl;
		}
		if(jovanTree.lower_bound(4)->second == 4)
		{
			std::cout << "Every Thing Good" << std::endl;
		}
		else
		{
			std::cout << "Every Thing BAD" << std::endl;
		}
		//*******************************************************
		//Upper Bound
		//*******************************************************
		std::cout << "Upper Bound" << std::endl;
		if(jovanTree.upper_bound(2)->second == 3)
		{
			std::cout << "Every Thing Good" << std::endl;
		}
		else
		{
			std::cout << "Every Thing BAD" << std::endl;
		}
		if(jovanTree.upper_bound(3)->second == 4)
		{
			std::cout << "Every Thing Good" << std::endl;
		}
		else
		{
			std::cout << "Every Thing BAD" << std::endl;
		}
		if(jovanTree.upper_bound(4)->second == 5)
		{
			std::cout << "Every Thing Good" << std::endl;
		}
		else
		{
			std::cout << "Every Thing BAD" << std::endl;
		}
		//*******************************************************
		//Emplace
		//*******************************************************
		typedef std::pair<avltree_type::iterator, bool> Pairib;
		Pairib emplaceTest = jovanTree.emplace(std::pair<int,int>(1,1));
		std::cout << emplaceTest.first->first << ":" << emplaceTest.first->first << "->" << emplaceTest.second<< std::endl;

		emplaceTest = jovanTree.emplace(std::pair<int,int>(45,45));
		std::cout << emplaceTest.first->first << ":" << emplaceTest.first->first << "->" << emplaceTest.second<< std::endl;

		std::cout << "END OF JOVAN TEST AREA" << std::endl;
		//*******************************************************
		//end of	Jovan Test Area
		//*******************************************************






	}
	catch(...)
	{
		std::cout<<"Catch Block\n";
	}
}