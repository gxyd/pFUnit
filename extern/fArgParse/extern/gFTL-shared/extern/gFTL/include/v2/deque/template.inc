
#define __IDENTITY(x) x
#define __MANGLE(proc) __IDENTITY(__guard)proc

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

#define __T T
#define __guard __deque_guard

!#define __T_kind__  1 << (__T & 07)
!
!#define __T_polymorphic__
!#define __T_type__ *
!#if !defined(__T_default__)
!#    define __T_default_scalar__ NO_TYPE__
!#endif


#define __T_declare_result__ class(*)
#undef tmp

   function __MANGLE(at_size_kind)(this, i, rc) result(res)
      class(__deque), target, intent(in) :: this
      integer(8), intent(in) :: i
      integer, intent(out) :: rc
      __T_declare_result__, pointer :: res
   end function __MANGLE(at_size_kind)

   function __MANGLE(at_default)(this, i, rc) result(res)
      class(__deque), target, intent(in) :: this
      integer, intent(in) :: i
      __T_declare_result__, pointer :: res
      integer, intent(out) :: rc

      res => this%at(int(i,8),rc)

      return
   end function __MANGLE(at_default)

   function __MANGLE(of_default)(this, i) result(res)
      class(__deque), target, intent(in) :: this
      integer, intent(in) :: i
      __T_declare_result__, pointer :: res
   end function __MANGLE(of_default)

#undef __guard
