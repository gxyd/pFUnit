#define __guard __deque_guard

#define __deque_iterator__ DequeIterator

#define __deque_riterator__ DequeRIterator

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

! undef internal template parameters
#undef __guard
