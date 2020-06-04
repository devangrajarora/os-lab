f=${1}
echo -n "Number of students with F grade:"
grep  -c F$ $f
sed  -e 's/A$/A+/g' $f
