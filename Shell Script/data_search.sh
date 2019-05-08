#!/bin/bash

searchAllByCity()
{
	echo
	while true
	do
		echo "Enter 'e' to exit the program."
		echo "Please enter a city name to search all (ex: Boston):"
		read sInput
		if [ "$sInput" == 'e' ]
			then
			break
		fi
		echo
		echo "timestamp city temperature light airquality_raw sound humidity dust"
		
		grep "$sInput" data.csv
		RETURNSTATUS=`echo $?`
		if [ $RETURNSTATUS -eq 1 ]
			then
			echo "Invalid input! Please try again!"
		fi
		echo
	done
}

searchAllByYear()
{
	echo
	while true
	do
		echo "Enter 'e' to exit the program."
		echo "Enter a specific year to see all parameters (ex.2015-): "
		read sInput
		if [ "$sInput" == 'e' ]
			then
			break
		fi
		echo
		echo "timestamp city temperature light airquality_raw sound humidity dust"
		
		grep "$sInput" data.csv
		RETURNSTATUS=`echo $?`
		if [ $RETURNSTATUS -eq 1 ]
			then
			echo "Invalid input! Please try again!"
		fi
		echo
	done
}

searchAllByDate()
{
	echo
	while true
	do
		echo "Enter 'e' to exit the program."
		echo "Please enter a date to search all parameters (ex: 2015-01-07): "
		read sInput
		if [ "$sInput" == 'e' ]
			then
			break
		fi
		echo
		echo "timestamp city temperature light airquality_raw sound humidity dust"
		
		grep "$sInput" data.csv
		RETURNSTATUS=`echo $?`
		if [ $RETURNSTATUS -eq 1 ]
			then
			echo "Invalid input! Please try again!"
		fi
		echo
	done
}

searchAllByTime()
{
	echo
	while true
	do
		echo "Enter 'e' to exit the program."
		echo "Please enter a time (ex: 20:15:00): "
		read sInput
		if [ "$sInput" == 'e' ]
			then
			break
		fi
		echo
		echo "timestamp city temperature light airquality_raw sound humidity dust"
		
		grep "$sInput" data.csv
		RETURNSTATUS=`echo $?`
		if [ $RETURNSTATUS -eq 1 ]
			then
			echo "Invalid input! Please try again!"
		fi
		echo
	done
}

echo
lastCharOfFile=`tail -c 1 data.csv` #making sure that the '.csv file' ends with newline character
if [ -n "$lastCharOfFile" ]
	then
	echo >> data.csv
fi
echo "###################################################"
echo "1. Search all parameters by a city name"
echo "2. Search all parameters' data by a year"
echo "3. Search all parameters' data by a specific date"
echo "4. Search all parameters' data by a specific time"
echo "###################################################"
echo "Please select a search option from above: "

read input

case $input in
	1) searchAllByCity;;
	2) searchAllByYear;;
	3) searchAllByDate;;
	4) searchAllByTime;;
esac
echo
