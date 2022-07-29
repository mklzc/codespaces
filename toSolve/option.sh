# !/bin/bash
print_pass(){
    echo -e "\033[32m$1 \033[0m"
}
if [ $1 = "clear" ]; then
    rm in out P???? std std.cpp ans *.out > /dev/null 2>&1
    print_pass "OK"
    elif [ $1 = "create" ]; then
        cp ../complete/template.cpp ./"$2.cpp"
        xdg-open "$2.cpp" > /dev/null 2>&1
        print_pass "OK"
    elif [ $1 = "data" ]; then
        mv ~/Downloads/*.in ./
        mv ~/Downloads/*.out ./
        mv *.in "in"
        mv *.out ans
        print_pass "OK"
    elif [ $1 = "update" ]; then
        git add ../* ../.vscode
        git status
        git commit -m "commit"
        git push origin master
fi
