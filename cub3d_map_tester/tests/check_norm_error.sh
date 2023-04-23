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
ERRORS_COUNT=0
NORMINETTE_OK="OK!"
NORMINETTE_HEADER="NORMINETTE VALIDATOR"

#LOGICAL/HELPERS VARIABLES
TRUE=1
FALSE=0

SO_LONG_PATH=../
HAS_NORM_ERROR=$FALSE
NORMINETTES_PATH=$(find "$SO_LONG_PATH" -maxdepth 1 -type d ! -path "$SO_LONG_PATH" -type d ! -path '*so_long_tester*' -type d ! -path '*.git*' | tr '\n' ' ')
NORMINETTES_FILES_C=$(find "$SO_LONG_PATH" -maxdepth 1 -type f -wholename "$SO_LONG_PATH*.c" | tr '\n' ' ')
NORMINETTES_PATH+="$NORMINETTES_FILES_C"
OUTPUT=$(norminette $NORMINETTES_PATH | grep -v "$NORMINETTE_OK")
ERRORS_COUNT=$(printf "%s" "$OUTPUT" | wc -l)

printf "$BWHITE$ON_CYAN\n%s$RESET\n" "$NORMINETTE_HEADER"
printf "$BWHITE""Norminette Folders and Files:$RESET $GREEN%s\n$RESET" "$NORMINETTES_PATH"
if (($ERRORS_COUNT > 0)) ; then
	printf "$BWHITE""Resut:$RESET $RED%-20s$RESET\n" $KO
	printf "%s" "$OUTPUT"
else
	printf "$BWHITE""Resut:$RESET $GREEN%-20s$RESET\n" $OK
fi

