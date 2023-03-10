/*! \file
\brief Некоторые фичи C++11, которые не реализованы библиотеке компилятора Keil
*/
#pragma once

namespace std
{
    // Defined in header <cstddef>
	typedef decltype(nullptr) nullptr_t;


    // Defined in header <algorithm>
    template< class T > struct remove_reference      {typedef T type;};
	template< class T > struct remove_reference<T&>  {typedef T type;};
	template< class T > struct remove_reference<T&&> {typedef T type;};
						
	template<class T> 
	typename remove_reference<T>::type&&
	move(T&& a) noexcept
	{
		typedef typename remove_reference<T>::type&& RvalRef;
		return static_cast<RvalRef>(a);
	} 

    // Defined in header <utility>
	template<class T> 
	T&&
	forward(typename remove_reference<T>::type& a) noexcept
	{
		return static_cast<T&&>(a);
	} 

} // namespace std

#include "stl_keil_type_traits.h"

