#if !defined (avl_utilities_20130202_)
#define avl_utilities_20130202_

namespace avl{
	template <class tree>
	class avl_utilities{
		typedef typename tree::key_type			key_type;
		typedef typename tree::mapped_type		Type;
		typedef typename tree::key_compare		compare;
		typedef typename tree::value_type		value_type;
		typedef typename tree::node				node;
		typedef typename tree::node_ptr			node_ptr;
		typedef typename tree::const_node_ptr	const_node_ptr;

	public:
		static void init_header( node_ptr& header ) {
			header = new node();
		}

		static bool is_header( const const_node_ptr & p ) {
			node_ptr p_left (node::get_left(p));
			node_ptr p_right (node::get_right(p));
			if(!node::get_parent(p) || //Header condition for empty tree
				(p_left && p_right &&         
				(p_left == p_right ||      
				(node::get_parent(p_left)  != p ||
				node::get_parent(p_right) != p ))
				)) {
					return true;
			}
			return false;
		}
		static node_ptr get_node( const key_type& key, node_ptr& header) {
			if( node::get_parent( header ) ) {
				node_ptr currentNode = node::get_parent( header );

				while ( currentNode ) {
					if ( key == currentNode->_value.first ) {
						return currentNode ;
					}
					compare _comparer;
					bool compare = _comparer( currentNode->_value.first, key );
					if ( compare ) {
						if ( !node::get_right( currentNode ) ) {
							break;
						} else {
							currentNode = node::get_right( currentNode );
						}
					} else {
						if ( !node::get_left( currentNode ) ) {
							break;
						} else {
							currentNode = node::get_left( currentNode );
						}
					}
				}
			}
			return header; 
		}

		static node_ptr get_header(const node_ptr & node) {
			node_ptr h = node;
			if(node::get_parent(node)) {
				h = node::get_parent(node);
				while(!is_header(h)) {
					h = node::get_parent(h);
				}
			}
			return h;
		}

		static node_ptr get_root( const node_ptr& node ) {
			return ( node::get_parent( node::get_header ( node ) ) );
		}

		static node_ptr next_node( const node_ptr & node ) {
			node_ptr p_right( node::get_right( node ) );
			if( p_right ) {
				return min( p_right );
			}
			else {
				node_ptr p(node);
				node_ptr x = node::get_parent(p);
				while( p == node::get_right(x) ) {
					p = x;
					x = node::get_parent(x);
				}
				return node::get_right(p) != x ? x : p;
			}
		}

		static node_ptr pre_node( const node_ptr & node ) {
			if( is_header( node ) ) {
				return node::get_right(node);
			}
			else if( node::get_left( node ) ) {
				return max( node::get_left( node ) );
			}
			else {
				node_ptr p(node);
				node_ptr x = node::get_parent(p);
				while(p == node::get_left(x)){
					p = x;
					x = node::get_parent(x);
				}
				return x;
			}
		}

		static node_ptr min ( node_ptr node ) {
			for(node_ptr p_left = node::get_left(node)
				;p_left
				;p_left = node::get_left(node)) {
					node = p_left;
			}
			return node;
		}

		static node_ptr max( node_ptr node ) {
			for(node_ptr p_right = node::get_right(node)
				;p_right
				;p_right = node::get_right(node)) {
					node = p_right;
			}
			return node;
		}

		//finds and returns a node matching a key value if it exists
		static node_ptr find_node( node_ptr node, const key_type& key ) {
			while ( node ) {
				if ( key == node->_value.first ) {
					return node;
				}

				compare _comparer;
				bool compare = _comparer( node->_value.first, key );
				if ( compare ) {
					if ( !node::get_right( node ) ) {
						break;
					} else {
						node = node::get_right( node );
					}
				} else {
					if ( !node::get_left( node ) ) {
						break;
					} else {
						node = node::get_left( node );
					}
				}
			}
			return NULL;
		}

