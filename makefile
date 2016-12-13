HEADERS :=					\
	LAL.h 					\
	./Vectors/Vectors.h 	\
	./Vectors/Vector2.h 	\
	./Vectors/Vector3.h 	\
	./Vectors/Vector4.h
SOURCES:=					\
	test.c++

G++FLAGS := -pedantic
C++STD= c++11

TESTBINARY:= test_exec

test: $(HEADERS) $(SOURCES)
# execution conditional on successful compilation
ifeq ($(shell g++ $(HEADERS) $(SOURCES) $(TESTFILE) -o $(TESTBINARY) -std=$(C++STD) $(G++FLAGS); echo $$?),0)
	@echo "${BOLD}${GREENFG}Compilation successful${WHITEFG}, executing compiled binary '$(TESTBINARY)'...${RESETCOLOR}\n"
	@./$(TESTBINARY) > test_output.txt 2>&1
	@echo "Output (stored in '${YELLOWFG}test_output.txt${RESETCOLOR}'):\n"
	@cat test_output.txt

else
	@echo "\n*** ${REDFG}${WHITEBG}Compilation failed${RESETCOLOR}: execution suppressed ***"
endif

#text decoration variables
REDFG=`tput setaf 1`
GREENFG=`tput setaf 2`
YELLOWFG=`tput setaf 3`
BLUEFG=`tput setaf 4`
WHITEFG=`tput setaf 7`
WHITEBG=`tput setab 7`
RESETCOLOR=`tput sgr0`
BOLD=`tput bold`