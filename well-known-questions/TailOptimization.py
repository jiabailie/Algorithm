#!/usr/bin/env python3.3.2
# This program show off a python decorator
# which implements tail call optimization.
# It does this by throwing an exception if it is it's own grandparent,
# and catching such exceptions to recall the stack.

import sys

class TailRecurseException(BaseException):
    def __init__(self, args, kwargs):
        self.args = args
        self.kwargs = kwargs

def tail_call_optimized(g):
    '''
    This function decorates a function with tail call optimization. It does this by
    throwing an exception if it is its own grandparent, and catching such exceptions
    to fake the tail call optimization.

    This function will fail if the decorated function recurse in a non-tail context.
    '''
    def func(*args, **kwargs):
        f = sys._getframe()
        if f.f_back and f.f_back.f_back and f.f_back.f_back.f_code == f.f_code:
            raise TailRecurseException(args, kwargs)
        else:
            while 1:
                try:
                    return g(*args, **kwargs)
                except TailRecurseException as e:
                    args = e.args
                    kwargs = e.kwargs
    func.__doc__ = g.__doc__
    return func

@tail_call_optimized
def factorial(n, acc = 1):
    # Calculate a factorial.
    if n == 0:
        return acc
    return factorial(n - 1, n * acc)

print(factorial(10000))

@tail_call_optimized
def fib(i, current = 1, next = 1):
    # Calculate a fabnacci array.
    if i == 0:
        return current
    else:
        return fib(i - 1, next, current + next)

print(fib(10000))
