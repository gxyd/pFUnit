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
   !  capacity - size of internal arrays; >= size()
   ! =======================
   pure function __MANGLE(capacity)(this) result(capacity)
      integer(kind=GFTL_SIZE_KIND) :: capacity
      class (__deque), intent(in) :: this

      if (allocated(this%buckets)) then
         capacity = size(this%buckets, kind=GFTL_SIZE_KIND)
      else
         capacity = 0
      end if

      return
   end function __MANGLE(capacity)



   ! Hopefully this is inlined
   function __MANGLE(idx)(this, i) result(idx)
      integer(kind=GFTL_SIZE_KIND) :: idx
      class(__deque), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND) :: i

      idx = 1 + modulo(this%front_ + (i-1) - 1, this%capacity())

   end function __MANGLE(idx)




   ! =======================
   !  of - return ith element without bounds checks
   ! =======================
   function __MANGLE(of_size_kind)(this, i) result(res)
      class(__deque), target, intent(in) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: i
      __T_declare_result__, pointer :: res


      res => this%buckets(this%idx(i))%ptr%bucket_items%item

      return
   end function __MANGLE(of_size_kind)


   ! =======================
   !  back() - last element; undefined behavior for empty container
   ! =======================
   function __MANGLE(back)(this) result(res)
      class(__deque), target, intent(in) :: this
      __T_declare_result__, pointer :: res

      res => this%buckets(this%back_)%ptr%bucket_items%item

      return
   end function __MANGLE(back)

   ! =======================
   !  front() ! first element; undefined behavior for empty container
   ! =======================
   function __MANGLE(front)(this) result(res)
      class(__deque), target, intent(in) :: this
      __T_declare_result__, pointer :: res

      res => this%buckets(this%front_)%ptr%bucket_items%item

      return
   end function __MANGLE(front)



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
            ii = lhs%idx(i)

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



   subroutine __MANGLE(resize_default)(this, count, unused, value, rc)
      class(__deque), intent(inout) :: this
      integer, intent(in) :: count
      type (KeywordEnforcer), optional, intent(in) :: unused
      __T_declare_dummy__, optional, intent(in) :: value
      integer, optional, intent(out) :: rc

      __UNUSED_DUMMY(unused)

      !call this%resize(int(count,kind=GFTL_SIZE_KIND), value=value, rc=rc)

   end subroutine __MANGLE(resize_default)


   ! =======================
   !  downsize()
   ! =======================
   subroutine __MANGLE(downsize)(this, from, to)
      class(__deque), intent(inout) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: from, to  ! assumes newsize<=size()

#if defined(__T_FREE__)
      integer(kind=GFTL_SIZE_KIND) :: i, ii
      if (from <= to) then

         do i = from, to - 1
            ii = this%idx(i)
            __T_FREE__(this%buckets(ii)%ptr%bucket_items%item)
         end do

      else

         do i = from, this%capacity()
            ii = this%idx(i)
            __T_FREE__(this%buckets(ii)%ptr%bucket_items%item)
         end do
         do i = 1, to
            ii = this%idx(i)
            __T_FREE__(this%buckets(ii)%ptr%bucket_items%item)
         end do

      endif
      __UNUSED_DUMMY(ii)
#endif

      this%size_ = this%size_ - modulo(from - to, this%capacity())  - 1

      return
   end subroutine __MANGLE(downsize)


   ! =======================
   !  clear
   ! =======================
   subroutine __MANGLE(clear)(this)
      class(__deque), intent(inout) :: this

      call this%downsize(this%front_, this%back_)
      this%front_ = -1
      this%back_ = 0

      return
   end subroutine __MANGLE(clear)


   ! =======================
   !  shrink_to_fit
   ! =======================

   subroutine __MANGLE(shrink_to_fit)(this)
      class(__deque), intent(inout) :: this

      if (this%size_ < this%capacity()) then
         !call this%set_capacity(this%size_)
      endif
      return
   end subroutine __MANGLE(shrink_to_fit)


   ! =======================
   !  swap
   ! =======================
   subroutine __MANGLE(swap)(this, x)
      class(__deque), target, intent(inout) :: this
      type(__deque), target, intent(inout) :: x

      type(__MANGLE(bucket_ptr)), dimension(:), allocatable :: tmp
      integer(kind=GFTL_SIZE_KIND) :: i_tmp

      call move_alloc(this%buckets, tmp)
      call move_alloc(x%buckets, this%buckets)
      call move_alloc(tmp, x%buckets)

      i_tmp = this%size_
      this%size_ = x%size_
      x%size_ = i_tmp

      i_tmp = this%front_
      this%front_ = x%front_
      x%front_ = i_tmp

      i_tmp = this%back_
      this%back_ = x%back_
      x%back_ = i_tmp
      
      return
   end subroutine __MANGLE(swap)


#ifdef __T_EQ__
   ! =======================
   !  get_index() Return index of first item equal to value
   !  If not found, return 0.
   ! =======================
      function __MANGLE(get_index)(this, value) result(i)
         class(__deque), target, intent(in) :: this
         __T_declare_dummy__, intent(in) :: value

         integer(kind=GFTL_SIZE_KIND) :: i, ii
         
         do i=1, this%size_
            ii = this%idx(i)
            if (__T_EQ__(this%buckets(ii)%ptr%bucket_items%item, value)) return
         end do
         i=0

         return
      end function __MANGLE(get_index)
#endif      


   ! =======================
   !  begin() - create an iterator
   ! =======================
   function __MANGLE(begin)(this) result(iter)
      type (__deque_iterator__) :: iter
      class (__deque), target, intent(in) :: this

      iter%current_index = 1
      iter%deque => this
      
   end function __MANGLE(begin)


   ! =======================
   !  end()
   !  Construct  forward iterator, initially set to just
   !  after last element of deque.
   ! =======================
   function __MANGLE(end)(this) result(iter)
      class (__deque), target, intent(in) :: this
      type (__deque_iterator__) :: iter

      iter%current_index = this%size() + 1 ! past the end
      iter%deque => this

   end function __MANGLE(end)


   ! =======================
   !  rbegin() - create a reverse iterator
   ! =======================
   function __MANGLE(rbegin)(this) result(iter)
      type (__deque_riterator__) :: iter
      class (__deque), target, intent(in) :: this

      iter%current_index = this%size_
      iter%deque => this

   end function __MANGLE(rbegin)


   ! =======================
   !  rend()
   !  Construct  reverse iterator, initially set to just
   !  before first element of deque
   ! =======================
   function __MANGLE(rend)(this) result(iter)
      class (__deque), target, intent(in) :: this
      type (__deque_riterator__) :: iter

      iter%current_index = 0 ! before beginning
      iter%deque => this

   end function __MANGLE(rend)



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


