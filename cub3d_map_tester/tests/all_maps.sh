#!/bin/bash

#FORMATTING VARIABLES
GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"
BPURPLE="\033[1;35m"
BWHITE="\033[1;37m"
ON_BLUE="\033[44m"
ON_CYAN="\033[46m"
OK="[OK]"
KO="[KO]"

#LOGICAL/HELPERS VARIABLES
TRUE=1
FALSE=0
COUNTER=1

#MAP VARIABLES
HEADER_VALID="VALID_MAPS"
HEADER_INVALID="INVALID_MAPS"
MAP_TYPE="$1"
SHOULD_RUN_VALID_MAPS=$FALSE
SHOULD_RUN_INVALID_MAPS=$FALSE
CUB3D_PATH=../
VALID_DIR=${CUB3D_PATH}assets/maps/valid
INVALID_DIR=${CUB3D_PATH}assets/maps/invalid
BINARY_FILE=cub3D

#CHECK ERRORS/SUCESS VARIABLES
GAME_START_FLAG="Game has started!"
MLX_ERROR="MLX Error"
ERROR="Error"
VALGRIND="valgrind -s --leak-check=full --show-leak-kinds=all "
NO_LEAK_MESSAGE="All heap blocks were freed -- no leaks are possible"
LOG_DIR="logs"
FIXED_PWD=""
if [ -z "$MAP_TYPE" ]; then
	echo "No argument supplied"
	exit
fi

if [ "$MAP_TYPE" = "both" ]; then
	SHOULD_RUN_VALID_MAPS=$TRUE
	SHOULD_RUN_INVALID_MAPS=$TRUE
elif [ "$MAP_TYPE" = "valid" ]; then
	SHOULD_RUN_VALID_MAPS=$TRUE
elif [ "$MAP_TYPE" = "invalid" ]; then
	SHOULD_RUN_INVALID_MAPS=$TRUE
else
	echo "The only available options are 'both','valid','invalid'"
	exit
fi

print_separator() {
	printf "$BWHITE$ON_CYAN\n%s$RESET\n" "$1"
}

print_file_name() {
	printf "$BWHITE Test %-3s$BPURPLE%-50s$RESET" $1 $2
}

print_output() {
	printf "%.1s" -{1..70} $'\n'
	OUTPUT=$(echo "$1" | sed 's/Error /Error \n  /g')
 	printf "  %-40s\n" "$OUTPUT"
	printf "%.1s" -{1..70} $'\n'
}

print_result() {
	TEST_RESULT=$FALSE
	if [ "$1" = $HEADER_INVALID ]; then
		TEST_RESULT=$(($HAS_ERROR == $TRUE && $IS_MLX_ERROR == $FALSE && $HAS_NO_LEAK == $TRUE))
	elif [ "$1" = $HEADER_VALID ]; then
		TEST_RESULT=$((($IS_MLX_ERROR == $TRUE || $GAME_HAS_STARTED == $TRUE) && $HAS_NO_LEAK == $TRUE))
	fi
	if (($TEST_RESULT == $TRUE)); then
		printf "$GREEN%-20s$RESET\n" $OK
	else
		printf "$RED%-20s$RESET\n" $KO
		if (($HAS_NO_LEAK == $FALSE)); then
			printf "\n$RED%s$RESET\n" "Check "$2" file to see all the memory leaks!"
		fi
	fi
}

save_pwd() {
	PWD="$(pwd)"
	FIXED_PWD="$PWD"
}

run_test() {
	SHOULD_RUN=$1
	HEADER="$2"
	DIRECTORY="$3"
	if (($SHOULD_RUN == $FALSE)); then
		return 0
	fi
	print_separator "$HEADER"
	for file in $DIRECTORY/*
	do
		if [ -d "$file" ]; then
			continue
		fi
		BASE_NAME=$(basename "$file")
		VALID_INVALID=$(basename $DIRECTORY)
		LOG_FILE="$LOG_DIR/$VALID_INVALID/memcheck_"$BASE_NAME".log"
		LOG_FILE_FULL_PATH="$FIXED_PWD/$LOG_FILE"
		print_file_name $(( COUNTER++ )) "$BASE_NAME"
		WHOLE_OUTPUT=$(cd "$CUB3D_PATH" && $VALGRIND --log-file="$LOG_FILE_FULL_PATH" ./${BINARY_FILE} "$FIXED_PWD/$file" && cd "$FIXED_PWD")
		HAS_ERROR=$(echo -e $WHOLE_OUTPUT | grep  "$ERROR" | wc -l)
		IS_MLX_ERROR=$(echo -e $WHOLE_OUTPUT | grep  "$MLX_ERROR" | wc -l)
		HAS_NO_LEAK=$(cat "$LOG_FILE_FULL_PATH" | grep "$NO_LEAK_MESSAGE" | wc -l)
		GAME_HAS_STARTED=$(echo -e $WHOLE_OUTPUT | grep "$GAME_START_FLAG" | wc -l)
		print_result $HEADER $LOG_FILE
		print_output "$WHOLE_OUTPUT"
	done
}
save_pwd
run_test $SHOULD_RUN_INVALID_MAPS "$HEADER_INVALID" "$INVALID_DIR"
run_test $SHOULD_RUN_VALID_MAPS "$HEADER_VALID" "$VALID_DIR"
