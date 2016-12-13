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
	@echo "${BOLD}Executing compiled binary '$(TESTBINARY)'...${RESETCOLOR}\n"
	@./$(TESTBINARY)
else
	@echo "\n*** ${REDFG}${WHITEBG}Compilation failed${RESETCOLOR}: execution suppressed ***"
endif

#text decoration variables
REDFG=`tput setaf 1`
WHITEBG=`tput setab 7`
RESETCOLOR=`tput sgr0`
BOLD=`tput bold`