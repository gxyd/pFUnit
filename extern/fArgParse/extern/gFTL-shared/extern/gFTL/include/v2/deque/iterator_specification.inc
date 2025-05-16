   type __deque_iterator__
      private
      type(__deque), pointer :: deque
      integer(kind=__gftl_size_kind) :: current_index = -1 ! intentionally invalid value
   contains

   end type __deque_iterator__
