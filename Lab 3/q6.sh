echo "Enter the folder: "
read fld
cd $fld
arr=$ls
for i in $arr
do
sed -i 's/^ex:/Example:/g' $i
sed -i 's/\.ex:/\.Example/g' $i
done
echo "done"
