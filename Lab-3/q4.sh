echo "Enter the basic amount: "
read basic
echo "Enter the total allowance: "
read t
echo "Final value: "
echo "$basic*1.1+$t "|bc -l

