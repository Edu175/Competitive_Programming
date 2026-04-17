#!/bin/bash

for i in {1..10000}
do
    ./c<pre>in
    o1=$(./a<in)
    o2=$(./b<in)
    if ["$o1" == "$o2"]; then
        echo "ok"
    else
        break
    fi
done
