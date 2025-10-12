xsimd_funcs
-----------

xsimd_funcs is a C++ library that implements an assortment of functions
that operate on 1-d arrays using the XSIMD library.

This code should be considered experimental and unstable.  Currently it
is my "sandbox" for experimenting with the XSIMD library.

The library defines the ``xsimd_funcs`` namespace.  The library includes
functions for:

* Determining whether all the values in the array are the same.
* Determining if the values in the array are in increasing order.
* Computing the sum of an array of floating point values using compensated
  arithmetic.
* Simultaneously computing the minimum and maximum of an array.
* Simultaneously computing the minimum and the index of the minimum.
* Computing the peak-to-peak value of an array.  The computed value for
  signed integer arrays is an unsigned integer with the same bitwidth as
  the array.
