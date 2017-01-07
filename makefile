HEADERS :=					\
	LAL.h 					\
	./Vectors/Vectors.h 	\
	./Vectors/Vector2.h 	\
	./Vectors/Vector3.h 	\
	./Matrices/Matrix3x3.h

SOURCES :=					\
	./Vectors/Vector2.c++	\
	./Vectors/Vector3.c++ 	\
	./Matrices/Matrix3x3.c++

TESTHEADERS:=							\
	test_utils.hpp						\
	./Vectors/Tests/Vector2_Test.h 		\
	./Vectors/Tests/Vector3_Test.h 		\
	./Matrices/Tests/Matrix3x3_Test.h

TESTSOURCES:=							\
	test.c++							\
	test_utils.c++						\
	./Vectors/Tests/Vector2_Test.c++ 	\
	./Vectors/Tests/Vector3_Test.c++ 	\
	./Matrices/Tests/Matrix3x3_Test.c++

G++FLAGS := -pedantic
C++STD= c++11
OUTPUTFILE= test_output.txt

TESTBINARY:= test_exec

test: $(HEADERS) $(SOURCES) $(TESTBINARY)
# execution conditional on successful compilation
	@rm -f $(OUTPUTFILE)
ifeq ($(shell g++ $(HEADERS) $(TESTHEADERS) $(SOURCES) $(TESTSOURCES) $(TESTFILE) -o $(TESTBINARY) -std=$(C++STD) $(G++FLAGS); echo $$?),0)
	@echo "${BOLD}${GREENFG}Compilation successful${WHITEFG}, executing compiled binary '$(TESTBINARY)'...${RESETCOLOR}\n"
	@./$(TESTBINARY) > test_output.txt 2>&1
	@echo "Output (stored in '${YELLOWFG}$(OUTPUTFILE)${RESETCOLOR}'):\n"
	@cat $(OUTPUTFILE)
else
	@echo "\n*** ${REDFG}${WHITEBG}Compilation failed${RESETCOLOR}: execution suppressed, $(OUTPUTFILE) and $(TESTBINARY) removed***"
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