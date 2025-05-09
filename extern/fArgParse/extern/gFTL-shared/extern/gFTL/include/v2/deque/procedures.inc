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

#if defined(__deque_iterator)
#    define __deque_iterator__ __deque_iterator
#else
#    define __deque_iterator__ DequeIterator
#endif

#if defined(__deque_riterator)
#    define __deque_riterator__ __deque_riterator
#else
#    define __deque_riterator__ DequeRIterator
#endif

#if defined(__deque_bucket_size)
#    define __deque_bucket_size__ __deque_bucket_size
#else
#    define __deque_bucket_size__ 1
#endif

! define derived generic template parameters from internal parameters.
#include "parameters/T/define_derived_macros.inc"


   function __MANGLE(new_deque_range)(first, last) result(v)
      type (__deque) :: v
      type (__deque_iterator__), intent(in) :: first
      type (__deque_iterator__), intent(in) :: last

      type (__deque_iterator__) :: iter

      iter = first
      do while (iter /= last)
         !call v%push_back(iter%of())
      end do

      return
   end function __MANGLE(new_deque_range)

   function __MANGLE(back)(this) result(res)
      class(__deque), target, intent(in) :: this
      __T_declare_result__, pointer :: res

      res => this%buckets(this%back_)%ptr%bucket_items%item

      return
   end function __MANGLE(back)


#include "deque/iterator_procedures.inc"
#include "deque/reverse_iterator_procedures.inc"

#if defined(__deque_iterator__)
#    undef __deque_iterator__
#endif

#if defined(__deque_riterator__)
#    undef __deque_riterator__
#endif

#if defined(__deque_bucket_size__)
#    undef __deque_bucket_size__
#endif

! undef derived template parameters
#include "parameters/T/undef_derived_macros.inc"

! undef internal template parameters
#undef __guard
#include "parameters/T/undef_internal.inc"


