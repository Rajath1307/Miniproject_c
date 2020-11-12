# Name of the project
PROJECT_NAME = FIR

# Output directory
BUILD = build

# All source code files
SRC=main.c\
unit/unity.c\
test/testlog.c



PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

#All header files
TEST= -Itest\
-Iunit

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test  doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(TEST) -o $(PROJECT_OUTPUT).out

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).out

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD)

# Create new build folder if not present
$(BUILD):
	mkdir build




