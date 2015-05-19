#!/bin/bash


num=$(awk 'BEGIN{for(i=4;i<=6;i+=0.1)print i}')




g++ BalancePendulum.cpp
for n in $num
do
                echo $n 89 91 >in.txt
                ./a.out <in.txt
                java -jar pendulum.jar 10000
                cat in.txt score.txt
            done
