#!/bin/sh

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

make std > /dev/null
./containers > std_out

rm containers

make ft > /dev/null 2>&1
./containers > ft_out

FILE=containers
if [ ! -f "${FILE}" ]
then
    echo "${RED}Compilation error. Your programme should compile at this stage. Check the main.c tests.${NC}"
else
	echo "-----Outputs test-----"
	DIFF=$(diff ft_out std_out)
	if [ "${DIFF}" != "" ]
	then
		echo "${RED}DIFF KO${NC}"
		diff ft_out std_out
	else
		echo "${GREEN}DIFF OK${NC}"
	fi
fi

echo "\n-----Compilation tests-----"
c++ -D NS=ft no_compile_1.cpp -o no_compile_test 2> /dev/null
FILE=no_compile_test
if [ -f "${FILE}" ]
then
    echo "${RED}${FILE} 1 should not compile.${NC}"
	rm ${FILE} > /dev/null
else
	echo "${GREEN}${FILE} 1 ok.${NC}"
fi

c++ -D NS=ft no_compile_2.cpp -o no_compile_test 2> /dev/null
FILE=no_compile_test
if [ -f "${FILE}" ]
then
    echo "${RED}${FILE} 2 should not compile.${NC}"
	rm ${FILE} > /dev/null
else
	echo "${GREEN}${FILE} 2 ok.${NC}"
fi

c++ -D NS=ft no_compile_3.cpp -o no_compile_test 2> /dev/null
FILE=no_compile_test
if [ -f "${FILE}" ]
then
    echo "${RED}${FILE} 3 should not compile.${NC}"
	rm ${FILE} > /dev/null
else
	echo "${GREEN}${FILE} 3 ok.${NC}"
fi


echo "\n-----Time test-----"
echo "(ft can be up to 20 times slower)"
c++ -D NS=std time_test.cpp -o time_test
echo "std: "
time ./time_test | grep real
c++ -D NS=ft time_test.cpp -o time_test
echo "\nft: "
time ./time_test | grep real


#comment the following line to keep and check the output files
rm ft_out std_out time_test > /dev/null
make fclean > /dev/null