		static void insert_balance( node_ptr node, int balance ) {
			while ( node && !is_header( node ) ) {
				node::set_balance( node, ( node::get_balance( node ) + balance ) );
				balance = node::get_balance( node );

				if ( balance == 0 ) {
					return;
				} else if ( balance == 2 ) {
					if( node::get_balance( node::get_left( node ) ) == 1 ) {
						rotate_right( node );
					} else {
						rotate_left_right( node );
					}
					return;
				} else if ( balance == -2 ) {
					if ( node::get_balance( node::get_right( node ) ) == -1 ) {
						rotate_left( node );
					} else {
						rotate_right_left( node );
					}
					return;
				}

				node_ptr parentNode = node::get_parent( node );
				if ( parentNode && !is_header( parentNode ) ) {
					balance = node::get_left( parentNode ) == node ? 1 : -1;
				}
				node = parentNode;
			}
		}

		static void delete_balance( node_ptr node, int balance ) {
			while ( node && !is_header( node ) ) {
				node::set_balance( node, ( node::get_balance( node ) + balance ) );
				balance = node::get_balance( node );

				if ( balance == 2 ) {
					if ( node::get_balance( node::get_left( node ) ) >= 0 ) {
						node = rotate_right( node );
						if ( node::get_balance( node ) == -1 ) {
							return;
						}
					} else {
						node = rotate_left_right( node );
					}
				} else if ( balance == -2 ) {
					if ( node::get_balance( node::get_right( node ) ) <= 0 ) {
						node = rotate_left( node );
						if ( node::get_balance( node ) == 1 ) {
							return;
						}
					} else {
						node = rotate_right_left( node );
					}
				} else if ( balance != 0 ) {
					return;
				}

				if ( node::get_parent( node ) ) {
					balance = node::get_left( node::get_parent( node ) ) == node ? -1 : 1;
				}

				node = node::get_parent( node );
			}
		}

		static node_ptr rotate_left( node_ptr node ) {
			node_ptr right ( node::get_right( node ) );
			node_ptr rightLeft ( node::get_left( right ) );
			node_ptr parent ( node::get_parent( node ) );
			bool isHeader = is_header( parent ); //get header before changing links
			node::set_parent( right, parent );
			node::set_left( right, node );
			node::set_right( node, rightLeft );
			node::set_parent( node, right );

			if ( rightLeft ) {
				node::set_parent( rightLeft, node );
			}
			//parent
			if ( isHeader ) {			
				node::set_parent( parent, right );
			} else if ( node::get_right( parent ) == node ) {		//right branch of parent node
				node::set_right( parent, right );
			} else {												//left branch of parent node
				node::set_left( parent, right );
			}

			node::set_balance( right, ( node::get_balance( right ) + 1 ) );
			node::set_balance( node, -( node::get_balance( right ) ) );

			return right;
		}

		static node_ptr rotate_right( node_ptr node ) {
			node_ptr left = node::get_left( node );
			node_ptr leftRight = node::get_right( left );
			node_ptr parent = node::get_parent( node );
			bool isHeader = is_header( parent );
			node::set_parent( left, parent );
			node::set_right( left, node );
			node::set_left( node, leftRight );
			node::set_parent( node, left );

			if ( leftRight ) {
				node::set_parent( leftRight, node );
			}

			if ( isHeader ) {			
				node::set_parent( parent, left );
			} else if ( node::get_left( parent ) == node ) {		
				node::set_left( parent, left );
			} else {												
				node::set_right( parent, left );
			}

			node::set_balance( left, ( node::get_balance( left ) + 1 ) );
			node::set_balance( node, -( node::get_balance( left ) ) );

			return left;
		}

