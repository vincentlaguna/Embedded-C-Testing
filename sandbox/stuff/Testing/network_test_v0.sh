#! usr/bin/bash
# This is v.0 of the network test
DUMPID=./nttcpdump.pid
TARGETIP="192.168.128.169"
SERVER="192.168.128.60"
HOST="192.168.128.18"
CONNECTED=0
IFACE="eth0"
SDELAY=5
LDELAY=90

echo "\n<<< This is Network Test V.0 >>>\n\n"

#Main Loop
while [ true ]
do
    sleep SDELAY
    #Check for connection to server
    echo "\n***Establishing Connection to Server***>>>\n"
    
    ping -w 5 -c 1 $TARGETIP
    
    CONNECTED=$?
    
    echo "\nCONNECTED result code is: $CONNECTED\n"
    
    if [ $CONNECTED -eq 0 ];
    then
        echo "\n***Connection Established Successfully!***\n";
        #Setup iperf3 client
        iperf3 -c 1 $SERVER -B $HOST
    
        if [ -f "$DUMPID"];
        then
            echo "\n***Found PID. Killing TCP Dump Proc... >>>***\n";
            
            killall tcpdump
            rm $DUMPID
        fi
    fi
    
    if [ $CONNECTED -ne 0 ];
    then
        echo "\nConnection to Server failed...\n";
        
        if [ ! -f "$DUMPID"];
        then
            echo "\n***Initializing TCP Dump... >>>***\n";
            
            tcpdump -U -nn -s0 -I $IFACE -vvv -w ./tcpdump_`date'+%Y_%m_%d_%H_%M_%S'`.pcap >tcpdumpstdout.log 2>tcpdumperror.log &
            echo $! > $DUMPID
        fi
        
        sleep LDELAY
        
        echo "\n***Attempting to Re-establish Connection to Server***>>>\n";
    fi
done