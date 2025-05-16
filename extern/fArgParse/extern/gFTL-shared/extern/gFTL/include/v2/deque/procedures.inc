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
   end subroutine __MANGLE(unused_procedure)


   ! =======================
   !  Structure constructors
   ! =======================
   function __MANGLE(new_deque_empty)() result(v)
      type (__deque) :: v
      logical, parameter :: flag = .false.
   end function __MANGLE(new_deque_empty)


   function __MANGLE(new_deque_fill_size_kind)(n, value) result(v)
      type (__deque) :: v
      integer(kind=GFTL_SIZE_KIND), intent(in) :: n
      __T_declare_dummy__, optional, intent(in) :: value
   end function __MANGLE(new_deque_fill_size_kind)


   function __MANGLE(new_deque_fill_default)(n, value) result(v)
      type (__deque) :: v
      integer, intent(in) :: n
      __T_declare_dummy__, optional, intent(in) :: value
   end function __MANGLE(new_deque_fill_default)


   function __MANGLE(new_deque_range)(first, last) result(v)
      type (__deque) :: v
      type (__deque_iterator__), intent(in) :: first
      type (__deque_iterator__), intent(in) :: last

      type (__deque_iterator__) :: iter
   end function __MANGLE(new_deque_range)


   function __MANGLE(new_deque_copy)(x) result(v)
      type (__deque) :: v
      type (__deque) :: x

      integer(kind=GFTL_SIZE_KIND) :: i
   end function __MANGLE(new_deque_copy)


   ! =======================
   !  size
   ! =======================
   pure function __MANGLE(size)(this) result(res)
      class(__deque), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND) :: res
   end function __MANGLE(size)

   ! =======================
   !  max_size()
   ! =======================
   pure function __MANGLE(max_size)() result(res)
      integer(kind=GFTL_SIZE_KIND) :: res

      integer(kind=GFTL_SIZE_KIND) :: index
   end function __MANGLE(max_size)

   ! =======================
   !  capacity - size of internal arrays; >= size()
   ! =======================
   pure function __MANGLE(capacity)(this) result(capacity)
      integer(kind=GFTL_SIZE_KIND) :: capacity
      class (__deque), intent(in) :: this
   end function __MANGLE(capacity)


   ! =======================
   !  empty() - is container empty?
   ! =======================
   pure logical function __MANGLE(empty)(this) result(empty)
      class(__deque), intent(in) :: this
   end function __MANGLE(empty)


   ! Hopefully this is inlined
   function __MANGLE(idx)(this, i) result(idx)
      integer(kind=GFTL_SIZE_KIND) :: idx
      class(__deque), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND) :: i
   end function __MANGLE(idx)


   ! =======================
   !  at() - return ith element with bounds check
   ! =======================
   function __MANGLE(at_size_kind)(this, i, rc) result(res)
      class(__deque), target, intent(in) :: this
      integer(KIND=GFTL_SIZE_KIND), intent(in) :: i
      integer, intent(out) :: rc
      __T_declare_result__, pointer :: res
   end function __MANGLE(at_size_kind)


   function __MANGLE(at_default)(this, i, rc) result(res)
      class(__deque), target, intent(in) :: this
      integer, intent(in) :: i
      __T_declare_result__, pointer :: res
      integer, intent(out) :: rc

      res => this%at(int(i,GFTL_SIZE_KIND),rc)

      return
   end function __MANGLE(at_default)


   ! =======================
   !  of - return ith element without bounds checks
   ! =======================
   function __MANGLE(of_size_kind)(this, i) result(res)
      class(__deque), target, intent(in) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: i
      __T_declare_result__, pointer :: res
   end function __MANGLE(of_size_kind)

   function __MANGLE(of_default)(this, i) result(res)
      class(__deque), target, intent(in) :: this
      integer, intent(in) :: i
      __T_declare_result__, pointer :: res
   end function __MANGLE(of_default)


   ! =======================
   !  back() - last element; undefined behavior for empty container
   ! =======================
   function __MANGLE(back)(this) result(res)
      class(__deque), target, intent(in) :: this
      __T_declare_result__, pointer :: res
   end function __MANGLE(back)

   ! =======================
   !  front() ! first element; undefined behavior for empty container
   ! =======================
   function __MANGLE(front)(this) result(res)
      class(__deque), target, intent(in) :: this
      __T_declare_result__, pointer :: res
   end function __MANGLE(front)


   ! =======================
   !  set() - modify contents of existing item with 
   ! =======================
   subroutine __MANGLE(set_size_kind)(this, i, value)
      class(__deque), intent(inout) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: i
      __T_declare_dummy__, intent(in) :: value

      integer(kind=GFTL_SIZE_KIND) :: ii
   end subroutine __MANGLE(set_size_kind)


   subroutine __MANGLE(set_default)(this, i, value)
      class(__deque), intent(inout) :: this
      integer, intent(in) :: i
      __T_declare_dummy__, intent(in) :: value
   end subroutine __MANGLE(set_default)

   ! =======================
   !  reset()
   ! =======================
   subroutine __MANGLE(reset)(this)
      class(__deque), intent(inout) :: this
   end subroutine __MANGLE(reset)


