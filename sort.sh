echo "Enter the Total numbers :"
read n
echo "Enter numbers :"
i=0
while [ $i -lt $n ]
do
    read arr[$i]
    i=`expr $i + 1`
done
for ((i = 0; i<5; i++))
do
for((j = 0; j<5-i-1; j++))
do
if [ "${arr[j]}" -gt ${arr[$((j+1))]} ]
then
temp=${arr[j]}
arr[$j]=${arr[$((j+1))]}  
arr[$((j+1))]=$temp
fi
done
done
echo "Array in sorted order :"
echo ${arr[*]}