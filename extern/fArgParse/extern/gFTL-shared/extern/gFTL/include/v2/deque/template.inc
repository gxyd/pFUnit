
#include "deque/header.inc"

   private
   public :: __deque
   public :: __deque_iterator

   ! Iterator functions
   public :: advance
   public :: distance
   public :: operator(+)
   public :: operator(-)


   ! Iterator and possibly container functions:
   ! The following are always defined for the iterator.
   ! May not also be defined for the container itself depending
   ! on properties of parameter T.

   public :: operator(==)
   public :: operator(/=)

   public :: operator(<)
   public :: operator(>)
   public :: operator(<=)
   public :: operator(>=)


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
      !type(__MANGLE(bucket_ptr)), allocatable :: buckets(:)
      integer(kind=GFTL_SIZE_KIND) :: size_ = 0
      integer(kind=GFTL_SIZE_KIND) :: front_ = -1
      integer(kind=GFTL_SIZE_KIND) :: back_ = 0
   contains
   end type __deque

#if defined(__T_EQ__) || defined(__T_LT__)
   interface operator(==)
   end interface operator(==)
   interface operator(/=)
   end interface operator(/=)

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



   contains

#include "deque/procedures.inc"
