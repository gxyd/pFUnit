#include "parameters/T/copy_deque_T_to_internal_T.inc"
#define __guard __deque_guard

#include "parameters/T/define_derived_macros.inc"

type :: __deque
contains
   procedure :: at_default => __MANGLE(at_default)
   procedure :: of_default => __MANGLE(of_default)
   generic :: at => at_default
   generic :: at => of_default

   procedure :: at_size_kind => __MANGLE(at_size_kind)
   generic :: at => at_size_kind
end type __deque

#include "parameters/T/undef_derived_macros.inc"

#undef __guard
#include "parameters/T/undef_internal.inc"
