#!/bin/bash

while true; do
  hours=$(date +%H)
  minutes=$(date +%M)
  seconds=$(date +%S)
  echo "$hours:$minutes:$seconds"
  sleep 1
done
