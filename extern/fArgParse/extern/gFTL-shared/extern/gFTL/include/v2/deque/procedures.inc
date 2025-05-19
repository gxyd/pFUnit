

#include "parameters/T/copy_deque_T_to_internal_T.inc"
#define __guard __deque_guard

#include "parameters/T/define_derived_macros.inc"

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

   function __MANGLE(of_default)(this, i) result(res)
      class(__deque), target, intent(in) :: this
      integer, intent(in) :: i
      __T_declare_result__, pointer :: res
   end function __MANGLE(of_default)

#include "parameters/T/undef_derived_macros.inc"

#undef __guard
#include "parameters/T/undef_internal.inc"
