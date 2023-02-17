git add .
FILE=`git status | grep -ioh "\S*.cpp"`
git commit -m "$FILE"
git push
echo "Success commit $FILE!"
