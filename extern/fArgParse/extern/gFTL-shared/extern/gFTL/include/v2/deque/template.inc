
#include "deque/header.inc"

   private
   public :: __deque
   public :: __deque_iterator
   !public :: __deque_riterator

   ! Iterator functions
   public :: advance
   public :: distance
   public :: operator(+)
   public :: operator(-)


   ! Iterator and possibly container functions:
   ! The following are always defined for the iterator.
   ! May not also be defined for the container itself depending
   ! on properties of parameter T.

   public :: operator(==)
   public :: operator(/=)

   public :: operator(<)
   public :: operator(>)
   public :: operator(<=)
   public :: operator(>=)


#include "deque/specification.inc"

   contains

#include "deque/procedures.inc"
