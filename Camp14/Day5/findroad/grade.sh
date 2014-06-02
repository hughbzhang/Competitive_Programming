#!/bin/bash
g++ $1.cpp -o $1
g++ grade.cpp -o grade
for n in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
do
  cp I.$n findroad.in
  ./$1
  cp O.$n findroad.key
  ./grade
  cp newkey key.$n
done
