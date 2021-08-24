LIB_NAME := libsll.a
OBJ_NAME := libsll.o
LIB_DIR := ./lib

SRC := libsll.c

${LIB_NAME}: ${OBJ_NAME}
	ar rcs ${LIB_DIR}/${LIB_NAME} ${LIB_DIR}/${OBJ_NAME}

${OBJ_NAME}: ${SRC}
	gcc -c ${SRC} -o ${LIB_DIR}/${OBJ_NAME}

clean:
	rm -rf ${LIB_DIR}/${OBJ_NAME} ${LIB_DIR}/${LIB_NAME}
