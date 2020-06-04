echo "Enter the file name"
read file
sed -i -n 1~2p $file
echo "done"

