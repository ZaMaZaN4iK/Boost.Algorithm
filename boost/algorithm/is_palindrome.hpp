#ifndef BOOST_ALGORITHM_IS_PALINDROME_HPP
#define BOOST_ALGORITHM_IS_PALINDROME_HPP

#include <iterator>

#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>

namespace boost {  namespace algorithm {

template <typename BidirectionalIterator, typename Comp>
bool is_palindrome(BidirectionalIterator begin, BidirectionalIterator end, Comp c)
{
    --end;
    while(std::distance(begin, end) > 0)
    {
        if(!c(*begin, *end))
        {
            return false;
        }
        ++begin;
        --end;
    }
    return true;
}

template <typename BidirectionalIterator>
bool is_palindrome(BidirectionalIterator begin, BidirectionalIterator end)
{
    return is_palindrome(begin, end,
                         std::equal_to<typename std::iterator_traits<BidirectionalIterator>::value_type> ());
}


template <typename R>
bool is_palindrome(const R& range)
{
    return is_palindrome(boost::begin(range), boost::end(range));
}


template <typename R, typename Comp>
bool is_palindrome(const R& range, Comp c)
{
    return is_palindrome(boost::begin(range), boost::end(range), c);
}

}}

#endif // BOOST_ALGORITHM_IS_PALINDROME_HPP
