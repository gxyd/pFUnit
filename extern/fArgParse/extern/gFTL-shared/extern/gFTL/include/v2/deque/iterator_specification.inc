!--------------------------------------------------------------------
! Copyright © 2020 United States Government as represented by the   |
! Administrator of the National Aeronautics and Space               |
! Administration. No copyright is claimed in the United States      |
! under Title 17, U.S. Code. All Other Rights Reserved.             |
!                                                                   |
! Licensed under the Apache License, Version 2.0.                   |
!--------------------------------------------------------------------

!   type __deque_iterator__
!      private
!
!      type(__deque), pointer :: deque
!      integer(kind=__gftl_size_kind) :: current_index = -1 ! intentionally invalid value
!
!   contains
!
!   end type __deque_iterator__
!
!
!   ! Non type-bound functions
!
!   ! Relational operators
!   interface operator(==)
!      module procedure __MANGLE(iter_equal)
!   end interface operator(==)
!
!   interface operator(/=)
!      module procedure __MANGLE(iter_not_equal)
!   end interface operator(/=)
