#if !defined (avl_node_20130202_)
#define avl_node_20130202_
namespace avl{
	template <class tree>
	struct avl_node {
	private:
		typedef typename tree::key_type			Key;
		typedef typename tree::mapped_type		Type;
		typedef typename tree::value_type		value_type;
	public:
		typedef avl_node*						node_ptr;
		typedef const avl_node*					const_node_ptr;
		node_ptr _parentNode, _leftNode, _rightNode;
		int _balance;
		value_type _value;
		//Constructors
		avl_node(): _balance(0), _parentNode(NULL), _leftNode(NULL), _rightNode(NULL) {} 
		
		avl_node( const value_type& value ) : _value(value), _balance(0), _parentNode(NULL), _leftNode(NULL), _rightNode(NULL) { }
		
		avl_node( avl_node && original ) {
			_value = original._value;
			_balance = original._balance;
			_parentNode = original._parentNode;
			_leftNode = original._leftNode;
			_rightNode = original._rightNode;

			original._parentNode = original._leftNode = original._rightNode = nullptr;
			original._value = NULL;
			original._balance = 0;
			delete ( original );
		}
		//Destructors
		~avl_node(){
			_parentNode = _leftNode = _rightNode = nullptr;
			_balance = 0;
		}

		avl_node& operator = ( const node_ptr & rhs ) {
			_balance = rhs->_balance;
			_value = rhs->_value;
			_parentNode = rhs->_parentNode;
			_leftNode = rhs->_leftNode;
			_rightNode = rhs->_rightNode;
		}
		avl_node& operator = ( const const_node_ptr & rhs ) {
			_balance = rhs->_balance;
			_value = rhs->_value;
			_parentNode = rhs->_parentNode;
			_leftNode = rhs->_leftNode;
			_rightNode = rhs->_rightNode;
		}
		bool operator == ( const node_ptr& rhs ) { return ( _value.first == rhs->_value.first ); }
		bool operator == ( const const_node_ptr& rhs ) { return ( _value.first == rhs->_value.first ); }
		bool operator != ( const node_ptr& rhs ) { return ( _value.first != rhs->_value.first ); }
		bool operator != ( const const_node_ptr& rhs ) { return ( _value.first != rhs->_value.first ); }

		static node_ptr get_parent( const const_node_ptr & node ) {
			return node->_parentNode;
		}

		static node_ptr get_parent( const node_ptr & node ) {
			return node->_parentNode;
		}

		static void set_parent( const node_ptr & node, const node_ptr & parent ) {
			node->_parentNode = parent;
		}

		static node_ptr get_left(const const_node_ptr & node) {
			return node->_leftNode;
		}

		static node_ptr get_left(const node_ptr & node) {
			return node->_leftNode;
		}

		static void set_left(const node_ptr & node, const node_ptr & left) {
			node->_leftNode = left;
		}

		static node_ptr get_right(const const_node_ptr & node) {
			return node->_rightNode;
		}

		static node_ptr get_right(const node_ptr & node) {
			return node->_rightNode;
		}

		static void set_right(const node_ptr & node, const node_ptr & right) {
			node->_rightNode = right;
		}

		static int get_balance(const const_node_ptr & node)	{
			return node->_balance;
		}

		static int get_balance(const node_ptr & node) {
			return node->_balance;
		}

		static void set_balance(const node_ptr & node, int balance) {
			node->_balance = balance;
		}

		static void set_value( const node_ptr& from, const node_ptr& to ) {
			to->_value = from->_value;
		}

		static node_ptr& to_ptr ( const const_node_ptr & rhs ){
			node_ptr node = new avl_node();
			node->_balance = rhs->_balance;
			node->_value = rhs->_value;
			node->_parentNode = rhs->_parentNode;
			node->_leftNode = rhs->_leftNode;
			node->_rightNode = rhs->_rightNode;
			return node;
		}
	};
} 
#endif