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


   subroutine __MANGLE(unused_procedure)()
      ! The following are an adhoc way to suppress compiler
      ! warnings about parameters not used in this template
      __UNUSED_DUMMY(BAD_ALLOC)
      __UNUSED_DUMMY(TYPE_HAS_NO_DEFAULT_VALUE)
      __UNUSED_DUMMY(NO_TYPE__)
   end subroutine __MANGLE(unused_procedure)


   ! =======================
   !  size
   ! =======================
   pure function __MANGLE(size)(this) result(res)
      class(__deque), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND) :: res

      res = this%size_

      return
   end function __MANGLE(size)


   ! =======================
   !  of - return ith element without bounds checks
   ! =======================
   function __MANGLE(of_size_kind)(this, i) result(res)
      class(__deque), target, intent(in) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: i
      __T_declare_result__, pointer :: res


      !res => this%buckets(this%idx(i))%ptr%bucket_items%item

      return
   end function __MANGLE(of_size_kind)


#if defined(__T_EQ__) || defined(__T_LT__)
   ! =======================
   !  equal
   ! =======================
   impure elemental function __MANGLE(equal)(lhs, rhs) result(equal)
      logical :: equal
      type(__deque), intent(in) :: lhs
      type(__deque), intent(in) :: rhs

      integer(kind=GFTL_SIZE_KIND) :: i, ii

      ! Same size?
      equal = (lhs%front_ == rhs%front_) .and. (lhs%back_ == rhs%back_)

      if (equal) then ! Same elements?
         
         do i = 1, lhs%size_
            !ii = lhs%idx(i)

            associate ( &
                 item_l => lhs%buckets(ii)%ptr%bucket_items%item, &
                 item_r => rhs%buckets(ii)%ptr%bucket_items%item)
#ifdef __T_EQ__
#if __T_rank > 0 && !defined(__T_shape)
              if (any(shape(item_l) /= shape(item_r))) then
               equal = .false.
               return
            endif
#endif
            if (.not. (__T_EQ__(item_l, item_r))) then
               equal = .false.
               return
            end if
#else
! then must have a less-than operator
            if ((__T_LT__(item_l,item_r))) then
               equal = .false.
               return
            elseif ((__T_LT__(item_r,item_l))) then
               equal = .false.
               return
            end if
#endif
            end associate
         end do

         ! all elements equal
         equal = .true. ! redundant
      endif

      return
   end function __MANGLE(equal)

   ! =======================
   !  not_equal
   ! =======================
   impure elemental function __MANGLE(not_equal)(lhs, rhs) result (not_equal)
      logical :: not_equal
      type(__deque), intent(in) :: lhs
      type(__deque), intent(in) :: rhs

      not_equal = .not. (lhs == rhs)

      return
   end function __MANGLE(not_equal)

#endif




#ifdef __T_LT__
   ! =======================
   !  operator(<) - use lexicographical compare
   ! =======================
   impure elemental function __MANGLE(less_than)(lhs, rhs) result(less_than)
      logical :: less_than
      type (__deque), intent(in) :: lhs
      type (__deque), intent(in) :: rhs

      integer(kind=GFTL_SIZE_KIND) :: i, n
      __T_declare_result__, pointer :: lhs_i, rhs_i
      
      n = min(lhs%size(), rhs%size())
      do i = 1, n
         
         lhs_i => lhs%of(i)
         rhs_i => rhs%of(i)

         if (__T_LT__(lhs_i, rhs_i)) then
            less_than = .true.
            return
         else if (__T_LT__(rhs_i,lhs_i)) then
            less_than = .false.
            return
         endif
      end do

      less_than = (n < rhs%size())

      return
   end function __MANGLE(less_than)

   impure elemental function __MANGLE(greater_than_or_equal_to)(lhs, rhs) &
        & result(greater_than_or_equal_to)
      logical :: greater_than_or_equal_to
      type (__deque), intent(in) :: lhs
      type (__deque), intent(in) :: rhs

      greater_than_or_equal_to = .not. (lhs < rhs)

      return
   end function __MANGLE(greater_than_or_equal_to)


   impure elemental function __MANGLE(greater_than)(lhs, rhs) result(greater_than)
      logical :: greater_than
      type (__deque), intent(in) :: lhs
      type (__deque), intent(in) :: rhs

      greater_than = (rhs < lhs)

      return
   end function __MANGLE(greater_than)


   impure elemental function __MANGLE(less_than_or_equal_to)(lhs, rhs) &
        &  result(less_than_or_equal_to)
      logical :: less_than_or_equal_to
      type (__deque), intent(in) :: lhs
      type (__deque), intent(in) :: rhs

      less_than_or_equal_to = .not. (rhs < lhs)

      return
   end function __MANGLE(less_than_or_equal_to)


#endif


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


