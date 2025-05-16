#include "parameters/T/copy_queue_T_to_deque_T.inc"

#define __deque __queue_container_type
#define __deque_guard __IDENTITY(__queue_guard)__IDENTITY(d_)
   
#include "deque/procedures.inc"

#undef __deque
#undef __deque_guard


#include "parameters/T/copy_queue_T_to_internal_T.inc"
#define __guard __queue_guard

#include "parameters/T/define_derived_macros.inc"



   function __MANGLE(new_queue_empty)() result(q)
      type (__queue) :: q
      logical, parameter :: flag = .false.


      return
   end function __MANGLE(new_queue_empty)

   function __MANGLE(new_queue_container)(container) result(q)
      type (__queue) :: q
      type(__queue_container_type), intent(in) :: container


   end function __MANGLE(new_queue_container)



   function __MANGLE(new_queue_copy)(x) result(q)
      type (__queue) :: q
      type (__queue) :: x

      integer(kind=GFTL_SIZE_KIND) :: i

   end function __MANGLE(new_queue_copy)



   pure function __MANGLE(size)(this) result(res)
      class(__queue), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND) :: res


   end function __MANGLE(size)

   
   
   pure logical function __MANGLE(empty)(this) result(empty)
      class(__queue), intent(in) :: this


   end function __MANGLE(empty)

   
   function __MANGLE(back)(this) result(res)
      class(__queue), target, intent(in) :: this
      __T_declare_result__, pointer :: res


   end function __MANGLE(back)

   function __MANGLE(front)(this) result(res)
      class(__queue), target, intent(in) :: this
      __T_declare_result__, pointer :: res


   end function __MANGLE(front)

   subroutine __MANGLE(push)(this, value, unused, rc)
      class(__queue), intent(inout) :: this
      __T_declare_dummy__, intent(in) :: value
      type (KeywordEnforcer), optional, intent(in) :: unused
      integer, optional, intent(out) :: rc




   end subroutine __MANGLE(push)


   subroutine __MANGLE(pop)(this)
      class(__queue), intent(inout) :: this


   end subroutine __MANGLE(pop)


#if defined(__T_EQ__) || defined(__T_LT__)
   impure elemental function __MANGLE(equal)(lhs, rhs) result(equal)
      logical :: equal
      type(__queue), intent(in) :: lhs
      type(__queue), intent(in) :: rhs



   end function __MANGLE(equal)

   impure elemental function __MANGLE(not_equal)(lhs, rhs) result (not_equal)
      logical :: not_equal
      type(__queue), intent(in) :: lhs
      type(__queue), intent(in) :: rhs


   end function __MANGLE(not_equal)

#endif




#ifdef __T_LT__
   impure elemental function __MANGLE(less_than)(lhs, rhs) result(less_than)
      logical :: less_than
      type (__queue), intent(in) :: lhs
      type (__queue), intent(in) :: rhs


   end function __MANGLE(less_than)

   impure elemental function __MANGLE(greater_than_or_equal_to)(lhs, rhs) &
        & result(greater_than_or_equal_to)
      logical :: greater_than_or_equal_to
      type (__queue), intent(in) :: lhs
      type (__queue), intent(in) :: rhs


   end function __MANGLE(greater_than_or_equal_to)


   impure elemental function __MANGLE(greater_than)(lhs, rhs) result(greater_than)
      logical :: greater_than
      type (__queue), intent(in) :: lhs
      type (__queue), intent(in) :: rhs


   end function __MANGLE(greater_than)


   impure elemental function __MANGLE(less_than_or_equal_to)(lhs, rhs) &
        &  result(less_than_or_equal_to)
      logical :: less_than_or_equal_to
      type (__queue), intent(in) :: lhs
      type (__queue), intent(in) :: rhs


   end function __MANGLE(less_than_or_equal_to)


#endif


   subroutine __MANGLE(swap)(this, x)
      class(__queue), target, intent(inout) :: this
      type(__queue), target, intent(inout) :: x


      
   end subroutine __MANGLE(swap)

   
   subroutine __MANGLE(write_formatted)(this, unit, iotype, v_list, iostat, iomsg)
    class(__queue), intent(in) :: this
    integer, intent(in) :: unit
    character(*), intent(in) :: iotype
    integer, intent(in) :: v_list(:)
    integer, intent(out) :: iostat
    character(*), intent(inout) :: iomsg

   end subroutine __MANGLE(write_formatted)


#include "parameters/T/undef_derived_macros.inc"

#undef __guard
#include "parameters/T/undef_internal.inc"

