#! /bin/bash
# This is v.1.0 of the network test
#TARGETIP="192.168.128.53"
#MIBIP="192.168.128.122"
#SERVER="192.168.128.49"
#HOST="192.168.128.18"
CONNECTEDTGT=0
CONNECTED=0
TRUE=1
#IFACE="eth0"
SDELAY=1
MDELAY=5
LDELAY=90

echo "<<< This is a Network Test V.1.0 >>>"
echo ""
echo "Please Enter Host IP Address: "
read HOST

echo ""
echo "Please Enter Server IP: "
read SERVER

echo ""
echo "Enter Target IP Address: "
read TARGETIP

echo ""
echo "Enter Target MIB IP Address: "
read MIBIP

echo ""
echo "Checking Connection to Target MicroLink...>>>"
echo ""
ping -w 5 -c 3 $TARGETIP
if [ $? -eq 0 ];
then
	sleep $SDELAY
	echo ""
	echo "<<< Connection to Target MicroLink Successful >>>"
	echo ""
else
	echo ""
	echo "<<< Failed to connect to Target MicroLink! >>>"
	echo ""
fi

echo ""
echo "Checking Connection to Target MicroLink MIB IP...>>>"
echo ""
ping -w 5 -c 3 $MIBIP
if [ $? -eq 0 ];
then
	sleep $SDELAY
	echo ""
	echo "<<< Connection to Target MicroLink MIB IP Successful >>>"
	echo ""
else
	echo ""
	echo "<<< Failed to connect to Target MicroLink MIB IP! >>>"
	echo ""
fi

echo ""
echo "Checking Connection to Server...>>>"
echo ""
ping -w 5 -c 5 $SERVER
if [ $? -eq 0 ];
then
	sleep $SDELAY
	echo ""
	echo "<<< Connection to Server Successful >>>"
	echo ""
else
	echo ""
	echo "<<< Failed to connect to Server! >>>"
	echo ""
fi

echo ""
echo "<<< Connected >>>"
echo ""

CONNECTED=$?

while [ $CONNECTED -eq 0 ]
do

	echo ""
	sleep $MDELAY
        echo "Checking Connection to Server Valid...>>>"
	echo ""
       	ping -w 5 -c 5 $SERVER
	echo ""
	echo "Connection to Server Successful! Running Iperf3 Tests"
	echo ""
	iperf3 -c $SERVER -B $HOST
	echo ""
	echo "<<< Iperf3 Test Successful >>>"
	echo ""
done

exit 0