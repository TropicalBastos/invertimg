#!/bin/bash



echo "Compiling source..."

g++ src/main.cpp src/invert.cpp -o bin/invertimage.out \
-std=c++11 -lX11 -lpthread &

#grab most recent process and store it in pid
pid=$!

trap "kill $pid 2> /dev/null" EXIT

chars="/-\|"
limit=20

for (( i=0; i<$limit; i++ )); do
  sleep 0.1
  echo -en "."
done

while kill -0 $pid 2> /dev/null; do
 for (( i=0; i<${#chars}; i++ )); do
   sleep 0.3
   #show char at position $i for only 1 len
   echo -en "\r" "${chars:$i:1}"
 done
done

echo -e "\n"

echo "Compile complete!"
echo "Installing binaries to path"

path="/usr/bin/"

chmod 777 invertimg
cp bin/invertimage.out $path
cp invertimg $path

echo "Install complete!"
