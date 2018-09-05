#include<iostream>
#include <map>
#include <limits>
using namespace std;
template<typename K, typename V>
class interval_map {
	std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        std::cout << "(" << keyBegin << "," << keyEnd << "," << val << ")\n";

		using iterator_t = typename std::map<K, V>::iterator;
        // assigning values of lower bound and upper bound
		iterator_t lower_limit = m_map.lower_bound(keyBegin); // the first entry in the map whose key is >= keyBegin
		iterator_t upper_limit = m_map.upper_bound(keyBegin); // the first entry in the map whose key is > keyBegin
        iterator_t delBegin,delEnd;
        if (!( keyBegin < keyEnd )){
            return ;
        }
        //delete or erase 
        m_map.erase(delBegin, ++delEnd);
// INSERT YOUR SOLUTION HERE
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.


int main()
{

    return 0;
}

void test_interval_map() {
		m_map.insert(std::make_pair(1, 'b'));
		m_map.insert(std::make_pair(4, 'c'));
		m_map.insert(std::make_pair(7, 'd'));
		m_map.insert(std::make_pair(10, 'e'));
		m_map.insert(std::make_pair(13, 'a'));
}