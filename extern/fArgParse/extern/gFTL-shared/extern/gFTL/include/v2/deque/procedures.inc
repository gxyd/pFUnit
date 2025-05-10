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

! define derived generic template parameters from internal parameters.
#include "parameters/T/define_derived_macros.inc"


   function __MANGLE(new_deque_range)(first, last) result(v)
      type (__deque) :: v
      type (__deque_iterator__), intent(in) :: first
      type (__deque_iterator__), intent(in) :: last

      type (__deque_iterator__) :: iter

      print *, iter /= last
      return
   end function __MANGLE(new_deque_range)

      ! Relational operators
      logical function __MANGLE(iter_equal)(a, b) result(eq)
         type(__deque_iterator__), intent(in) :: a
         type(__deque_iterator__), intent(in) :: b

         eq = (a%current_index == b%current_index)

      end function __MANGLE(iter_equal)

      logical function __MANGLE(iter_not_equal)(a, b) result(ne)
         type(__deque_iterator__), intent(in) :: a
         type(__deque_iterator__), intent(in) :: b

         ne = .not. (a == b)

      end function __MANGLE(iter_not_equal)

      logical function __MANGLE(riter_equal)(a, b) result(eq)
         type(__deque_riterator__), intent(in) :: a
         type(__deque_riterator__), intent(in) :: b

         eq = (a%current_index == b%current_index)

      end function __MANGLE(riter_equal)

      logical function __MANGLE(riter_not_equal)(a, b) result(ne)
         type(__deque_riterator__), intent(in) :: a
         type(__deque_riterator__), intent(in) :: b

         ne = .not. (a == b)

      end function __MANGLE(riter_not_equal)



#if defined(__deque_iterator__)
#    undef __deque_iterator__
#endif

#if defined(__deque_riterator__)
#    undef __deque_riterator__
#endif

! undef derived template parameters
#include "parameters/T/undef_derived_macros.inc"

! undef internal template parameters
#undef __guard
#include "parameters/T/undef_internal.inc"
