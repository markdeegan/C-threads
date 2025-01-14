########################################
# Mark Deegan Tue 14 Jan 2025 16:29:19 GMT
# Thread vs. Process Demo Makefile
########################################

########################################
# define variables for the gcc compiler
CXX		= gcc
CXXFLAGS 	= -Wall
BINDIR 		= ../bin

VERSIONS = 02 03 04

########################################
# define the default value for VER
# to override it when running make, use make VER=03 etc...
# or VER=03 make
VER?=03

########################################
# define the SRC file and the TARGET based omn the VER variable above
FILENAMEROOT	= thread_process_demo
TARGET	 	= $(FILENAMEROOT)$(VER)
SRC		= $(FILENAMEROOT)$(VER).c

########################################
# Build the TARGET (defined above based on VER) from the SRC (also defined above based on VER)
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BINDIR)/$(TARGET)

########################################
# Run the target, again, based on the target defined above based on VER
run:	$(BINDIR)/$(TARGET)
	$(BINDIR)/$(TARGET)

# all:	$(TARGET)
all:
	$(foreach var,$(VERSIONS),$(CXX) $(CXXFLAGS) $(FILENAMEROOT)$(var).c -o $(BINDIR)/$(FILENAMEROOT)$(var);)
	
clean:
# @-rm -f $(TARGET) >/dev/null || true
	@-rm -f ../bin/* >/dev/null || true
