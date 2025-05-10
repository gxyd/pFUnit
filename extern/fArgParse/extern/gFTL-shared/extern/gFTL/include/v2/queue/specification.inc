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

#include "parameters/T/copy_queue_T_to_deque_T.inc"

#define __deque __queue_container_type
#define __deque_guard __IDENTITY(__queue_guard)__IDENTITY(d_)
   
#define __guard __deque_guard

#define __deque_iterator__ DequeIterator
#define __deque_riterator__ DequeRIterator

   ! Structure constructors
   interface __deque
      module procedure __MANGLE(new_deque_range)
   end interface __deque

   type :: __deque
      private
   contains
   end type __deque

   interface operator(==)
   end interface operator(==)
   interface operator(/=)
   end interface operator(/=)

type __deque_iterator__
private

type(__deque), pointer :: deque
integer(kind=__gftl_size_kind) :: current_index = -1 ! intentionally invalid value

contains

end type __deque_iterator__


! Non type-bound functions

! Relational operators
interface operator(==)
module procedure __MANGLE(iter_equal)
end interface operator(==)

interface operator(/=)
module procedure __MANGLE(iter_not_equal)
end interface operator(/=)

type __deque_riterator__
private

type(__deque), pointer :: deque
integer(kind=__gftl_size_kind) :: current_index = -1 ! intentionally invalid value

contains

end type __deque_riterator__

! Relational operators
interface operator(==)
module procedure __MANGLE(riter_equal)
end interface operator(==)

interface operator(/=)
module procedure __MANGLE(riter_not_equal)
end interface operator(/=)


! undef internal template parameters
#undef __guard


#undef __deque
#undef __deque_guard


#include "parameters/T/copy_queue_T_to_internal_T.inc"
#define __guard __queue_guard

! define derived generic template parameters from internal parameters.
#include "parameters/T/define_derived_macros.inc"

   
   ! Structure constructors
   interface __queue
      module procedure __MANGLE(new_queue_empty)
      module procedure __MANGLE(new_queue_container)
      module procedure __MANGLE(new_queue_copy)
   end interface __queue

   type :: __queue
      private
      type(__queue_container_type) :: container
   contains

      procedure :: size => __MANGLE(size)
      procedure :: empty => __MANGLE(empty)
!      procedure, nopass :: max_size => __MANGLE(max_size)
!      procedure :: capacity => __MANGLE(capacity)

      ! Accessors

      procedure :: back => __MANGLE(back)
      procedure :: front => __MANGLE(front)

      procedure :: push => __MANGLE(push)
      procedure :: pop => __MANGLE(pop)

      procedure :: swap => __MANGLE(swap)

      ! I/O
      procedure :: write_formatted => __MANGLE(write_formatted)
      generic :: write(formatted) => write_formatted

   end type __queue


   interface swap
      module procedure __MANGLE(swap)
   end interface swap


#if defined(__T_EQ__) || defined(__T_LT__)
   interface operator(==)
      module procedure __MANGLE(equal)
   end interface operator(==)
   interface operator(/=)
      module procedure __MANGLE(not_equal)
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
      



! undef derived template parameters
#include "parameters/T/undef_derived_macros.inc"

! undef internal template parameters
#undef __guard
#include "parameters/T/undef_internal.inc"

