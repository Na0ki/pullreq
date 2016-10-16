TARGET=pullreq

OBJS=pullreq.o

CC=gcc

CFLAGS += -O3

$(TARGET): $(OBJS)
	$(CC) -Wall $(CFLAGS) -o $(TARGET) $(OBJS)

.PHONY: clean

clean:
	rm -f *~ *.o

cleanall: clean
	rm -f $(TARGET)
