# Macros ========================================
CC = gcc
CPP = g++
CFLAGS = -c -Wall -Wextra -Werror -pedantic -O2
CPPFLAGS = -Wall -Wextra -Werror -pedantic -O2 -Wconversion -g -std=c++11
OUTDIR = bin/
OBJECTS = $(OUTDIR)main.o
EXE = RUN
INPUT =
OUTPUT = myoutput.txt

#Doxygen.exe - Supports documentation for coding projects
#( type Doxyfile & echo EXTRACT_ALL=YES ) | doxygen.exe -
#( type Doxyfile & echo EXTRACT_ALL=NO ) | doxygen.exe -
DOXY = doxygen Doxyfile

#Tablen.exe - Examines files for tabs and line spacing
TAB = tablen
TFLAGS = --filename --all --verbose
TOUTPUT = patch.txt

#Zip.exe - Compresses files
ZIP = zip
ZFLAGS = -db -dc -de
ZOUT = zipfile.zip

#diff.exe - Compares text based code
DIFF = diff
DFLAGS = --strip-trailing-cr --side-by-side --report-identical-files
DOUT = patch.txt

#cloc.exe - Counts the code for specific files
CLOC = cloc.exe
CLCFLAGS = --by-file --csv
CLCDEFINE = --force-lang-def=clocdefinitions.txt ./
CLCOUT = -out=CodeCount.CSV

#Practical Makefiles by John Tsiombikas
SRCCC = $(wildcard *.c)
src = $(wildcard *.cpp)
OBJCC = $(SRCCC:.c=.o)
OBJCPP = $(src:.cpp=.o)

# Targets ========================================

$(OUTDIR)$(EXE) : $(OBJCPP) | $(OUTDIR)
	$(CPP) -o $@ $^ $(CPPFLAGS)

$(OUTDIR):
	mkdir -p $(OUTDIR)

.PHONY: clean
clean :
	rm $(OUTDIR)$(EXE) $(OBJCPP)

.PHONY: rebuild
rebuild :
	$(MAKE) clean
	$(MAKE)

.PHONY: run
run:
	cmd /c $(EXE) > $(OUTPUT) # 'cmd /C' Carries out the command specified by string and then terminates

.PHONY: diff
diff :
	$(DIFF) $(OUTPUT) $(INPUT) $(DFLAGS) >> $(DOUT); exit 0 #[ $$? -eq 1 ] BASH version

.PHONY: tablen
tablen :
	$(TAB) $(TFLAGS) $(wildcard *.c) >> $(TOUTPUT); exit 0
	$(TAB) $(TFLAGS) $(wildcard *.cpp) >> $(TOUTPUT); exit 0
	$(TAB) $(TFLAGS) $(wildcard *.h) >> $(TOUTPUT); exit 0

.PHONY: zip
zip :
	$(ZIP) $(ZFLAGS) $(ZOUT) $(wildcard *.c)
	$(ZIP) $(ZFLAGS) $(ZOUT) $(wildcard *.cpp)
	$(ZIP) $(ZFLAGS) $(ZOUT) $(wildcard *.h)

.PHONY: count
count :
	$(CLOC) $(CLCFLAGS) $(CLCDEFINE) $(CLCOUT)
