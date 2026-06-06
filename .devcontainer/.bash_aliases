alias upapt="sudo apt update && sudo apt upgrade -y && sudo apt full-upgrade -y && sudo apt autoremove -y && sudo apt autoclean -y"

alias g+="g++ -std=gnu++23 -O2 -DONLINE_JUDGE -DATCODER \
-Wall -Wextra -mtune=native -march=native -ftrivial-auto-var-init=zero \
-fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 \
-fconstexpr-ops-limit=2147483647 main.cpp"

function db() {
    g++ -std=gnu++23 -O2 -DONLINE_JUDGE -DATCODER -Wall -Wextra -mtune=native -march=native -ftrivial-auto-var-init=zero -fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 -fconstexpr-ops-limit=2147483647 -g -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC main.cpp
    ./a.out 2>&1 | awk "/Error: /{print; getline; print}"
    g++ -std=gnu++23 -DONLINE_JUDGE -DATCODER -Wall -Wextra -mtune=native -march=native -ftrivial-auto-var-init=zero -fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 -fconstexpr-ops-limit=2147483647 -g -fstack-protector -fsanitize=address -fsanitize=undefined main.cpp
    ./a.out 2>&1 | grep "/main.cpp"
}

alias cpt="cp /workspace/tmp/main.cpp ./"

alias cptmp="cp /workspace/tmp/main.cpp ~/.config/atcoder-cli-nodejs/cpp/"

function acnew() {
    cd /workspace/abc

    mod=$(($1 % 25))
    start=0
    if [ $mod -ne 0 ]; then start=$(($1 - $mod + 1))
    else start=$(($1 - 24))
    fi
    end=$(($start + 24))

    folder="abc$start~$end"
    if [ ! -d "$folder" ]; then mkdir $folder
    fi
    cd $folder

    acc new "abc$1" 1>& /dev/null
    cd "abc$1"
}

function abc() {
    mod=$(($1 % 25))
    start=0
    if [ $mod -ne 0 ]; then start=$(($1 - $mod + 1))
    else start=$(($1 - 24))
    fi
    end=$(($start + 24))

    cd /workspace/abc/abc$start~$end/abc$1
}

function ahctest() {
    cargo run -r --bin tester ./a.out < in/$1.txt > out/$1.txt
}
