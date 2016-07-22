#if !defined (avl_iterator_20130202_)
#define avl_iterator_20130202_
#include <assert.h>
namespace avl{
	template <class tree>
	class const_avl_iterator;

	template <class tree>
	class avl_iterator {
	public:
		typedef typename tree::node					node;
		typedef typename tree::node_ptr				node_ptr;
		typedef typename tree::value_type*			pointer;
		typedef typename tree::value_type&			reference;
		typedef typename tree::const_node_ptr		const_node_ptr;
		typedef typename tree::utilities			utilities;
		typedef typename tree::value_type			value_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef std::ptrdiff_t						difference_type;

	private:
		friend class const_avl_iterator<tree>;
		node_ptr _node;
	public:
		avl_iterator() : _node()  { }
		avl_iterator( const node_ptr node ) : _node ( node ) { }
		avl_iterator( const avl_iterator& iterator ) {
			(*this) = iterator;
		}
		~avl_iterator() { _node = NULL; }

		avl_iterator& operator=(const avl_iterator& rhs) {
			_node = rhs._node;
			return (*this);
		}
		avl_iterator& operator=(const const_avl_iterator<tree>& rhs) {
			_node = rhs._node;
			return (*this);
		}

		bool operator == ( const avl_iterator& rhs ) const { return ( _node == rhs._node); }
		bool operator != ( const avl_iterator& rhs ) const { return ( _node != rhs._node); }

		avl_iterator& operator++()
		{
			_node = utilities::next_node( _node );
			return (*this);
		}
		avl_iterator operator ++( int ) {
			avl_iterator temp(*this);
			++(*this);
			return(temp);
		}

		avl_iterator& operator -- () {
			_node = utilities::pre_node( _node );
			return (*this);
		}

		avl_iterator operator -- ( int ) {
			avl_iterator temp(*this);
			--(*this);
			return(temp);
		}

		reference operator * () const {
			assert( ! utilities::is_header( _node ) );
			return _node->_value;
		}

		pointer operator -> () const {
			assert( ! utilities::is_header( _node ) );
			return &_node->_value;
		}
	};

	template <class tree>
	class const_avl_iterator {
	public:
		typedef typename tree::node							node;
		typedef typename tree::node_ptr						node_ptr;
		typedef typename tree::value_type*					pointer;
		typedef typename tree::value_type&					reference;
		typedef typename tree::const_node_ptr				const_node_ptr;
		typedef typename tree::utilities					utilities;
		typedef typename tree::value_type					value_type;
		typedef std::bidirectional_iterator_tag				iterator_category;
		typedef std::ptrdiff_t								difference_type;

	private:
		friend class avl_iterator<tree>;
		node_ptr _node;
	public:
		const_avl_iterator() : _node()  { }
		const_avl_iterator( const node_ptr node ) : _node ( node ) { }
		const_avl_iterator( const const_avl_iterator& iterator ) {
			(*this) = iterator;
		}
		~const_avl_iterator() { _node = NULL; }

		const_avl_iterator& operator=(const const_avl_iterator& rhs) {
			_node = rhs._node;
			return (*this);
		}

		const_avl_iterator& operator=(const avl_iterator<tree>& rhs) {
			_node = rhs._node;
			return (*this);
		}

		bool operator == ( const const_avl_iterator& rhs ) const { return ( _node == rhs._node); }
		bool operator != ( const const_avl_iterator& rhs ) const { return ( _node != rhs._node); }

		const_avl_iterator& operator++()
		{
			_node = utilities::next_node( _node );
			return (*this);
		}
		const_avl_iterator operator ++( int ) {
			const_avl_iterator temp(*this);
			++(*this);
			return(temp);
		}

		const_avl_iterator& operator -- () {
			_node = utilities::pre_node( _node );
			return (*this);
		}

		const_avl_iterator operator -- ( int ) {
			const_avl_iterator temp(*this);
			--(*this);
			return(temp);
		}

		const reference operator * () const {
			assert( ! utilities::is_header( _node ) );
			return _node->_value;
		}

		const pointer operator -> () const {
			assert( ! utilities::is_header( _node ) );
			return &_node->_value;
		}
	};
}
#endif