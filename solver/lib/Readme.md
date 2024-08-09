# Electrical System Parser

## Overview

The Electrical System Parser is a tool designed for parsing and analyzing input files related to electrical systems. It uses Flex and Bison for lexical analysis and parsing, respectively, to handle and interpret input data that describes various components of a Single Line Diagram (SLD) for power systems.

## Project Structure

### Components

- **InputParser**: The main class responsible for parsing input files and initializing the SLD with components such as buses, transformers, and generators.
- **Lexer (`lexer.l`)**: Defines the lexical analyzer using Flex to tokenize the input stream.
- **Parser (`parser.y`)**: Defines the grammar and parsing rules using Bison to construct SLD components from tokenized input.
- **Header Files**: Define the structure of components and provide method declarations for the `InputParser` class.
- **Utilities**: Contains utility functions for error handling and other common tasks.

### Files

- `lib/input_parser.h`: Header file for the `InputParser` class.
- `lib/input_parser.cpp`: Implementation of the `InputParser` class.
- `lib/parser.y`: Bison file defining the grammar for parsing the input.
- `lib/lexer.l`: Flex file for tokenizing the input.
- `lib/parser_utils.h`: Header file for parser utility functions.
- `CMakeLists.txt`: CMake build configuration file for managing the build process.

## Detailed Documentation

### InputParser Class

The `InputParser` class is responsible for reading input files and command-line inputs, parsing them to extract definitions, and initializing the SLD components.

**Header File (`input_parser.h`)**

- **Public Methods**:
  - `InputParser()`: Default constructor.
  - `InputParser(const std::string& filename)`: Constructor that takes a filename for file-based input.
  - `void parseFile()`: Parses the input file specified in the constructor.
  - `void parseCLI(std::istringstream& input)`: Parses input from a command-line input stream.
  - `std::vector<Bus> getBuses() const`: Returns the list of buses.
  - `std::vector<Transformer> getTransformers() const`: Returns the list of transformers.
  - `std::vector<Generator> getGenerators() const`: Returns the list of generators.
  - `std::vector<Load> getLoads() const`: Returns the list of loads.
  - `std::vector<TransmissionLine> getTransmissionLines() const`: Returns the list of transmission lines.
  - `std::vector<CircuitBreaker> getCircuitBreakers() const`: Returns the list of circuit breakers.
  - `std::vector<Relay> getRelays() const`: Returns the list of relays.
  - `std::vector<Capacitor> getCapacitors() const`: Returns the list of capacitors.
  - `std::vector<Reactor> getReactors() const`: Returns the list of reactors.
  - `std::vector<Grid> getGrids() const`: Returns the list of grids.
  - `std::vector<Line> getLines() const`: Returns the list of lines.

- **Private Methods**:
  - `void parse(std::istream& input)`: Core parsing logic using Flex and Bison.

### Lexer (`lexer.l`)

Defines the lexical analyzer using Flex.

- **Tokens**:
  - `GRID`, `TRANSFORMER`, `BUS`, `CONNECTED`, `TO`, `VOLTAGE`, `TYPE`, `RATING`, `IMPEDANCE`, `FROM`, `GENERATION`, `LOAD`, `CONTROL`, `NONE`, `PQ`, `SLACK`: Keywords in the input.
  - `NUMBER`: Represents numerical values.
  - `STRING`: Represents string values.

- **Rules**:
  - Tokenizes keywords, numerical values, and strings.
  - Ignores whitespace.
  - Handles single-character tokens.

### Parser (`parser.y`)

Defines the grammar rules for parsing the input.

- **Grammar Rules**:
  - `input`: Represents the starting rule of the grammar, allowing for multiple lines of input.
  - `line`: Defines various types of lines, including bus definitions, transformer definitions, and grid definitions.
  - `bus_definition`: Parses bus definitions including voltage, generation, and control type.
  - `transformer_definition`: Parses transformer definitions including ratings and impedance.
  - `grid_definition`: Parses grid definitions including voltage and type.

- **Actions**:
  - Calls methods on `InputParser` to add components to the SLD.
  - Frees allocated memory for strings.

### Error Handling

- **Lexer (`lexer.l`)**: Defines a placeholder for error reporting (`yyerror`).
- **Parser (`parser.y`)**: Provides an implementation of `yyerror` to report parsing errors with line numbers.

## Building the Project

1. **Install Dependencies**: Ensure Flex and Bison are installed on your system.

2. **Generate Source Files**:
   - Run Flex to generate `lex.yy.cpp`:
     ```bash
     flex lib/lexer.l
     ```
   - Run Bison to generate `parser.tab.cpp` and `parser.tab.hpp`:
     ```bash
     bison -d lib/parser.y
     ```

3. **Configure CMake**:
   - Navigate to the project directory and create a build directory:
     ```bash
     mkdir build
     cd build
     ```
   - Run CMake to configure the project:
     ```bash
     cmake ..
     ```

4. **Build the Project**:
   - Compile the project using make:
     ```bash
     make
     ```

## Usage

1. **Input Files**: Prepare an input file with the required definitions for buses, transformers, etc. The format should follow the grammar specified in `parser.y`.

2. **Running the Parser**:
   - To parse a file, use the `InputParser` class:
     ```cpp
     InputParser parser("input_file.txt");
     parser.parseFile();
     ```

   - To parse command-line input:
     ```cpp
     std::istringstream cliInput("..."); // CLI input string
     parser.parseCLI(cliInput);
     ```

## Documentation

Detailed documentation for the parser and lexer is available in the `parser.y` and `lexer.l` files. Please refer to these files for information on the grammar and token definitions used in the project.

## License

This project is licensed under the GNU General Public License (GPL). See the [LICENSE](LICENSE) file for more details.

## Contributors

- **Subhendu Mishra**: Author and Maintainer

For any questions or contributions, please contact [Subhendu Mishra](mailto:subhendu.mishra@example.com).
