/* 
   Copyright (c) Marshall Clow 2008-2010.

   Distributed under the Boost Software License, Version 1.0. (See accompanying
   file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

 Revision history:
   05 May 2008 mtc First version - as part of BoostCon 2008
   07 May 2009 mtc Changed names to match n2666
   02 Jul 2010 mtc Changed namespace to boost::algorithm::sequence
   16 Nov 2010 mtc Changed name of "exists_and_only" to "one_of" based
        on a suggestion by Sean Parent.
*/

/// \file
/// \brief Test ranges against predicates.
/// \author Marshall Clow

#ifndef BOOST_ALGORITHM_ALL_HPP
#define BOOST_ALGORITHM_ALL_HPP

#include <algorithm>            // for std::find and std::find_if

#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>

//  I would love to use the all_of, any_of and none_of that are in the C++0x
//  standard library if they are available, but I don't know how to do that.
//  -- mtc 11-May-2009
//  Something like:
//  #ifdef <something>
//  use std::all_of;
//  #else
//  template<typename I, typename V> 
//  bool all_of ( I first, I last, const V &val )
//      ... and so on.
//  #endif


namespace boost { namespace algorithm {

/// \fn all_of ( I first, I last, const V &val )
/// \return true if all elements in [first, last) are equal to 'val'
/// 
/// \param first The start of the input sequence
/// \param last  One past the end of the input sequence
/// \param val   A value to compare against
///
  template<typename I, typename V> 
  bool all_of ( I first, I last, const V &val )
  {
//  return std::find ( first, last, != val ) == last;  
    while (first != last)
    {
      if ( *first++ != val ) 
        return false;
    } 
    return true; 
  } 


/// \fn all_of ( const R &range, const V &val )
/// \return true if all elements in the range are equal to 'val'
/// 
/// \param range The input range
/// \param val   A value to compare against
///
  template<typename R, typename V> 
  bool all_of ( const R &range, const V &val ) 
  {
    return (all_of) ( boost::begin ( range ), boost::end ( range ), val );
  } 


/// \fn all_of_if ( I first, I last, Pred p )
/// \return true if all elements in [first, last) satisfy the predicate 'p'
/// 
/// \param first The start of the input sequence
/// \param last  One past the end of the input sequence
/// \param p     A predicate for testing the elements of the sequence
///
template<typename I, typename Pred> 
  bool all_of_if ( I first, I last, Pred p )
  {
//  return std::find_if ( first, last, !p ) == last;  
    while (first != last)
    {
      if ( !p(*first++)) 
        return false;
    } 
    return true; 
  } 

/// \fn all_of_if ( const R &range, Pred p )
/// \return true if all elements in the range satisfy the predicate 'p'
/// 
/// \param range The input range
/// \param p     A predicate for testing the elements of the range
///
  template<typename R, typename Pred> 
  bool all_of_if ( const R &range, Pred p )
  {
    return (all_of_if) ( boost::begin ( range ), boost::end ( range ), p );
  } 

/// \fn none_of ( I first, I last, const V &val )
/// \return true if none of the elements in [first, last) are equal to 'val'
/// 
/// \param first The start of the input sequence
/// \param last  One past the end of the input sequence
/// \param val   A value to compare against
///
  template<typename I, typename V> 
  bool none_of ( I first, I last, const V &val ) 
  {
//  return std::find ( first, last, val ) == last;
    while (first != last)
    {
      if ( *first++ == val ) 
        return false;
    } 
    return true; 
  } 

/// \fn none_of ( const R &range, const V &val )
/// \return true if none of the elements in the range are equal to 'val'
/// 
/// \param range The input range
/// \param val   A value to compare against
///
  template<typename R, typename V> 
  bool none_of ( const R &range, const V & val ) 
  {
    return (none_of) ( boost::begin ( range ), boost::end ( range ), val );
  } 


/// \fn none_of_if ( I first, I last, Pred p )
/// \return true if none of the elements in [first, last) satisfy the predicate 'p'
/// 
/// \param first The start of the input sequence
/// \param last  One past the end of the input sequence
/// \param p     A predicate for testing the elements of the sequence
///
template<typename I, typename Pred> 
  bool none_of_if ( I first, I last, Pred p )
  {
    while (first != last)
    {
      if ( p(*first++)) 
        return false;
    } 
    return true; 
  } 

/// \fn none_of_if ( const R &range, Pred p )
/// \return true if none of the elements in the range satisfy the predicate 'p'
/// 
/// \param range The input range
/// \param p     A predicate for testing the elements of the range
///
  template<typename R, typename Pred> 
  bool none_of_if ( const R &range, Pred p )
  {
    return (none_of_if) ( boost::begin ( range ), boost::end ( range ), p );
  } 

/// \fn any_of ( I first, I last, const V &val )
/// \return true if any of the elements in [first, last) are equal to 'val'
/// 
/// \param first The start of the input sequence
/// \param last  One past the end of the input sequence
/// \param val   A value to compare against
///
  template<typename I, typename V> 
  bool any_of ( I first, I last, const V &val ) 
  {
//  return std::find ( first, last, val ) != last;
    while (first != last)
    {
      if ( *first++ == val ) 
        return true;
    } 
    return false; 
  } 

/// \fn any_of ( const R &range, const V &val )
/// \return true if any of the elements in the range are equal to 'val'
/// 
/// \param range The input range
/// \param val   A value to compare against
///
  template<typename R, typename V> 
  bool any_of ( const R &range, const V &val ) 
  {
    return (any_of) ( boost::begin ( range ), boost::end ( range ), val );
  } 

/// \fn any_of_if ( I first, I last, Pred p )
/// \return true if any of the elements in [first, last) satisfy the predicate
/// 
/// \param first The start of the input sequence
/// \param last  One past the end of the input sequence
/// \param p     A predicate for testing the elements of the sequence
///
  template<typename I, typename Pred> 
  bool any_of_if ( I first, I last, Pred p) 
  {
//  return std::find_if ( first, last, p ) != last;
    while (first != last)
    {
      if ( p(*first++)) 
        return true;
    } 
    return false; 
  } 

/// \fn any_of_if ( const R &range, Pred p )
/// \return true if any elements in the range satisfy the predicate 'p'
/// 
/// \param range The input range
/// \param p     A predicate for testing the elements of the range
///
  template<typename R, typename Pred> 
  bool any_of_if ( const R &range, Pred p )
  {
    return (any_of_if) ( boost::begin ( range ), boost::end ( range ), p );
  } 

/// \fn one_of ( I first, I last, const V &val )
/// \return true if the value 'val' exists only once in [first, last).
/// 
/// \param first The start of the input sequence
/// \param last  One past the end of the input sequence
/// \param val   A value to compare against
///
  template<typename I, typename V> 
  bool one_of ( I first, I last, const V &val )
  {
    I i = std::find (first, last, val);	// find first occurrence of 'val'
    if (i == last) return false;		// Didn't occur at all
    return (none_of) (++i, last, val);
  }

/// \fn one_of ( const R &range, const V &val )
/// \return true if the value 'val' exists only once in the range.
/// 
/// \param range The input range
/// \param val   A value to compare against
///
  template<typename R, typename V> 
  bool one_of ( const R &range, const V &val )
  {
    return (one_of) ( boost::begin ( range ), boost::end ( range ), val );
  } 

/// \fn one_of_if ( I first, I last, Pred p )
/// \return true if the predicate 'p' is true for exactly one item in [first, last).
/// 
/// \param first The start of the input sequence
/// \param last  One past the end of the input sequence
/// \param p     A predicate for testing the elements of the sequence
///
  template<typename I, typename Pred> 
  bool  one_of_if ( I first, I last, Pred p )
  {
    I i = std::find_if (first, last, p);
    if (i == last) return false;	// Didn't occur at all
    return (none_of_if) (++i, last, p);
  }

/// \fn one_of_if ( const R &range, Pred p )
/// \return true if the predicate 'p' is true for exactly one item in the range.
/// 
/// \param range The input range
/// \param p     A predicate for testing the elements of the range
///
  template<typename R, typename Pred> 
  bool one_of_if ( const R &range, Pred p ) 
  {
    return (one_of_if) ( boost::begin ( range ), boost::end ( range ), p );
  } 


}} // namespace boost and algorithm

#endif // BOOST_ALGORITHM_ALL_HPP
