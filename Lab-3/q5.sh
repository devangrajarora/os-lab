echo "enter the extension: "
read ext
echo "Enter the folder to move to: "
read fld
mkdir -p $fld
mv -i *.$ext $fld
