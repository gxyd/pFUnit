!--------------------------------------------------------------------
! Copyright © 2020 United States Government as represented by the   |
! Administrator of the National Aeronautics and Space               |
! Administration. No copyright is claimed in the United States      |
! under Title 17, U.S. Code. All Other Rights Reserved.             |
!                                                                   |
! Licensed under the Apache License, Version 2.0.                   |
!--------------------------------------------------------------------

!---------------
! The sequence of includes below seems a bit of overkill in the
! case of Pair containers.  However, it becomes necessary when
! considering higher order containers that use lower order
! containers.  E.g., Set uses Deque and Map uses Pair.
!---------------

#include "parameters/T/copy_deque_T_to_internal_T.inc"
#define __guard __deque_guard

#ifdef __deque_iterator
#    define __deque_iterator__ __deque_iterator
#else
#    define __deque_iterator__ DequeIterator
#endif

#ifdef __deque_riterator
#    define __deque_riterator__ __deque_riterator
#else
#    define __deque_riterator__ DequeRIterator
#endif

! define derived generic template parameters from internal parameters.
#include "parameters/T/define_derived_macros.inc"
   
   ! Structure constructors
   interface __deque
      module procedure __MANGLE(new_deque_range)
   end interface __deque

   ! Internal wrapper type allows support for types that cannot be
   ! directly treated as arrays: arrays, deferred type, deferred
   ! length.  To reduce implementation complexity the wrapper is used
   ! even when technically not required.  
   type :: __MANGLE(wrapper)
      __T_declare_component__ :: item
   end type __MANGLE(Wrapper)

   type :: __MANGLE(bucket)
      type(__MANGLE(wrapper)) :: bucket_items
   end type __MANGLE(bucket)

   type :: __MANGLE(bucket_ptr)
      type(__MANGLE(bucket)), pointer :: ptr => null()
   end type __MANGLE(bucket_ptr)

   type :: __deque
      private
      type(__MANGLE(bucket_ptr)), allocatable :: buckets(:)
      integer(kind=GFTL_SIZE_KIND) :: size_ = 0
      integer(kind=GFTL_SIZE_KIND) :: front_ = -1
      integer(kind=GFTL_SIZE_KIND) :: back_ = 0
   contains

      procedure :: erase_one => __MANGLE(erase_one)
      procedure :: erase_range => __MANGLE(erase_range)
      generic :: erase => erase_one
      generic :: erase => erase_range

      !procedure :: swap => __MANGLE(swap)
      !procedure :: reset => __MANGLE(reset)


      ! Factory methods for iterators
      !procedure :: begin => __MANGLE(begin)
      !procedure :: end => __MANGLE(end)
      !procedure :: rbegin => __MANGLE(rbegin)
      !procedure :: rend => __MANGLE(rend)

      ! No analog for the following in STL, but it seems very convenient.
#ifdef __T_EQ__
      procedure :: get_index => __MANGLE(get_index)
#endif
      ! I/O
      procedure :: write_formatted => __MANGLE(write_formatted)
      generic :: write(formatted) => write_formatted

      ! private helper procedures
      procedure, private :: set_capacity => __MANGLE(set_capacity)
      procedure, private :: grow_to => __MANGLE(grow_to)
      procedure, private :: bucket_index => __MANGLE(bucket_index)
      procedure, private :: bucket_offset => __MANGLE(bucket_offset)
   end type __deque


   !interface swap
   !   module procedure __MANGLE(swap)
   !end interface swap


#if defined(__T_EQ__) || defined(__T_LT__)
   interface operator(==)
   end interface operator(==)
   interface operator(/=)
   end interface operator(/=)

#endif

#ifdef __T_LT__
   interface operator(<)
      module procedure __MANGLE(less_than)
   end interface
   interface operator(>)
      module procedure __MANGLE(greater_than)
   end interface
   interface operator(<=)
      module procedure __MANGLE(less_than_or_equal_to)
   end interface
   interface operator(>=)
      module procedure __MANGLE(greater_than_or_equal_to)
   end interface
#endif
      

#include "deque/iterator_specification.inc"
#include "deque/reverse_iterator_specification.inc"

#ifdef __deque_iterator__
#    undef __deque_iterator__
#endif

#ifdef __deque_riterator__
#    undef __deque_riterator__
#endif

! undef derived template parameters
#include "parameters/T/undef_derived_macros.inc"

! undef internal template parameters
#undef __guard
#include "parameters/T/undef_internal.inc"

