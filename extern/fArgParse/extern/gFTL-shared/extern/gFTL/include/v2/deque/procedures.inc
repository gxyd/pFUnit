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


   !subroutine __MANGLE(unused_procedure)()
   !   ! The following are an adhoc way to suppress compiler
   !   ! warnings about parameters not used in this template
   !   __UNUSED_DUMMY(BAD_ALLOC)
   !   __UNUSED_DUMMY(TYPE_HAS_NO_DEFAULT_VALUE)
   !   __UNUSED_DUMMY(NO_TYPE__)
   !end subroutine __MANGLE(unused_procedure)


   function __MANGLE(new_deque_range)(first, last) result(v)
      type (__deque) :: v
      type (__deque_iterator__), intent(in) :: first
      type (__deque_iterator__), intent(in) :: last

      type (__deque_iterator__) :: iter

      iter = first
      do while (iter /= last)
         call v%push_back(iter%of())
      end do

      return
   end function __MANGLE(new_deque_range)


   !function __MANGLE(at_default)(this, i, rc) result(res)
   !   class(__deque), target, intent(in) :: this
   !   integer, intent(in) :: i
   !   __T_declare_result__, pointer :: res
   !   integer, intent(out) :: rc

   !   !res => this%at(int(i,GFTL_SIZE_KIND),rc)

   !   return
   !end function __MANGLE(at_default)


   !function __MANGLE(of_default)(this, i) result(res)
   !   class(__deque), target, intent(in) :: this
   !   integer, intent(in) :: i
   !   __T_declare_result__, pointer :: res

   !   !res => this%at(int(i,GFTL_SIZE_KIND))

   !   return
   !end function __MANGLE(of_default)


   function __MANGLE(back)(this) result(res)
      class(__deque), target, intent(in) :: this
      __T_declare_result__, pointer :: res

      res => this%buckets(this%back_)%ptr%bucket_items%item

      return
   end function __MANGLE(back)


   !function __MANGLE(front)(this) result(res)
   !   class(__deque), target, intent(in) :: this
   !   __T_declare_result__, pointer :: res

   !   res => this%buckets(this%front_)%ptr%bucket_items%item

   !   return
   !end function __MANGLE(front)

   subroutine __MANGLE(reset)(this)
      class(__deque), intent(inout) :: this

      !if (allocated(this%buckets)) then
      !   deallocate(this%buckets)
      !end if
      !this%front_ = -1
      !this%back_ = 0

      !return
   end subroutine __MANGLE(reset)


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

      !greater_than_or_equal_to = .not. (lhs < rhs)

      return
   end function __MANGLE(greater_than_or_equal_to)


   impure elemental function __MANGLE(greater_than)(lhs, rhs) result(greater_than)
      logical :: greater_than
      type (__deque), intent(in) :: lhs
      type (__deque), intent(in) :: rhs

      !greater_than = (rhs < lhs)

      return
   end function __MANGLE(greater_than)


   impure elemental function __MANGLE(less_than_or_equal_to)(lhs, rhs) &
        &  result(less_than_or_equal_to)
      logical :: less_than_or_equal_to
      type (__deque), intent(in) :: lhs
      type (__deque), intent(in) :: rhs

      !less_than_or_equal_to = .not. (rhs < lhs)

      return
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

      __UNUSED_DUMMY(unused)

   end subroutine __MANGLE(push_back)


   ! =======================
   !  pop_back()
   ! =======================
   subroutine __MANGLE(pop_back)(this)
      class(__deque), intent(inout) :: this

      integer(kind=GFTL_SIZE_KIND) :: old_back

      old_back = this%back_

      return
   end subroutine __MANGLE(pop_back)


   !subroutine __MANGLE(resize_default)(this, count, unused, value, rc)
   !   class(__deque), intent(inout) :: this
   !   integer, intent(in) :: count
   !   type (KeywordEnforcer), optional, intent(in) :: unused
   !   __T_declare_dummy__, optional, intent(in) :: value
   !   integer, optional, intent(out) :: rc

   !   __UNUSED_DUMMY(unused)

   !   !call this%resize(int(count,kind=GFTL_SIZE_KIND), value=value, rc=rc)

   !end subroutine __MANGLE(resize_default)


   ! =======================
   !  downsize()
   ! =======================
   !subroutine __MANGLE(downsize)(this, from, to)
   !   class(__deque), intent(inout) :: this
   !   integer(kind=GFTL_SIZE_KIND), intent(in) :: from, to  ! assumes newsize<=size()

   !end subroutine __MANGLE(downsize)


   ! =======================
   !  clear
   ! =======================
   subroutine __MANGLE(clear)(this)
      class(__deque), intent(inout) :: this

      this%front_ = -1
      this%back_ = 0

      return
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

      return
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

      !iter%current_index = this%size() + 1 ! past the end
      !iter%deque => this

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


   subroutine __MANGLE(write_formatted)(this, unit, iotype, v_list, iostat, iomsg)
    class(__deque), intent(in) :: this
    integer, intent(in) :: unit
    character(*), intent(in) :: iotype
    integer, intent(in) :: v_list(:)
    integer, intent(out) :: iostat
    character(*), intent(inout) :: iomsg

    iostat = 0

#ifdef __T_name__
    write(unit,'(a)') 'Deque<' // __T_declare_string__ // '>'
#else
    write(unit,'(a)') 'Deque<' // 'unknown' // '>'
#endif
    write(unit,'(a)') new_line('a')
    !write(unit,'(4x,a10,1x,i0)') 'size: ',this%size()

    __UNUSED_DUMMY(iomsg)
    __UNUSED_DUMMY(iotype)
    __UNUSED_DUMMY(v_list)
   end subroutine __MANGLE(write_formatted)


   function __MANGLE(bucket_index)(this, i) result(bucket_index)
      integer(kind=GFTL_SIZE_KIND) :: bucket_index
      class(__deque), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: i

      bucket_index = 1 + (i-1)/__deque_bucket_size__

      __UNUSED_DUMMY(this)
   end function __MANGLE(bucket_index)

   function __MANGLE(bucket_offset)(this, i) result(bucket_offset)
      integer(kind=GFTL_SIZE_KIND) :: bucket_offset
      class(__deque), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND), intent(in) :: i

      bucket_offset = 1 + modulo(i-1, int(__deque_bucket_size__,kind=GFTL_SIZE_KIND))

      __UNUSED_DUMMY(this)
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


