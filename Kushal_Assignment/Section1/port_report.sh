#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <IP>"
    exit 1
fi

IP=$1
DATE=$(date +%Y-%m-%d)
FILE="scan_${IP}_${DATE}.txt"

PORTS=(21 22 80 443 3306)
OPEN_COUNT=0

echo "Scanning $IP..." > $FILE

for PORT in "${PORTS[@]}"; do
    timeout 1 bash -c "echo > /dev/tcp/$IP/$PORT" 2>/dev/null
    if [ $? -eq 0 ]; then
        echo "Port $PORT: OPEN" >> $FILE
        ((OPEN_COUNT++))
    else
        echo "Port $PORT: CLOSED" >> $FILE
    fi
done

echo "Total Open Ports: $OPEN_COUNT"
echo "Report saved in $FILE"
