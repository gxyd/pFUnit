
      subroutine __MANGLE(iter_next)(this)
         class (__deque_iterator__), intent(inout) :: this

      end subroutine __MANGLE(iter_next)


      subroutine __MANGLE(iter_prev)(this)
         class (__deque_iterator__), intent(inout) :: this


      end subroutine __MANGLE(iter_prev)


      function __MANGLE(iter_of)(this) result(ptr)
         __T_declare_result__, pointer :: ptr
         class (__deque_iterator__), intent(in) :: this


      end function __MANGLE(iter_of)


      function __MANGLE(iter_of_offset_size_kind)(this, i) result(ptr)
         __T_declare_result__, pointer :: ptr
         class (__deque_iterator__), intent(in) :: this
         integer(kind=__gftl_size_kind), intent(in) :: i


      end function __MANGLE(iter_of_offset_size_kind)

      function __MANGLE(iter_of_offset_default)(this, i) result(ptr)
         __T_declare_result__, pointer :: ptr
         class (__deque_iterator__), intent(in) :: this
         integer, intent(in) :: i


      end function __MANGLE(iter_of_offset_default)


      subroutine __MANGLE(iter_add_n_size_kind)(this, n)
         class(__deque_iterator__), intent(inout) :: this
         integer(kind=__gftl_size_kind), intent(in) :: n
         return
      end subroutine __MANGLE(iter_add_n_size_kind)

      subroutine __MANGLE(iter_add_n_default)(this, n)
         class(__deque_iterator__), intent(inout) :: this
         integer, intent(in) :: n
         return
      end subroutine __MANGLE(iter_add_n_default)

      subroutine __MANGLE(iter_sub_n_size_kind)(this, n)
         class(__deque_iterator__), intent(inout) :: this
         integer(kind=__gftl_size_kind), intent(in) :: n
         return
      end subroutine __MANGLE(iter_sub_n_size_kind)

      subroutine __MANGLE(iter_sub_n_default)(this, n)
         class(__deque_iterator__), intent(inout) :: this
         integer, intent(in) :: n
         return
      end subroutine __MANGLE(iter_sub_n_default)



      function __MANGLE(iter_a_plus_n_size_kind)(a, n) result(new_iter)
         type (__deque_iterator__) :: new_iter
         type(__deque_iterator__), intent(in) :: a
         integer(kind=__gftl_size_kind), intent(in) :: n


      end function __MANGLE(iter_a_plus_n_size_kind)

      function __MANGLE(iter_n_plus_a_size_kind)(n, a) result(new_iter)
         type (__deque_iterator__) :: new_iter
         integer(kind=__gftl_size_kind), intent(in) :: n
         type(__deque_iterator__), intent(in) :: a


      end function __MANGLE(iter_n_plus_a_size_kind)

      function __MANGLE(iter_a_minus_n_size_kind)(a, n) result(new_iter)
         type (__deque_iterator__) :: new_iter
         type (__deque_iterator__), intent(in) :: a
         integer(kind=__gftl_size_kind), intent(in) :: n


      end function __MANGLE(iter_a_minus_n_size_kind)

      function __MANGLE(iter_a_plus_n_default)(a, n) result(new_iter)
         type (__deque_iterator__) :: new_iter
         type (__deque_iterator__), intent(in) :: a
         integer, intent(in) :: n


      end function __MANGLE(iter_a_plus_n_default)

      function __MANGLE(iter_n_plus_a_default)(n, a) result(new_iter)
         type (__deque_iterator__) :: new_iter
         integer, intent(in) :: n
         type (__deque_iterator__), intent(in) :: a


      end function __MANGLE(iter_n_plus_a_default)

      function __MANGLE(iter_a_minus_n_default)(a, n) result(new_iter)
         type (__deque_iterator__) :: new_iter
         type (__deque_iterator__), intent(in) :: a
         integer, intent(in) :: n


      end function __MANGLE(iter_a_minus_n_default)

      function __MANGLE(iter_a_minus_b)(a, b) result(n)
         integer(kind=__gftl_size_kind) :: n
         type(__deque_iterator__), intent(in) :: a
         type(__deque_iterator__), intent(in) :: b

      end function __MANGLE(iter_a_minus_b)


      logical function __MANGLE(iter_equal)(a, b) result(eq)
         type(__deque_iterator__), intent(in) :: a
         type(__deque_iterator__), intent(in) :: b


      end function __MANGLE(iter_equal)


      logical function __MANGLE(iter_not_equal)(a, b) result(ne)
         type(__deque_iterator__), intent(in) :: a
         type(__deque_iterator__), intent(in) :: b


      end function __MANGLE(iter_not_equal)

      logical function __MANGLE(iter_less)(a, b) result(less)
         type(__deque_iterator__), intent(in) :: a
         type(__deque_iterator__), intent(in) :: b
      end function __MANGLE(iter_less)


      function __MANGLE(iter_less_equal)(a,b) result(le)
         logical :: le
         type(__deque_iterator__), intent(in) :: a
         type(__deque_iterator__), intent(in) :: b
      end function __MANGLE(iter_less_equal)

      logical function __MANGLE(iter_greater)(a, b) result(gt)
         type(__deque_iterator__), intent(in) :: a
         type(__deque_iterator__), intent(in) :: b
      end function __MANGLE(iter_greater)

      function __MANGLE(iter_greater_equal)(a,b) result(ge)
         logical :: ge
         type(__deque_iterator__), intent(in) :: a
         type(__deque_iterator__), intent(in) :: b
      end function __MANGLE(iter_greater_equal)



      subroutine __MANGLE(iter_advance_size_kind)(it, n)
         type(__deque_iterator__), intent(inout) :: it
         integer(kind=__gftl_size_kind), intent(in) :: n


         return
      end subroutine __MANGLE(iter_advance_size_kind)

      subroutine __MANGLE(iter_advance_default)(it, n)
         type(__deque_iterator__), intent(inout) :: it
         integer, intent(in) :: n


         return
      end subroutine __MANGLE(iter_advance_default)


      function __MANGLE(iter_begin)(cont) result(begin)
         type(__deque_iterator__) :: begin
         type(__deque), target, intent(in) :: cont


         return
      end function __MANGLE(iter_begin)

      
      integer(kind=__gftl_size_kind) function __MANGLE(iter_distance)(a, b) result(distance)
         class(__deque_iterator__), intent(in) :: a
         type(__deque_iterator__), intent(in) :: b


         return
      end function __MANGLE(iter_distance)


      function __MANGLE(iter_end)(cont) result(end)
         type(__deque_iterator__) :: end
         type(__deque), target, intent(in) :: cont


         return
      end function __MANGLE(iter_end)


      function __MANGLE(iter_next_1)(it) result(new_it)
         type(__deque_iterator__) :: new_it
         type(__deque_iterator__), intent(in) :: it


         return
      end function __MANGLE(iter_next_1)

      function __MANGLE(iter_next_n_size_kind)(it, n) result(new_it)
         type(__deque_iterator__) :: new_it
         type(__deque_iterator__), intent(in) :: it
         integer(kind=__gftl_size_kind), intent(in) :: n


      end function __MANGLE(iter_next_n_size_kind)

      function __MANGLE(iter_next_n_default)(it, n) result(new_it)
         type(__deque_iterator__) :: new_it
         type(__deque_iterator__), intent(in) :: it
         integer, intent(in) :: n


      end function __MANGLE(iter_next_n_default)

      function __MANGLE(iter_prev_1)(it) result(new_it)
         type(__deque_iterator__) :: new_it
         type(__deque_iterator__), intent(in) :: it


      end function __MANGLE(iter_prev_1)

      function __MANGLE(iter_prev_n_size_kind)(it, n) result(new_it)
         type(__deque_iterator__) :: new_it
         type(__deque_iterator__), intent(in) :: it
         integer(kind=__gftl_size_kind), intent(in) :: n


      end function __MANGLE(iter_prev_n_size_kind)

      function __MANGLE(iter_prev_n_default)(it, n) result(new_it)
         type(__deque_iterator__) :: new_it
         type(__deque_iterator__), intent(in) :: it
         integer, intent(in) :: n


      end function __MANGLE(iter_prev_n_default)