#if defined(__T_EQ__) || defined(__T_LT__)
   ! =======================
   !  equal
   ! =======================
   impure elemental function __MANGLE(equal)(lhs, rhs) result(equal)
      logical :: equal
      type(__deque), intent(in) :: lhs
      type(__deque), intent(in) :: rhs

      integer(kind=GFTL_SIZE_KIND) :: i, ii
   end function __MANGLE(equal)

   ! =======================
   !  not_equal
   ! =======================
   impure elemental function __MANGLE(not_equal)(lhs, rhs) result (not_equal)
      logical :: not_equal
      type(__deque), intent(in) :: lhs
      type(__deque), intent(in) :: rhs
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
   end function __MANGLE(less_than)

   impure elemental function __MANGLE(greater_than_or_equal_to)(lhs, rhs) &
        & result(greater_than_or_equal_to)
      logical :: greater_than_or_equal_to
      type (__deque), intent(in) :: lhs
      type (__deque), intent(in) :: rhs
   end function __MANGLE(greater_than_or_equal_to)


   impure elemental function __MANGLE(greater_than)(lhs, rhs) result(greater_than)
      logical :: greater_than
      type (__deque), intent(in) :: lhs
      type (__deque), intent(in) :: rhs
   end function __MANGLE(greater_than)


   impure elemental function __MANGLE(less_than_or_equal_to)(lhs, rhs) &
        &  result(less_than_or_equal_to)
      logical :: less_than_or_equal_to
      type (__deque), intent(in) :: lhs
      type (__deque), intent(in) :: rhs
   end function __MANGLE(less_than_or_equal_to)


#endif



   ! =======================
   !  push_back()
   ! =======================
   subroutine __MANGLE(push_back)(this, value, unused, rc)
      class(__deque), intent(inout) :: this
      __T_declare_dummy__, intent(in) :: value
      type (KeywordEnforcer), optional, intent(in) :: unused
      integer, optional, intent(out) :: rc
   end subroutine __MANGLE(push_back)


   ! =======================
   !  pop_back()
   ! =======================
   subroutine __MANGLE(pop_back)(this)
      class(__deque), intent(inout) :: this

      integer(kind=GFTL_SIZE_KIND) :: old_back
   end subroutine __MANGLE(pop_back)


   ! =======================
   !  push_front()
   ! =======================
   subroutine __MANGLE(push_front)(this, value, unused, rc)
      class(__deque), intent(inout) :: this
      __T_declare_dummy__, intent(in) :: value
      type (KeywordEnforcer), optional, intent(in) :: unused
      integer, optional, intent(out) :: rc
   end subroutine __MANGLE(push_front)


   ! =======================
   !  pop_front()
   ! =======================
   subroutine __MANGLE(pop_front)(this)
      class(__deque), intent(inout) :: this

      integer(kind=GFTL_SIZE_KIND) :: old_front
   end subroutine __MANGLE(pop_front)



   ! =======================
   !  resize()
   ! =======================
   subroutine __MANGLE(resize_size_kind)(this, count, unused, value, rc)
      class(__deque), intent(inout) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: count
      type (KeywordEnforcer), optional, intent(in) :: unused
      __T_declare_dummy__, optional, intent(in) :: value
      integer, optional, intent(out) :: rc

      integer(kind=GFTL_SIZE_KIND) :: old_size
      integer :: status
#if defined(__T_FREE__)
      integer(kind=GFTL_SIZE_KIND) :: i, ii
