

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

#include "parameters/T/define_derived_macros.inc"


   subroutine __MANGLE(unused_procedure)()
   end subroutine __MANGLE(unused_procedure)


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


   pure function __MANGLE(size)(this) result(res)
      class(__deque), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND) :: res
   end function __MANGLE(size)

   pure function __MANGLE(max_size)() result(res)
      integer(kind=GFTL_SIZE_KIND) :: res

      integer(kind=GFTL_SIZE_KIND) :: index
   end function __MANGLE(max_size)

   pure function __MANGLE(capacity)(this) result(capacity)
      integer(kind=GFTL_SIZE_KIND) :: capacity
      class (__deque), intent(in) :: this
   end function __MANGLE(capacity)


   pure logical function __MANGLE(empty)(this) result(empty)
      class(__deque), intent(in) :: this
   end function __MANGLE(empty)


   function __MANGLE(idx)(this, i) result(idx)
      integer(kind=GFTL_SIZE_KIND) :: idx
      class(__deque), intent(in) :: this
      integer(kind=GFTL_SIZE_KIND) :: i
   end function __MANGLE(idx)


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


   function __MANGLE(back)(this) result(res)
      class(__deque), target, intent(in) :: this
      __T_declare_result__, pointer :: res
   end function __MANGLE(back)

   function __MANGLE(front)(this) result(res)
      class(__deque), target, intent(in) :: this
      __T_declare_result__, pointer :: res
   end function __MANGLE(front)



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

#include "parameters/T/undef_derived_macros.inc"

#undef __guard
#include "parameters/T/undef_internal.inc"


