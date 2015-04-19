


# project name (generate executable with this name)
TARGET	= test


CC		= gcc
CFLAGS	= -std=gnu99 -Wall -I.

LINKER	= gcc -o
LDFLAGS	= -Wall -I. -lm

SRCDIR	= src
OBJDIR	= obj

#SOURCES	:= $(wildcard $(SRCDIR)/*.c)
SOURCES	= src/noyau.c src/noyaufil.c src/test.c
OBJECTS	:= $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm		= rm -f


$(TARGET): $(OBJECTS)
	$(LINKER) $@ $(LFLAGS) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONEY: clean
clean:
	$(rm) $(OBJECTS)
	$(rm) $(TARGET)
