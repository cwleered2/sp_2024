SRCS = main.c
LIBSRCS = open.c close.c put.c get.c
TARG = kvs_static
TARG_DYNAMIC = kvs_dynamic

CC = gcc
OPTS = -Wall -g
LIBS_STATIC = -L. -lkvs
LIBS_DYNAMIC = -L. -lkvs_dynamic

OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)

LARS = libkvs.a
LSO = libkvs_dynamic.so

all: static dynamic

static: $(TARG)
$(TARG): $(OBJS) $(LARS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS_STATIC) -static

$(LARS): $(LOBJS)
	ar rs $(LARS) $(LOBJS)

dynamic: $(TARG_DYNAMIC)
$(TARG_DYNAMIC): $(OBJS) $(LSO)
	$(CC) -o $(TARG_DYNAMIC) $(OBJS) $(LIBS_DYNAMIC)

$(LSO): $(LOBJS)
	$(CC) -shared -o $(LSO) $(LOBJS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@
clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(LSO) $(TARG) $(TARG_DYNAMIC)
