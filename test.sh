for i in {1..100}
do
	VALUES=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`
	N=./push_swap $VALUES | wc -l
	VALID=./push_swap $VALUES | ./checker $VALUES
	echo $VALID $N
done
