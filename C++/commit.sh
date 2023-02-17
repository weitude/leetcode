git add .
FILE=`git status | grep -ioh "\S*.cpp"`
echo $FILE
git commit -m "$FILE"
