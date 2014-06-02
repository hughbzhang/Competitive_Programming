#!/bin/bash
./grade.sh $1 | awk '/score/ { print; sum += $4; } END { print "Total score:"; print sum; }'
