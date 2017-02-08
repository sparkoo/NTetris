## -*- Makefile -*-
##
## User: mvala
## Time: Feb 8, 2017 10:06:03 AM
## Makefile created by Oracle Developer Studio.
##
## This file is generated automatically.
##


#### Compiler and tool definitions shared by all build targets #####
CCC = g++
CXX = g++
BASICOPTS = -g
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# Define the target directories.
TARGETDIR_ntetris=build


all: $(TARGETDIR_ntetris)/ntetris

## Target: ntetris
CPPFLAGS_ntetris = \
	-Isrc
OBJS_ntetris =  \
	$(TARGETDIR_ntetris)/main.o \
	$(TARGETDIR_ntetris)/init.o \
	$(TARGETDIR_ntetris)/Kostka.o \
	$(TARGETDIR_ntetris)/Tvar.o \
	$(TARGETDIR_ntetris)/Stavba.o \
	$(TARGETDIR_ntetris)/Bod.o
SYSLIBS_ntetris = -lcurses 
USERLIBS_ntetris = /lib64/libncursesw.so.6.0 /lib64/libncursesw.so.6 /lib64/libncurses.so.6.0 /lib64/libncurses.so.6 $(SYSLIBS_ntetris) 
DEPLIBS_ntetris =      
LDLIBS_ntetris = $(USERLIBS_ntetris)


# Link or archive
$(TARGETDIR_ntetris)/ntetris: $(TARGETDIR_ntetris) $(OBJS_ntetris) $(DEPLIBS_ntetris)
	$(LINK.cc) $(CCFLAGS_ntetris) $(CPPFLAGS_ntetris) -o $@ $(OBJS_ntetris) $(LDLIBS_ntetris)


# Compile source files into .o files
$(TARGETDIR_ntetris)/main.o: $(TARGETDIR_ntetris) src/main.cpp
	$(COMPILE.cc) $(CCFLAGS_ntetris) $(CPPFLAGS_ntetris) -o $@ src/main.cpp

$(TARGETDIR_ntetris)/init.o: $(TARGETDIR_ntetris) src/init.cpp
	$(COMPILE.cc) $(CCFLAGS_ntetris) $(CPPFLAGS_ntetris) -o $@ src/init.cpp

$(TARGETDIR_ntetris)/Kostka.o: $(TARGETDIR_ntetris) src/Kostka.cpp
	$(COMPILE.cc) $(CCFLAGS_ntetris) $(CPPFLAGS_ntetris) -o $@ src/Kostka.cpp

$(TARGETDIR_ntetris)/Tvar.o: $(TARGETDIR_ntetris) src/Tvar.cpp
	$(COMPILE.cc) $(CCFLAGS_ntetris) $(CPPFLAGS_ntetris) -o $@ src/Tvar.cpp

$(TARGETDIR_ntetris)/Stavba.o: $(TARGETDIR_ntetris) src/Stavba.cpp
	$(COMPILE.cc) $(CCFLAGS_ntetris) $(CPPFLAGS_ntetris) -o $@ src/Stavba.cpp

$(TARGETDIR_ntetris)/Bod.o: $(TARGETDIR_ntetris) src/Bod.cpp
	$(COMPILE.cc) $(CCFLAGS_ntetris) $(CPPFLAGS_ntetris) -o $@ src/Bod.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_ntetris)/ntetris \
		$(TARGETDIR_ntetris)/main.o \
		$(TARGETDIR_ntetris)/init.o \
		$(TARGETDIR_ntetris)/Kostka.o \
		$(TARGETDIR_ntetris)/Tvar.o \
		$(TARGETDIR_ntetris)/Stavba.o \
		$(TARGETDIR_ntetris)/Bod.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_ntetris)


# Create the target directory (if needed)
$(TARGETDIR_ntetris):
	mkdir -p $(TARGETDIR_ntetris)


# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Linux

