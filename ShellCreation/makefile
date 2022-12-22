TARGET=a.out
SOURCE=A1.c
DEPEND1=date_cmd
DEPEND2=ls_cmd
DEPEND3=cat_cmd
DEPEND4=mkdir_cmd
DEPEND5=rm_cmd

all: $(DEPEND1) $(DEPEND2) $(DEPEND3) $(DEPEND4) $(DEPEND5) $(TARGET)

a.out: $(SOURCE)
		gcc $(SOURCE) -lreadline

$(DEPEND1):
		gcc -o $(DEPEND1) date_cmd.c
$(DEPEND2):
		gcc -o $(DEPEND2) ls_cmd.c
$(DEPEND3):
		gcc -o $(DEPEND3) cat_cmd.c
$(DEPEND4):
		gcc -o $(DEPEND4) mkdir_cmd.c
$(DEPEND5):
		gcc -o $(DEPEND5) rm_cmd.c

run:
		./$(TARGET)

clean:
		rm -rf $(TARGET) $(DEPEND1) $(DEPEND2) $(DEPEND3) $(DEPEND4) $(DEPEND5)