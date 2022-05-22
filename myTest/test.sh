#!/bin/sh

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

make std > /dev/null
./containers > std_out

make ft > /dev/null
./containers > ft_out


DIFF=$(diff ft_out std_out)
if [ "$DIFF" != "" ]
then
	echo "${RED}DIFF KO${NC}"
	diff ft_out std_out
else
	echo "${GREEN}DIFF OK${NC}"
fi


#comment these lines to keep and check the output files
#rm ft_out std_out > /dev/null
make fclean > /dev/null