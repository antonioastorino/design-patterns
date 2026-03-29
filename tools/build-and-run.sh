#!/usr/bin/env zsh

set -eu
setopt +o nomatch

pushd $1
FLAGS="-Wall -Wextra -Werror -std=c++23 -pedantic -fsanitize=address"
if [ "$(uname -s)" = "Linux" ]; then
    FLAGS="${FLAGS} -D_BSD_SOURCE -D_DEFAULT_SOURCE -D_GNU_SOURCE"
fi

echo "Formatting source code"
clang-format -i --style=file:"${HOME}/config/.clang-format" src/* include/*
echo "Formatting done"

rm -rf build/*
mkdir -p build

echo "--------"
echo "Building"
clang++ -v -o build/app src/main.cpp $(echo ${FLAGS})
echo "\n-------\nRunning\n"
./build/app
echo "-------"
