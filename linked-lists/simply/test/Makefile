EXE_NAME := test_sll
OBJ := test_sll.o
SRC := test_sll.c
LIB_DIR := ../lib

INCL := -I. -I..
LIB_FLAGS := -L${LIB_DIR} -lsll

${EXE_NAME}: ${OBJ}
	gcc -o ${EXE_NAME} ${OBJ} ${LIB_FLAGS}

${OBJ}: ${SRC}
	gcc -c ${SRC} -o ${OBJ} ${INCL}

clean:
	rm -rf ${EXE_NAME} ${OBJ}
