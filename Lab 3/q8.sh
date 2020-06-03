echo "Enter the number"
read n
for ((i=2;i<n;i++));do
if [ $((n%i)) -eq 0 ]; then
echo "The number is not prime"
exit
fi
done

echo "The number is prime"