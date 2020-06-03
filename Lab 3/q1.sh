echo "Enter the file name"
read file
if [ -d $file ]
then
echo "is a directory"
else
echo "Not a directory"
fi
