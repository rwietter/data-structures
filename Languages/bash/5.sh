#!/bin/bash

: <<'COMMENT'
  Comparing Numbers
COMMENT

read -p "X: " X
read -p "Y: " Y

X=$(($X))
Y=$(($Y))

if [[ $X -gt $Y ]]; then
  echo "X is greater than Y"

elif [[ $X -lt $Y ]]; then
  echo "X is less than Y"
elif [[ $X -eq $Y ]]; then
  echo "X is equal to Y"
fi
