read id
cp ../complete/template.cpp ./
mv template.cpp "$id.cpp"
xdg-open "$id.cpp" && exit
