HEADERS :=			\
	LAL.h 			\
	Vectors.h
SOURCES:=			\
	test.c++

G++FLAGS := -pedantic
C++STD= c++11

test: $(HEADERS) $(SOURCES)
# execution conditional on successful compilation
ifeq ($(shell g++ $(HEADERS) $(SOURCES) $(TESTFILE) -o test_exec -std=$(C++STD) $(G++FLAGS); echo $$?),0)
	@echo "${BOLD}Executing compiled binary...${RESETCOLOR}\n"
	@./test_exec
else
	@echo "\n*** ${REDFG}${WHITEBG}Compilation failed${RESETCOLOR}: execution suppressed ***"
endif

#text decoration variables
REDFG=`tput setaf 1`
WHITEBG=`tput setab 7`
RESETCOLOR=`tput sgr0`
BOLD=`tput bold`