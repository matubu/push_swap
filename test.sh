#!/bin/bash

total=0
for i in {0..100}
do
	echo $(total) + $(./push_swap `ruby -e "puts (1..50).to_a.shuffle.join(' ')"` | wc -l)
done