#endif
   end subroutine __MANGLE(resize_size_kind)

   subroutine __MANGLE(resize_default)(this, count, unused, value, rc)
      class(__deque), intent(inout) :: this
      integer, intent(in) :: count
      type (KeywordEnforcer), optional, intent(in) :: unused
      __T_declare_dummy__, optional, intent(in) :: value
      integer, optional, intent(out) :: rc
   end subroutine __MANGLE(resize_default)


   ! =======================
   !  downsize()
   ! =======================
   subroutine __MANGLE(downsize)(this, from, to)
      class(__deque), intent(inout) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: from, to  ! assumes newsize<=size()

   end subroutine __MANGLE(downsize)


   ! =======================
   !  clear
   ! =======================
   subroutine __MANGLE(clear)(this)
      class(__deque), intent(inout) :: this

      !call this%downsize(this%front_, this%back_)
      !this%front_ = -1
      !this%back_ = 0

      !return
   end subroutine __MANGLE(clear)


   ! =======================
   !  shrink_to_fit
   ! =======================

   subroutine __MANGLE(shrink_to_fit)(this)
      class(__deque), intent(inout) :: this
   end subroutine __MANGLE(shrink_to_fit)


   ! =======================
   !  erase_one
   ! =======================
   function __MANGLE(erase_one)(this, position) result(new_iter)
      type(__deque_iterator__), target :: new_iter
      class(__deque), target, intent(inout) :: this
      type (__deque_iterator__), intent(in)  :: position
   end function __MANGLE(erase_one)


   ! =======================
   !  erase_range
   ! =======================
   function __MANGLE(erase_range)(this, first, last) result(new_iter)
      type(__deque_iterator__), target :: new_iter
      class(__deque), target, intent(inout) :: this
      type (__deque_iterator__), intent(in)  :: first
      type (__deque_iterator__), intent(in)  :: last

      integer(kind=GFTL_SIZE_KIND) :: i, ii, delta
   end function __MANGLE(erase_range)

   ! =======================
   !  reserve()
   ! =======================
   subroutine __MANGLE(reserve_size_kind)(this, capacity, unused, rc)
      class(__deque), intent(inout) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: capacity
      class(KeywordEnforcer), optional, intent(in) :: unused
      integer, optional, intent(out) :: rc
   end subroutine __MANGLE(reserve_size_kind)

   subroutine __MANGLE(reserve_default)(this, capacity, unused, rc)
      class(__deque), intent(inout) :: this
      integer, intent(in) :: capacity
      class(KeywordEnforcer), optional, intent(in) :: unused
      integer, optional, intent(out) :: rc
   end subroutine __MANGLE(reserve_default)


   ! =======================
   !  set_capacity()
   ! =======================
   subroutine __MANGLE(set_capacity)(this, capacity)
      class(__deque), target, intent(inout) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: capacity  ! capacity must be >=0
      type(__MANGLE(bucket_ptr)), dimension(:), allocatable :: temp

      integer(kind=GFTL_SIZE_KIND) :: i, ii
      integer(kind=GFTL_SIZE_KIND) :: old_capacity
   end subroutine __MANGLE(set_capacity)

   ! =======================
   !  grow_to()
   ! =======================
   subroutine __MANGLE(grow_to)(this, capacity)
      class(__deque), intent(inout) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: capacity
   end subroutine __MANGLE(grow_to)

   ! =======================
   !  swap
   ! =======================
   subroutine __MANGLE(swap)(this, x)
      class(__deque), target, intent(inout) :: this
      type(__deque), target, intent(inout) :: x

      type(__MANGLE(bucket_ptr)), dimension(:), allocatable :: tmp
      integer(kind=GFTL_SIZE_KIND) :: i_tmp
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
         return
      end function __MANGLE(get_index)
#endif      


   ! =======================
   !  begin() - create an iterator
   ! =======================
   function __MANGLE(begin)(this) result(iter)
      type (__deque_iterator__) :: iter
      class (__deque), target, intent(in) :: this
   end function __MANGLE(begin)


   ! =======================
   !  end()
   !  Construct  forward iterator, initially set to just
   !  after last element of deque.
   ! =======================
   function __MANGLE(end)(this) result(iter)
      class (__deque), target, intent(in) :: this
      type (__deque_iterator__) :: iter
   end function __MANGLE(end)


   ! =======================
   !  rbegin() - create a reverse iterator
   ! =======================
   function __MANGLE(rbegin)(this) result(iter)
      type (__deque_riterator__) :: iter
      class (__deque), target, intent(in) :: this
   end function __MANGLE(rbegin)


   ! =======================
   !  rend()
   !  Construct  reverse iterator, initially set to just
   !  before first element of deque
   ! =======================
   function __MANGLE(rend)(this) result(iter)
      class (__deque), target, intent(in) :: this
      type (__deque_riterator__) :: iter
   end function __MANGLE(rend)


   subroutine __MANGLE(write_formatted)(this, unit, iotype, v_list, iostat, iomsg)
    class(__deque), intent(in) :: this
    integer, intent(in) :: unit
    character(*), intent(in) :: iotype
    integer, intent(in) :: v_list(:)
    integer, intent(out) :: iostat
    character(*), intent(inout) :: iomsg
   end subroutine __MANGLE(write_formatted)


   function __MANGLE(bucket_index)(this, i) result(bucket_index)
      integer(kind=GFTL_SIZE_KIND) :: bucket_index
      class(__deque), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: i
   end function __MANGLE(bucket_index)

   function __MANGLE(bucket_offset)(this, i) result(bucket_offset)
      integer(kind=GFTL_SIZE_KIND) :: bucket_offset
      class(__deque), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: i
   end function __MANGLE(bucket_offset)

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


