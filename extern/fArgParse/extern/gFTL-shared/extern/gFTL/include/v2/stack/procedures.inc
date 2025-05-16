#include "parameters/T/copy_stack_T_to_deque_T.inc"

#define __deque __stack_container_type
#define __deque_guard __IDENTITY(__stack_guard)__IDENTITY(d_)
   
#include "deque/procedures.inc"

#undef __deque
#undef __deque_guard


#include "parameters/T/copy_stack_T_to_internal_T.inc"
#define __guard __stack_guard

#include "parameters/T/define_derived_macros.inc"



   function __MANGLE(new_stack_empty)() result(q)
      type (__stack) :: q
      logical, parameter :: flag = .false.


   end function __MANGLE(new_stack_empty)

   function __MANGLE(new_stack_container)(container) result(q)
      type (__stack) :: q
      type(__stack_container_type), intent(in) :: container


   end function __MANGLE(new_stack_container)



   function __MANGLE(new_stack_copy)(x) result(q)
      type (__stack) :: q
      type (__stack) :: x

      integer(kind=GFTL_SIZE_KIND) :: i

   end function __MANGLE(new_stack_copy)



   pure function __MANGLE(size)(this) result(res)
      class(__stack), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND) :: res


   end function __MANGLE(size)

   
   
   pure logical function __MANGLE(empty)(this) result(empty)
      class(__stack), intent(in) :: this


   end function __MANGLE(empty)

   
   function __MANGLE(top)(this) result(res)
      class(__stack), target, intent(in) :: this
      __T_declare_result__, pointer :: res


      return
   end function __MANGLE(top)


   subroutine __MANGLE(push)(this, value, unused, rc)
      class(__stack), intent(inout) :: this
      __T_declare_dummy__, intent(in) :: value
      type (KeywordEnforcer), optional, intent(in) :: unused
      integer, optional, intent(out) :: rc




   end subroutine __MANGLE(push)


   subroutine __MANGLE(pop)(this)
      class(__stack), intent(inout) :: this


   end subroutine __MANGLE(pop)


#if defined(__T_EQ__) || defined(__T_LT__)
   impure elemental function __MANGLE(equal)(lhs, rhs) result(equal)
      logical :: equal
      type(__stack), intent(in) :: lhs
      type(__stack), intent(in) :: rhs



      return
   end function __MANGLE(equal)

   impure elemental function __MANGLE(not_equal)(lhs, rhs) result (not_equal)
      logical :: not_equal
      type(__stack), intent(in) :: lhs
      type(__stack), intent(in) :: rhs
   end function __MANGLE(not_equal)

#endif




#ifdef __T_LT__
   impure elemental function __MANGLE(less_than)(lhs, rhs) result(less_than)
      logical :: less_than
      type (__stack), intent(in) :: lhs
      type (__stack), intent(in) :: rhs
   end function __MANGLE(less_than)

   impure elemental function __MANGLE(greater_than_or_equal_to)(lhs, rhs) &
        & result(greater_than_or_equal_to)
      logical :: greater_than_or_equal_to
      type (__stack), intent(in) :: lhs
      type (__stack), intent(in) :: rhs
   end function __MANGLE(greater_than_or_equal_to)


   impure elemental function __MANGLE(greater_than)(lhs, rhs) result(greater_than)
      logical :: greater_than
      type (__stack), intent(in) :: lhs
      type (__stack), intent(in) :: rhs
   end function __MANGLE(greater_than)


   impure elemental function __MANGLE(less_than_or_equal_to)(lhs, rhs) &
        &  result(less_than_or_equal_to)
      logical :: less_than_or_equal_to
      type (__stack), intent(in) :: lhs
      type (__stack), intent(in) :: rhs
   end function __MANGLE(less_than_or_equal_to)


#endif


   subroutine __MANGLE(swap)(this, x)
      class(__stack), target, intent(inout) :: this
      type(__stack), target, intent(inout) :: x
   end subroutine __MANGLE(swap)

   
   subroutine __MANGLE(write_formatted)(this, unit, iotype, v_list, iostat, iomsg)
    class(__stack), intent(in) :: this
    integer, intent(in) :: unit
    character(*), intent(in) :: iotype
    integer, intent(in) :: v_list(:)
    integer, intent(out) :: iostat
    character(*), intent(inout) :: iomsg
   end subroutine __MANGLE(write_formatted)


#include "parameters/T/undef_derived_macros.inc"

#undef __guard
#include "parameters/T/undef_internal.inc"

