!--------------------------------------------------------------------
! Copyright © 2020 United States Government as represented by the   |
! Administrator of the National Aeronautics and Space               |
! Administration. No copyright is claimed in the United States      |
! under Title 17, U.S. Code. All Other Rights Reserved.             |
!                                                                   |
! Licensed under the Apache License, Version 2.0.                   |
!--------------------------------------------------------------------

   type __deque_iterator__
      private

      type(__deque), pointer :: deque
      integer(kind=__gftl_size_kind) :: current_index = -1 ! intentionally invalid value

   contains

   end type __deque_iterator__


   ! Non type-bound functions

   ! Relational operators
   interface operator(==)
      module procedure __MANGLE(iter_equal)
   end interface operator(==)

   interface operator(/=)
      module procedure __MANGLE(iter_not_equal)
   end interface operator(/=)

!   interface next
!      ! Cannot use optional dummy due to otherwise ambiguous interfaces
!      module procedure __MANGLE(iter_next_1)
!#ifndef  __gftl_disable_index_kind_overload
!      module procedure __MANGLE(iter_next_n_size_kind)
!#endif
!      module procedure __MANGLE(iter_next_n_default)
!   end interface next

!   interface prev
!      module procedure __MANGLE(iter_prev_1)
!#ifndef __gftl_disable_index_kind_overload
!      module procedure __MANGLE(iter_prev_n_size_kind)
!#endif
!      module procedure __MANGLE(iter_prev_n_default)
!   end interface prev
