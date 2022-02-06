

echo "enter the exponent for counter.cpp: "
read exponent

count=5

total=0

if [[ $exponent == "quit" ]] ; then
    exit 0
    fi

for ((i=1; i <=count; i++)) 
do
    echo "Running iteration ${i}..."
    time=`./a.out ${exponent}`
    echo "time taken: ${time} ms"
    total=`expr $total + $time`
done

echo "Average time was "`expr $total / $count`"ms"