		static node_ptr rotate_left_right( node_ptr node ) {
			node_ptr left = node::get_left( node );
			node_ptr leftRight = node::get_right( left );
			node_ptr parent = node::get_parent( node );
			node_ptr leftRightRight = node::get_right( leftRight );
			node_ptr leftRightLeft = node::get_left( leftRight );
			bool isHeader = is_header( parent );
			node::set_parent( leftRight, parent );
			node::set_left( node, leftRightRight );
			node::set_right( left, leftRightLeft );
			node::set_left( leftRight, left );
			node::set_right( leftRight, node );
			node::set_parent( left, leftRight );
			node::set_parent( node, leftRight );

			if ( leftRightRight ) {
				node::set_parent( leftRightRight, node );
			}

			if ( leftRightLeft ) {
				node::set_parent( leftRightLeft, left );
			}

			if ( isHeader ) {			
				node::set_parent( parent, leftRight );
			} else if ( node::get_left( parent ) == node ) {
				node::set_left( parent, leftRight );
			} else {
				node::set_right( parent, leftRight );
			}

			if ( node::get_balance( leftRight ) == 1 ) {
				node::set_balance( node, 0 );
				node::set_balance( left, 1 );
			} else if ( node::get_balance( leftRight ) == 0 ) {
				node::set_balance( node, 0 );
				node::set_balance( left, 0 );
			} else {
				node::set_balance( node, -1 );
				node::set_balance( left, 0 );
			}

			node::set_balance( leftRight, 0 );

			return leftRight;
		}

		static node_ptr rotate_right_left( node_ptr node ) {
			node_ptr right = node::get_right( node );
			node_ptr rightLeft = node::get_left( right );
			node_ptr parent = node::get_parent( node );
			node_ptr rightLeftLeft = node::get_left( rightLeft );
			node_ptr rightLeftRight = node::get_right( rightLeft );
			bool isHeader = is_header( parent );
			node::set_parent( rightLeft, parent );
			node::set_right( node, rightLeftLeft );
			node::set_left( right, rightLeftRight );
			node::set_right( rightLeft, right );
			node::set_left( rightLeft, node );
			node::set_parent( right, rightLeft );
			node::set_parent( node, rightLeft );

			if ( rightLeftLeft ) {
				node::set_parent( rightLeftLeft, node );
			}

			if ( rightLeftRight ) {
				node::set_parent( rightLeftRight, right );
			}

			if ( isHeader ) {			
				node::set_parent( parent, rightLeft );
			} else if ( node::get_right( parent ) == node ) {
				node::set_right( parent, rightLeft );
			} else {
				node::set_left( parent, rightLeft );
			}

			if ( node::get_balance( rightLeft ) == 1 ) {
				node::set_balance( node, 0 );
				node::set_balance( right, 1 );
			} else if ( node::get_balance( rightLeft ) == 0 ) {
				node::set_balance( node, 0 );
				node::set_balance( right, 0 );
			} else {
				node::set_balance( node, -1 );
				node::set_balance( right, 0 );
			}

			node::set_balance( rightLeft, 0 );

			return rightLeft;
		}

		static void succeed( node_ptr& predecessor, node_ptr& successor ) {
								
			node_ptr left = node::get_left( successor );
			node_ptr right = node::get_right( successor );
			node_ptr parent = node::get_parent( predecessor );

			node_ptr header = get_header( parent );

			bool isHeader = is_header( parent );
			bool isFirstNode = node::get_left( header ) == predecessor;
			bool isLastNode = node::get_right( header ) == predecessor;
			delete( predecessor );
			predecessor = successor;
			node::set_parent( predecessor, parent );
			if ( isHeader ) {
				node::set_parent( parent, predecessor );
			}
			if( isFirstNode ){
				node::set_left( parent, predecessor );
			}
			if( isLastNode ){
				node::set_right( parent, predecessor );
			}
		
			if ( left ) {
				node::set_parent( left, predecessor );
			}

			if ( right ) {
				node::set_parent( right, predecessor );
			}
		}

		//Clears node and all children
		static void clear_tree ( node_ptr node ) {
			if( node != NULL ){
				node_ptr p_left (node::get_left(node));
				node_ptr p_right(node::get_right(node));
				if ( p_left ) {
					clear_tree( p_left );
				}
				if ( p_right ) {
					clear_tree( p_right );
				}
				delete( node );
			}
		}
	};
}
#endif