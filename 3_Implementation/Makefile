PROJ_NAME = bankmain
TEST_PROJ_NAME = bank_test

SRC =src/see.c \
src/transact.c \
src/new_account.c \
src/interest.c \
src/menu.c \
src/delay.c \

COV_SRC = bank_test.c

TEST_SRC = test/bank_test.c \
unity/unity.c 
INC_H = inc
INC_T = unity

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif
.PHONY: run clean test doc all

all:
	gcc -I $(INC_H) $(SRC) bankmain.c -o $(call FixPath,$(PROJ_NAME).$(EXEC))
	
run:
	$(call FixPath,$(PROJ_NAME).$(EXEC))
	
test:
	gcc -I $(INC_H) -I $(INC_T) $(TEST_SRC) $(SRC) -o $(call FixPath,$(TEST_PROJ_NAME).$(EXEC))
	./$(call FixPath,$(TEST_PROJ_NAME).$(EXEC))

coverage:
	gcc -fprofile-arcs -ftest-coverage -I $(INC_H) -I $(INC_T) unity/unity.c test/bank_test.c $(SRC) -o $(call FixPath, $(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath, ./$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(COV_SRC)

cppcheck:
	cppcheck --enable=all $(SRC) bankmain.c
debug:
	gcc -I $(INC_H) $(SRC) bankmain.c -g -o $(PROJ_NAME).$(EXEC)
	gdb $(PROJ_NAME).$(EXEC)

valgrind:
	valgrind ./$(TEST_PROJ_NAME).$(EXEC)

doc:
	make -C ./documentation

clean:
	del *.DAT
	del *.$(EXEC)
	del *.gcda
	del *.gcno
