adjacent-squares
================

The coffee time challenges can be found here at http://www.datagenetics.com/blog/june22014/index.html

The 12th problem is the adjacent squares problem, defined as:

"Arrange the integers 1-17 (inclusive) so that each adjacent pair of numbers is a perfect square. e.g. 14, 2, 7 … (The first and last do not have to wrap around)"

This C program attempts to find any one solution to this problem for arbitrary size. So, instead of integers 1-17, it solves the problem for integers 1-N.

The default program finds solutions for the problem up to N=100. For low N, some solutions do not exist. However, for large N, many solutions may exist.
For this particular problem, it only finds one solutions using a "smart" brute-force method, checking only the numbers that could possibly come next in the sequence.
