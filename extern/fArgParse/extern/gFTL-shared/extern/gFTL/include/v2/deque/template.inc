
#ifndef __gftl_common

#    define __gftl_common

! Per-container name mangling   
#    define __IDENTITY(x) x
#    define __COMMA(x) , x
#    define __MANGLE(proc) __IDENTITY(__guard)__IDENTITY(proc)

! Fortran portability support
#    ifdef  gftl_size_kind
#        define __gftl_size_kind gftl_size_kind
#    else
!        Note: F2018 guarantees that there is at least one integer
!        kind that supports 18 digits.  For all extant compilers (July
!        2020), this will be different than default integer
#        define __gftl_size_kind selected_int_kind(18)
#    endif
#    ifdef gftl_disable_index_kind_overload
#        define __gftl_disable_index_kind_overload
#    endif


! Predefined intrinsic types

! Note: Fortran preprocessors do not consistently intrepret octal
! constants, so we have to do some careful arithmetic in base 10
! instead of the more elegant approach possible in C.

   
#define __INTEGER__               2
#define __REAL__                  3
#define __UNLIMITED_POLYMORPHIC__ 7

#define __UNLIMITED_POLYMORPHIC 56

   implicit none
#    define __UNUSED_DUMMY(x) if (.false.) print*,shape(x)

   integer, parameter :: GFTL_SIZE_KIND = __gftl_size_kind
#endif





#include "parameters/T/copy_T_to_deque_T.inc"

#define __deque Deque
#define __deque_guard deque_

#define __guard __deque_guard
type :: __deque
contains
   procedure :: at_default => __MANGLE(at_default)
   procedure :: of_default => __MANGLE(of_default)
   generic :: at => at_default
   generic :: at => of_default

   procedure :: at_size_kind => __MANGLE(at_size_kind)
   generic :: at => at_size_kind
end type __deque

#undef __guard
   contains

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
