#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename U>

void iter(T *array, int length, void (*f)(U &))
{
  if (f != NULL)
 {
  for (int i = 0; i < length; i++)
  {
	  f(array[i]);
  }
}
}

#endif
