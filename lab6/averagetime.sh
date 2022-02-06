echo "Enter the hashTable file: "
read hashTable
echo "Enter the  grid file: "
read grid

run1=`./a.out $hashTable $grid | tail -1`
run2=`./a.out $hashTable $grid | tail -1`
run3=`./a.out $hashTable $grid | tail -1`
run4=`./a.out $hashTable $grid | tail -1`
run5=`./a.out $hashTable $grid | tail -1`

runCombo1=`expr $run1 + $run2`
runCombo2=`expr $run3 + $run4`
runCombo3=`expr $runCombo1 + $runCombo2`
total=`expr $runCombo3 + $run5`

averageTime=`expr $total / 5`
echo "The average time in milliseconds is: " 
echo $averageTime