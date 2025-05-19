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
